#pragma once

#include <cstdint>
#include <ostream>
#include <string>
#include <array>
#include "PacketHeader.h"
#include "Packet.h"

namespace F122::Network::Packets {
    /// The session packet includes details about the current session in progress.<br>
    /// <br>
    /// Frequency: 2 per second<br>
    /// Size: 632 bytes<br>
    /// Version: 1<br>
    struct SessionData : public Packet {
        struct MarshalZone {
            static constexpr size_t SIZE = 5;

            MarshalZone() = default;

            explicit MarshalZone(const std::array<std::uint8_t, SIZE>& bytes);

            /// Fraction (0..1) of way through the lap the marshal zone starts
            float m_zoneStart;
            /// -1 = invalid/unknown, 0 = none, 1 = green, 2 = blue, 3 = yellow, 4 = red
            std::int8_t m_zoneFlag;

            friend std::ostream& operator<<(std::ostream& os, const MarshalZone& zone);
        };

        struct WeatherForecastSample {
            static constexpr size_t SIZE = 8;

            WeatherForecastSample() = default;

            explicit WeatherForecastSample(const std::array<std::uint8_t, SIZE>& bytes);

            friend std::ostream& operator<<(std::ostream& os, const WeatherForecastSample& forecastSample);

            /// 0 = unknown, 1 = P1, 2 = P2, 3 = P3, 4 = Short P, 5 = Q1
            /// 6 = Q2, 7 = Q3, 8 = Short Q, 9 = OSQ, 10 = R, 11 = R2
            /// 12 = R3, 13 = Time Trial
            std::uint8_t m_sessionType;
            /// Time in minutes the forecast is for
            std::uint8_t m_timeOffset;
            /// Weather - 0 = clear, 1 = light cloud, 2 = overcast, 3 = light rain, 4 = heavy rain, 5 = storm
            std::uint8_t m_weather;
            /// Track temp. in degrees Celsius
            std::int8_t m_trackTemperature;
            /// Track temp. change – 0 = up, 1 = down, 2 = no change
            std::int8_t m_trackTemperatureChange;
            /// Air temp. in degrees celsius
            std::int8_t m_airTemperature;
            /// Air temp. change – 0 = up, 1 = down, 2 = no change
            std::int8_t m_airTemperatureChange;
            /// Rain percentage (0-100)
            std::uint8_t m_rainPercentage;
        };

    public:
        static constexpr size_t SIZE = PacketHeader::SIZE + 21 * MarshalZone::SIZE +
                                       56 * WeatherForecastSample::SIZE + 55;

        explicit SessionData(const std::array<std::uint8_t, SIZE>& bytes);

        ~SessionData() override;

        friend std::ostream& operator<<(std::ostream& os, const SessionData& data);

