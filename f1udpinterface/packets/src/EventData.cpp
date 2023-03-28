#include "../EventData.h"
#include "../../../util.h"
#include "../../ids/ButtonFlags.h"
#include "../../ids/PenaltyTypeId.h"
#include "../../ids/InfringementTypeId.h"

namespace F122::Network::Packets {
    EventData::EventData(const std::array<std::uint8_t, SIZE>& bytes) :
            Packet(bytes),
            m_header{{util::copy_resize<std::uint8_t, SIZE, PacketHeader::SIZE>(bytes)}},
            m_eventStringCode{util::copy_resize<std::uint8_t, SIZE, 4, PacketHeader::SIZE>(bytes)},
            m_eventDetails{} {

        constexpr size_t expectedSizeOfEventDetailsSegment = 12;
        constexpr size_t offset = PacketHeader::SIZE + 4 * sizeof(std::uint8_t);
        static_assert(SIZE - offset == expectedSizeOfEventDetailsSegment, "Invalid size");
        const auto code = eventCode();

        if (code == EventStringCodes::FASTEST_LAP) {
            m_eventDetails.FastestLap.vehicleIdx = bytes[offset];
            m_eventDetails.FastestLap.vehicleIdx = bytes[offset + 1];
        } else if (code == EventStringCodes::RETIREMENT || code == EventStringCodes::TEAM_MATE_IN_PITS ||
                   code == EventStringCodes::RACE_WINNER || code == EventStringCodes::START_LIGHTS ||
                   code == EventStringCodes::DRIVE_THROUGH_SERVED || code == EventStringCodes::STOP_GO_SERVED) {
            // All cases have the same struct layout, specifically a struct, that contains only one byte,
            // so we'll merge them all into one case.
            m_eventDetails.Retirement.vehicleIdx = bytes[offset];
        } else if (code == EventStringCodes::PENALTY_ISSUED) {
            m_eventDetails.Penalty.penaltyType = bytes[offset];
            m_eventDetails.Penalty.infringementType = bytes[offset + 1];
            m_eventDetails.Penalty.vehicleIdx = bytes[offset + 2];
            m_eventDetails.Penalty.otherVehicleIdx = bytes[offset + 3];
            m_eventDetails.Penalty.time = bytes[offset + 4];
            m_eventDetails.Penalty.lapNum = bytes[offset + 5];
            m_eventDetails.Penalty.placesGained = bytes[offset + 6];
        } else if (code == EventStringCodes::SPEED_TRAP_TRIGGERED) {
            m_eventDetails.SpeedTrap.vehicleIdx = bytes[offset];
            m_eventDetails.SpeedTrap.speed = util::convert<float>(
                    {bytes[offset + 1], bytes[offset + 2], bytes[offset + 3], bytes[offset + 4]});
            m_eventDetails.SpeedTrap.isOverallFastestInSession = bytes[offset + 5];
            m_eventDetails.SpeedTrap.isDriverFastestInSession = bytes[offset + 6];
            m_eventDetails.SpeedTrap.fastestVehicleIdxInSession = bytes[offset + 7];
            m_eventDetails.SpeedTrap.fastestSpeedInSession = util::convert<float>(
                    {bytes[offset + 8], bytes[offset + 9], bytes[offset + 10], bytes[offset + 11]});
        } else if (code == EventStringCodes::FLASHBACK) {
            m_eventDetails.Flashback.flashbackFrameIdentifier = util::convert<std::uint32_t>(
                    {bytes[offset], bytes[offset + 1], bytes[offset + 2], bytes[offset + 3]});
            m_eventDetails.Flashback.flashbackSessionTime = util::convert<float>(
                    {bytes[offset + 4], bytes[offset + 5], bytes[offset + 6], bytes[offset + 7]});
        } else if (code == EventStringCodes::BUTTON_STATUS) {
            m_eventDetails.Buttons.m_buttonStatus = util::convert<std::uint32_t>(
                    {bytes[offset], bytes[offset + 1], bytes[offset + 2], bytes[offset + 3]});
        } else {
            // Other cases don't have data attached to them
        }
    }

    EventData::~EventData() = default;

