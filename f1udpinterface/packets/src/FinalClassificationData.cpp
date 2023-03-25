#include <sstream>
#include "../FinalClassificationData.h"
#include "../../../util.h"

namespace F122::Network::Packets {
    FinalClassificationData::Data::Data(const std::array<std::uint8_t, SIZE>& bytes) :
            m_position{bytes[0]},
            m_numLaps{bytes[1]},
            m_gridPosition{bytes[2]},
            m_points{bytes[3]},
            m_numPitStops{bytes[4]},
            m_resultStatus{bytes[5]},
            m_bestLapTimeInMS{util::convert<std::uint32_t>({bytes[6], bytes[7], bytes[8], bytes[9]})},
            m_totalRaceTime{util::convert<double>(
                    {bytes[10], bytes[11], bytes[12], bytes[13], bytes[14], bytes[15], bytes[16], bytes[17]})},
            m_penaltiesTime{bytes[18]},
            m_numPenalties{bytes[19]},
            m_numTyreStints{bytes[20]},
            m_tyreStintsActual{
                    {bytes[21], bytes[22], bytes[23], bytes[24], bytes[25], bytes[26], bytes[27], bytes[28]},
            },
            m_tyreStintsVisual{
                    {bytes[29], bytes[30], bytes[31], bytes[32], bytes[33], bytes[34], bytes[35], bytes[36]},
            },
            m_tyreStintsEndLaps{
                    {bytes[37], bytes[38], bytes[39], bytes[40], bytes[41], bytes[42], bytes[43], bytes[44]},
            } {}

    FinalClassificationData::FinalClassificationData(const std::array<std::uint8_t, SIZE>& bytes) :
            Packet(bytes),
            m_header{{util::copy_resize<std::uint8_t, SIZE, PacketHeader::SIZE>(bytes)}},
            m_numCars{bytes[24]},
            m_classificationData{util::batch_create<Data, SIZE, Data::SIZE, 22, PacketHeader::SIZE + 1>(bytes)} {}

    FinalClassificationData::~FinalClassificationData() = default;

    std::string FinalClassificationData::Data::to_string() const {
        std::stringstream ss;

        ss << "m_position: " << std::to_string(m_position) << "\n"
           << "m_numLaps: " << std::to_string(m_numLaps) << "\n"
           << "m_gridPosition: " << std::to_string(m_gridPosition) << "\n"
           << "m_points: " << std::to_string(m_points) << "\n"
           << "m_numPitStops: " << std::to_string(m_numPitStops) << "\n"
           << "m_resultStatus: " << std::to_string(m_resultStatus) << "\n"
           << "m_bestLapTimeInMS: " << std::to_string(m_bestLapTimeInMS) << "\n"
           << "m_totalRaceTime: " << std::to_string(m_totalRaceTime) << "\n"
           << "m_penaltiesTime: " << std::to_string(m_penaltiesTime) << "\n"
           << "m_numPenalties: " << std::to_string(m_numPenalties) << "\n"
           << "m_numTyreStints: " << std::to_string(m_numTyreStints) << "\n"
           << "m_tyreStintsActual: " << util::to_string(m_tyreStintsActual) << "\n"
           << "m_tyreStintsVisual: " << util::to_string(m_tyreStintsVisual) << "\n"
           << "m_tyreStintsEndLaps: " << util::to_string(m_tyreStintsEndLaps);

        return ss.str();
    }

    std::ostream& operator<<(std::ostream& os, const FinalClassificationData::Data& data) {
        os << data.to_string();
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const FinalClassificationData& data) {
        os << "m_header: " << "\n" << data.m_header << "\n"
           << "m_numCars: " << data.m_numCars << "\n"
           << "m_classificationData: " << "\n\n";

        for (size_t i = 0; i < data.m_classificationData.size(); ++i) {
            os << "Car " << std::to_string(i) << ": " << "\n";
            os << data.m_classificationData[i] << (i < data.m_classificationData.size() - 1 ? "\n\n" : "");
        }

        return os;
    }
}
