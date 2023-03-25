#pragma once

#include <ostream>
#include "PacketHeader.h"

#pragma pack(1)

namespace F122::Network {
    /// This packet details the players currently in a multiplayer lobby. It details each player’s selected car, any
    /// AI involved in the game and also the ready status of each of the participants.<br>
    /// <br>
    /// Frequency: Two every second when in the lobby<br>
    /// Size: 1191 bytes<br>
    /// Version: 1<br>
    struct PacketLobbyInfoData {
        struct Data {
            Data() = default;

            explicit Data(const std::array<std::uint8_t, 53>& bytes);

            /// Whether the vehicle is AI (1) or Human (0) controlled
            uint8 m_aiControlled;
            /// Team id - see appendix (255 if no team currently selected)
            uint8 m_teamId;
            /// Nationality of the driver
            uint8 m_nationality;
            /// Name of participant in UTF-8 format – null terminated
            /// Will be truncated with ... (U+2026) if too long
            std::array<char, 48> m_name;
            /// Car number of the player
            uint8 m_carNumber;
            /// 0 = not ready, 1 = ready, 2 = spectating
            uint8 m_readyStatus;

            friend std::ostream &operator<<(std::ostream &os, const Data &data);
        };

    public:
        explicit PacketLobbyInfoData(const std::array<std::uint8_t, 1191>& bytes);

        PacketHeader m_header;
        /// Number of players in the lobby data
        uint8 m_numPlayers;
        /// Data of each player
        std::array<Data, 22> m_lobbyPlayers;

        friend std::ostream &operator<<(std::ostream &os, const PacketLobbyInfoData &data);
    };

    std::ostream &operator<<(std::ostream &os, const PacketLobbyInfoData &data);

    std::ostream &operator<<(std::ostream &os, const PacketLobbyInfoData::Data &data);
}

#pragma pack()