    std::string EventData::EventDataDetails::to_string(EventData::EventStringCodes type) const {
        std::stringstream ss;

        if (type == EventStringCodes::BUTTON_STATUS) {
            std::uint32_t mask = Buttons.m_buttonStatus;
            ss << "m_buttonStatus: " << std::to_string(mask);

            // TODO create proper iterator for type ButtonFlags
            ButtonFlagsIterator iter{};

            while (iter.hasNext()) {
                ButtonFlags flags = iter.next();
                if ((mask & static_cast<std::uint32_t>(flags)) == static_cast<std::uint32_t>(flags)) {
                    ss << std::endl << flags;
                }
            }

            return ss.str();
        }

        switch (type) {
            case EventStringCodes::FASTEST_LAP:
                ss << "vehicleIdx: " << std::to_string(FastestLap.vehicleIdx) << std::endl;
                ss << "lapTime: " << std::to_string(FastestLap.lapTime) << " s";
                break;
            case EventStringCodes::RETIREMENT:
            case EventStringCodes::TEAM_MATE_IN_PITS:
            case EventStringCodes::RACE_WINNER:
            case EventStringCodes::DRIVE_THROUGH_SERVED:
            case EventStringCodes::STOP_GO_SERVED:
                ss << "vehicleIdx: " << std::to_string(Retirement.vehicleIdx);
                break;
            case EventStringCodes::PENALTY_ISSUED:
                ss << "penaltyType: " << F122::to_string(static_cast<PenaltyTypeId>(Penalty.penaltyType)) << "\n";
                ss << "infringementType: "
                   << F122::to_string(static_cast<InfringementTypeId>(Penalty.infringementType)) << "\n";
                ss << "vehicleIdx: " << std::to_string(Penalty.vehicleIdx) << "\n";
                ss << "otherVehicleIdx: " << std::to_string(Penalty.otherVehicleIdx) << "\n";
                ss << "time: " << std::to_string(Penalty.time) << "\n";
                ss << "lapNum: " << std::to_string(Penalty.lapNum) << "\n";
                ss << "placesGained: " << std::to_string(Penalty.placesGained);
                break;
            case EventStringCodes::SPEED_TRAP_TRIGGERED:
                ss << "vehicleIdx: " << std::to_string(SpeedTrap.vehicleIdx) << "\n";
                ss << "speed: " << std::to_string(SpeedTrap.speed) << " km/h" << "\n";
                ss << "isOverallFastestInSession: " << std::boolalpha
                   << (SpeedTrap.isOverallFastestInSession == 1) << std::noboolalpha << "\n";
                ss << "isDriverFastestInSession: " << std::boolalpha
                   << (SpeedTrap.isDriverFastestInSession == 1) << std::noboolalpha << "\n";
                ss << "fastestSpeedInSession: " << std::to_string(SpeedTrap.fastestSpeedInSession) << " km/h" << "\n";
                ss << "fastestVehicleIdxInSession: " << std::to_string(SpeedTrap.fastestVehicleIdxInSession);
                break;
            case EventStringCodes::START_LIGHTS:
                ss << "numLights: " << std::to_string(StartLights.numLights);
                break;
            case EventStringCodes::FLASHBACK:
                ss << "flashbackFrameIdentifier: " << std::to_string(Flashback.flashbackFrameIdentifier) << "\n";
                ss << "flashbackSessionTime: " << std::to_string(Flashback.flashbackSessionTime);
                break;
            default:
                ss << "This event doesn't contain data." << std::endl;
                break;
        }

        return ss.str();
    }

    EventData::EventStringCodes EventData::from(const std::string& str) {
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
                throw std::invalid_argument("Can't match argument string to an enum value.");
        }
    }

    EventData::EventStringCodes EventData::eventCode() const {
        char cs[5] = {
                static_cast<char>(m_eventStringCode[0]), static_cast<char>(m_eventStringCode[1]),
                static_cast<char>(m_eventStringCode[2]), static_cast<char>(m_eventStringCode[3]), '\0'
        };

        return EventData::from(std::string{cs});
    }

    std::string EventData::eventString() const {
        // Double convert to make sure the code actually exists (eventCode() will itself create a string and
        // convert it then to the appropriate enum value, which we here then use to convert it back to a string again).
        return EventData::to_string(eventCode());
    }

    std::string EventData::to_string(EventData::EventStringCodes enumCase) {
        return std::string{
                static_cast<char>(static_cast<std::uint64_t>(enumCase) >> 24),
                static_cast<char>(static_cast<std::uint64_t>(enumCase) >> 16),
                static_cast<char>(static_cast<std::uint64_t>(enumCase) >> 8),
                static_cast<char>(static_cast<std::uint64_t>(enumCase) >> 0),
        };
    }

    std::ostream& operator<<(std::ostream& os, const EventData& data) {
        os << "m_header: " << "\n" << data.m_header
           << "m_eventStringCode: " << data.eventString() << "\n"
           << "m_eventDetails: [" << "\n" << data.m_eventDetails.to_string(data.eventCode()) << "\n]\n";

        return os;
    }
}
