#include <QUdpSocket>
#include <QObject>
#include <QNetworkDatagram>
#include <QApplication>
#include <QLineSeries>
#include <QChartView>
#include <QChart>
#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <thread>
#include <iostream>
#include <fstream>
#include <QPushButton>
#include <unordered_set>
#include <QThread>

#include "f1udpinterface/public.h"
#include "gui/CarActivationButton.h"
#include "gui/TeamColorMapping.h"
#include "f1udpinterface/ids/TeamId.h"
#include "gui/Worker.h"
#include "f1udpinterface/packets/PacketFactory.h"
#include "util.h"

using namespace F122::Network::Packets;

std::shared_ptr<ParticipantsData> participantsData;
// The number of max cars is 22
std::array<QLineSeries*, 22> speedSeries;
std::array<QLineSeries*, 22> throttleSeries;
std::array<QLineSeries*, 22> breakSeries;
std::array<CarActivationButton*, 22> carActivationButtons;

void processTheDatagram(const QNetworkDatagram& datagram, QChart* chart) {
    auto bytes = datagram.data();
    auto packet = createPacket(bytes);

    if (bytes.length() == CarTelemetryData::SIZE) {
        std::unique_ptr<CarTelemetryData> telemetryData =
                std::get<std::unique_ptr<CarTelemetryData>>(std::move(packet));
        auto points = speedSeries[0]->points();
        QPointF minXPoint = QPointF(0, 0);

        if (!points.empty()) {
            minXPoint = *std::min_element(points.begin(), points.end(),
                                          [](const QPointF& p1, const QPointF& p2) { return p1.x() < p2.x(); });
        }

        // Increase length of x-axis. The x-axis is time.
        const float time = telemetryData->m_header.m_sessionTime;
        chart->axes(Qt::Horizontal)[0]->setRange(std::min(static_cast<double>(time), minXPoint.x()), time + 5);

        for (int i = 0; i < speedSeries.size(); ++i) {
            auto& carTelemetryData = telemetryData->m_carTelemetryData[i];
            auto* carSpeedSeries = speedSeries[i];

            (*carSpeedSeries) << QPointF(time, carTelemetryData.m_speed);
        }
    } else if (bytes.length() == ParticipantsData::SIZE) {
        // TODO
        participantsData = std::make_shared<ParticipantsData>(util::copy_to_array<ParticipantsData::SIZE>(bytes));

        std::unordered_set<F122::TeamId> encounteredTeams;
        for (int i = 0; i < 22; ++i) {
            auto participant = participantsData->m_participants[i];

            // 255 means no team is selected. This only happens if the received is an empty dummy object, i.e.,
            // a car seat that doesn't participate in the race.
            if (participant.m_teamId != 255) continue;

            auto teamId = static_cast<F122::TeamId>(participant.m_teamId);
            auto rgba = to_rgba(F122::from_team_id(teamId));
            auto color = QColor(std::get<0>(rgba), std::get<1>(rgba), std::get<2>(rgba));

            if (!encounteredTeams.contains(teamId)) {
                color = color.darker(150);
                encounteredTeams.insert(teamId);
            }

            speedSeries[i]->setColor(color);
            carActivationButtons[i]->setText(QString::fromStdString(participant.name()));
        }
    }
}

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QMainWindow window;

    auto* mainWidget = new QWidget(&window);
    auto* layout = new QVBoxLayout();
    auto* speedChart = new QChart();
    auto* throttleChart = new QChart();

    auto* btnLayout = new QHBoxLayout();
    for (int i = 0; i < 22; ++i) {
        speedSeries[i] = new QLineSeries(speedChart);
        speedChart->addSeries(speedSeries[i]);

        throttleSeries[i] = new QLineSeries(throttleChart);
        throttleChart->addSeries(throttleSeries[i]);

        // Create toggle button to turn each series on or off, i.e., display them or not.
        auto* button = new CarActivationButton(speedSeries[i]);
        carActivationButtons[i] = button;
        button->setText(QString::fromStdString("Car " + std::to_string(i + 1)));
        btnLayout->addWidget(button);
    }

    layout->addLayout(btnLayout);

    {
        auto* container = new QHBoxLayout();
        auto* selectAllBtn = new QPushButton();

        auto isAnyInactiveFunc = []() {
            return std::any_of(carActivationButtons.begin(), carActivationButtons.end(),
                               [](auto* x) { return !x->isActive(); });
        };

        auto setAppropriateButtonText = [&selectAllBtn](bool isAnyInactive) {
            selectAllBtn->setText(QString::fromStdString(isAnyInactive ? "Select All" : "Deselect All"));
        };

        auto toggleAllButtons = [&isAnyInactiveFunc, &setAppropriateButtonText]() {
            bool isAnyInactive = isAnyInactiveFunc();

            std::cout << isAnyInactiveFunc() << std::endl;

            std::for_each(carActivationButtons.begin(), carActivationButtons.end(),
                          [&isAnyInactive](auto* x) { x->setIsActive(isAnyInactive); });
            setAppropriateButtonText(!isAnyInactive);
        };

        std::cout << isAnyInactiveFunc() << std::endl;

        setAppropriateButtonText(isAnyInactiveFunc());
        QObject::connect(selectAllBtn, &QPushButton::clicked, toggleAllButtons);

        container->addWidget(selectAllBtn);

        layout->addLayout(container);
    }

    speedChart->legend()->hide();
    speedChart->createDefaultAxes();
    speedChart->setTitle("Driver Speed in km/h");

    throttleChart->legend()->hide();
    throttleChart->createDefaultAxes();
    throttleChart->setTitle("Throttle Application");

    // Set speedChart range to [0, 355], because the top speed is ~343 km/h.
    speedChart->axes(Qt::Vertical /*, series */)[0]->setRange(0, 355);

    auto* speedChartView = new QChartView(speedChart);
    speedChartView->setRenderHint(QPainter::Antialiasing);

    auto* throttleChartView = new QChartView(throttleChart);
    throttleChartView->setRenderHint(QPainter::Antialiasing);

    window.resize(400, 300);

    auto* label = new QLabel(&window);
    label->setText("first line\nsecond line");

    layout->addWidget(label);
    {
        auto* chartContainer = new QHBoxLayout();

        chartContainer->addWidget(speedChartView);
        chartContainer->addWidget(throttleChartView);

        layout->addLayout(chartContainer);
    }

    mainWidget->setLayout(layout);

    window.setCentralWidget(mainWidget);
    window.show();

    auto* thread = new QThread();
    auto* worker = new Worker(speedChart, speedSeries, carActivationButtons, participantsData);
    worker->moveToThread(thread);

    QUdpSocket udpSocket;
    udpSocket.bind(20777, QUdpSocket::ShareAddress);
    QObject::connect(&udpSocket, &QUdpSocket::readyRead, [&udpSocket, &worker]() {
        for (int i = 0; i < 25 && udpSocket.hasPendingDatagrams(); ++i) {
            worker->insert(udpSocket.receiveDatagram());
        }
    });

    QObject::connect(worker, &Worker::error, [](const auto& x) { qDebug() << x; });
    QObject::connect(thread, &QThread::started, worker, &Worker::process);
    QObject::connect(worker, &Worker::finished, thread, &QThread::quit);
    QObject::connect(worker, &Worker::finished, worker, &Worker::deleteLater);
    QObject::connect(thread, &QThread::finished, thread, &QThread::deleteLater);
    thread->start();

    return QApplication::exec();
}
