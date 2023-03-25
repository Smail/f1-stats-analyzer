#include "PacketHeader.h"
#include "../../util.h"

namespace F122::Network::Packets {
    PacketHeader::PacketHeader(const std::array<std::uint8_t, SIZE>& bytes) :
            m_packetFormat{util::convert<std::uint16_t>({bytes[0], bytes[1]})},
            m_gameMajorVersion{bytes[2]},
            m_gameMinorVersion{bytes[3]},
            m_packetVersion{bytes[4]},
            m_packetId{bytes[5]},
            m_sessionUID{util::convert<std::uint64_t>(
                    {bytes[6], bytes[7], bytes[8], bytes[9], bytes[10], bytes[11], bytes[12], bytes[13]}
            )},
            m_sessionTime{util::convert<float>({bytes[14], bytes[15], bytes[16], bytes[17]})},
            m_frameIdentifier{util::convert<std::uint32_t>({bytes[18], bytes[19], bytes[20], bytes[21]})},
            m_playerCarIndex{bytes[22]},
            m_secondaryPlayerCarIndex{bytes[23]} {}

    PacketHeader::PacketId PacketHeader::from(std::uint8_t value) {
        if (value < static_cast<std::uint8_t>(PacketId::MOTION) ||
            value > static_cast<std::uint8_t>(PacketId::SESSION_HISTORY)) {
            throw std::out_of_range("Value must be between [" +
                                    std::to_string(static_cast<std::uint8_t>(PacketId::MOTION)) + ", " +
                                    std::to_string(static_cast<std::uint8_t>(PacketId::SESSION_HISTORY)) + "]"
            );
        }

        return static_cast<PacketId>(value);
    }

    std::string PacketHeader::to_string(PacketId id) {
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

    std::ostream& operator<<(std::ostream& os, const PacketHeader& header) {
        os << "m_packetFormat: " << std::to_string(header.m_packetFormat) << "\n"
           << "m_gameMajorVersion: " << std::to_string(header.m_gameMajorVersion) << "\n"
           << "m_gameMinorVersion: " << std::to_string(header.m_gameMinorVersion) << "\n"
           << "m_packetVersion: " << std::to_string(header.m_packetVersion) << "\n"
           << "m_packetId: " << PacketHeader::to_string(PacketHeader::from(header.m_packetId)) << "\n"
           << "m_sessionUID: " << std::to_string(header.m_sessionUID) << "\n"
           << "m_sessionTime: " << std::to_string(header.m_sessionTime) << "\n"
           << "m_frameIdentifier: " << std::to_string(header.m_frameIdentifier) << "\n"
           << "m_playerCarIndex: " << std::to_string(header.m_playerCarIndex) << "\n"
           << "m_secondaryPlayerCarIndex: " << std::to_string(header.m_secondaryPlayerCarIndex) << "\n";

        return os;
    }
}
