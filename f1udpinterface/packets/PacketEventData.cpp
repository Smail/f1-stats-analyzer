#include "PacketEventData.h"
#include "../../util.h"

namespace F122::Network {
    PacketEventData::PacketEventData(const std::array<std::uint8_t, 40>& bytes) :
            m_header{{util::copy_resize<std::uint8_t, 40, 24>(bytes)}},
            m_eventStringCode{util::copy_resize<std::uint8_t, 40, 4, 24 + 1>(bytes)} {
        // TODO init m_eventDetails: Check for string code to get size of struct
    }

    std::string PacketEventData::EventDataDetails::to_string(PacketEventData::EventStringCodes type) const {
        std::stringstream ss;

        if (type == EventStringCodes::FASTEST_LAP) {
            ss << "vehicleIdx: " << std::to_string(FastestLap.vehicleIdx) << "\n";
            ss << "lapTime: " << std::to_string(FastestLap.lapTime);
        } else if (type == EventStringCodes::RETIREMENT) {
            ss << "vehicleIdx: " << std::to_string(Retirement.vehicleIdx);
        } else if (type == EventStringCodes::TEAM_MATE_IN_PITS) {
            ss << "vehicleIdx: " << std::to_string(TeamMateInPits.vehicleIdx);
        } else if (type == EventStringCodes::RACE_WINNER) {
            ss << "vehicleIdx: " << std::to_string(RaceWinner.vehicleIdx);
        } else if (type == EventStringCodes::PENALTY_ISSUED) {
            ss << "penaltyType: " << std::to_string(Penalty.penaltyType) << "\n";
            ss << "infringementType: " << std::to_string(Penalty.infringementType) << "\n";
            ss << "vehicleIdx: " << std::to_string(Penalty.vehicleIdx) << "\n";
            ss << "otherVehicleIdx: " << std::to_string(Penalty.otherVehicleIdx) << "\n";
            ss << "time: " << std::to_string(Penalty.time) << "\n";
            ss << "lapNum: " << std::to_string(Penalty.lapNum) << "\n";
            ss << "placesGained: " << std::to_string(Penalty.placesGained);
        } else if (type == EventStringCodes::SPEED_TRAP_TRIGGERED) {
            ss << "vehicleIdx: " << std::to_string(SpeedTrap.vehicleIdx) << "\n";
            ss << "speed: " << std::to_string(SpeedTrap.speed) << "\n";
            ss << "isOverallFastestInSession: " << std::to_string(SpeedTrap.isOverallFastestInSession) << "\n";
            ss << "isDriverFastestInSession: " << std::to_string(SpeedTrap.isDriverFastestInSession) << "\n";
            ss << "fastestSpeedInSession: " << std::to_string(SpeedTrap.fastestSpeedInSession) << "\n";
            ss << "fastestVehicleIdxInSession: " << std::to_string(SpeedTrap.fastestVehicleIdxInSession);
        } else if (type == EventStringCodes::START_LIGHTS) {
            ss << "numLights: " << std::to_string(StartLights.numLights);
        } else if (type == EventStringCodes::DRIVE_THROUGH_SERVED) {
            ss << "vehicleIdx: " << std::to_string(DriveThroughPenaltyServed.vehicleIdx);
        } else if (type == EventStringCodes::STOP_GO_SERVED) {
            ss << "vehicleIdx: " << std::to_string(StopGoPenaltyServed.vehicleIdx);
        } else if (type == EventStringCodes::FLASHBACK) {
            ss << "flashbackFrameIdentifier: " << std::to_string(Flashback.flashbackFrameIdentifier) << "\n";
            ss << "flashbackSessionTime: " << std::to_string(Flashback.flashbackSessionTime);
        } else if (type == EventStringCodes::BUTTON_STATUS) {
            ss << "m_buttonStatus: " << std::to_string(Buttons.m_buttonStatus);
        }

        return ss.str();
    }

