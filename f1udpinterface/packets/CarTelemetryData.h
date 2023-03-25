#pragma once

#include <cstdint>
#include "PacketHeader.h"

namespace F122::Network::Packets {
    /// This packet details telemetry for all the cars in the race. It details various values that would be recorded
    /// on the car such as speed, throttle application, DRS etc. Note that the rev light configurations are
    /// presented separately as well and will mimic real life driver preferences.<br>
    /// <br>
    /// Frequency: Rate as specified in menus<br>
    /// Size: 1347 bytes<br>
    /// Version: 1<br>
    struct CarTelemetryData {
        struct Data {
            Data() = default;

            explicit Data(const std::array<std::uint8_t, 60>& bytes);

            /// Speed of car in kilometres per hour
            std::uint16_t m_speed;
            /// Amount of throttle applied (0.0 to 1.0)
            float m_throttle;
            /// Steering (-1.0 (full lock left) to 1.0 (full lock right))
            float m_steer;
            /// Amount of brake applied (0.0 to 1.0)
            float m_brake;
            /// Amount of clutch applied (0 to 100)
            std::uint8_t m_clutch;
            /// Gear selected (1-8, N=0, R=-1)
            std::int8_t m_gear;
            /// Engine RPM
            std::uint16_t m_engineRPM;
            /// 0 = off, 1 = on
            std::uint8_t m_drs;
            /// Rev lights indicator (percentage)
            std::uint8_t m_revLightsPercent;
            /// Rev lights (bit 0 = leftmost LED, bit 14 = rightmost LED)
            std::uint16_t m_revLightsBitValue;
            /// Brakes temperature (celsius)
            std::array<std::uint16_t, 4> m_brakesTemperature;
            /// Tyres surface temperature (celsius)
            std::array<std::uint8_t, 4> m_tyresSurfaceTemperature;
            /// Tyres inner temperature (celsius)
            std::array<std::uint8_t, 4> m_tyresInnerTemperature;
            /// Engine temperature (celsius)
            std::uint16_t m_engineTemperature;
            /// Tyres pressure (PSI)
            std::array<float, 4> m_tyresPressure;
            /// Driving surface, see appendices
            std::array<std::uint8_t, 4> m_surfaceType;

            /// Returns if the car's DRS is currently active, i.e., if the wing is open.
            [[nodiscard]] bool is_drs_open() const {
                return m_drs == 1;
            }

            friend std::ostream& operator<<(std::ostream& os, const Data& data);
        };

    public:
        explicit CarTelemetryData(const std::array<std::uint8_t, 1347>& bytes);

        friend std::ostream& operator<<(std::ostream& os, const CarTelemetryData& data);

        PacketHeader m_header;
        std::array<Data, 22> m_carTelemetryData;
        /// Index of MFD panel open (255 = MFD closed)
        /// Single player, race – 0 = Car setup, 1 = Pits, 2 = Damage, 3 = Engine, 4 = Temperatures
        /// May vary depending on game mode
        std::uint8_t m_mfdPanelIndex;
        /// Secondary player, race – 0 = Car setup, 1 = Pits, 2 = Damage, 3 = Engine, 4 = Temperatures
        /// May vary depending on game mode
        std::uint8_t m_mfdPanelIndexSecondaryPlayer;
        /// Suggested gear for the player (1-8) - 0 if no gear suggested
        std::int8_t m_suggestedGear;
    };

    std::ostream& operator<<(std::ostream& os, const CarTelemetryData::Data& data);

    std::ostream& operator<<(std::ostream& os, const CarTelemetryData& data);
}