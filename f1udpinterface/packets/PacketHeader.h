#pragma once

#include <cstdint>
#include <ostream>
#include <string>
#include <array>

namespace F122::Network {
    using int8 = std::int8_t;
    using uint8 = std::uint8_t;
    using int16 = std::int16_t;
    using uint16 = std::uint16_t;
    using uint32 = std::uint32_t;
    using uint64 = std::uint64_t;

    /// Size: 24 bytes
    struct PacketHeader {
        enum class PacketId : uint8 {
            /// Contains all motion data for player's car - only sent while player is in control
            MOTION = 0,
            /// Data about the session - track, time left
            SESSION = 1,
            /// Data about all the lap times of cars in the session
            LAP_DATA = 2,
            /// Various notable events that happen during a session
            EVENT = 3,
            /// List of participants in the session, mostly relevant for multiplayer
            PARTICIPANTS = 4,
            /// Packet detailing car setups for cars in the race
            CAR_SETUPS = 5,
            /// Telemetry data for all cars
            CAR_TELEMETRY = 6,
            /// Status data for all cars
            CAR_STATUS = 7,
            /// Final classification confirmation at the end of a race
            FINAL_CLASSIFICATION = 8,
            /// Information about players in a multiplayer lobby
            LOBBY_INFO = 9,
            /// Damage status for all cars
            CAR_DAMAGE = 10,
            /// Lap and tyre data for session
            SESSION_HISTORY = 11,
        };

        static PacketId from(uint8 value);

        explicit PacketHeader(const std::array<std::uint8_t, 24>& bytes);

        static std::string to_string(PacketId id);

    public:
        /// 2022
        uint16 m_packetFormat;
        /// Game major version - "X.00"
        uint8 m_gameMajorVersion;
        /// Game minor version - "1.XX"
        uint8 m_gameMinorVersion;
        /// Version of this packet type, all start from 1
        uint8 m_packetVersion;
        /// Identifier for the packet type, see below
        uint8 m_packetId;
        /// Unique identifier for the session
        uint64 m_sessionUID;
        /// Session timestamp
        float m_sessionTime;
        /// Identifier for the frame the data was retrieved on
        uint32 m_frameIdentifier;
        /// Index of player's car in the array
        uint8 m_playerCarIndex;
        /// Index of secondary player's car in the array (splitscreen)
        /// 255 if no second player
        uint8 m_secondaryPlayerCarIndex;

        friend std::ostream& operator<<(std::ostream& os, const PacketHeader& header);
    };

    std::ostream& operator<<(std::ostream& os, const PacketHeader& header);
}
