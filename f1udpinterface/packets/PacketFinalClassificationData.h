#pragma once

#include "PacketHeader.h"

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
            Data() = default;

            explicit Data(const std::array<std::uint8_t, 45>& bytes);

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

            [[nodiscard]] std::string to_string() const;

            friend std::ostream& operator<<(std::ostream& os, const Data& data);
        };

    public:
        explicit PacketFinalClassificationData(const std::array<std::uint8_t, 1015>& bytes);

        PacketHeader m_header;
        /// Number of cars in the final classification
        uint8 m_numCars;
        std::array<Data, 22> m_classificationData;

        friend std::ostream& operator<<(std::ostream& os, const PacketFinalClassificationData& data);
    };

    std::ostream& operator<<(std::ostream& os, const PacketFinalClassificationData& data);

    std::ostream& operator<<(std::ostream& os, const PacketFinalClassificationData::Data& data);
}

#pragma pack()
