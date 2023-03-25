#include "PacketLobbyInfoData.h"
#include "../../util.h"

namespace F122::Network {
    PacketLobbyInfoData::Data::Data(const std::array<std::uint8_t, 53>& bytes) :
            m_aiControlled{bytes[0]},
            m_teamId{bytes[1]},
            m_nationality{bytes[2]},
            m_name{util::convert_type<48>(util::copy_resize<std::uint8_t, 53, 48, 3>(bytes))},
            m_carNumber{bytes[51]},
            m_readyStatus{bytes[52]} {}

    PacketLobbyInfoData::PacketLobbyInfoData(const std::array<std::uint8_t, 1191>& bytes) :
            m_header{{util::copy_resize<std::uint8_t, 1191, 24>(bytes)}},
            m_numPlayers{bytes[24]},
            m_lobbyPlayers{util::batch_create<Data, 1191, 53, 22, 24 + 1>(bytes)} {}

    std::ostream& operator<<(std::ostream& os, const PacketLobbyInfoData::Data& data) {
        os << "m_aiControlled: " << std::to_string(data.m_aiControlled) << "\n"
           << "m_teamId: " << std::to_string(data.m_teamId) << "\n"
           << "m_nationality: " << std::to_string(data.m_nationality) << "\n"
           << "m_name: " << util::to_string(data.m_name) << "\n"
           << "m_carNumber: " << std::to_string(data.m_carNumber) << "\n"
           << "m_readyStatus: " << std::to_string(data.m_readyStatus);

        return os;
    }

    std::ostream& operator<<(std::ostream& os, const PacketLobbyInfoData& data) {
        os << "m_header: " << "\n" << data.m_header << "\n"
           << "m_numPlayers: " << std::to_string(data.m_numPlayers) << "\n"
           << "m_lobbyPlayers: " << "\n\n";

        for (size_t i = 0; i < data.m_lobbyPlayers.size(); ++i) {
            os << "Car " << std::to_string(i) << ": " << "\n";
            os << data.m_lobbyPlayers[i] << (i < data.m_lobbyPlayers.size() - 1 ? "\n\n" : "");
        }

        return os;
    }
}
