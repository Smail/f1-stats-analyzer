#include <iostream>
#include <unordered_set>
#include <utility>
#include <QThread>
#include "Worker.h"
#include "../f1udpinterface/packets/PacketFactory.h"
#include "TeamColorMapping.h"

Worker::Worker(QChart* speedChart, std::array<QLineSeries*, 22>& speedSeries,
               std::array<CarActivationButton*, 22>& carActivationButtons,
               std::shared_ptr<ParticipantsData> participantsData)
        : speedChart{speedChart},
          speedSeries{speedSeries},
          participantsData{std::move(participantsData)},
          carActivationButtons{carActivationButtons} {
}

Worker::~Worker() = default;

void Worker::processDatagram(const QNetworkDatagram& datagram) {
    auto bytes = datagram.data();
    processDatagram(bytes, bytes.size());
}

void Worker::processDatagram(const QByteArray& bytes, size_t size) {
    auto packet = createPacket(bytes, size);

    if (bytes.length() == CarTelemetryData::SIZE) {
        auto telemetryData = std::get<std::unique_ptr<CarTelemetryData>>(std::move(packet));

        // Initialize lower bound of chart x-axis
        if (!isMinXInitialized) {
            auto points = speedSeries[0]->points();
            if (!points.empty()) {
                minX = (*std::min_element(points.begin(), points.end(),
                                          [](const QPointF& p1, const QPointF& p2) { return p1.x() < p2.x(); })).x();
                isMinXInitialized = true;
            }
        }

        // Increase length of x-axis. The x-axis is time.
        const float time = telemetryData->m_header.m_sessionTime;
        speedChart->axes(Qt::Horizontal)[0]->setRange(std::min(static_cast<double>(time), minX), time + 5);

        for (int i = 0; i < speedSeries.size(); ++i) {
            auto& carTelemetryData = telemetryData->m_carTelemetryData[i];
            auto* carSpeedSeries = speedSeries[i];

            (*carSpeedSeries) << QPointF(time, carTelemetryData.m_speed);
        }
    } else if (bytes.length() == ParticipantsData::SIZE) {
        participantsData = std::get<std::unique_ptr<ParticipantsData>>(std::move(packet));
        std::unordered_set<F122::TeamId> encounteredTeams;

        for (int i = 0; i < 22; ++i) {
            auto participant = participantsData->m_participants[i];

            // 255 means no team is selected. This only happens if the received is an empty dummy object, i.e.,
            // a car seat that doesn't participate in the race.
            if (participant.m_teamId == 255) continue;

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

void Worker::process() {
    while (!shouldStop) {
        while (!queue.empty()) {
            processDatagram(queue.front());
            queue.pop_front();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void Worker::insert(QNetworkDatagram datagram) {
    queue.push_back(std::move(datagram));
}

void Worker::stop() {
    shouldStop = true;
}
