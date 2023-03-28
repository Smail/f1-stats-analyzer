#include "../LobbyInfoData.h"
#include "../../../util.h"
#include "../../ids/NationalityId.h"
#include "../../ids/TeamId.h"

namespace F122::Network::Packets {
    LobbyInfoData::Data::Data(const std::array<std::uint8_t, SIZE>& bytes) :
            m_aiControlled{bytes[0]},
            m_teamId{bytes[1]},
            m_nationality{bytes[2]},
            m_name{util::convert_type<48>(util::copy_resize<std::uint8_t, SIZE, 48, 3>(bytes))},
            m_carNumber{bytes[51]},
            m_readyStatus{bytes[52]} {}

    LobbyInfoData::LobbyInfoData(const std::array<std::uint8_t, SIZE>& bytes) :
            Packet(bytes),
            m_header{{util::copy_resize<std::uint8_t, SIZE, PacketHeader::SIZE>(bytes)}},
            m_numPlayers{bytes[24]},
            m_lobbyPlayers{util::batch_create<Data, SIZE, Data::SIZE, 22, PacketHeader::SIZE + 1>(bytes)} {}

    LobbyInfoData::~LobbyInfoData() = default;

    std::string LobbyInfoData::Data::readyStatus() const {
        if (m_readyStatus == 0) return "Not Ready";
        else if (m_readyStatus == 1) return "Ready";
        else if (m_readyStatus == 2) return "Spectating";
        else throw std::runtime_error("Invalid state: " + std::to_string(m_readyStatus) + " is not valid value");
    }

    std::ostream& operator<<(std::ostream& os, const LobbyInfoData::Data& data) {
        os << "m_aiControlled: " << std::to_string(data.m_aiControlled) << "\n"
           << "m_teamId: " << (data.m_teamId == 255 ?
                               "No team selected" : F122::to_string(static_cast<TeamId>(data.m_teamId))) << "\n"
           << "m_nationality: " << (data.m_nationality == 255 ? "No nationality selected" : F122::to_string(
                static_cast<NationalityId>(data.m_nationality))) << "\n"
           << "m_name: " << util::to_string(data.m_name) << "\n"
           << "m_carNumber: " << std::to_string(data.m_carNumber) << "\n"
           << "m_readyStatus: " << data.readyStatus();

        return os;
    }

    std::ostream& operator<<(std::ostream& os, const LobbyInfoData& data) {
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
