#pragma once

#include <cstdint>
#include <ostream>
#include "PacketHeader.h"
#include "Packet.h"

namespace F122::Network::Packets {
    /// This packet details the car setups for each vehicle in the session. Note that in multiplayer games, other
    /// player cars will appear as blank, you will only be able to see your car setup and AI cars.<br>
    /// <br>
    /// Frequency: 2 per second<br>
    /// Size: 1102 bytes<br>
    /// Version: 1<br>
    struct CarSetupData : public Packet {
        struct Data {
            static constexpr size_t SIZE = 49;

            Data() = default;

            explicit Data(const std::array<std::uint8_t, SIZE>& bytes);

            /// Front wing aero
            std::uint8_t m_frontWing;
            /// Rear wing aero
            std::uint8_t m_rearWing;
            /// Differential adjustment on throttle (percentage)
            std::uint8_t m_onThrottle;
            /// Differential adjustment off throttle (percentage)
            std::uint8_t m_offThrottle;
            /// Front camber angle (suspension geometry)
            float m_frontCamber;
            /// Rear camber angle (suspension geometry)
            float m_rearCamber;
            /// Front toe angle (suspension geometry)
            float m_frontToe;
            /// Rear toe angle (suspension geometry)
            float m_rearToe;
            /// Front suspension
            std::uint8_t m_frontSuspension;
            /// Rear suspension
            std::uint8_t m_rearSuspension;
            /// Front anti-roll bar
            std::uint8_t m_frontAntiRollBar;
            /// Front anti-roll bar
            std::uint8_t m_rearAntiRollBar;
            /// Front ride height
            std::uint8_t m_frontSuspensionHeight;
            /// Rear ride height
            std::uint8_t m_rearSuspensionHeight;
            /// Brake pressure (percentage)
            std::uint8_t m_brakePressure;
            /// Brake bias (percentage)
            std::uint8_t m_brakeBias;
            /// Rear left tyre pressure (PSI)
            float m_rearLeftTyrePressure;
            /// Rear right tyre pressure (PSI)
            float m_rearRightTyrePressure;
            /// Front left tyre pressure (PSI)
            float m_frontLeftTyrePressure;
            /// Front right tyre pressure (PSI)
            float m_frontRightTyrePressure;
            /// Ballast
            std::uint8_t m_ballast;
            /// Fuel load
            float m_fuelLoad;

            friend std::ostream& operator<<(std::ostream& os, const Data& data);
        };

    public:
        static constexpr size_t SIZE = PacketHeader::SIZE + 22 * Data::SIZE;

        explicit CarSetupData(const std::array<std::uint8_t, SIZE>& bytes);

        ~CarSetupData() override;

        friend std::ostream& operator<<(std::ostream& os, const CarSetupData& data);

        PacketHeader m_header;
        std::array<Data, 22> m_carSetups;

        static_assert(SIZE == 1102, "Invalid size");
        static_assert(PacketHeader::SIZE + 22 * Data::SIZE == SIZE, "Invalid size 2");
    };

    std::ostream& operator<<(std::ostream& os, const CarSetupData::Data& data);

    std::ostream& operator<<(std::ostream& os, const CarSetupData& data);
}
