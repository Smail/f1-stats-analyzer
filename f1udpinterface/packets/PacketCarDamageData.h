#pragma once

#include <ostream>
#include <array>
#include "PacketHeader.h"

#pragma pack(1)

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
            std::array<uint8, 4> m_tyresDamage;
            /// Brakes damage (percentage)
            std::array<uint8, 4> m_brakesDamage;
            /// Front left wing damage (percentage)
            uint8 m_frontLeftWingDamage;
            /// Front right wing damage (percentage)
            uint8 m_frontRightWingDamage;
            /// Rear wing damage (percentage)
            uint8 m_rearWingDamage;
            /// Floor damage (percentage)
            uint8 m_floorDamage;
            /// Diffuser damage (percentage)
            uint8 m_diffuserDamage;
            /// Sidepod damage (percentage)
            uint8 m_sidepodDamage;
            /// Indicator for DRS fault, 0 = OK, 1 = fault
            uint8 m_drsFault;
            /// Indicator for ERS fault, 0 = OK, 1 = fault
            uint8 m_ersFault;
            /// Gear box damage (percentage)
            uint8 m_gearBoxDamage;
            /// Engine damage (percentage)
            uint8 m_engineDamage;
            /// Engine wear MGU-H (percentage)
            uint8 m_engineMGUHWear;
            /// Engine wear ES (percentage)
            uint8 m_engineESWear;
            /// Engine wear CE (percentage)
            uint8 m_engineCEWear;
            /// Engine wear ICE (percentage)
            uint8 m_engineICEWear;
            /// Engine wear MGU-K (percentage)
            uint8 m_engineMGUKWear;
            /// Engine wear TC (percentage)
            uint8 m_engineTCWear;
            /// Engine blown, 0 = OK, 1 = fault
            uint8 m_engineBlown;
            /// Engine seized, 0 = OK, 1 = fault
            uint8 m_engineSeized;

            friend std::ostream &operator<<(std::ostream &os, const Data &data);
        };

    public:
        explicit PacketCarDamageData(const std::array<std::uint8_t, 948>& bytes);

        PacketHeader m_header;
        std::array<Data, 22> m_carDamageData;

        friend std::ostream &operator<<(std::ostream &os, const PacketCarDamageData &data);
    };

    std::ostream &operator<<(std::ostream &os, const PacketCarDamageData &data);

    std::ostream &operator<<(std::ostream &os, const PacketCarDamageData::Data &data);
}

#pragma pack()
