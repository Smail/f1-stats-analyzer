#pragma once

#include <cstdint>
#include <ostream>
#include <string>
#include <array>

namespace F122::Network {
    /// Size: 24 bytes
    struct PacketHeader {
        enum class PacketId : std::uint8_t {
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

        static PacketId from(std::uint8_t value);

        explicit PacketHeader(const std::array<std::uint8_t, 24>& bytes);

        static std::string to_string(PacketId id);

    public:
        /// 2022
        std::uint16_t m_packetFormat;
        /// Game major version - "X.00"
        std::uint8_t m_gameMajorVersion;
        /// Game minor version - "1.XX"
        std::uint8_t m_gameMinorVersion;
        /// Version of this packet type, all start from 1
        std::uint8_t m_packetVersion;
        /// Identifier for the packet type, see below
        std::uint8_t m_packetId;
        /// Unique identifier for the session
        std::uint64_t m_sessionUID;
        /// Session timestamp
        float m_sessionTime;
        /// Identifier for the frame the data was retrieved on
        std::uint32_t m_frameIdentifier;
        /// Index of player's car in the array
        std::uint8_t m_playerCarIndex;
        /// Index of secondary player's car in the array (splitscreen)
        /// 255 if no second player
        std::uint8_t m_secondaryPlayerCarIndex;

        friend std::ostream& operator<<(std::ostream& os, const PacketHeader& header);
    };

    std::ostream& operator<<(std::ostream& os, const PacketHeader& header);
}
