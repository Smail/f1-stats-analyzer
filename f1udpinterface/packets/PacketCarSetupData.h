#pragma once

#include <ostream>
#include "PacketHeader.h"

#pragma pack(1)

namespace F122::Network {
    /// This packet details the car setups for each vehicle in the session. Note that in multiplayer games, other
    /// player cars will appear as blank, you will only be able to see your car setup and AI cars.<br>
    /// <br>
    /// Frequency: 2 per second<br>
    /// Size: 1102 bytes<br>
    /// Version: 1<br>
    struct PacketCarSetupData {
        struct Data {
            Data() = default;

            explicit Data(const std::array<std::uint8_t, 49>& bytes);

            /// Front wing aero
            uint8 m_frontWing;
            /// Rear wing aero
            uint8 m_rearWing;
            /// Differential adjustment on throttle (percentage)
            uint8 m_onThrottle;
            /// Differential adjustment off throttle (percentage)
            uint8 m_offThrottle;
            /// Front camber angle (suspension geometry)
            float m_frontCamber;
            /// Rear camber angle (suspension geometry)
            float m_rearCamber;
            /// Front toe angle (suspension geometry)
            float m_frontToe;
            /// Rear toe angle (suspension geometry)
            float m_rearToe;
            /// Front suspension
            uint8 m_frontSuspension;
            /// Rear suspension
            uint8 m_rearSuspension;
            /// Front anti-roll bar
            uint8 m_frontAntiRollBar;
            /// Front anti-roll bar
            uint8 m_rearAntiRollBar;
            /// Front ride height
            uint8 m_frontSuspensionHeight;
            /// Rear ride height
            uint8 m_rearSuspensionHeight;
            /// Brake pressure (percentage)
            uint8 m_brakePressure;
            /// Brake bias (percentage)
            uint8 m_brakeBias;
            /// Rear left tyre pressure (PSI)
            float m_rearLeftTyrePressure;
            /// Rear right tyre pressure (PSI)
            float m_rearRightTyrePressure;
            /// Front left tyre pressure (PSI)
            float m_frontLeftTyrePressure;
            /// Front right tyre pressure (PSI)
            float m_frontRightTyrePressure;
            /// Ballast
            uint8 m_ballast;
            /// Fuel load
            float m_fuelLoad;

            friend std::ostream &operator<<(std::ostream &os, const Data &data);
        };

    public:
        explicit PacketCarSetupData(const std::array<std::uint8_t, 1102>& bytes);
        
        PacketHeader m_header;
        std::array<Data, 22> m_carSetups;

        friend std::ostream &operator<<(std::ostream &os, const PacketCarSetupData &data);
    };

    std::ostream &operator<<(std::ostream &os, const PacketCarSetupData::Data &data);

    std::ostream &operator<<(std::ostream &os, const PacketCarSetupData &data);
}

#pragma pack()
