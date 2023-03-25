#pragma once

#include <cstdint>
#include <ostream>
#include <array>
#include "PacketHeader.h"

namespace F122::Network {
    /// This packet details car damage parameters for all the cars in the race.<br>
    /// <br>
    /// Frequency: 2 per second<br>
    /// Size: 948 bytes<br>
    /// Version: 1<br>
    struct PacketCarDamageData {
        struct Data {
            Data() = default;

            explicit Data(const std::array<std::uint8_t, 42>& bytes);

            /// Tyre wear (percentage)
            std::array<float, 4> m_tyresWear;
            /// Tyre damage (percentage)
            std::array<std::uint8_t, 4> m_tyresDamage;
            /// Brakes damage (percentage)
            std::array<std::uint8_t, 4> m_brakesDamage;
            /// Front left wing damage (percentage)
            std::uint8_t m_frontLeftWingDamage;
            /// Front right wing damage (percentage)
            std::uint8_t m_frontRightWingDamage;
            /// Rear wing damage (percentage)
            std::uint8_t m_rearWingDamage;
            /// Floor damage (percentage)
            std::uint8_t m_floorDamage;
            /// Diffuser damage (percentage)
            std::uint8_t m_diffuserDamage;
            /// Sidepod damage (percentage)
            std::uint8_t m_sidepodDamage;
            /// Indicator for DRS fault, 0 = OK, 1 = fault
            std::uint8_t m_drsFault;
            /// Indicator for ERS fault, 0 = OK, 1 = fault
            std::uint8_t m_ersFault;
            /// Gear box damage (percentage)
            std::uint8_t m_gearBoxDamage;
            /// Engine damage (percentage)
            std::uint8_t m_engineDamage;
            /// Engine wear MGU-H (percentage)
            std::uint8_t m_engineMGUHWear;
            /// Engine wear ES (percentage)
            std::uint8_t m_engineESWear;
            /// Engine wear CE (percentage)
            std::uint8_t m_engineCEWear;
            /// Engine wear ICE (percentage)
            std::uint8_t m_engineICEWear;
            /// Engine wear MGU-K (percentage)
            std::uint8_t m_engineMGUKWear;
            /// Engine wear TC (percentage)
            std::uint8_t m_engineTCWear;
            /// Engine blown, 0 = OK, 1 = fault
            std::uint8_t m_engineBlown;
            /// Engine seized, 0 = OK, 1 = fault
            std::uint8_t m_engineSeized;

            friend std::ostream& operator<<(std::ostream& os, const Data& data);
        };

    public:
        explicit PacketCarDamageData(const std::array<std::uint8_t, 948>& bytes);

        friend std::ostream& operator<<(std::ostream& os, const PacketCarDamageData& data);

        PacketHeader m_header;
        std::array<Data, 22> m_carDamageData;
    };

    std::ostream& operator<<(std::ostream& os, const PacketCarDamageData& data);

    std::ostream& operator<<(std::ostream& os, const PacketCarDamageData::Data& data);
}
