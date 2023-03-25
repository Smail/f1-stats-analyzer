#include "SessionData.h"
#include "../../util.h"

namespace F122::Network::Packets {
    SessionData::MarshalZone::MarshalZone(const std::array<std::uint8_t, SIZE>& bytes) :
            m_zoneStart{util::convert<float>({bytes[0], bytes[1], bytes[2], bytes[3]})},
            m_zoneFlag{static_cast<std::int8_t>(bytes[4])} {}

    SessionData::WeatherForecastSample::WeatherForecastSample(const std::array<std::uint8_t, SIZE>& bytes) :
            m_sessionType{bytes[0]},
            m_timeOffset{bytes[1]},
            m_weather{bytes[2]},
            m_trackTemperature{static_cast<std::int8_t>(bytes[3])},
            m_trackTemperatureChange{static_cast<std::int8_t>(bytes[4])},
            m_airTemperature{static_cast<std::int8_t>(bytes[5])},
            m_airTemperatureChange{static_cast<std::int8_t>(bytes[6])},
            m_rainPercentage{bytes[7]} {}

    SessionData::SessionData(const std::array<std::uint8_t, SIZE>& bytes) :
            m_header{{util::copy_resize<std::uint8_t, SIZE, PacketHeader::SIZE>(bytes)}},
            m_weather{bytes[24]},
            m_trackTemperature{static_cast<std::int8_t>(bytes[25])},
            m_airTemperature{static_cast<std::int8_t>(bytes[26])},
            m_totalLaps{bytes[27]},
            m_trackLength{util::convert<std::uint16_t>({bytes[28], bytes[29]})},
            m_sessionType{bytes[30]},
            m_trackId{static_cast<std::int8_t>(bytes[31])},
            m_formula{bytes[32]},
            m_sessionTimeLeft{util::convert<std::uint16_t>({bytes[33], bytes[34]})},
            m_sessionDuration{util::convert<std::uint16_t>({bytes[35], bytes[36]})},
            m_pitSpeedLimit{bytes[37]},
            m_gamePaused{bytes[38]},
            m_isSpectating{bytes[39]},
            m_spectatorCarIndex{bytes[40]},
            m_sliProNativeSupport{bytes[41]},
            m_numMarshalZones{bytes[42]},
            m_marshalZones{util::batch_create<MarshalZone, SIZE, MarshalZone::SIZE, 21, 43>(bytes)},
            m_safetyCarStatus{bytes[148]},
            m_networkGame{bytes[149]},
            m_numWeatherForecastSamples{bytes[150]},
            m_weatherForecastSamples{
                    util::batch_create<WeatherForecastSample, SIZE, WeatherForecastSample::SIZE, 56, 151>(bytes)},
            m_forecastAccuracy{bytes[599]},
            m_aiDifficulty{bytes[600]},
            m_seasonLinkIdentifier{util::convert<std::uint32_t>({bytes[601], bytes[602], bytes[603], bytes[604]})},
            m_weekendLinkIdentifier{util::convert<std::uint32_t>({bytes[605], bytes[606], bytes[607], bytes[608]})},
            m_sessionLinkIdentifier{util::convert<std::uint32_t>({bytes[609], bytes[610], bytes[611], bytes[612]})},
            m_pitStopWindowIdealLap{bytes[613]},
            m_pitStopWindowLatestLap{bytes[614]},
            m_pitStopRejoinPosition{bytes[615]},
            m_steeringAssist{bytes[616]},
            m_brakingAssist{bytes[617]},
            m_gearboxAssist{bytes[618]},
            m_pitAssist{bytes[619]},
            m_pitReleaseAssist{bytes[620]},
            m_ERSAssist{bytes[621]},
            m_DRSAssist{bytes[622]},
            m_dynamicRacingLine{bytes[623]},
            m_dynamicRacingLineType{bytes[624]},
            m_gameMode{bytes[625]},
            m_ruleSet{bytes[626]},
            m_timeOfDay{util::convert<std::uint32_t>({bytes[627], bytes[628], bytes[629], bytes[630]})},
            m_sessionLength{bytes[631]} {}

    std::ostream& operator<<(std::ostream& os, const SessionData::MarshalZone& zone) {
        os << "m_zoneStart: " << std::to_string(zone.m_zoneStart) << "\n"
           << "m_zoneFlag: " << std::to_string(zone.m_zoneFlag);

        return os;
    }

    std::ostream& operator<<(std::ostream& os, const SessionData::WeatherForecastSample& forecastSample) {
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

    std::ostream& operator<<(std::ostream& os, const SessionData& data) {
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
}
