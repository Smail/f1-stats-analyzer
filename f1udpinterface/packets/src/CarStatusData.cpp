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
            Packet(bytes),
            m_header{{util::copy_resize<std::uint8_t, SIZE, PacketHeader::SIZE>(bytes)}},
            m_carStatusData{util::batch_create<Data, SIZE, Data::SIZE, 22, PacketHeader::SIZE>(bytes)} {}

    CarStatusData::~CarStatusData() = default;

    std::uint16_t CarStatusData::Data::distance_to_next_drs_zone() const {
        return m_drsActivationDistance;
    }

    bool CarStatusData::Data::is_drs_available() const {
        return m_drsActivationDistance > 0;
    }

    std::string CarStatusData::Data::tractionControlString() const {
        if (m_tractionControl == 0) return "OFF";
        else if (m_tractionControl == 1) return "MEDIUM";
        else if (m_tractionControl == 2) return "FULL";
        else throw std::runtime_error("Invalid state: " + std::to_string(m_tractionControl) + " is not valid value");
    }

    std::string CarStatusData::Data::fuelMixString() const {
        if (m_fuelMix == 0) return "LEAN";
        else if (m_fuelMix == 1) return "STANDARD";
        else if (m_fuelMix == 2) return "RICH";
        else if (m_fuelMix == 3) return "MAX";
        else throw std::runtime_error("Invalid state: " + std::to_string(m_fuelMix) + " is not valid value");
    }

    std::string CarStatusData::Data::fiaFlags() const {
        if (m_vehicleFiaFlags == 0) return "None";
        else if (m_vehicleFiaFlags == 1) return "Green";
        else if (m_vehicleFiaFlags == 2) return "Blue";
        else if (m_vehicleFiaFlags == 3) return "Yellow";
        else if (m_vehicleFiaFlags == 4) return "Red";
        else return "Invalid/Unknown";
    }

    std::string CarStatusData::Data::ers_deploy_mode() const {
        if (m_ersDeployMode == 0) return "None";
        else if (m_ersDeployMode == 1) return "Medium";
        else if (m_ersDeployMode == 2) return "Hotlap";
        else if (m_ersDeployMode == 3) return "Overtake";
        else throw std::runtime_error("Invalid state: " + std::to_string(m_ersDeployMode) + " is not valid value");
    }

    std::ostream& operator<<(std::ostream& os, const CarStatusData::Data& data) {
        std::string drsActivationDistance = data.m_drsActivationDistance == 0 ?
                                            "DRS UNAVAILABLE" : (std::to_string(data.m_drsActivationDistance) + " m");

        os << "m_tractionControl: " << data.tractionControlString() << "\n"
           << "m_antiLockBrakes: " << (data.m_antiLockBrakes == 0 ? "OFF" : "ON") << "\n"
           << "m_fuelMix: " << data.fuelMixString() << "\n"
           << "m_frontBrakeBias: " << std::to_string(data.m_frontBrakeBias) << "%" << "\n"
           << "m_pitLimiterStatus: " << (data.m_pitLimiterStatus ? "ON" : "OFF") << "\n"
           << "m_fuelInTank: " << std::to_string(data.m_fuelInTank) << " l" << "\n"
           << "m_fuelCapacity: " << std::to_string(data.m_fuelCapacity) << " l" << "\n"
           << "m_fuelRemainingLaps: " << std::to_string(data.m_fuelRemainingLaps) << "\n"
           << "m_maxRPM: " << std::to_string(data.m_maxRPM) << "\n"
           << "m_idleRPM: " << std::to_string(data.m_idleRPM) << "\n"
           << "m_maxGears: " << std::to_string(data.m_maxGears) << "\n"
           << "m_drsAllowed: " << (data.m_drsAllowed ? "ALLOWED" : "NOT ALLOWED") << "\n"
           << "m_drsActivationDistance: " << drsActivationDistance << "\n"
           << "m_actualTyreCompound: " << std::to_string(data.m_actualTyreCompound) << "\n"
           << "m_visualTyreCompound: " << std::to_string(data.m_visualTyreCompound) << "\n"
           << "m_tyresAgeLaps: " << std::to_string(data.m_tyresAgeLaps) << "\n"
           << "m_vehicleFiaFlags: " << data.fiaFlags() << "\n"
           << "m_ersStoreEnergy: " << std::to_string(data.m_ersStoreEnergy) << " Joules" << "\n"
           << "m_ersDeployMode: " << data.ers_deploy_mode() << "\n"
           << "m_ersHarvestedThisLapMGUK: " << std::to_string(data.m_ersHarvestedThisLapMGUK) << " Joules" << "\n"
           << "m_ersHarvestedThisLapMGUH: " << std::to_string(data.m_ersHarvestedThisLapMGUH) << " Joules" << "\n"
           << "m_ersDeployedThisLap: " << std::to_string(data.m_ersDeployedThisLap) << " Joules" << "\n"
           << "m_networkPaused: " << std::boolalpha << data.m_networkPaused << std::noboolalpha << "\n";

        return os;
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
