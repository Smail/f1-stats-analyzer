#pragma once

#include <ostream>
#include <cstdint>
#include <array>
#include "PacketHeader.h"
#include "Packet.h"

namespace F122::Network::Packets {
    /// The motion packet gives physics data for all the cars being driven. There is additional data for the car
    /// being driven with the goal of being able to drive a motion platform setup.
    /// N.B. For the normalised vectors below, to convert to float values divide by 32767.0f – 16-bit signed values
    /// are used to pack the data and on the assumption that direction values are always between -1.0f and 1.0f.<br>
    /// <br>
    /// Frequency: Rate as specified in menus<br>
    /// Size: 1464 bytes<br>
    /// Version: 1<br>
    struct MotionData : public Packet {
        struct Data {
            static constexpr size_t SIZE = 60;

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
        static constexpr size_t SIZE = PacketHeader::SIZE + 22 * Data::SIZE + 120;

        explicit MotionData(const std::array<std::uint8_t, SIZE>& bytes);

        ~MotionData() override;

        friend std::ostream& operator<<(std::ostream& os, const MotionData& data);

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

        static_assert(SIZE == 1464, "Invalid size");
        static_assert(PacketHeader::SIZE + sizeof(m_suspensionPosition) + sizeof(m_suspensionVelocity) +
                      sizeof(m_suspensionAcceleration) + sizeof(m_wheelSpeed) + sizeof(m_wheelSlip) +
                      sizeof(m_localVelocityX) + sizeof(m_localVelocityY) + sizeof(m_localVelocityZ) +
                      sizeof(m_angularVelocityX) + sizeof(m_angularVelocityY) + sizeof(m_angularVelocityZ) +
                      sizeof(m_angularAccelerationX) + sizeof(m_angularAccelerationY) + sizeof(m_angularAccelerationZ) +
                      sizeof(m_frontWheelsAngle) + 22 * Data::SIZE == SIZE, "Invalid size 2");

    };

    std::ostream& operator<<(std::ostream& os, const MotionData& data);

    std::ostream& operator<<(std::ostream& os, const MotionData::Data& data);
}
