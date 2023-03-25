#include "../SessionHistoryData.h"
#include "../../../util.h"

namespace F122::Network::Packets {
    SessionHistoryData::LapHistoryData::LapHistoryData(const std::array<std::uint8_t, SIZE>& bytes) :
            m_lapTimeInMS{util::convert<std::uint32_t>({bytes[0], bytes[1], bytes[2], bytes[3]})},
            m_sector1TimeInMS{util::convert<std::uint16_t>({bytes[4], bytes[5]})},
            m_sector2TimeInMS{util::convert<std::uint16_t>({bytes[6], bytes[7]})},
            m_sector3TimeInMS{util::convert<std::uint16_t>({bytes[8], bytes[9]})},
            m_lapValidBitFlags{bytes[10]} {}

    SessionHistoryData::TyreStintHistoryData::TyreStintHistoryData(const std::array<std::uint8_t, SIZE>& bytes) :
            m_endLap{bytes[0]},
            m_tyreActualCompound{bytes[1]},
            m_tyreVisualCompound{bytes[2]} {}

    SessionHistoryData::SessionHistoryData(const std::array<std::uint8_t, SIZE>& bytes) :
            m_header{{util::copy_resize<std::uint8_t, SIZE, PacketHeader::SIZE>(bytes)}},
            m_carIdx{bytes[24]},
            m_numLaps{bytes[25]},
            m_numTyreStints{bytes[26]},
            m_bestLapTimeLapNum{bytes[27]},
            m_bestSector1LapNum{bytes[28]},
            m_bestSector2LapNum{bytes[29]},
            m_bestSector3LapNum{bytes[30]},
            m_lapHistoryData{util::batch_create<LapHistoryData, SIZE, LapHistoryData::SIZE, 100, 31>(bytes)},
            m_tyreStintsHistoryData{
                    util::batch_create<TyreStintHistoryData, SIZE, TyreStintHistoryData::SIZE, 8, 1131>(bytes)} {}

    std::ostream& operator<<(std::ostream& os, const SessionHistoryData::LapHistoryData& data) {
        os << "m_lapTimeInMS: " << std::to_string(data.m_lapTimeInMS) << "\n"
           << "m_sector1TimeInMS: " << std::to_string(data.m_sector1TimeInMS) << "\n"
           << "m_sector2TimeInMS: " << std::to_string(data.m_sector2TimeInMS) << "\n"
           << "m_sector3TimeInMS: " << std::to_string(data.m_sector3TimeInMS) << "\n"
           << "m_lapValidBitFlags: " << std::to_string(data.m_lapValidBitFlags);

        return os;
    }

    std::ostream& operator<<(std::ostream& os, const SessionHistoryData::TyreStintHistoryData& data) {
        os << "m_endLap: " << std::to_string(data.m_endLap) << "\n"
           << "m_tyreActualCompound: " << std::to_string(data.m_tyreActualCompound) << "\n"
           << "m_tyreVisualCompound: " << std::to_string(data.m_tyreVisualCompound) << "\n";

        return os;
    }

    std::ostream& operator<<(std::ostream& os, const SessionHistoryData& data) {
        os << "m_header: " << "\n" << data.m_header << "\n"
           << "m_carIdx: " << std::to_string(data.m_carIdx) << "\n"
           << "m_numLaps: " << std::to_string(data.m_numLaps) << "\n"
           << "m_numTyreStints: " << std::to_string(data.m_numTyreStints) << "\n"
           << "m_bestLapTimeLapNum: " << std::to_string(data.m_bestLapTimeLapNum) << "\n"
           << "m_bestSector1LapNum: " << std::to_string(data.m_bestSector1LapNum) << "\n"
           << "m_bestSector2LapNum: " << std::to_string(data.m_bestSector2LapNum) << "\n"
           << "m_bestSector3LapNum: " << std::to_string(data.m_bestSector3LapNum) << "\n"
           << "m_lapHistoryData: " << "\n\n";

        for (size_t i = 0; i < data.m_lapHistoryData.size(); ++i) {
            os << "Lap " << std::to_string(i) << ": " << "\n";
            os << data.m_lapHistoryData[i] << (i < data.m_lapHistoryData.size() - 1 ? "\n\n" : "\n");
        }

        os << "m_tyreStintsHistoryData: " << "\n\n";

        for (size_t i = 0; i < data.m_tyreStintsHistoryData.size(); ++i) {
            os << "Tyre Stint " << std::to_string(i) << ": " << "\n";
            os << data.m_tyreStintsHistoryData[i] << (i < data.m_tyreStintsHistoryData.size() - 1 ? "\n" : "");
        }

        return os;
    }
}
