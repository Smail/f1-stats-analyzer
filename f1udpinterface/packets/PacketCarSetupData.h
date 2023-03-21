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

            friend std::ostream &operator<<(std::ostream &os, const Data &data) {
                os << "m_frontWing: " << std::to_string(data.m_frontWing) << "\n"
                   << "m_rearWing: " << std::to_string(data.m_rearWing) << "\n"
                   << "m_onThrottle: " << std::to_string(data.m_onThrottle) << "\n"
                   << "m_offThrottle: " << std::to_string(data.m_offThrottle) << "\n"
                   << "m_frontCamber: " << std::to_string(data.m_frontCamber) << "\n"
                   << "m_rearCamber: " << std::to_string(data.m_rearCamber) << "\n"
                   << "m_frontToe: " << std::to_string(data.m_frontToe) << "\n"
                   << "m_rearToe: " << std::to_string(data.m_rearToe) << "\n"
                   << "m_frontSuspension: " << std::to_string(data.m_frontSuspension) << "\n"
                   << "m_rearSuspension: " << std::to_string(data.m_rearSuspension) << "\n"
                   << "m_frontAntiRollBar: " << std::to_string(data.m_frontAntiRollBar) << "\n"
                   << "m_rearAntiRollBar: " << std::to_string(data.m_rearAntiRollBar) << "\n"
                   << "m_frontSuspensionHeight: " << std::to_string(data.m_frontSuspensionHeight) << "\n"
                   << "m_rearSuspensionHeight: " << std::to_string(data.m_rearSuspensionHeight) << "\n"
                   << "m_brakePressure: " << std::to_string(data.m_brakePressure) << "\n"
                   << "m_brakeBias: " << std::to_string(data.m_brakeBias) << "\n"
                   << "m_rearLeftTyrePressure: " << std::to_string(data.m_rearLeftTyrePressure) << "\n"
                   << "m_rearRightTyrePressure: " << std::to_string(data.m_rearRightTyrePressure) << "\n"
                   << "m_frontLeftTyrePressure: " << std::to_string(data.m_frontLeftTyrePressure) << "\n"
                   << "m_frontRightTyrePressure: " << std::to_string(data.m_frontRightTyrePressure) << "\n"
                   << "m_ballast: " << std::to_string(data.m_ballast) << "\n"
                   << "m_fuelLoad: " << std::to_string(data.m_fuelLoad) << "\n";
                return os;
            }
        };

    public:
        PacketHeader m_header;
        std::array<Data, 22> m_carSetups;

        friend std::ostream &operator<<(std::ostream &os, const PacketCarSetupData &data) {
            os << "m_header: " << "\n" << data.m_header << "\n"
               << "m_carSetups: " << "\n\n";

            for (size_t i = 0; i < data.m_carSetups.size(); ++i) {
                os << "Car " << std::to_string(i) << ": " << "\n";
                os << data.m_carSetups[i] << (i < data.m_carSetups.size() - 1 ? "\n" : "");
            }

            return os;
        }
    };
}

#pragma pack()
