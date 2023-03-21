#pragma once

#include "PacketHeader.h"
#include "../../util.h"

#pragma pack(1)

namespace F122::Network {
    /// This packet details telemetry for all the cars in the race. It details various values that would be recorded
    /// on the car such as speed, throttle application, DRS etc. Note that the rev light configurations are
    /// presented separately as well and will mimic real life driver preferences.<br>
    /// <br>
    /// Frequency: Rate as specified in menus<br>
    /// Size: 1347 bytes<br>
    /// Version: 1<br>
    struct PacketCarTelemetryData {
        struct Data {
            /// Speed of car in kilometres per hour
            uint16 m_speed;
            /// Amount of throttle applied (0.0 to 1.0)
            float m_throttle;
            /// Steering (-1.0 (full lock left) to 1.0 (full lock right))
            float m_steer;
            /// Amount of brake applied (0.0 to 1.0)
            float m_brake;
            /// Amount of clutch applied (0 to 100)
            uint8 m_clutch;
            /// Gear selected (1-8, N=0, R=-1)
            int8 m_gear;
            /// Engine RPM
            uint16 m_engineRPM;
            /// 0 = off, 1 = on
            uint8 m_drs;
            /// Rev lights indicator (percentage)
            uint8 m_revLightsPercent;
            /// Rev lights (bit 0 = leftmost LED, bit 14 = rightmost LED)
            uint16 m_revLightsBitValue;
            /// Brakes temperature (celsius)
            std::array<uint16, 4> m_brakesTemperature;
            /// Tyres surface temperature (celsius)
            std::array<uint8, 4> m_tyresSurfaceTemperature;
            /// Tyres inner temperature (celsius)
            std::array<uint8, 4> m_tyresInnerTemperature;
            /// Engine temperature (celsius)
            uint16 m_engineTemperature;
            /// Tyres pressure (PSI)
            std::array<float, 4> m_tyresPressure;
            /// Driving surface, see appendices
            std::array<uint8, 4> m_surfaceType;

            /// Returns if the car's DRS is currently active, i.e., if the wing is open.
            [[nodiscard]] bool is_drs_open() const {
                return m_drs == 1;
            }

            friend std::ostream &operator<<(std::ostream &os, const Data &data) {
                os << "m_speed: " << std::to_string(data.m_speed) << "\n"
                   << "m_throttle: " << std::to_string(data.m_throttle) << "\n"
                   << "m_steer: " << std::to_string(data.m_steer) << "\n"
                   << "m_brake: " << std::to_string(data.m_brake) << "\n"
                   << "m_clutch: " << std::to_string(data.m_clutch) << "\n"
                   << "m_gear: " << std::to_string(data.m_gear) << "\n"
                   << "m_engineRPM: " << std::to_string(data.m_engineRPM) << "\n"
                   << "m_drs: " << std::to_string(data.m_drs) << "\n"
                   << "m_revLightsPercent: " << std::to_string(data.m_revLightsPercent) << "\n"
                   << "m_revLightsBitValue: " << std::to_string(data.m_revLightsBitValue) << "\n"
                   << "m_brakesTemperature: " << util::to_string(data.m_brakesTemperature) << "\n"
                   << "m_tyresSurfaceTemperature: " << util::to_string(data.m_tyresSurfaceTemperature) << "\n"
                   << "m_tyresInnerTemperature: " << util::to_string(data.m_tyresInnerTemperature) << "\n"
                   << "m_engineTemperature: " << std::to_string(data.m_engineTemperature) << "\n"
                   << "m_tyresPressure: " << util::to_string(data.m_tyresPressure) << "\n"
                   << "m_surfaceType: " << util::to_string(data.m_surfaceType);

                return os;
            }
        };

    public:
        PacketHeader m_header;
        std::array<Data, 22> m_carTelemetryData;
        /// Index of MFD panel open (255 = MFD closed)
        /// Single player, race – 0 = Car setup, 1 = Pits, 2 = Damage, 3 = Engine, 4 = Temperatures
        /// May vary depending on game mode
        uint8 m_mfdPanelIndex;
        /// Secondary player, race – 0 = Car setup, 1 = Pits, 2 = Damage, 3 = Engine, 4 = Temperatures
        /// May vary depending on game mode
        uint8 m_mfdPanelIndexSecondaryPlayer;
        /// Suggested gear for the player (1-8) - 0 if no gear suggested
        int8 m_suggestedGear;

        friend std::ostream &operator<<(std::ostream &os, const PacketCarTelemetryData &data) {
            os << "m_header: " << "\n" << data.m_header << "\n"
               << "m_mfdPanelIndex: " << std::to_string(data.m_mfdPanelIndex) << "\n"
               << "m_mfdPanelIndexSecondaryPlayer: " << std::to_string(data.m_mfdPanelIndexSecondaryPlayer) << "\n"
               << "m_suggestedGear: " << std::to_string(data.m_suggestedGear) << "\n"
               << "m_carTelemetryData: " << "\n\n";

            for (size_t i = 0; i < data.m_carTelemetryData.size(); ++i) {
                os << "Car " << std::to_string(i) << ": " << "\n";
                os << data.m_carTelemetryData[i] << (i < data.m_carTelemetryData.size() - 1 ? "\n\n" : "");
            }

            return os;
        }
    };
}

#pragma pack()
