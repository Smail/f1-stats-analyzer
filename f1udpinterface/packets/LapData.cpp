#include "LapData.h"
#include "../../util.h"

namespace F122::Network::Packets {
    LapData::Data::Data(const std::array<std::uint8_t, 43>& bytes) :
            m_lastLapTimeInMS{util::convert<std::uint32_t>({bytes[0], bytes[1], bytes[2], bytes[3]})},
            m_currentLapTimeInMS{util::convert<std::uint32_t>({bytes[4], bytes[5], bytes[6], bytes[7]})},
            m_sector1TimeInMS{util::convert<std::uint16_t>({bytes[8], bytes[9]})},
            m_sector2TimeInMS{util::convert<std::uint16_t>({bytes[10], bytes[11]})},
            m_lapDistance{util::convert<float>({bytes[12], bytes[13], bytes[14], bytes[15]})},
            m_totalDistance{util::convert<float>({bytes[16], bytes[17], bytes[18], bytes[19]})},
            m_safetyCarDelta{util::convert<float>({bytes[20], bytes[21], bytes[22], bytes[23]})},
            m_carPosition{bytes[24]},
            m_currentLapNum{bytes[25]},
            m_pitStatus{bytes[26]},
            m_numPitStops{bytes[27]},
            m_sector{bytes[28]},
            m_currentLapInvalid{bytes[29]},
            m_penalties{bytes[30]},
            m_warnings{bytes[31]},
            m_numUnservedDriveThroughPens{bytes[32]},
            m_numUnservedStopGoPens{bytes[33]},
            m_gridPosition{bytes[34]},
            m_driverStatus{bytes[35]},
            m_resultStatus{bytes[36]},
            m_pitLaneTimerActive{bytes[37]},
            m_pitLaneTimeInLaneInMS{util::convert<std::uint16_t>({bytes[38], bytes[39]})},
            m_pitStopTimerInMS{util::convert<std::uint16_t>({bytes[40], bytes[41]})},
            m_pitStopShouldServePen{bytes[42]} {}

    LapData::LapData(const std::array<std::uint8_t, SIZE>& bytes) :
            m_header{{util::copy_resize<std::uint8_t, SIZE, PacketHeader::SIZE>(bytes)}},
            m_lapData{util::batch_create<Data, SIZE, Data::SIZE, 22, PacketHeader::SIZE>(bytes)},
            m_timeTrialPBCarIdx{bytes[970]},
            m_timeTrialRivalCarIdx{bytes[971]} {}

    std::ostream& operator<<(std::ostream& os, const LapData::Data& data) {
        os << "m_lastLapTimeInMS: " << std::to_string(data.m_lastLapTimeInMS) << "\n"
           << "m_currentLapTimeInMS: " << std::to_string(data.m_currentLapTimeInMS) << "\n"
           << "m_sector1TimeInMS: " << std::to_string(data.m_sector1TimeInMS) << "\n"
           << "m_sector2TimeInMS: " << std::to_string(data.m_sector2TimeInMS) << "\n"
           << "m_lapDistance: " << std::to_string(data.m_lapDistance) << "\n"
           << "m_totalDistance: " << std::to_string(data.m_totalDistance) << "\n"
           << "m_safetyCarDelta: " << std::to_string(data.m_safetyCarDelta) << "\n"
           << "m_carPosition: " << std::to_string(data.m_carPosition) << "\n"
           << "m_currentLapNum: " << std::to_string(data.m_currentLapNum) << "\n"
           << "m_pitStatus: " << std::to_string(data.m_pitStatus) << "\n"
           << "m_numPitStops: " << std::to_string(data.m_numPitStops) << "\n"
           << "m_sector: " << std::to_string(data.m_sector) << "\n"
           << "m_currentLapInvalid: " << std::to_string(data.m_currentLapInvalid) << "\n"
           << "m_penalties: " << std::to_string(data.m_penalties) << "\n"
           << "m_warnings: " << std::to_string(data.m_warnings) << "\n"
           << "m_numUnservedDriveThroughPens: " << std::to_string(data.m_numUnservedDriveThroughPens) << "\n"
           << "m_numUnservedStopGoPens: " << std::to_string(data.m_numUnservedStopGoPens) << "\n"
           << "m_gridPosition: " << std::to_string(data.m_gridPosition) << "\n"
           << "m_driverStatus: " << std::to_string(data.m_driverStatus) << "\n"
           << "m_resultStatus: " << std::to_string(data.m_resultStatus) << "\n"
           << "m_pitLaneTimerActive: " << std::to_string(data.m_pitLaneTimerActive) << "\n"
           << "m_pitLaneTimeInLaneInMS: " << std::to_string(data.m_pitLaneTimeInLaneInMS) << "\n"
           << "m_pitStopTimerInMS: " << std::to_string(data.m_pitStopTimerInMS) << "\n"
           << "m_pitStopShouldServePen: " << std::to_string(data.m_pitStopShouldServePen) << "\n";

        return os;
    }

    std::ostream& operator<<(std::ostream& os, const LapData& data) {
        os << "m_header: " << "\n" << data.m_header << "\n"
           << "m_timeTrialPBCarIdx: " << std::to_string(data.m_timeTrialPBCarIdx) << "\n"
           << "m_timeTrialRivalCarIdx: " << std::to_string(data.m_timeTrialRivalCarIdx) << "\n"
           << "m_lapData: " << "\n\n";

        for (size_t i = 0; i < data.m_lapData.size(); ++i) {
            os << "Lap " << std::to_string(i) << ": " << "\n";
            os << data.m_lapData[i] << (i < data.m_lapData.size() - 1 ? "\n" : "");
        }

        return os;
    }
}
