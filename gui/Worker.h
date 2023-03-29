#pragma once

#include <QObject>
#include <QUdpSocket>
#include <QChart>
#include <QNetworkDatagram>
#include <QLineSeries>
#include <deque>
#include "../f1udpinterface/public.h"
#include "CarActivationButton.h"

using namespace F122::Network::Packets;

class Worker : public QObject {
Q_OBJECT

public:
    Worker(QChart* speedChart, std::array<QLineSeries*, 22>& speedSeries,
           std::array<CarActivationButton*, 22>& carActivationButtons,
           std::shared_ptr<ParticipantsData> participantsData);

    ~Worker() override;

    void insert(QNetworkDatagram datagram);

public slots:

    void process();

    void processDatagram(const QByteArray& bytes, size_t size);

    void processDatagram(const QNetworkDatagram& datagram);

    void stop();

signals:

    void update();

    void finished();

    void error(QString err);

private:
    QChart* speedChart;
    double minX{0.0};
    bool isMinXInitialized{false};
    bool shouldStop{false};

    std::shared_ptr<ParticipantsData> participantsData;
    // The number of max cars is 22
    std::array<QLineSeries*, 22>& speedSeries;
    std::array<CarActivationButton*, 22>& carActivationButtons;
    std::deque<QNetworkDatagram> queue;
};
