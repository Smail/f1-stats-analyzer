#pragma once

#include <ostream>
#include <string>
#include <array>
#include "PacketHeader.h"

#pragma pack(1)

namespace F122::Network {
    /// The session packet includes details about the current session in progress.<br>
    /// <br>
    /// Frequency: 2 per second<br>
    /// Size: 632 bytes<br>
    /// Version: 1<br>
    struct PacketSessionData {
        struct MarshalZone {
            /// Fraction (0..1) of way through the lap the marshal zone starts
            float m_zoneStart;
            /// -1 = invalid/unknown, 0 = none, 1 = green, 2 = blue, 3 = yellow, 4 = red
            int8 m_zoneFlag;

            friend std::ostream &operator<<(std::ostream &os, const MarshalZone &zone) {
                os << "m_zoneStart: " << std::to_string(zone.m_zoneStart) << "\n"
                   << "m_zoneFlag: " << std::to_string(zone.m_zoneFlag);
                return os;
            }
        };

        struct WeatherForecastSample {
            /// 0 = unknown, 1 = P1, 2 = P2, 3 = P3, 4 = Short P, 5 = Q1
            /// 6 = Q2, 7 = Q3, 8 = Short Q, 9 = OSQ, 10 = R, 11 = R2
            /// 12 = R3, 13 = Time Trial
            uint8 m_sessionType;
            /// Time in minutes the forecast is for
            uint8 m_timeOffset;
            /// Weather - 0 = clear, 1 = light cloud, 2 = overcast, 3 = light rain, 4 = heavy rain, 5 = storm
            uint8 m_weather;
            /// Track temp. in degrees Celsius
            int8 m_trackTemperature;
            /// Track temp. change – 0 = up, 1 = down, 2 = no change
            int8 m_trackTemperatureChange;
            /// Air temp. in degrees celsius
            int8 m_airTemperature;
            /// Air temp. change – 0 = up, 1 = down, 2 = no change
            int8 m_airTemperatureChange;
            /// Rain percentage (0-100)
            uint8 m_rainPercentage;

            friend std::ostream &operator<<(std::ostream &os, const WeatherForecastSample &forecastSample) {
                os << "m_sessionType: " << std::to_string(forecastSample.m_sessionType) << "\n"
                   << "m_timeOffset: " << std::to_string(forecastSample.m_timeOffset) << "\n"
                   << "m_weather: " << std::to_string(forecastSample.m_weather) << "\n"
                   << "m_trackTemperature: " << std::to_string(forecastSample.m_trackTemperature) << "\n"
                   << "m_trackTemperatureChange: " << std::to_string(forecastSample.m_trackTemperatureChange) << "\n"
                   << "m_airTemperature: " << std::to_string(forecastSample.m_airTemperature) << "\n"
                   << "m_airTemperatureChange: " << std::to_string(forecastSample.m_airTemperatureChange) << "\n"
                   << "m_rainPercentage: " << std::to_string(forecastSample.m_rainPercentage);
                return os;
            }
        };

