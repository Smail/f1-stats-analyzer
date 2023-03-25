#pragma once

#include "PacketHeader.h"
#include <string>
#include <array>

#pragma pack(1)

namespace F122::Network {
    
    /// This is a list of participants in the race. If the vehicle is controlled by AI, then the name will be the driver
    /// name. If this is a multiplayer game, the names will be the Steam Id on PC, or the LAN name if appropriate.
    /// N.B. on Xbox One, the names will always be the driver name, on PS4 the name will be the LAN name if
    /// playing a LAN game, otherwise it will be the driver name.
    /// The array should be indexed by vehicle index.<br>
    /// <br>
    /// Frequency: Every 5 seconds<br>
    /// Size: 1257 bytes<br>
    /// Version: 1<br>
    struct PacketParticipantsData {
        struct Data {
            Data() = default;

            explicit Data(const std::array<std::uint8_t, 56>& bytes);
            
            /// Whether the vehicle is AI (1) or Human (0) controlled
            uint8 m_aiControlled;
            /// Driver id - see appendix, 255 if network human
            uint8 m_driverId;
            /// Network id - unique identifier for network players
            uint8 m_networkId;
            /// Team id - see appendix
            uint8 m_teamId;
            /// My team flag - 1 = My Team, 0 = otherwise
            uint8 m_myTeam;
            /// Race number of the car
            uint8 m_raceNumber;
            /// Nationality of the driver
            uint8 m_nationality;
            /// Name of participant in UTF-8 format – null terminated
            /// Will be truncated with ... (U+2026) if too long
            std::array<char, 48> m_name;
            /// The player's UDP setting, 0 = restricted, 1 = public
            uint8 m_yourTelemetry;

            [[nodiscard]] std::string name() const;

            [[nodiscard]] bool is_ai_controlled() const;

            friend std::ostream &operator<<(std::ostream &os, const Data &data);
        };

    private:

    public:
        explicit PacketParticipantsData(const std::array<std::uint8_t, 1257>& bytes);

        PacketHeader m_header;
        /// Number of active cars in the data - should match number of cars on HUD
        uint8 m_numActiveCars;
        std::array<Data, 22> m_participants;

        friend std::ostream &operator<<(std::ostream &os, const PacketParticipantsData &data);
    };

    std::ostream &operator<<(std::ostream &os, const PacketParticipantsData &data);

    std::ostream &operator<<(std::ostream &os, const PacketParticipantsData::Data &data);
}

#pragma pack()
