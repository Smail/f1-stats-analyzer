#include <QUdpSocket>
#include <QObject>
#include <QNetworkDatagram>
#include <iostream>
#include <QApplication>
#include <fstream>
#include <signal.h>
#include <QLineSeries>
#include <QChartView>
#include <QChart>
#include <QMainWindow>

#include "f1udpinterface/public.h"

void processTheDatagram(const QNetworkDatagram &datagram, std::ofstream &file) {
    using namespace F122::Network;
    QByteArray bytes = datagram.data();

    std::variant<PacketCarDamageData *, PacketCarSetupData *, PacketCarStatusData *, PacketCarTelemetryData *,
            PacketEventData *, PacketFinalClassificationData *, PacketLapData *, PacketLobbyInfoData *,
            PacketMotionData *, PacketParticipantsData *, PacketSessionData *, PacketSessionHistoryData *> packetVariant;


    if (bytes.size() == sizeof(PacketCarDamageData)) {
        packetVariant = reinterpret_cast<PacketCarDamageData *>(bytes.data());
    } else if (bytes.size() == sizeof(PacketCarSetupData)) {
        packetVariant = reinterpret_cast<PacketCarSetupData *>(bytes.data());
    } else if (bytes.size() == sizeof(PacketCarStatusData)) {
        packetVariant = reinterpret_cast<PacketCarStatusData *>(bytes.data());
    } else if (bytes.size() == sizeof(PacketCarTelemetryData)) {
        packetVariant = reinterpret_cast<PacketCarTelemetryData *>(bytes.data());
    } else if (bytes.size() == sizeof(PacketEventData)) {
        packetVariant = reinterpret_cast<PacketEventData *>(bytes.data());
    } else if (bytes.size() == sizeof(PacketFinalClassificationData)) {
        packetVariant = reinterpret_cast<PacketFinalClassificationData *>(bytes.data());
    } else if (bytes.size() == sizeof(PacketLapData)) {
        packetVariant = reinterpret_cast<PacketLapData *>(bytes.data());
    } else if (bytes.size() == sizeof(PacketLobbyInfoData)) {
        packetVariant = reinterpret_cast<PacketLobbyInfoData *>(bytes.data());
    } else if (bytes.size() == sizeof(PacketMotionData)) {
        packetVariant = reinterpret_cast<PacketMotionData *>(bytes.data());
    } else if (bytes.size() == sizeof(PacketParticipantsData)) {
        packetVariant = reinterpret_cast<PacketParticipantsData *>(bytes.data());
    } else if (bytes.size() == sizeof(PacketSessionData)) {
        packetVariant = reinterpret_cast<PacketSessionData *>(bytes.data());
    } else if (bytes.size() == sizeof(PacketSessionHistoryData)) {
        packetVariant = reinterpret_cast<PacketSessionHistoryData *>(bytes.data());
    }

    std::visit([](const auto &x) { std::cout << (*x) << std::endl; }, packetVariant);
//    std::visit([&file](const auto &x) { file << (*x) << std::endl; }, packetVariant);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QUdpSocket udpSocket;

    udpSocket.bind(20777, QUdpSocket::ShareAddress);
    QObject::connect(&udpSocket, &QUdpSocket::readyRead, [&udpSocket]() {
        std::ofstream file{"output.txt", std::ios::trunc};

        while (udpSocket.hasPendingDatagrams()) {
            QNetworkDatagram datagram = udpSocket.receiveDatagram();
            processTheDatagram(datagram, file);
        }
    });

    auto *series = new QLineSeries();
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

    auto *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");

    auto *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();

    return QApplication::exec();
}
