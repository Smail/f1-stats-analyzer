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
            Data() = default;

            explicit Data(const std::array<std::uint8_t, 47>& bytes);

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

            [[nodiscard]] std::string ers_deploy_mode() const;

            friend std::ostream& operator<<(std::ostream& os, const Data& data);
        };

    public:
        explicit PacketCarStatusData(const std::array<std::uint8_t, 1058>& bytes);

        PacketHeader m_header;
        std::array<Data, 22> m_carStatusData;

        friend std::ostream& operator<<(std::ostream& os, const PacketCarStatusData& data);
    };

    std::ostream& operator<<(std::ostream& os, const PacketCarStatusData& data);

    std::ostream& operator<<(std::ostream& os, const PacketCarStatusData::Data& data);
}

#pragma pack()
