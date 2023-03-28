#include <QUdpSocket>
#include <QObject>
#include <QNetworkDatagram>
#include <QApplication>
#include <QLineSeries>
#include <QChartView>
#include <QChart>
#include <QMainWindow>
#include <thread>
#include <iostream>
#include <fstream>

#include "f1udpinterface/public.h"

using namespace F122::Network::Packets;
using PacketVariant = std::variant<std::unique_ptr<CarDamageData>, std::unique_ptr<CarSetupData>,
        std::unique_ptr<CarStatusData>, std::unique_ptr<CarTelemetryData>, std::unique_ptr<EventData>,
        std::unique_ptr<FinalClassificationData>, std::unique_ptr<LapData>, std::unique_ptr<LobbyInfoData>,
        std::unique_ptr<MotionData>, std::unique_ptr<ParticipantsData>, std::unique_ptr<SessionData>,
        std::unique_ptr<SessionHistoryData>>;

template<size_t N>
std::array<std::uint8_t, N> copy_to_array(const QByteArray& bytes) {
    std::array<std::uint8_t, N> array{};
    std::copy(bytes.begin(), bytes.end(), array.begin());

    return array;
}

/// A factory to create the specific data structure from the incoming network packet.
PacketVariant createPacket(const QByteArray& bytes) {
    PacketVariant packetVariant{};

    switch (bytes.size()) {
        case CarDamageData::SIZE:
            packetVariant = std::make_unique<CarDamageData>(CarDamageData{copy_to_array<CarDamageData::SIZE>(bytes)});
            break;
        case CarSetupData::SIZE:
            packetVariant = std::make_unique<CarSetupData>(copy_to_array<CarSetupData::SIZE>(bytes));
            break;
        case CarStatusData::SIZE:
            packetVariant = std::make_unique<CarStatusData>(copy_to_array<CarStatusData::SIZE>(bytes));
            break;
        case CarTelemetryData::SIZE:
            packetVariant = std::make_unique<CarTelemetryData>(copy_to_array<CarTelemetryData::SIZE>(bytes));
            break;
        case EventData::SIZE:
            packetVariant = std::make_unique<EventData>(copy_to_array<EventData::SIZE>(bytes));
            break;
        case FinalClassificationData::SIZE:
            packetVariant = std::make_unique<FinalClassificationData>(
                    copy_to_array<FinalClassificationData::SIZE>(bytes));
            break;
        case LapData::SIZE:
            packetVariant = std::make_unique<LapData>(copy_to_array<LapData::SIZE>(bytes));
            break;
        case LobbyInfoData::SIZE:
            packetVariant = std::make_unique<LobbyInfoData>(copy_to_array<LobbyInfoData::SIZE>(bytes));
            break;
        case MotionData::SIZE:
            packetVariant = std::make_unique<MotionData>(copy_to_array<MotionData::SIZE>(bytes));
            break;
        case ParticipantsData::SIZE:
            packetVariant = std::make_unique<ParticipantsData>(copy_to_array<ParticipantsData::SIZE>(bytes));
            break;
        case SessionData::SIZE:
            packetVariant = std::make_unique<SessionData>(copy_to_array<SessionData::SIZE>(bytes));
            break;
        case SessionHistoryData::SIZE:
            packetVariant = std::make_unique<SessionHistoryData>(copy_to_array<SessionHistoryData::SIZE>(bytes));
            break;
        default:
            throw std::invalid_argument(
                    "Unknown byte size: The given byte array doesn't match any known type in this factory");
    }

    return packetVariant;
}

void processTheDatagram(const QNetworkDatagram& datagram, std::ofstream& file, QLineSeries* series) {
    auto packet = createPacket(datagram.data());
    std::visit([&file](const auto& x) {
        std::cout << (*x) << std::endl;
        file << (*x) << std::endl;
    }, packet);
}

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QUdpSocket udpSocket;

    auto* chart = new QChart();
    auto* series = new QLineSeries();

    udpSocket.bind(20777, QUdpSocket::ShareAddress);
    QObject::connect(&udpSocket, &QUdpSocket::readyRead, [&udpSocket, &series, &chart]() {
        std::ofstream file{"output.txt", std::ios::trunc};

        while (udpSocket.hasPendingDatagrams()) {
            QNetworkDatagram datagram = udpSocket.receiveDatagram();
            processTheDatagram(datagram, file, series);
        }
    });

    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");

    series->attachAxis(chart->axisX());
    series->attachAxis(chart->axisY());

    auto* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();

    return QApplication::exec();
}