    public:
        PacketHeader m_header;
        /// Weather - 0 = clear, 1 = light cloud, 2 = overcast, 3 = light rain, 4 = heavy rain, 5 = storm
        uint8 m_weather;
        /// Track temp. in degrees celsius
        int8 m_trackTemperature;
        /// Air temp. in degrees celsius
        int8 m_airTemperature;
        /// Total number of laps in this race
        uint8 m_totalLaps;
        /// Track length in metres
        uint16 m_trackLength;
        /// 0 = unknown, 1 = P1, 2 = P2, 3 = P3, 4 = Short P
        /// 5 = Q1, 6 = Q2, 7 = Q3, 8 = Short Q, 9 = OSQ
        /// 10 = R, 11 = R2, 12 = R3, 13 = Time Trial
        uint8 m_sessionType;
        /// -1 for unknown, see appendix
        int8 m_trackId;
        /// Formula, 0 = F1 Modern, 1 = F1 Classic, 2 = F2,
        /// 3 = F1 Generic, 4 = Beta, 5 = Supercars
        /// 6 = Esports, 7 = F2 2021
        uint8 m_formula;
        /// Time left in session in seconds
        uint16 m_sessionTimeLeft;
        /// Session duration in seconds
        uint16 m_sessionDuration;
        /// Pit speed limit in kilometres per hour
        uint8 m_pitSpeedLimit;
        /// Whether the game is paused – network game only
        uint8 m_gamePaused;
        /// Whether the player is spectating
        uint8 m_isSpectating;
        /// Index of the car being spectated
        uint8 m_spectatorCarIndex;
        /// SLI Pro support, 0 = inactive, 1 = active
        uint8 m_sliProNativeSupport;
        /// Number of marshal zones to follow
        uint8 m_numMarshalZones;
        /// List of marshal zones – max 21
        std::array<MarshalZone, 21> m_marshalZones;
        /// 0 = no safety car, 1 = full
        /// 2 = virtual, 3 = formation lap
        uint8 m_safetyCarStatus;
        /// 0 = offline, 1 = online
        uint8 m_networkGame;
        /// Number of weather samples to follow
        uint8 m_numWeatherForecastSamples;
        /// Array of weather forecast samples
        std::array<WeatherForecastSample, 56> m_weatherForecastSamples;
        /// 0 = Perfect, 1 = Approximate
        uint8 m_forecastAccuracy;
        /// AI Difficulty rating – 0-110
        uint8 m_aiDifficulty;
        /// Identifier for season - persists across saves
        uint32 m_seasonLinkIdentifier;
        /// Identifier for weekend - persists across saves
        uint32 m_weekendLinkIdentifier;
        /// Identifier for session - persists across saves
        uint32 m_sessionLinkIdentifier;
        /// Ideal lap to pit on for current strategy (player)
        uint8 m_pitStopWindowIdealLap;
        /// Latest lap to pit on for current strategy (player)
        uint8 m_pitStopWindowLatestLap;
        /// Predicted position to rejoin at (player)
        uint8 m_pitStopRejoinPosition;
        /// 0 = off, 1 = on
        uint8 m_steeringAssist;
        /// 0 = off, 1 = low, 2 = medium, 3 = high
        uint8 m_brakingAssist;
        /// 1 = manual, 2 = manual & suggested gear, 3 = auto
        uint8 m_gearboxAssist;
        /// 0 = off, 1 = on
        uint8 m_pitAssist;
        /// 0 = off, 1 = on
        uint8 m_pitReleaseAssist;
        /// 0 = off, 1 = on
        uint8 m_ERSAssist;
        /// 0 = off, 1 = on
        uint8 m_DRSAssist;
        /// 0 = off, 1 = corners only, 2 = full
        uint8 m_dynamicRacingLine;
        /// 0 = 2D, 1 = 3D
        uint8 m_dynamicRacingLineType;
        /// Game mode id - see appendix
        uint8 m_gameMode;
        /// Ruleset - see appendix
        uint8 m_ruleSet;
        /// Local time of day - minutes since midnight
        uint32 m_timeOfDay;
        /// 0 = None, 2 = Very Short, 3 = Short, 4 = Medium, 5 = Medium Long, 6 = Long, 7 = Full
        uint8 m_sessionLength;

