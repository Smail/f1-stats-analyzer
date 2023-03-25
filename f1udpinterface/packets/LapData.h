#pragma once

#include <cstdint>
#include <ostream>
#include "PacketHeader.h"

namespace F122::Network::Packets {
    /// The lap data packet gives details of all the cars in the session.<br>
    /// <br>
    /// Frequency: Rate as specified in menus<br>
    /// Size: 972 bytes<br>
    /// Version: 1<br>
    struct LapData {
        struct Data {
            Data() = default;

            explicit Data(const std::array<std::uint8_t, 43>& bytes);

            /// Last lap time in milliseconds
            std::uint32_t m_lastLapTimeInMS;
            /// Current time around the lap in milliseconds
            std::uint32_t m_currentLapTimeInMS;
            /// Sector 1 time in milliseconds
            std::uint16_t m_sector1TimeInMS;
            /// Sector 2 time in milliseconds
            std::uint16_t m_sector2TimeInMS;
            /// Distance vehicle is around current lap in metres – could
            /// be negative if line hasn't been crossed yet
            float m_lapDistance;
            /// Total distance travelled in session in metres – could be negative if line hasn't been crossed yet
            float m_totalDistance;
            /// Delta in seconds for safety car
            float m_safetyCarDelta;
            /// Car race position
            std::uint8_t m_carPosition;
            /// Current lap number
            std::uint8_t m_currentLapNum;
            /// 0 = none, 1 = pitting, 2 = in pit area
            std::uint8_t m_pitStatus;
            /// Number of pit stops taken in this race
            std::uint8_t m_numPitStops;
            /// 0 = sector1, 1 = sector2, 2 = sector3
            std::uint8_t m_sector;
            /// Current lap invalid - 0 = valid, 1 = invalid
            std::uint8_t m_currentLapInvalid;
            /// Accumulated time penalties in seconds to be added
            std::uint8_t m_penalties;
            /// Accumulated number of warnings issued
            std::uint8_t m_warnings;
            /// Num drive through pens left to serve
            std::uint8_t m_numUnservedDriveThroughPens;
            /// Num stop go pens left to serve
            std::uint8_t m_numUnservedStopGoPens;
            /// Grid position the vehicle started the race in
            std::uint8_t m_gridPosition;
            /// Status of driver - 0 = in garage, 1 = flying lap, 2 = in lap, 3 = out lap, 4 = on track
            std::uint8_t m_driverStatus;
            /// Result status - 0 = invalid, 1 = inactive, 2 = active, 3 = finished, 4 = didnotfinish, 5 = disqualified,
            /// 6 = not classified, 7 = retired
            std::uint8_t m_resultStatus;
            /// Pit lane timing, 0 = inactive, 1 = active
            std::uint8_t m_pitLaneTimerActive;
            /// If active, the current time spent in the pit lane in ms
            std::uint16_t m_pitLaneTimeInLaneInMS;
            /// Time of the actual pit stop in ms
            std::uint16_t m_pitStopTimerInMS;
            /// Whether the car should serve a penalty at this stop
            std::uint8_t m_pitStopShouldServePen;

            friend std::ostream& operator<<(std::ostream& os, const Data& data);
        };

    public:
        explicit LapData(const std::array<std::uint8_t, 972>& bytes);

        PacketHeader m_header;
        /// Lap data for all cars on track
        std::array<Data, 22> m_lapData;
        /// Index of Personal Best car in time trial (255 if invalid)
        std::uint8_t m_timeTrialPBCarIdx;
        /// Index of Rival car in time trial (255 if invalid)
        std::uint8_t m_timeTrialRivalCarIdx;

        friend std::ostream& operator<<(std::ostream& os, const LapData& data);
    };

    std::ostream& operator<<(std::ostream& os, const LapData& data);

    std::ostream& operator<<(std::ostream& os, const LapData::Data& data);
}
