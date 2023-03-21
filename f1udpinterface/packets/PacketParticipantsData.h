#pragma once

#include "PacketHeader.h"
#include "../../util.h"
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

            [[nodiscard]] std::string name() const {
                auto i = std::find_if(m_name.begin(), m_name.end(), [](auto c) { return c == '\0'; });

                if (i == m_name.end()) {
                    throw std::runtime_error("Could not find null character. Array: " + util::to_string(m_name));
                }

                return std::string{m_name.data()};
            }

            [[nodiscard]] bool is_ai_controlled() const {
                return m_aiControlled == 1;
            }

            friend std::ostream &operator<<(std::ostream &os, const Data &data) {
                os << "m_aiControlled: " << std::to_string(data.m_aiControlled) << "\n"
                   << "m_driverId: " << std::to_string(data.m_driverId) << "\n"
                   << "m_networkId: " << std::to_string(data.m_networkId) << "\n"
                   << "m_teamId: " << std::to_string(data.m_teamId) << "\n"
                   << "m_myTeam: " << std::to_string(data.m_myTeam) << "\n"
                   << "m_raceNumber: " << std::to_string(data.m_raceNumber) << "\n"
                   << "m_nationality: " << std::to_string(data.m_nationality) << "\n"
                   << "m_yourTelemetry: " << std::to_string(data.m_yourTelemetry) << "\n"
                   << "m_name: " << data.name() << " " <<  util::to_string(data.m_name);

                return os;
            }
        };

    public:
        PacketHeader m_header;
        /// Number of active cars in the data - should match number of cars on HUD
        uint8 m_numActiveCars;
        std::array<Data, 22> m_participants;

        friend std::ostream &operator<<(std::ostream &os, const PacketParticipantsData &data) {
            os << "m_header: " << "\n" << data.m_header
               << "m_numActiveCars: " << std::to_string(data.m_numActiveCars) << "\n"
               << "m_participants: " << "\n\n";

            for (size_t i = 0; i < data.m_participants.size(); ++i) {
                os << "Car " << std::to_string(i) << ": " << "\n";
                os << data.m_participants[i] << (i < data.m_participants.size() - 1 ? "\n\n" : "");
            }

            return os;
        }
    };
}

#pragma pack()
