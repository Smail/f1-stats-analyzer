#include "../CarSetupData.h"
#include "../../../util.h"

namespace F122::Network::Packets {
    CarSetupData::Data::Data(const std::array<std::uint8_t, SIZE>& bytes) :
            m_frontWing{bytes[0]},
            m_rearWing{bytes[1]},
            m_onThrottle{bytes[2]},
            m_offThrottle{bytes[3]},
            m_frontCamber{util::convert<float>({bytes[4], bytes[5], bytes[6], bytes[7]})},
            m_rearCamber{util::convert<float>({bytes[8], bytes[9], bytes[10], bytes[11]})},
            m_frontToe{util::convert<float>({bytes[12], bytes[13], bytes[14], bytes[15]})},
            m_rearToe{util::convert<float>({bytes[16], bytes[17], bytes[18], bytes[19]})},
            m_frontSuspension{bytes[20]},
            m_rearSuspension{bytes[21]},
            m_frontAntiRollBar{bytes[22]},
            m_rearAntiRollBar{bytes[23]},
            m_frontSuspensionHeight{bytes[24]},
            m_rearSuspensionHeight{bytes[25]},
            m_brakePressure{bytes[26]},
            m_brakeBias{bytes[27]},
            m_rearLeftTyrePressure{util::convert<float>({bytes[28], bytes[29], bytes[30], bytes[31]})},
            m_rearRightTyrePressure{util::convert<float>({bytes[32], bytes[33], bytes[34], bytes[35]})},
            m_frontLeftTyrePressure{util::convert<float>({bytes[36], bytes[37], bytes[38], bytes[39]})},
            m_frontRightTyrePressure{util::convert<float>({bytes[40], bytes[41], bytes[42], bytes[43]})},
            m_ballast{bytes[44]},
            m_fuelLoad{util::convert<float>({bytes[45], bytes[46], bytes[47], bytes[48]})} {}

    CarSetupData::CarSetupData(const std::array<std::uint8_t, SIZE>& bytes) :
            Packet(bytes),
            m_header{{util::copy_resize<std::uint8_t, SIZE, PacketHeader::SIZE>(bytes)}},
            m_carSetups{util::batch_create<Data, SIZE, Data::SIZE, 22, PacketHeader::SIZE>(bytes)} {}

    CarSetupData::~CarSetupData() = default;

    std::ostream& operator<<(std::ostream& os, const CarSetupData& data) {
        os << "m_header: " << "\n" << data.m_header << "\n"
           << "m_carSetups: " << "\n\n";

        for (size_t i = 0; i < data.m_carSetups.size(); ++i) {
            os << "Car " << std::to_string(i) << ": " << "\n";
            os << data.m_carSetups[i] << (i < data.m_carSetups.size() - 1 ? "\n" : "");
        }

        return os;
    }

    std::ostream& operator<<(std::ostream& os, const CarSetupData::Data& data) {
        os << "m_frontWing: " << std::to_string(data.m_frontWing) << " (aero value)" << "\n"
           << "m_rearWing: " << std::to_string(data.m_rearWing) << " (aero value)" << "\n"
           << "m_onThrottle: " << std::to_string(data.m_onThrottle) << "%" << " (differential adj.)" << "\n"
           << "m_offThrottle: " << std::to_string(data.m_offThrottle) << "%" << " (differential adj.)" << "\n"
           << "m_frontCamber: " << std::to_string(data.m_frontCamber) << "\n"
           << "m_rearCamber: " << std::to_string(data.m_rearCamber) << "\n"
           << "m_frontToe: " << std::to_string(data.m_frontToe) << "\n"
           << "m_rearToe: " << std::to_string(data.m_rearToe) << "\n"
           << "m_frontSuspension: " << std::to_string(data.m_frontSuspension) << "\n"
           << "m_rearSuspension: " << std::to_string(data.m_rearSuspension) << "\n"
           << "m_frontAntiRollBar: " << std::to_string(data.m_frontAntiRollBar) << "\n"
           << "m_rearAntiRollBar: " << std::to_string(data.m_rearAntiRollBar) << "\n"
           << "m_frontSuspensionHeight: " << std::to_string(data.m_frontSuspensionHeight) << "\n"
           << "m_rearSuspensionHeight: " << std::to_string(data.m_rearSuspensionHeight) << "\n"
           << "m_brakePressure: " << std::to_string(data.m_brakePressure) << "%" << "\n"
           << "m_brakeBias: " << std::to_string(data.m_brakeBias) << "%" << "\n"
           << "m_rearLeftTyrePressure: " << std::to_string(data.m_rearLeftTyrePressure) << " PSI" << "\n"
           << "m_rearRightTyrePressure: " << std::to_string(data.m_rearRightTyrePressure) << " PSI" << "\n"
           << "m_frontLeftTyrePressure: " << std::to_string(data.m_frontLeftTyrePressure) << " PSI" << "\n"
           << "m_frontRightTyrePressure: " << std::to_string(data.m_frontRightTyrePressure) << " PSI" << "\n"
           << "m_ballast: " << std::to_string(data.m_ballast) << " kg" << "\n"
           << "m_fuelLoad: " << std::to_string(data.m_fuelLoad) << " kg" << "\n";

        return os;
    }
}
