#include "../CarStatusData.h"
#include "../../../util.h"

namespace F122::Network::Packets {
    CarStatusData::Data::Data(const std::array<std::uint8_t, SIZE>& bytes) :
            m_tractionControl{bytes[0]},
            m_antiLockBrakes{bytes[1]},
            m_fuelMix{bytes[2]},
            m_frontBrakeBias{bytes[3]},
            m_pitLimiterStatus{bytes[4]},
            m_fuelInTank{util::convert<float>({bytes[5], bytes[6], bytes[7], bytes[8]})},
            m_fuelCapacity{util::convert<float>({bytes[9], bytes[10], bytes[11], bytes[12]})},
            m_fuelRemainingLaps{util::convert<float>({bytes[13], bytes[14], bytes[15], bytes[16]})},
            m_maxRPM{util::convert<std::uint16_t>({bytes[17], bytes[18]})},
            m_idleRPM{util::convert<std::uint16_t>({bytes[19], bytes[20]})},
            m_maxGears{bytes[21]},
            m_drsAllowed{bytes[22]},
            m_drsActivationDistance{util::convert<std::uint16_t>({bytes[23], bytes[24]})},
            m_actualTyreCompound{bytes[25]},
            m_visualTyreCompound{bytes[26]},
            m_tyresAgeLaps{bytes[27]},
            m_vehicleFiaFlags{static_cast<std::int8_t>(bytes[28])},
            m_ersStoreEnergy{util::convert<float>({bytes[29], bytes[30], bytes[31], bytes[32]})},
            m_ersDeployMode{bytes[33]},
            m_ersHarvestedThisLapMGUK{util::convert<float>({bytes[34], bytes[35], bytes[36], bytes[37]})},
            m_ersHarvestedThisLapMGUH{util::convert<float>({bytes[38], bytes[39], bytes[40], bytes[41]})},
            m_ersDeployedThisLap{util::convert<float>({bytes[42], bytes[43], bytes[44], bytes[45]})},
            m_networkPaused{bytes[46]} {}

    CarStatusData::CarStatusData(const std::array<std::uint8_t, SIZE>& bytes) :
            m_header{{util::copy_resize<std::uint8_t, SIZE, PacketHeader::SIZE>(bytes)}},
            m_carStatusData{util::batch_create<Data, SIZE, Data::SIZE, 22, PacketHeader::SIZE>(bytes)} {}

    std::ostream& operator<<(std::ostream& os, const CarStatusData::Data& data) {
        os << "m_tractionControl: " << std::to_string(data.m_tractionControl) << "\n"
           << "m_antiLockBrakes: " << std::to_string(data.m_antiLockBrakes) << "\n"
           << "m_fuelMix: " << std::to_string(data.m_fuelMix) << "\n"
           << "m_frontBrakeBias: " << std::to_string(data.m_frontBrakeBias) << "\n"
           << "m_pitLimiterStatus: " << std::to_string(data.m_pitLimiterStatus) << "\n"
           << "m_fuelInTank: " << std::to_string(data.m_fuelInTank) << "\n"
           << "m_fuelCapacity: " << std::to_string(data.m_fuelCapacity) << "\n"
           << "m_fuelRemainingLaps: " << std::to_string(data.m_fuelRemainingLaps) << "\n"
           << "m_maxRPM: " << std::to_string(data.m_maxRPM) << "\n"
           << "m_idleRPM: " << std::to_string(data.m_idleRPM) << "\n"
           << "m_maxGears: " << std::to_string(data.m_maxGears) << "\n"
           << "m_drsAllowed: " << std::to_string(data.m_drsAllowed) << "\n"
           << "m_drsActivationDistance: " << std::to_string(data.m_drsActivationDistance) << "\n"
           << "m_actualTyreCompound: " << std::to_string(data.m_actualTyreCompound) << "\n"
           << "m_visualTyreCompound: " << std::to_string(data.m_visualTyreCompound) << "\n"
           << "m_tyresAgeLaps: " << std::to_string(data.m_tyresAgeLaps) << "\n"
           << "m_vehicleFiaFlags: " << std::to_string(data.m_vehicleFiaFlags) << "\n"
           << "m_ersStoreEnergy: " << std::to_string(data.m_ersStoreEnergy) << " Joules" << "\n"
           << "m_ersDeployMode: " << data.ers_deploy_mode() << "\n"
           << "m_ersHarvestedThisLapMGUK: " << std::to_string(data.m_ersHarvestedThisLapMGUK) << "\n"
           << "m_ersHarvestedThisLapMGUH: " << std::to_string(data.m_ersHarvestedThisLapMGUH) << "\n"
           << "m_ersDeployedThisLap: " << std::to_string(data.m_ersDeployedThisLap) << "\n"
           << "m_networkPaused: " << std::to_string(data.m_networkPaused) << "\n";

        return os;
    }

    std::string CarStatusData::Data::ers_deploy_mode() const {
        switch (m_ersDeployMode) {
            case 0:
                return "None";
            case 1:
                return "Medium";
            case 2:
                return "Hotlap";
            case 3:
                return "Overtake";
            default:
                throw std::runtime_error("Invalid state: " + std::to_string(m_ersDeployMode) + " is not valid value");
        }
    }

    std::ostream& operator<<(std::ostream& os, const CarStatusData& data) {
        os << "m_header: " << "\n" << data.m_header << "\n"
           << "m_carStatusData: " << "\n\n";

        for (size_t i = 0; i < data.m_carStatusData.size(); ++i) {
            os << "Car " << std::to_string(i) << ": " << "\n";
            os << data.m_carStatusData[i] << (i < data.m_carStatusData.size() - 1 ? "\n" : "");
        }

        return os;
    }
}
