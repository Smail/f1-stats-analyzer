#include "../CarDamageData.h"
#include "../../../util.h"

namespace F122::Network::Packets {
    CarDamageData::Data::Data(const std::array<std::uint8_t, SIZE>& bytes) :
            m_tyresWear{util::convert<float>({bytes[0], bytes[1], bytes[2], bytes[3]}),
                        util::convert<float>({bytes[4], bytes[5], bytes[6], bytes[7]}),
                        util::convert<float>({bytes[8], bytes[9], bytes[10], bytes[11]}),
                        util::convert<float>({bytes[12], bytes[13], bytes[14], bytes[15]})},
            m_tyresDamage{bytes[16], bytes[17], bytes[18], bytes[19]},
            m_brakesDamage{bytes[20], bytes[21], bytes[22], bytes[23]},
            m_frontLeftWingDamage{bytes[24]},
            m_frontRightWingDamage{bytes[25]},
            m_rearWingDamage{bytes[26]},
            m_floorDamage{bytes[27]},
            m_diffuserDamage{bytes[28]},
            m_sidepodDamage{bytes[29]},
            m_drsFault{bytes[30]},
            m_ersFault{bytes[31]},
            m_gearBoxDamage{bytes[32]},
            m_engineDamage{bytes[33]},
            m_engineMGUHWear{bytes[34]},
            m_engineESWear{bytes[35]},
            m_engineCEWear{bytes[36]},
            m_engineICEWear{bytes[37]},
            m_engineMGUKWear{bytes[38]},
            m_engineTCWear{bytes[39]},
            m_engineBlown{bytes[40]},
            m_engineSeized{bytes[41]} {}

    CarDamageData::CarDamageData(const std::array<std::uint8_t, SIZE>& bytes) :
            Packet(bytes),
            m_header{{util::copy_resize<std::uint8_t, SIZE, PacketHeader::SIZE>(bytes)}},
            m_carDamageData{util::batch_create<Data, SIZE, Data::SIZE, 22, PacketHeader::SIZE>(bytes)} {}

    CarDamageData::~CarDamageData() = default;

    std::ostream& operator<<(std::ostream& os, const CarDamageData& data) {
        os << "m_header: " << "\n" << data.m_header << "\n"
           << "m_carDamageData: " << "\n\n";

        for (size_t i = 0; i < data.m_carDamageData.size(); ++i) {
            os << "Car " << std::to_string(i) << ": " << "\n";
            os << data.m_carDamageData[i] << (i < data.m_carDamageData.size() - 1 ? "\n" : "");
        }

        return os;
    }

    std::ostream& operator<<(std::ostream& os, const CarDamageData::Data& data) {
        os << "m_tyresWear: " << util::to_string(data.m_tyresWear) << "\n"
           << "m_tyresDamage: " << util::to_string(data.m_tyresDamage) << "\n"
           << "m_brakesDamage: " << util::to_string(data.m_brakesDamage) << "\n"
           << "m_frontLeftWingDamage: " << std::to_string(data.m_frontLeftWingDamage) << "\n"
           << "m_frontRightWingDamage: " << std::to_string(data.m_frontRightWingDamage) << "\n"
           << "m_rearWingDamage: " << std::to_string(data.m_rearWingDamage) << "\n"
           << "m_floorDamage: " << std::to_string(data.m_floorDamage) << "\n"
           << "m_diffuserDamage: " << std::to_string(data.m_diffuserDamage) << "\n"
           << "m_sidepodDamage: " << std::to_string(data.m_sidepodDamage) << "\n"
           << "m_drsFault: " << std::to_string(data.m_drsFault) << "\n"
           << "m_ersFault: " << std::to_string(data.m_ersFault) << "\n"
           << "m_gearBoxDamage: " << std::to_string(data.m_gearBoxDamage) << "\n"
           << "m_engineDamage: " << std::to_string(data.m_engineDamage) << "\n"
           << "m_engineMGUHWear: " << std::to_string(data.m_engineMGUHWear) << "\n"
           << "m_engineESWear: " << std::to_string(data.m_engineESWear) << "\n"
           << "m_engineCEWear: " << std::to_string(data.m_engineCEWear) << "\n"
           << "m_engineICEWear: " << std::to_string(data.m_engineICEWear) << "\n"
           << "m_engineMGUKWear: " << std::to_string(data.m_engineMGUKWear) << "\n"
           << "m_engineTCWear: " << std::to_string(data.m_engineTCWear) << "\n"
           << "m_engineBlown: " << std::to_string(data.m_engineBlown) << "\n"
           << "m_engineSeized: " << std::to_string(data.m_engineSeized) << "\n";

        return os;
    }
}
