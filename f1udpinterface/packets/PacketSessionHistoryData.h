#pragma once

#include "PacketHeader.h"
#include <array>
#include <string>

#pragma pack(1)

namespace F122::Network {
    /// This packet contains lap times and tyre usage for the session.<br><br><b>This packet works slightly differently
    /// to other packets. To reduce CPU and bandwidth, each packet relates to a specific vehicle and is
    /// sent every 1/20 s, and the vehicle being sent is cycled through. Therefore in a 20 car race you
    /// should receive an update for each vehicle at least once per second.</b><br><br>
    /// Note that at the end of the race, after the final classification packet has been sent, a final bulk update
    /// of all the session histories for the vehicles in that session will be sent.<br>
    /// <br>
    /// Frequency: 20 per second but cycling through cars<br>
    /// Size: 1155 bytes<br>
    /// Version: 1<br>
    struct PacketSessionHistoryData {
        struct LapHistoryData {
            LapHistoryData() = default;

            explicit LapHistoryData(const std::array<std::uint8_t, 11>& bytes);

            /// Lap time in milliseconds
            uint32 m_lapTimeInMS;
            /// Sector 1 time in milliseconds
            uint16 m_sector1TimeInMS;
            /// Sector 2 time in milliseconds
            uint16 m_sector2TimeInMS;
            /// Sector 3 time in milliseconds
            uint16 m_sector3TimeInMS;
            /// 0x01 bit set-lap valid, 0x02 bit set-sector 1 valid,
            /// 0x04 bit set-sector 2 valid, 0x08 bit set-sector 3 valid
            uint8 m_lapValidBitFlags;

            friend std::ostream& operator<<(std::ostream& os, const LapHistoryData& data);
        };

        struct TyreStintHistoryData {
            TyreStintHistoryData() = default;

            explicit TyreStintHistoryData(const std::array<std::uint8_t, 3>& bytes);

            /// Lap the tyre usage ends on (255 of current tyre)
            uint8 m_endLap;
            /// Actual tyres used by this driver
            uint8 m_tyreActualCompound;
            /// Visual tyres used by this driver
            uint8 m_tyreVisualCompound;

            friend std::ostream& operator<<(std::ostream& os, const TyreStintHistoryData& data);
        };

    public:
        explicit PacketSessionHistoryData(const std::array<std::uint8_t, 1155>& bytes);

        PacketHeader m_header;
        /// Index of the car this lap data relates to
        uint8 m_carIdx;
        /// Num laps in the data (including current partial lap)
        uint8 m_numLaps;
        /// Number of tyre stints in the data
        uint8 m_numTyreStints;
        /// Lap the best lap time was achieved on
        uint8 m_bestLapTimeLapNum;
        /// Lap the best Sector 1 time was achieved on
        uint8 m_bestSector1LapNum;
        /// Lap the best Sector 2 time was achieved on
        uint8 m_bestSector2LapNum;
        /// Lap the best Sector 3 time was achieved on
        uint8 m_bestSector3LapNum;
        /// 100 laps of data max
        std::array<LapHistoryData, 100> m_lapHistoryData;
        std::array<TyreStintHistoryData, 8> m_tyreStintsHistoryData;

        friend std::ostream& operator<<(std::ostream& os, const PacketSessionHistoryData& data);
    };

    std::ostream& operator<<(std::ostream& os, const PacketSessionHistoryData& data);

    std::ostream& operator<<(std::ostream& os, const PacketSessionHistoryData::TyreStintHistoryData& data);

    std::ostream& operator<<(std::ostream& os, const PacketSessionHistoryData::LapHistoryData& data);
}

#pragma pack()
