#pragma once

#include <ostream>
#include <array>

#include "../../util.h"
#include "PacketHeader.h"

#pragma pack(1)

namespace F122::Network {
    /// The motion packet gives physics data for all the cars being driven. There is additional data for the car
    /// being driven with the goal of being able to drive a motion platform setup.
    /// N.B. For the normalised vectors below, to convert to float values divide by 32767.0f – 16-bit signed values
    /// are used to pack the data and on the assumption that direction values are always between -1.0f and 1.0f.<br>
    /// <br>
    /// Frequency: Rate as specified in menus<br>
    /// Size: 1464 bytes<br>
    /// Version: 1<br>
    struct PacketMotionData {
        struct Data {
            /// World space X position
            float m_worldPositionX;
            /// World space Y position
            float m_worldPositionY;
            /// World space Z position
            float m_worldPositionZ;
            /// Velocity in world space X
            float m_worldVelocityX;
            /// Velocity in world space Y
            float m_worldVelocityY;
            /// Velocity in world space Z
            float m_worldVelocityZ;
            /// World space forward X direction (normalised)
            int16 m_worldForwardDirX;
            /// World space forward Y direction (normalised)
            int16 m_worldForwardDirY;
            /// World space forward Z direction (normalised)
            int16 m_worldForwardDirZ;
            /// World space right X direction (normalised)
            int16 m_worldRightDirX;
            /// World space right Y direction (normalised)
            int16 m_worldRightDirY;
            /// World space right Z direction (normalised)
            int16 m_worldRightDirZ;
            /// Lateral G-Force component
            float m_gForceLateral;
            /// Longitudinal G-Force component
            float m_gForceLongitudinal;
            /// Vertical G-Force component
            float m_gForceVertical;
            /// Yaw angle in radians
            float m_yaw;
            /// Pitch angle in radians
            float m_pitch;
            /// Roll angle in radians
            float m_roll;

            friend std::ostream &operator<<(std::ostream &os, const Data &data) {
                os << "m_worldPositionX: " << std::to_string(data.m_worldPositionX) << "\n"
                   << "m_worldPositionY: " << std::to_string(data.m_worldPositionY) << "\n"
                   << "m_worldPositionZ: " << std::to_string(data.m_worldPositionZ) << "\n"
                   << "m_worldVelocityX: " << std::to_string(data.m_worldVelocityX) << "\n"
                   << "m_worldVelocityY: " << std::to_string(data.m_worldVelocityY) << "\n"
                   << "m_worldVelocityZ: " << std::to_string(data.m_worldVelocityZ) << "\n"
                   << "m_worldForwardDirX: " << std::to_string(data.m_worldForwardDirX) << "\n"
                   << "m_worldForwardDirY: " << std::to_string(data.m_worldForwardDirY) << "\n"
                   << "m_worldForwardDirZ: " << std::to_string(data.m_worldForwardDirZ) << "\n"
                   << "m_worldRightDirX: " << std::to_string(data.m_worldRightDirX) << "\n"
                   << "m_worldRightDirY: " << std::to_string(data.m_worldRightDirY) << "\n"
                   << "m_worldRightDirZ: " << std::to_string(data.m_worldRightDirZ) << "\n"
                   << "m_gForceLateral: " << std::to_string(data.m_gForceLateral) << "\n"
                   << "m_gForceLongitudinal: " << std::to_string(data.m_gForceLongitudinal) << "\n"
                   << "m_gForceVertical: " << std::to_string(data.m_gForceVertical) << "\n"
                   << "m_yaw: " << std::to_string(data.m_yaw) << "\n"
                   << "m_pitch: " << std::to_string(data.m_pitch) << "\n"
                   << "m_roll: " << std::to_string(data.m_roll) << "\n";

                return os;
            }
        };

    public:
        PacketHeader m_header;
        /// Data for all cars on track
        /// Extra player car ONLY data
        std::array<Data, 22> m_carMotionData;
        /// Note: All wheel arrays have the following order:
        std::array<float, 4> m_suspensionPosition;
        /// RL (rear left), RR, FL, FR
        std::array<float, 4> m_suspensionVelocity;
        /// RL (rear left), RR, FL, FR
        std::array<float, 4> m_suspensionAcceleration;
        /// Speed of each wheel
        std::array<float, 4> m_wheelSpeed;
        /// Slip ratio for each wheel
        std::array<float, 4> m_wheelSlip;
        /// Velocity in local space
        float m_localVelocityX;
        /// Velocity in local space
        float m_localVelocityY;
        /// Velocity in local space
        float m_localVelocityZ;
        /// Angular velocity x-component
        float m_angularVelocityX;
        /// Angular velocity y-component
        float m_angularVelocityY;
        /// Angular velocity z-component
        float m_angularVelocityZ;
        /// Angular velocity x-component
        float m_angularAccelerationX;
        /// Angular velocity y-component
        float m_angularAccelerationY;
        /// Angular velocity z-component
        float m_angularAccelerationZ;
        /// Current front wheels angle in radians
        float m_frontWheelsAngle;

        friend std::ostream &operator<<(std::ostream &os, const PacketMotionData &data) {
            os << "m_header: " << "\n" << data.m_header << "\n"
               << "m_suspensionPosition: " << util::to_string(data.m_suspensionPosition) << "\n"
               << "m_suspensionVelocity: " << util::to_string(data.m_suspensionVelocity) << "\n"
               << "m_suspensionAcceleration: " << util::to_string(data.m_suspensionAcceleration) << "\n"
               << "m_wheelSpeed: " << util::to_string(data.m_wheelSpeed) << "\n"
               << "m_wheelSlip: " << util::to_string(data.m_wheelSlip) << "\n"
               << "m_localVelocityX: " << std::to_string(data.m_localVelocityX) << "\n"
               << "m_localVelocityY: " << std::to_string(data.m_localVelocityY) << "\n"
               << "m_localVelocityZ: " << std::to_string(data.m_localVelocityZ) << "\n"
               << "m_angularVelocityX: " << std::to_string(data.m_angularVelocityX) << "\n"
               << "m_angularVelocityY: " << std::to_string(data.m_angularVelocityY) << "\n"
               << "m_angularVelocityZ: " << std::to_string(data.m_angularVelocityZ) << "\n"
               << "m_angularAccelerationX: " << std::to_string(data.m_angularAccelerationX) << "\n"
               << "m_angularAccelerationY: " << std::to_string(data.m_angularAccelerationY) << "\n"
               << "m_angularAccelerationZ: " << std::to_string(data.m_angularAccelerationZ) << "\n"
               << "m_frontWheelsAngle: " << std::to_string(data.m_frontWheelsAngle) << "\n"
               << "m_carMotionData: " << "\n\n";

            for (size_t i = 0; i < data.m_carMotionData.size(); ++i) {
                os << "Car " << std::to_string(i) << ": " << "\n";
                os << data.m_carMotionData[i] << (i < data.m_carMotionData.size() - 1 ? "\n" : "");
            }

            return os;
        }
    };
}

#pragma pack()
