#pragma once

#include <ostream>
#include <cstdint>
#include <array>
#include "PacketHeader.h"

namespace F122::Network::Packets {
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
            Data() = default;

            explicit Data(const std::array<std::uint8_t, 60>& bytes);

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
            std::int16_t m_worldForwardDirX;
            /// World space forward Y direction (normalised)
            std::int16_t m_worldForwardDirY;
            /// World space forward Z direction (normalised)
            std::int16_t m_worldForwardDirZ;
            /// World space right X direction (normalised)
            std::int16_t m_worldRightDirX;
            /// World space right Y direction (normalised)
            std::int16_t m_worldRightDirY;
            /// World space right Z direction (normalised)
            std::int16_t m_worldRightDirZ;
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

            friend std::ostream& operator<<(std::ostream& os, const Data& data);
        };

    public:
        explicit PacketMotionData(const std::array<std::uint8_t, 1464>& bytes);

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

        friend std::ostream& operator<<(std::ostream& os, const PacketMotionData& data);
    };

    std::ostream& operator<<(std::ostream& os, const PacketMotionData& data);

    std::ostream& operator<<(std::ostream& os, const PacketMotionData::Data& data);
}