    PacketEventData::EventStringCodes PacketEventData::from(const std::string& str) {
        switch (to_ascii_int(str)) {
            case static_cast<std::uint64_t>(EventStringCodes::SESSION_STARTED):
                return EventStringCodes::SESSION_STARTED;
            case static_cast<std::uint64_t>(EventStringCodes::SESSION_ENDED):
                return EventStringCodes::SESSION_ENDED;
            case static_cast<std::uint64_t>(EventStringCodes::FASTEST_LAP):
                return EventStringCodes::FASTEST_LAP;
            case static_cast<std::uint64_t>(EventStringCodes::RETIREMENT):
                return EventStringCodes::RETIREMENT;
            case static_cast<std::uint64_t>(EventStringCodes::DRS_ENABLED):
                return EventStringCodes::DRS_ENABLED;
            case static_cast<std::uint64_t>(EventStringCodes::DRS_DISABLED):
                return EventStringCodes::DRS_DISABLED;
            case static_cast<std::uint64_t>(EventStringCodes::TEAM_MATE_IN_PITS):
                return EventStringCodes::TEAM_MATE_IN_PITS;
            case static_cast<std::uint64_t>(EventStringCodes::CHEQUERED_FLAG):
                return EventStringCodes::CHEQUERED_FLAG;
            case static_cast<std::uint64_t>(EventStringCodes::RACE_WINNER):
                return EventStringCodes::RACE_WINNER;
            case static_cast<std::uint64_t>(EventStringCodes::PENALTY_ISSUED):
                return EventStringCodes::PENALTY_ISSUED;
            case static_cast<std::uint64_t>(EventStringCodes::SPEED_TRAP_TRIGGERED):
                return EventStringCodes::SPEED_TRAP_TRIGGERED;
            case static_cast<std::uint64_t>(EventStringCodes::START_LIGHTS):
                return EventStringCodes::START_LIGHTS;
            case static_cast<std::uint64_t>(EventStringCodes::LIGHTS_OUT):
                return EventStringCodes::LIGHTS_OUT;
            case static_cast<std::uint64_t>(EventStringCodes::DRIVE_THROUGH_SERVED):
                return EventStringCodes::DRIVE_THROUGH_SERVED;
            case static_cast<std::uint64_t>(EventStringCodes::STOP_GO_SERVED):
                return EventStringCodes::STOP_GO_SERVED;
            case static_cast<std::uint64_t>(EventStringCodes::FLASHBACK):
                return EventStringCodes::FLASHBACK;
            case static_cast<std::uint64_t>(EventStringCodes::BUTTON_STATUS):
                return EventStringCodes::BUTTON_STATUS;
            default:
                throw std::invalid_argument("Can't match argument string to an enum case.");
        }
    }

    std::string PacketEventData::to_string(PacketEventData::EventStringCodes enumCase) {
        return std::string{
                static_cast<char>(static_cast<std::uint64_t>(enumCase) >> 24),
                static_cast<char>(static_cast<std::uint64_t>(enumCase) >> 16),
                static_cast<char>(static_cast<std::uint64_t>(enumCase) >> 8),
                static_cast<char>(static_cast<std::uint64_t>(enumCase) >> 0),
        };
    }

    std::ostream& operator<<(std::ostream& os, const PacketEventData& data) {
        char cs[5] = {
                static_cast<char>(data.m_eventStringCode[0]), static_cast<char>(data.m_eventStringCode[1]),
                static_cast<char>(data.m_eventStringCode[2]), static_cast<char>(data.m_eventStringCode[3]), '\0'
        };

        PacketEventData::EventStringCodes eventCode = PacketEventData::from(std::string{cs});
        std::string eventCodeString = PacketEventData::to_string(eventCode);

        os << "m_header: " << "\n" << data.m_header << "\n"
           << "m_eventStringCode: " << eventCodeString << "\n"
           << "m_eventDetails: " << "\n" << data.m_eventDetails.to_string(eventCode) << "\n";

        return os;
    }
}