        PacketHeader m_header;
        /// Weather - 0 = clear, 1 = light cloud, 2 = overcast, 3 = light rain, 4 = heavy rain, 5 = storm
        std::uint8_t m_weather;
        /// Track temp. in degrees celsius
        std::int8_t m_trackTemperature;
        /// Air temp. in degrees celsius
        std::int8_t m_airTemperature;
        /// Total number of laps in this race
        std::uint8_t m_totalLaps;
        /// Track length in metres
        std::uint16_t m_trackLength;
        /// 0 = unknown, 1 = P1, 2 = P2, 3 = P3, 4 = Short P
        /// 5 = Q1, 6 = Q2, 7 = Q3, 8 = Short Q, 9 = OSQ
        /// 10 = R, 11 = R2, 12 = R3, 13 = Time Trial
        std::uint8_t m_sessionType;
        /// -1 for unknown, see appendix
        std::int8_t m_trackId;
        /// Formula, 0 = F1 Modern, 1 = F1 Classic, 2 = F2,
        /// 3 = F1 Generic, 4 = Beta, 5 = Supercars
        /// 6 = Esports, 7 = F2 2021
        std::uint8_t m_formula;
        /// Time left in session in seconds
        std::uint16_t m_sessionTimeLeft;
        /// Session duration in seconds
        std::uint16_t m_sessionDuration;
        /// Pit speed limit in kilometres per hour
        std::uint8_t m_pitSpeedLimit;
        /// Whether the game is paused – network game only
        std::uint8_t m_gamePaused;
        /// Whether the player is spectating
        std::uint8_t m_isSpectating;
        /// Index of the car being spectated
        std::uint8_t m_spectatorCarIndex;
        /// SLI Pro support, 0 = inactive, 1 = active
        std::uint8_t m_sliProNativeSupport;
        /// Number of marshal zones to follow
        std::uint8_t m_numMarshalZones;
        /// List of marshal zones – max 21
        std::array<MarshalZone, 21> m_marshalZones;
        /// 0 = no safety car, 1 = full
        /// 2 = virtual, 3 = formation lap
        std::uint8_t m_safetyCarStatus;
        /// 0 = offline, 1 = online
        std::uint8_t m_networkGame;
        /// Number of weather samples to follow
        std::uint8_t m_numWeatherForecastSamples;
        /// Array of weather forecast samples
        std::array<WeatherForecastSample, 56> m_weatherForecastSamples;
        /// 0 = Perfect, 1 = Approximate
        std::uint8_t m_forecastAccuracy;
        /// AI Difficulty rating – 0-110
        std::uint8_t m_aiDifficulty;
        /// Identifier for season - persists across saves
        std::uint32_t m_seasonLinkIdentifier;
        /// Identifier for weekend - persists across saves
        std::uint32_t m_weekendLinkIdentifier;
        /// Identifier for session - persists across saves
        std::uint32_t m_sessionLinkIdentifier;
        /// Ideal lap to pit on for current strategy (player)
        std::uint8_t m_pitStopWindowIdealLap;
        /// Latest lap to pit on for current strategy (player)
        std::uint8_t m_pitStopWindowLatestLap;
        /// Predicted position to rejoin at (player)
        std::uint8_t m_pitStopRejoinPosition;
        /// 0 = off, 1 = on
        std::uint8_t m_steeringAssist;
        /// 0 = off, 1 = low, 2 = medium, 3 = high
        std::uint8_t m_brakingAssist;
        /// 1 = manual, 2 = manual & suggested gear, 3 = auto
        std::uint8_t m_gearboxAssist;
        /// 0 = off, 1 = on
        std::uint8_t m_pitAssist;
        /// 0 = off, 1 = on
        std::uint8_t m_pitReleaseAssist;
        /// 0 = off, 1 = on
        std::uint8_t m_ERSAssist;
        /// 0 = off, 1 = on
        std::uint8_t m_DRSAssist;
        /// 0 = off, 1 = corners only, 2 = full
        std::uint8_t m_dynamicRacingLine;
        /// 0 = 2D, 1 = 3D
        std::uint8_t m_dynamicRacingLineType;
        /// Game mode id - see appendix
        std::uint8_t m_gameMode;
        /// Ruleset - see appendix
        std::uint8_t m_ruleSet;
        /// Local time of day - minutes since midnight
        std::uint32_t m_timeOfDay;
        /// 0 = None, 2 = Very Short, 3 = Short, 4 = Medium, 5 = Medium Long, 6 = Long, 7 = Full
        std::uint8_t m_sessionLength;

        static_assert(SIZE == 632, "Invalid size");
        static_assert(PacketHeader::SIZE + sizeof(m_weather) + sizeof(m_trackTemperature) + sizeof(m_airTemperature) +
                      sizeof(m_totalLaps) + sizeof(m_trackLength) + sizeof(m_sessionType) + sizeof(m_sessionLength) +
                      sizeof(m_trackId) + sizeof(m_formula) + sizeof(m_sessionTimeLeft) + sizeof(m_sessionDuration) +
                      sizeof(m_pitSpeedLimit) + sizeof(m_gamePaused) + sizeof(m_isSpectating) + sizeof(m_timeOfDay) +
                      sizeof(m_spectatorCarIndex) + sizeof(m_sliProNativeSupport) + sizeof(m_numMarshalZones) +
                      sizeof(m_safetyCarStatus) + sizeof(m_networkGame) + sizeof(m_numWeatherForecastSamples) +
                      sizeof(m_forecastAccuracy) + sizeof(m_aiDifficulty) + sizeof(m_seasonLinkIdentifier) +
                      sizeof(m_weekendLinkIdentifier) + sizeof(m_sessionLinkIdentifier) + sizeof(m_DRSAssist) +
                      sizeof(m_pitStopWindowIdealLap) + sizeof(m_pitStopWindowLatestLap) + sizeof(m_ERSAssist) +
                      sizeof(m_pitStopRejoinPosition) + sizeof(m_steeringAssist) + sizeof(m_brakingAssist) +
                      sizeof(m_gearboxAssist) + sizeof(m_pitAssist) + sizeof(m_pitReleaseAssist) + sizeof(m_ruleSet) +
                      sizeof(m_dynamicRacingLine) + sizeof(m_dynamicRacingLineType) + sizeof(m_gameMode) +
                      (21 * MarshalZone::SIZE) + (56 * WeatherForecastSample::SIZE) == SIZE, "Invalid size 2");
    };

    std::ostream& operator<<(std::ostream& os, const SessionData& data);

    std::ostream& operator<<(std::ostream& os, const SessionData::MarshalZone& zone);

    std::ostream& operator<<(std::ostream& os, const SessionData::WeatherForecastSample& forecastSample);
}
