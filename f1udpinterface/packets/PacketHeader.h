#pragma once

#include <cstdint>
#include <ostream>
#include <string>

#pragma pack(1)

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

        static PacketId from(uint8 value) {
            if (value < static_cast<uint8>(PacketId::MOTION) || value > static_cast<uint8>(PacketId::SESSION_HISTORY)) {
                throw std::out_of_range("Value must be between [" +
                                        std::to_string(static_cast<uint8>(PacketId::MOTION)) + ", " +
                                        std::to_string(static_cast<uint8>(PacketId::SESSION_HISTORY)) + "]"
                );
            }

            return static_cast<PacketId>(value);
        }

        static std::string to_string(PacketId id) {
            switch (id) {
                case PacketId::MOTION:
                    return "Motion";
                case PacketId::SESSION:
                    return "Session";
                case PacketId::LAP_DATA:
                    return "Lap Data";
                case PacketId::EVENT:
                    return "Event";
                case PacketId::PARTICIPANTS:
                    return "Participant";
                case PacketId::CAR_SETUPS:
                    return "Car Setups";
                case PacketId::CAR_TELEMETRY:
                    return "Car Telemetry";
                case PacketId::CAR_STATUS:
                    return "Car Status";
                case PacketId::FINAL_CLASSIFICATION:
                    return "Final Classification";
                case PacketId::LOBBY_INFO:
                    return "Lobby Info";
                case PacketId::CAR_DAMAGE:
                    return "Car Damage";
                case PacketId::SESSION_HISTORY:
                    return "Session History";
                default:
                    throw std::invalid_argument("Unknown argument case");
            }
        }

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

        friend std::ostream &operator<<(std::ostream &os, const PacketHeader &header) {
            os << "m_packetFormat: " << std::to_string(header.m_packetFormat) << "\n"
               << "m_gameMajorVersion: " << std::to_string(header.m_gameMajorVersion) << "\n"
               << "m_gameMinorVersion: " << std::to_string(header.m_gameMinorVersion) << "\n"
               << "m_packetVersion: " << std::to_string(header.m_packetVersion) << "\n"
               << "m_packetId: " << to_string(from(header.m_packetId)) << "\n"
               << "m_sessionUID: " << std::to_string(header.m_sessionUID) << "\n"
               << "m_sessionTime: " << std::to_string(header.m_sessionTime) << "\n"
               << "m_frameIdentifier: " << std::to_string(header.m_frameIdentifier) << "\n"
               << "m_playerCarIndex: " << std::to_string(header.m_playerCarIndex) << "\n"
               << "m_secondaryPlayerCarIndex: " << std::to_string(header.m_secondaryPlayerCarIndex) << "\n";

            return os;
        }
    };
}

#pragma pack()
