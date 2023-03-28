#include "../CarTelemetryData.h"
#include "../../../util.h"
#include "../../ids/SurfaceTypeId.h"
#include <algorithm>
#include <bitset>

namespace F122::Network::Packets {
    CarTelemetryData::Data::Data(const std::array<std::uint8_t, SIZE>& bytes) :
            m_speed{util::convert<std::uint16_t>({bytes[0], bytes[1]})},
            m_throttle{util::convert<float>({bytes[2], bytes[3], bytes[4], bytes[5]})},
            m_steer{util::convert<float>({bytes[6], bytes[7], bytes[8], bytes[9]})},
            m_brake{util::convert<float>({bytes[10], bytes[11], bytes[12], bytes[13]})},
            m_clutch{bytes[14]},
            m_gear{static_cast<std::int8_t>(bytes[15])},
            m_engineRPM{util::convert<std::uint16_t>({bytes[16], bytes[17]})},
            m_drs{bytes[18]},
            m_revLightsPercent{bytes[19]},
            m_revLightsBitValue{util::convert<std::uint16_t>({bytes[20], bytes[21]})},
            m_brakesTemperature{
                    {
                            util::convert<std::uint16_t>({bytes[22], bytes[23]}),
                            util::convert<std::uint16_t>({bytes[24], bytes[25]}),
                            util::convert<std::uint16_t>({bytes[26], bytes[27]}),
                            util::convert<std::uint16_t>({bytes[28], bytes[29]})
                    },
            },
            m_tyresSurfaceTemperature{{bytes[30], bytes[31], bytes[32], bytes[33]}},
            m_tyresInnerTemperature{{bytes[34], bytes[35], bytes[36], bytes[37]}},
            m_engineTemperature{util::convert<std::uint16_t>({bytes[38], bytes[39]})},
            m_tyresPressure{
                    util::convert<float>({bytes[40], bytes[41], bytes[42], bytes[43]}),
                    util::convert<float>({bytes[44], bytes[45], bytes[46], bytes[47]}),
                    util::convert<float>({bytes[48], bytes[49], bytes[50], bytes[51]}),
                    util::convert<float>({bytes[52], bytes[53], bytes[54], bytes[55]})},
            m_surfaceType{{bytes[56], bytes[57], bytes[58], bytes[59]}} {}

    CarTelemetryData::CarTelemetryData(const std::array<std::uint8_t, SIZE>& bytes) :
            Packet(bytes),
            m_header{{util::copy_resize<std::uint8_t, SIZE, PacketHeader::SIZE>(bytes)}},
            m_carTelemetryData{util::batch_create<Data, SIZE, Data::SIZE, 22, PacketHeader::SIZE>(bytes)},
            m_mfdPanelIndex{bytes[22 * Data::SIZE + PacketHeader::SIZE]},
            m_mfdPanelIndexSecondaryPlayer{bytes[22 * Data::SIZE + PacketHeader::SIZE + 1]},
            m_suggestedGear{static_cast<std::int8_t>(bytes[22 * Data::SIZE + PacketHeader::SIZE + 2])} {}

    CarTelemetryData::~CarTelemetryData() = default;

    bool CarTelemetryData::Data::is_drs_open() const {
        return m_drs == 1;
    }

    std::ostream& operator<<(std::ostream& os, const CarTelemetryData& data) {
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

    std::ostream& operator<<(std::ostream& os, const CarTelemetryData::Data& data) {
        os << "m_speed: " << std::to_string(data.m_speed) << " km/h" << "\n"
           << "m_throttle: " << std::to_string(data.m_throttle) << "\n"
           << "m_steer: " << std::to_string(data.m_steer) << "\n"
           << "m_brake: " << std::to_string(data.m_brake) << "\n"
           << "m_clutch: " << std::to_string(data.m_clutch) << "\n"
           << "m_gear: " << std::to_string(data.m_gear) << "\n"
           << "m_engineRPM: " << std::to_string(data.m_engineRPM) << "\n"
           << "m_drs: " << std::boolalpha << std::to_string(data.m_drs) << std::noboolalpha << "\n"
           << "m_revLightsPercent: " << std::to_string(data.m_revLightsPercent) << "%" << "\n"
           << "m_revLightsBitValue: " << std::bitset<16>(data.m_revLightsBitValue) << "\n"
           << "m_brakesTemperature: " << "["
           << data.m_brakesTemperature[0] << " Celsius" << ", "
           << data.m_brakesTemperature[1] << " Celsius"<< ", "
           << data.m_brakesTemperature[2] << " Celsius"<< ", "
           << data.m_brakesTemperature[3] << " Celsius"<< ", "
           << "]\n"
           << "m_tyresSurfaceTemperature: " << "["
           << data.m_tyresSurfaceTemperature[0] << " Celsius" << ", "
           << data.m_tyresSurfaceTemperature[1] << " Celsius"<< ", "
           << data.m_tyresSurfaceTemperature[2] << " Celsius"<< ", "
           << data.m_tyresSurfaceTemperature[3] << " Celsius"<< ", "
           << "]\n"
           << "m_tyresInnerTemperature: " << "["
           << data.m_tyresInnerTemperature[0] << " Celsius" << ", "
           << data.m_tyresInnerTemperature[1] << " Celsius"<< ", "
           << data.m_tyresInnerTemperature[2] << " Celsius"<< ", "
           << data.m_tyresInnerTemperature[3] << " Celsius"<< ", "
           << "]\n"
           << "m_engineTemperature: " << std::to_string(data.m_engineTemperature) << " Celsius" << "\n"
           << "m_tyresPressure: " << "["
           << data.m_tyresPressure[0] << " PSI" << ", "
           << data.m_tyresPressure[1] << " PSI"<< ", "
           << data.m_tyresPressure[2] << " PSI"<< ", "
           << data.m_tyresPressure[3] << " PSI"<< ", "
           << "]\n"
           << "m_surfaceType: " << "["
           << F122::to_string(static_cast<SurfaceTypeId>(data.m_surfaceType[0])) << ", "
           << F122::to_string(static_cast<SurfaceTypeId>(data.m_surfaceType[1])) << ", "
           << F122::to_string(static_cast<SurfaceTypeId>(data.m_surfaceType[2])) << ", "
           << F122::to_string(static_cast<SurfaceTypeId>(data.m_surfaceType[3])) << ", "
           << "]\n";

        return os;
    }
}
