#pragma once

#include <ostream>
#include <array>
#include "PacketHeader.h"
#include "../../util.h"

#pragma pack(1)

namespace F122::Network {
    /// This packet details car damage parameters for all the cars in the race.<br>
    /// <br>
    /// Frequency: 2 per second<br>
    /// Size: 948 bytes<br>
    /// Version: 1<br>
    struct PacketCarDamageData {
        struct Data {
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

            friend std::ostream &operator<<(std::ostream &os, const Data &data) {
                os << "m_tyresWear: " << util::to_string(data.m_tyresWear) << "\n"
                   << "m_tyresDamage: " << util::to_string(data.m_tyresDamage) << "\n"
                   << "m_brakesDamage: " << util::to_string(data.m_brakesDamage) << "\n"
                   << "m_frontLeftWingDamage: " << std::to_string(data.m_frontLeftWingDamage) << "\n"
                   << "m_frontRightWingDamage: " << std::to_string(data.m_frontRightWingDamage) << "\n"
                   << "m_rearWingDamage: " << std::to_string(data.m_rearWingDamage) << "\n"
                   << "m_floorDamage: " << std::to_string(data.m_floorDamage) << "\n"
                   << "m_diffuserDamage: " << std::to_string(data.m_diffuserDamage) << "\n"
                   << "m_sidepodDamage: " << std::to_string(data.m_sidepodDamage) << "\n"
                   << "m_drsFault: " << std::to_string(data.m_drsFault) << "\n"
                   << "m_ersFault: " << std::to_string(data.m_ersFault) << "\n"
                   << "m_gearBoxDamage: " << std::to_string(data.m_gearBoxDamage) << "\n"
                   << "m_engineDamage: " << std::to_string(data.m_engineDamage) << "\n"
                   << "m_engineMGUHWear: " << std::to_string(data.m_engineMGUHWear) << "\n"
                   << "m_engineESWear: " << std::to_string(data.m_engineESWear) << "\n"
                   << "m_engineCEWear: " << std::to_string(data.m_engineCEWear) << "\n"
                   << "m_engineICEWear: " << std::to_string(data.m_engineICEWear) << "\n"
                   << "m_engineMGUKWear: " << std::to_string(data.m_engineMGUKWear) << "\n"
                   << "m_engineTCWear: " << std::to_string(data.m_engineTCWear) << "\n"
                   << "m_engineBlown: " << std::to_string(data.m_engineBlown) << "\n"
                   << "m_engineSeized: " << std::to_string(data.m_engineSeized) << "\n";
                return os;
            }
        };

    public:
        PacketHeader m_header;
        std::array<Data, 22> m_carDamageData;

        friend std::ostream &operator<<(std::ostream &os, const PacketCarDamageData &data) {
            os << "m_header: " << "\n" << data.m_header << "\n"
               << "m_carDamageData: " << "\n\n";

            for (size_t i = 0; i < data.m_carDamageData.size(); ++i) {
                os << "Car " << std::to_string(i) << ": " << "\n";
                os << data.m_carDamageData[i] << (i < data.m_carDamageData.size() - 1 ? "\n" : "");
            }

            return os;
        }
    };
}

#pragma pack()
