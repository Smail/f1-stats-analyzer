#pragma once

#include "PacketHeader.h"
#include "../../util.h"

#pragma pack(1)

namespace F122::Network {
    /// This packet details the final classification at the end of the race, and the data will match with the post
    /// race results screen. This is especially useful for multiplayer games where it is not always possible to send
    /// lap times on the final frame because of network delay.<br>
    /// <br>
    /// Frequency: Once at the end of a race<br>
    /// Size: 1015 bytes<br>
    /// Version: 1<br>
    struct PacketFinalClassificationData {
        struct Data {
            /// Finishing position
            uint8 m_position;
            /// Number of laps completed
            uint8 m_numLaps;
            /// Grid position of the car
            uint8 m_gridPosition;
            /// Number of points scored
            uint8 m_points;
            /// Number of pit stops made
            uint8 m_numPitStops;
            /// Result status - 0 = invalid, 1 = inactive, 2 = active,
            /// 3 = finished, 4 = didnotfinish, 5 = disqualified,
            /// 6 = not classified, 7 = retired
            uint8 m_resultStatus;
            /// Best lap time of the session in milliseconds
            uint32 m_bestLapTimeInMS;
            /// Total race time in seconds without penalties
            double m_totalRaceTime;
            /// Total penalties accumulated in seconds
            uint8 m_penaltiesTime;
            /// Number of penalties applied to this driver
            uint8 m_numPenalties;
            /// Number of tyres stints up to maximum
            uint8 m_numTyreStints;
            /// Actual tyres used by this driver
            std::array<uint8, 8> m_tyreStintsActual;
            /// Visual tyres used by this driver
            std::array<uint8, 8> m_tyreStintsVisual;
            /// The lap number stints end on
            std::array<uint8, 8> m_tyreStintsEndLaps;

            [[nodiscard]] std::string to_string() const {
                std::stringstream ss;

                ss << "m_position: " << std::to_string(m_position) << "\n"
                   << "m_numLaps: " << std::to_string(m_numLaps) << "\n"
                   << "m_gridPosition: " << std::to_string(m_gridPosition) << "\n"
                   << "m_points: " << std::to_string(m_points) << "\n"
                   << "m_numPitStops: " << std::to_string(m_numPitStops) << "\n"
                   << "m_resultStatus: " << std::to_string(m_resultStatus) << "\n"
                   << "m_bestLapTimeInMS: " << std::to_string(m_bestLapTimeInMS) << "\n"
                   << "m_totalRaceTime: " << std::to_string(m_totalRaceTime) << "\n"
                   << "m_penaltiesTime: " << std::to_string(m_penaltiesTime) << "\n"
                   << "m_numPenalties: " << std::to_string(m_numPenalties) << "\n"
                   << "m_numTyreStints: " << std::to_string(m_numTyreStints) << "\n"
                   << "m_tyreStintsActual: " << util::to_string(m_tyreStintsActual) << "\n"
                   << "m_tyreStintsVisual: " << util::to_string(m_tyreStintsVisual) << "\n"
                   << "m_tyreStintsEndLaps: " << util::to_string(m_tyreStintsEndLaps);

                return ss.str();
            }

            friend std::ostream &operator<<(std::ostream &os, const Data &data) {
                os << data.to_string();
                return os;
            }
        };

    public:
        PacketHeader m_header;
        /// Number of cars in the final classification
        uint8 m_numCars;
        std::array<Data, 22> m_classificationData;

        friend std::ostream &operator<<(std::ostream &os, const PacketFinalClassificationData &data) {
            os << "m_header: " << "\n" << data.m_header << "\n"
               << "m_numCars: " << data.m_numCars << "\n"
               << "m_classificationData: " << "\n\n";

            for (size_t i = 0; i < data.m_classificationData.size(); ++i) {
                os << "Car " << std::to_string(i) << ": " << "\n";
                os << data.m_classificationData[i] << (i < data.m_classificationData.size() - 1 ? "\n\n" : "");
            }

            return os;
        }
    };
}

#pragma pack()
