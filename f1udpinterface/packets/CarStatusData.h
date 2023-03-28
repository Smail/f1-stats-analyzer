#pragma once

#include <cstdint>
#include "PacketHeader.h"
#include "Packet.h"

namespace F122::Network::Packets {
    /// This packet details car statuses for all the cars in the race.<br>
    /// <br>
    /// Frequency: Rate as specified in menus<br>
    /// Size: 1058 bytes<br>
    /// Version: 1<br>
    struct CarStatusData : public Packet {
        struct Data {
            static constexpr size_t SIZE = 47;

            Data() = default;

            explicit Data(const std::array<std::uint8_t, SIZE>& bytes);

            [[nodiscard]] bool is_drs_available() const;

            [[nodiscard]] std::uint16_t distance_to_next_drs_zone() const;

            [[nodiscard]] std::string tractionControlString() const;

            [[nodiscard]] std::string fuelMixString() const;

            [[nodiscard]] std::string fiaFlags() const;

            [[nodiscard]] std::string ers_deploy_mode() const;

            friend std::ostream& operator<<(std::ostream& os, const Data& data);

            /// Traction control: 0 = off, 1 = medium, 2 = full
            std::uint8_t m_tractionControl;
            /// 0 = off, 1 = on
            std::uint8_t m_antiLockBrakes;
            /// Fuel mix: 0 = lean, 1 = standard, 2 = rich, 3 = max
            std::uint8_t m_fuelMix;
            /// Front brake bias (percentage)
            std::uint8_t m_frontBrakeBias;
            /// Pit limiter status: 0 = off, 1 = on
            std::uint8_t m_pitLimiterStatus;
            /// Current fuel mass
            float m_fuelInTank;
            /// Fuel capacity
            float m_fuelCapacity;
            /// Fuel remaining in terms of laps (value on MFD)
            float m_fuelRemainingLaps;
            /// Cars max RPM, point of rev limiter
            std::uint16_t m_maxRPM;
            /// Cars idle RPM
            std::uint16_t m_idleRPM;
            /// Maximum number of gears
            std::uint8_t m_maxGears;
            /// 0 = not allowed, 1 = allowed
            std::uint8_t m_drsAllowed;
            /// 0 = DRS not available, non-zero - DRS will be available, in [X] metres
            std::uint16_t m_drsActivationDistance;
            /// F1 Modern -
            /// 16 = C5, 17 = C4, 18 = C3, 19 = C2, 20 = C1, 7 = inter, 8 = wet
            /// F1 Classic -
            /// 9 = dry, 10 = wet, F2 – 11 = super soft, 12 = soft, 13 = medium, 14 = hard, 15 = wet
            std::uint8_t m_actualTyreCompound;
            /// F1 visual (can be different from actual compound)
            /// 16 = soft, 17 = medium, 18 = hard, 7 = inter, 8 = wet
            /// F1 Classic – same as above
            /// F2 ‘19, 15 = wet, 19 – super soft, 20 = soft, 21 = medium , 22 = hard
            std::uint8_t m_visualTyreCompound;
            /// Age in laps of the current set of tyres
            std::uint8_t m_tyresAgeLaps;
            /// -1 = invalid/unknown, 0 = none, 1 = green, 2 = blue, 3 = yellow, 4 = red
            std::int8_t m_vehicleFiaFlags;
            /// ERS energy store in Joules
            float m_ersStoreEnergy;
            /// ERS deployment mode, 0 = none, 1 = medium, 2 = hotlap, 3 = overtake
            std::uint8_t m_ersDeployMode;
            /// ERS energy harvested this lap by MGU-K
            float m_ersHarvestedThisLapMGUK;
            /// ERS energy harvested this lap by MGU-H
            float m_ersHarvestedThisLapMGUH;
            /// ERS energy deployed this lap
            float m_ersDeployedThisLap;
            /// Whether the car is paused in a network game
            std::uint8_t m_networkPaused;
        };

    public:
        static constexpr size_t SIZE = PacketHeader::SIZE + 22 * Data::SIZE;

        explicit CarStatusData(const std::array<std::uint8_t, SIZE>& bytes);

        ~CarStatusData() override;

        friend std::ostream& operator<<(std::ostream& os, const CarStatusData& data);

        PacketHeader m_header;
        std::array<Data, 22> m_carStatusData;

        static_assert(SIZE == 1058, "Invalid size");
        static_assert(PacketHeader::SIZE + 22 * Data::SIZE == SIZE, "Invalid size 2");
    };

    std::ostream& operator<<(std::ostream& os, const CarStatusData& data);

    std::ostream& operator<<(std::ostream& os, const CarStatusData::Data& data);
}
