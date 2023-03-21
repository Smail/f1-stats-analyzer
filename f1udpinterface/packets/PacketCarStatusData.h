#pragma once

#include "PacketHeader.h"

#pragma pack(1)

namespace F122::Network {
    /// This packet details car statuses for all the cars in the race.<br>
    /// <br>
    /// Frequency: Rate as specified in menus<br>
    /// Size: 1058 bytes<br>
    /// Version: 1<br>
    struct PacketCarStatusData {
        struct Data {
            /// Traction control - 0 = off, 1 = medium, 2 = full
            uint8 m_tractionControl;
            /// 0 (off) - 1 (on)
            uint8 m_antiLockBrakes;
            /// Fuel mix - 0 = lean, 1 = standard, 2 = rich, 3 = max
            uint8 m_fuelMix;
            /// Front brake bias (percentage)
            uint8 m_frontBrakeBias;
            /// Pit limiter status - 0 = off, 1 = on
            uint8 m_pitLimiterStatus;
            /// Current fuel mass
            float m_fuelInTank;
            /// Fuel capacity
            float m_fuelCapacity;
            /// Fuel remaining in terms of laps (value on MFD)
            float m_fuelRemainingLaps;
            /// Cars max RPM, point of rev limiter
            uint16 m_maxRPM;
            /// Cars idle RPM
            uint16 m_idleRPM;
            /// Maximum number of gears
            uint8 m_maxGears;
            /// 0 = not allowed, 1 = allowed
            uint8 m_drsAllowed;
            /// 0 = DRS not available, non-zero - DRS will be available, in [X] metres
            uint16 m_drsActivationDistance;
            /// F1 Modern -
            /// 16 = C5, 17 = C4, 18 = C3, 19 = C2, 20 = C1, 7 = inter, 8 = wet
            /// F1 Classic -
            /// 9 = dry, 10 = wet, F2 – 11 = super soft, 12 = soft, 13 = medium, 14 = hard, 15 = wet
            uint8 m_actualTyreCompound;
            /// F1 visual (can be different from actual compound)
            /// 16 = soft, 17 = medium, 18 = hard, 7 = inter, 8 = wet
            /// F1 Classic – same as above
            /// F2 ‘19, 15 = wet, 19 – super soft, 20 = soft, 21 = medium , 22 = hard
            uint8 m_visualTyreCompound;
            /// Age in laps of the current set of tyres
            uint8 m_tyresAgeLaps;
            /// -1 = invalid/unknown, 0 = none, 1 = green, 2 = blue, 3 = yellow, 4 = red
            int8 m_vehicleFiaFlags;
            /// ERS energy store in Joules
            float m_ersStoreEnergy;
            /// ERS deployment mode, 0 = none, 1 = medium, 2 = hotlap, 3 = overtake
            uint8 m_ersDeployMode;
            /// ERS energy harvested this lap by MGU-K
            float m_ersHarvestedThisLapMGUK;
            /// ERS energy harvested this lap by MGU-H
            float m_ersHarvestedThisLapMGUH;
            /// ERS energy deployed this lap
            float m_ersDeployedThisLap;
            /// Whether the car is paused in a network game
            uint8 m_networkPaused;

            [[nodiscard]] bool is_drs_available() const {
                return m_drsActivationDistance > 0;
            }

            [[nodiscard]] uint16 distance_to_next_drs_zone() const {
                return m_drsActivationDistance;
            }

            [[nodiscard]] std::string ers_deploy_mode() const {
                switch (m_ersDeployMode) {
                    case 0:
                        return "None";
                    case 1:
                        return "Medium";
                    case 2:
                        return "Hotlap";
                    case 3:
                        return "Overtake";
                    default:
                        throw std::runtime_error(
                                "Invalid state: " + std::to_string(m_ersDeployMode) + " is not valid value");
                }
            }

            friend std::ostream &operator<<(std::ostream &os, const Data &data) {
                os << "m_tractionControl: " << std::to_string(data.m_tractionControl) << "\n"
                   << "m_antiLockBrakes: " << std::to_string(data.m_antiLockBrakes) << "\n"
                   << "m_fuelMix: " << std::to_string(data.m_fuelMix) << "\n"
                   << "m_frontBrakeBias: " << std::to_string(data.m_frontBrakeBias) << "\n"
                   << "m_pitLimiterStatus: " << std::to_string(data.m_pitLimiterStatus) << "\n"
                   << "m_fuelInTank: " << std::to_string(data.m_fuelInTank) << "\n"
                   << "m_fuelCapacity: " << std::to_string(data.m_fuelCapacity) << "\n"
                   << "m_fuelRemainingLaps: " << std::to_string(data.m_fuelRemainingLaps) << "\n"
                        << "m_maxRPM: " << std::to_string(data.m_maxRPM) << "\n"
                        << "m_idleRPM: " << std::to_string(data.m_idleRPM) << "\n"
                        << "m_maxGears: " << std::to_string(data.m_maxGears) << "\n"
                        << "m_drsAllowed: " << std::to_string(data.m_drsAllowed) << "\n"
                        << "m_drsActivationDistance: " << std::to_string(data.m_drsActivationDistance) << "\n"
                        << "m_actualTyreCompound: " << std::to_string(data.m_actualTyreCompound) << "\n"
                        << "m_visualTyreCompound: " << std::to_string(data.m_visualTyreCompound) << "\n"
                        << "m_tyresAgeLaps: " << std::to_string(data.m_tyresAgeLaps) << "\n"
                        << "m_vehicleFiaFlags: " << std::to_string(data.m_vehicleFiaFlags) << "\n"
                        << "m_ersStoreEnergy: " << std::to_string(data.m_ersStoreEnergy) << " Joules" << "\n"
                        << "m_ersDeployMode: " << data.ers_deploy_mode() << "\n"
                   << "m_ersHarvestedThisLapMGUK: " << std::to_string(data.m_ersHarvestedThisLapMGUK) << "\n"
                   << "m_ersHarvestedThisLapMGUH: " << std::to_string(data.m_ersHarvestedThisLapMGUH) << "\n"
                   << "m_ersDeployedThisLap: " << std::to_string(data.m_ersDeployedThisLap) << "\n"
                   << "m_networkPaused: " << std::to_string(data.m_networkPaused) << "\n";

                return os;
            }
        };

    public:
        PacketHeader m_header;
        std::array<Data, 22> m_carStatusData;

        friend std::ostream &operator<<(std::ostream &os, const PacketCarStatusData &data) {
            os << "m_header: " << "\n" << data.m_header << "\n"
               << "m_carStatusData: " << "\n\n";

            for (size_t i = 0; i < data.m_carStatusData.size(); ++i) {
                os << "Car " << std::to_string(i) << ": " << "\n";
                os << data.m_carStatusData[i] << (i < data.m_carStatusData.size() - 1 ? "\n" : "");
            }

            return os;
        }
    };
}

#pragma pack()
