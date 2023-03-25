#pragma once

#include <cstdint>
#include "PacketHeader.h"

namespace F122::Network::Packets {
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
            std::uint8_t m_position;
            /// Number of laps completed
            std::uint8_t m_numLaps;
            /// Grid position of the car
            std::uint8_t m_gridPosition;
            /// Number of points scored
            std::uint8_t m_points;
            /// Number of pit stops made
            std::uint8_t m_numPitStops;
            /// Result status - 0 = invalid, 1 = inactive, 2 = active,
            /// 3 = finished, 4 = didnotfinish, 5 = disqualified,
            /// 6 = not classified, 7 = retired
            std::uint8_t m_resultStatus;
            /// Best lap time of the session in milliseconds
            std::uint32_t m_bestLapTimeInMS;
            /// Total race time in seconds without penalties
            double m_totalRaceTime;
            /// Total penalties accumulated in seconds
            std::uint8_t m_penaltiesTime;
            /// Number of penalties applied to this driver
            std::uint8_t m_numPenalties;
            /// Number of tyres stints up to maximum
            std::uint8_t m_numTyreStints;
            /// Actual tyres used by this driver
            std::array<std::uint8_t, 8> m_tyreStintsActual;
            /// Visual tyres used by this driver
            std::array<std::uint8_t, 8> m_tyreStintsVisual;
            /// The lap number stints end on
            std::array<std::uint8_t, 8> m_tyreStintsEndLaps;

            [[nodiscard]] std::string to_string() const;

            friend std::ostream& operator<<(std::ostream& os, const Data& data);
        };

    public:
        explicit PacketFinalClassificationData(const std::array<std::uint8_t, 1015>& bytes);

        friend std::ostream& operator<<(std::ostream& os, const PacketFinalClassificationData& data);

        PacketHeader m_header;
        /// Number of cars in the final classification
        std::uint8_t m_numCars;
        std::array<Data, 22> m_classificationData;
    };

    std::ostream& operator<<(std::ostream& os, const PacketFinalClassificationData& data);

    std::ostream& operator<<(std::ostream& os, const PacketFinalClassificationData::Data& data);
}
