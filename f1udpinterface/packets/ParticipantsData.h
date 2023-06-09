#pragma once

#include <string>
#include <cstdint>
#include <array>
#include "PacketHeader.h"

namespace F122::Network::Packets {
    /// This is a list of participants in the race. If the vehicle is controlled by AI, then the name will be the driver
    /// name. If this is a multiplayer game, the names will be the Steam Id on PC, or the LAN name if appropriate.
    /// N.B. on Xbox One, the names will always be the driver name, on PS4 the name will be the LAN name if
    /// playing a LAN game, otherwise it will be the driver name.
    /// The array should be indexed by vehicle index.<br>
    /// <br>
    /// Frequency: Every 5 seconds<br>
    /// Size: 1257 bytes<br>
    /// Version: 1<br>
    struct ParticipantsData : public Packet {
        struct Data {
            static constexpr size_t SIZE = 56;

            Data() = default;

            explicit Data(const std::array<std::uint8_t, SIZE>& bytes);

            [[nodiscard]] std::string name() const;

            [[nodiscard]] bool is_ai_controlled() const;

            friend std::ostream& operator<<(std::ostream& os, const Data& data);

            /// Whether the vehicle is AI (1) or Human (0) controlled
            std::uint8_t m_aiControlled;
            /// Driver id - see appendix, 255 if network human
            std::uint8_t m_driverId;
            /// Network id - unique identifier for network players
            std::uint8_t m_networkId;
            /// Team id, 255 if no team selected @see TeamId
            std::uint8_t m_teamId;
            /// My team flag: 1 = My Team, 0 = otherwise
            std::uint8_t m_myTeam;
            /// Race number of the car
            std::uint8_t m_raceNumber;
            /// Nationality id of the driver, 255 if no nationality selected @see NationalityId
            std::uint8_t m_nationality;
            /// Name of participant in UTF-8 format – null terminated
            /// Will be truncated with ... (U+2026) if too long
            std::array<char, 48> m_name;
            /// The player's UDP setting, 0 = restricted, 1 = public
            std::uint8_t m_yourTelemetry;
        };

    public:
        static constexpr size_t SIZE = PacketHeader::SIZE + 22 * Data::SIZE + 1;

        explicit ParticipantsData(const std::array<std::uint8_t, SIZE>& bytes);

        ~ParticipantsData() override;

        friend std::ostream& operator<<(std::ostream& os, const ParticipantsData& data);

        PacketHeader m_header;
        /// Number of active cars in the data - should match number of cars on HUD
        std::uint8_t m_numActiveCars;
        std::array<Data, 22> m_participants;

        static_assert(SIZE == 1257, "Invalid size");
        static_assert(PacketHeader::SIZE + sizeof(m_numActiveCars) + (22 * Data::SIZE) == SIZE, "Invalid size 2");

    };

    std::ostream& operator<<(std::ostream& os, const ParticipantsData& data);

    std::ostream& operator<<(std::ostream& os, const ParticipantsData::Data& data);
}
