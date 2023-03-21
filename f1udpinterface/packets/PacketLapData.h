#include <ostream>
#include "PacketHeader.h"

#pragma pack(1)

namespace F122::Network {
    /// The lap data packet gives details of all the cars in the session.<br>
    /// <br>
    /// Frequency: Rate as specified in menus<br>
    /// Size: 972 bytes<br>
    /// Version: 1<br>
    struct PacketLapData {
        struct Data {
            /// Last lap time in milliseconds
            uint32 m_lastLapTimeInMS;
            /// Current time around the lap in milliseconds
            uint32 m_currentLapTimeInMS;
            /// Sector 1 time in milliseconds
            uint16 m_sector1TimeInMS;
            /// Sector 2 time in milliseconds
            uint16 m_sector2TimeInMS;
            /// Distance vehicle is around current lap in metres – could
            /// be negative if line hasn't been crossed yet
            float m_lapDistance;
            /// Total distance travelled in session in metres – could be negative if line hasn't been crossed yet
            float m_totalDistance;
            /// Delta in seconds for safety car
            float m_safetyCarDelta;
            /// Car race position
            uint8 m_carPosition;
            /// Current lap number
            uint8 m_currentLapNum;
            /// 0 = none, 1 = pitting, 2 = in pit area
            uint8 m_pitStatus;
            /// Number of pit stops taken in this race
            uint8 m_numPitStops;
            /// 0 = sector1, 1 = sector2, 2 = sector3
            uint8 m_sector;
            /// Current lap invalid - 0 = valid, 1 = invalid
            uint8 m_currentLapInvalid;
            /// Accumulated time penalties in seconds to be added
            uint8 m_penalties;
            /// Accumulated number of warnings issued
            uint8 m_warnings;
            /// Num drive through pens left to serve
            uint8 m_numUnservedDriveThroughPens;
            /// Num stop go pens left to serve
            uint8 m_numUnservedStopGoPens;
            /// Grid position the vehicle started the race in
            uint8 m_gridPosition;
            /// Status of driver - 0 = in garage, 1 = flying lap, 2 = in lap, 3 = out lap, 4 = on track
            uint8 m_driverStatus;
            /// Result status - 0 = invalid, 1 = inactive, 2 = active, 3 = finished, 4 = didnotfinish, 5 = disqualified,
            /// 6 = not classified, 7 = retired
            uint8 m_resultStatus;
            /// Pit lane timing, 0 = inactive, 1 = active
            uint8 m_pitLaneTimerActive;
            /// If active, the current time spent in the pit lane in ms
            uint16 m_pitLaneTimeInLaneInMS;
            /// Time of the actual pit stop in ms
            uint16 m_pitStopTimerInMS;
            /// Whether the car should serve a penalty at this stop
            uint8 m_pitStopShouldServePen;

            friend std::ostream &operator<<(std::ostream &os, const Data &data) {
                os << "m_lastLapTimeInMS: " << std::to_string(data.m_lastLapTimeInMS) << "\n"
                   << "m_currentLapTimeInMS: " << std::to_string(data.m_currentLapTimeInMS) << "\n"
                   << "m_sector1TimeInMS: " << std::to_string(data.m_sector1TimeInMS) << "\n"
                   << "m_sector2TimeInMS: " << std::to_string(data.m_sector2TimeInMS) << "\n"
                   << "m_lapDistance: " << std::to_string(data.m_lapDistance) << "\n"
                   << "m_totalDistance: " << std::to_string(data.m_totalDistance) << "\n"
                   << "m_safetyCarDelta: " << std::to_string(data.m_safetyCarDelta) << "\n"
                   << "m_carPosition: " << std::to_string(data.m_carPosition) << "\n"
                   << "m_currentLapNum: " << std::to_string(data.m_currentLapNum) << "\n"
                   << "m_pitStatus: " << std::to_string(data.m_pitStatus) << "\n"
                   << "m_numPitStops: " << std::to_string(data.m_numPitStops) << "\n"
                   << "m_sector: " << std::to_string(data.m_sector) << "\n"
                   << "m_currentLapInvalid: " << std::to_string(data.m_currentLapInvalid) << "\n"
                   << "m_penalties: " << std::to_string(data.m_penalties) << "\n"
                   << "m_warnings: " << std::to_string(data.m_warnings) << "\n"
                   << "m_numUnservedDriveThroughPens: " << std::to_string(data.m_numUnservedDriveThroughPens) << "\n"
                   << "m_numUnservedStopGoPens: " << std::to_string(data.m_numUnservedStopGoPens) << "\n"
                   << "m_gridPosition: " << std::to_string(data.m_gridPosition) << "\n"
                   << "m_driverStatus: " << std::to_string(data.m_driverStatus) << "\n"
                   << "m_resultStatus: " << std::to_string(data.m_resultStatus) << "\n"
                   << "m_pitLaneTimerActive: " << std::to_string(data.m_pitLaneTimerActive) << "\n"
                   << "m_pitLaneTimeInLaneInMS: " << std::to_string(data.m_pitLaneTimeInLaneInMS) << "\n"
                   << "m_pitStopTimerInMS: " << std::to_string(data.m_pitStopTimerInMS) << "\n"
                   << "m_pitStopShouldServePen: " << std::to_string(data.m_pitStopShouldServePen) << "\n";

                return os;
            }
        };

    public:
        PacketHeader m_header;
        /// Lap data for all cars on track
        std::array<Data, 22> m_lapData;
        /// Index of Personal Best car in time trial (255 if invalid)
        uint8 m_timeTrialPBCarIdx;
        /// Index of Rival car in time trial (255 if invalid)
        uint8 m_timeTrialRivalCarIdx;

        friend std::ostream &operator<<(std::ostream &os, const PacketLapData &data) {
            os << "m_header: " << "\n" << data.m_header << "\n"
               << "m_timeTrialPBCarIdx: " << std::to_string(data.m_timeTrialPBCarIdx) << "\n"
               << "m_timeTrialRivalCarIdx: " << std::to_string(data.m_timeTrialRivalCarIdx) << "\n"
               << "m_lapData: " << "\n\n";

            for (size_t i = 0; i < data.m_lapData.size(); ++i) {
                os << "Lap " << std::to_string(i) << ": " << "\n";
                os << data.m_lapData[i] << (i < data.m_lapData.size() - 1 ? "\n" : "");
            }

            return os;
        }
    };
}

#pragma pack()
