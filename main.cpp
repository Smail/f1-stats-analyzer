#include <QUdpSocket>
#include <QObject>
#include <QNetworkDatagram>
#include <iostream>
#include <QApplication>
#include <fstream>
#include <QLineSeries>
#include <QChartView>
#include <QChart>
#include <QMainWindow>
#include <thread>

#include "f1udpinterface/public.h"

static int abc = 12;

void processTheDatagram(const QNetworkDatagram& datagram, std::ofstream& file, QLineSeries* series) {
    using namespace F122::Network;
    QByteArray bytes = datagram.data();

    std::array<std::uint8_t, 24> packetHeaderBytes{};

    std::cout << (*reinterpret_cast<PacketHeader*>(bytes.data())) << std::endl;

    for (int i = 0; i < 24; ++i) {
        packetHeaderBytes[i] = bytes[i];
    }


    series->append(abc++, 4);
//    chart->update();

    std::cout << (*reinterpret_cast<PacketHeader*>(packetHeaderBytes.data())) << std::endl;
    std::cout << "c: " << (PacketHeader{packetHeaderBytes}) << std::endl;

    series->append(7, 4);

//    IPacket* packet = PacketFactory::create_from_bytes(bytes);

//    std::cout << (*packet) << std::endl;

//    std::visit([](const auto &x) { std::cout << (*x) << std::endl; }, packetVariant);
//    std::visit([&file](const auto &x) { file << (*x) << std::endl; }, packetVariant);
}

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QUdpSocket udpSocket;

    auto* chart = new QChart();
    auto* series = new QLineSeries();

    udpSocket.bind(20777, QUdpSocket::ShareAddress);
    QObject::connect(&udpSocket, &QUdpSocket::readyRead, [&udpSocket, &series, &chart] () {
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