        friend std::ostream &operator<<(std::ostream &os, const PacketSessionData &data) {
            os << "m_header: " << "\n" << data.m_header << "\n"
               << "m_weather: " << std::to_string(data.m_weather) << "\n"
               << "m_trackTemperature: " << std::to_string(data.m_trackTemperature) << "\n"
               << "m_airTemperature: " << std::to_string(data.m_airTemperature) << "\n"
               << "m_totalLaps: " << std::to_string(data.m_totalLaps) << "\n"
               << "m_trackLength: " << std::to_string(data.m_trackLength) << "\n"
               << "m_sessionType: " << std::to_string(data.m_sessionType) << "\n"
               << "m_trackId: " << std::to_string(data.m_trackId) << "\n"
               << "m_formula: " << std::to_string(data.m_formula) << "\n"
               << "m_sessionTimeLeft: " << std::to_string(data.m_sessionTimeLeft) << "\n"
               << "m_sessionDuration: " << std::to_string(data.m_sessionDuration) << "\n"
               << "m_pitSpeedLimit: " << std::to_string(data.m_pitSpeedLimit) << "\n"
               << "m_gamePaused: " << std::to_string(data.m_gamePaused) << "\n"
               << "m_isSpectating: " << std::to_string(data.m_isSpectating) << "\n"
               << "m_spectatorCarIndex: " << std::to_string(data.m_spectatorCarIndex) << "\n"
               << "m_sliProNativeSupport: " << std::to_string(data.m_sliProNativeSupport) << "\n"
               << "m_numMarshalZones: " << std::to_string(data.m_numMarshalZones) << "\n"
               << "m_marshalZones: " << "\n\n";

            for (size_t i = 0; i < data.m_marshalZones.size(); ++i) {
                os << "Marshal Zone " << std::to_string(i) << ": " << "\n"
                   << data.m_marshalZones[i] << "\n"
                   << (i < data.m_marshalZones.size() - 1 ? "\n\n" : "\n");
            }

            os << "m_safetyCarStatus: " << std::to_string(data.m_safetyCarStatus) << "\n"
               << "m_networkGame: " << std::to_string(data.m_networkGame) << "\n"
               << "m_numWeatherForecastSamples: " << std::to_string(data.m_numWeatherForecastSamples) << "\n"
               << "m_weatherForecastSamples: " << "\n\n";

            for (size_t i = 0; i < data.m_weatherForecastSamples.size(); ++i) {
                os << "Weather Forecast Samples Zone " << std::to_string(i) << ": " << "\n\n"
                   << data.m_weatherForecastSamples[i]
                   << (i < data.m_weatherForecastSamples.size() - 1 ? "\n\n" : "\n");
            }

            os << "m_forecastAccuracy: " << std::to_string(data.m_forecastAccuracy) << "\n"
               << "m_aiDifficulty: " << std::to_string(data.m_aiDifficulty) << "\n"
               << "m_seasonLinkIdentifier: " << std::to_string(data.m_seasonLinkIdentifier) << "\n"
               << "m_weekendLinkIdentifier: " << std::to_string(data.m_weekendLinkIdentifier) << "\n"
               << "m_sessionLinkIdentifier: " << std::to_string(data.m_sessionLinkIdentifier) << "\n"
               << "m_pitStopWindowIdealLap: " << std::to_string(data.m_pitStopWindowIdealLap) << "\n"
               << "m_pitStopWindowLatestLap: " << std::to_string(data.m_pitStopWindowLatestLap) << "\n"
               << "m_pitStopRejoinPosition: " << std::to_string(data.m_pitStopRejoinPosition) << "\n"
               << "m_steeringAssist: " << std::to_string(data.m_steeringAssist) << "\n"
               << "m_brakingAssist: " << std::to_string(data.m_brakingAssist) << "\n"
               << "m_gearboxAssist: " << std::to_string(data.m_gearboxAssist) << "\n"
               << "m_pitAssist: " << std::to_string(data.m_pitAssist) << "\n"
               << "m_pitReleaseAssist: " << std::to_string(data.m_pitReleaseAssist) << "\n"
               << "m_ERSAssist: " << std::to_string(data.m_ERSAssist) << "\n"
               << "m_DRSAssist: " << std::to_string(data.m_DRSAssist) << "\n"
               << "m_dynamicRacingLine: " << std::to_string(data.m_dynamicRacingLine) << "\n"
               << "m_dynamicRacingLineType: " << std::to_string(data.m_dynamicRacingLineType) << "\n"
               << "m_gameMode: " << std::to_string(data.m_gameMode) << "\n"
               << "m_ruleSet: " << std::to_string(data.m_ruleSet) << "\n"
               << "m_timeOfDay: " << std::to_string(data.m_timeOfDay) << "\n"
               << "m_sessionLength: " << std::to_string(data.m_sessionLength);

            return os;
        }
    };
}

#pragma pack()
