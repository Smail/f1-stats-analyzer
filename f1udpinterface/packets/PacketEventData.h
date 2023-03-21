#pragma once

#include <string>
#include <array>
#include <sstream>
#include <ostream>
#include "PacketHeader.h"
#include "../../util.h"

#pragma pack(1)

namespace F122::Network {
    constexpr std::uint64_t to_ascii_int(const std::string &str) {
        if (str.length() != 4) throw std::invalid_argument("Expected string of length 4");
        return (str[0] << 24) | (str[1] << 16) | (str[2] << 8) | (str[3] << 0);
    }

    /// This packet gives details of events that happen during the course of a session.<br>
    /// <br>
    /// Frequency: When the event occurs<br>
    /// Size: 40 bytes<br>
    /// Version: 1<br>
    /// <br>
    /// <b>The event details packet is different for each type of event.
    /// Make sure only the correct type is interpreted.</b>
    struct PacketEventData {
        enum class EventStringCodes : std::uint64_t {
            /// Sent when the session starts
            SESSION_STARTED = to_ascii_int("SSTA"),
            /// Sent when the session ends
            SESSION_ENDED = to_ascii_int("SEND"),
            /// When a driver achieves the fastest lap
            FASTEST_LAP = to_ascii_int("FTLP"),
            /// When a driver retires
            RETIREMENT = to_ascii_int("RTMT"),
            /// Race control have enabled DRS
            DRS_ENABLED = to_ascii_int("DRSE"),
            /// Race control have disabled DRS
            DRS_DISABLED = to_ascii_int("DRSD"),
            /// Your team mate has entered the pits
            TEAM_MATE_IN_PITS = to_ascii_int("TMPT"),
            /// The chequered flag has been waved
            CHEQUERED_FLAG = to_ascii_int("CHQF"),
            /// The race winner is announced
            RACE_WINNER = to_ascii_int("RCWN"),
            /// A penalty has been issued – details in event
            PENALTY_ISSUED = to_ascii_int("PENA"),
            /// Speed trap has been triggered by fastest speed
            SPEED_TRAP_TRIGGERED = to_ascii_int("SPTP"),
            /// Start lights – number shown
            START_LIGHTS = to_ascii_int("STLG"),
            /// Lights out
            LIGHTS_OUT = to_ascii_int("LGOT"),
            /// Drive through penalty served
            DRIVE_THROUGH_SERVED = to_ascii_int("DTSV"),
            /// Stop go penalty served
            STOP_GO_SERVED = to_ascii_int("SGSV"),
            /// FLASHBACK activated
            FLASHBACK = to_ascii_int("FLBK"),
            /// Button status changed
            BUTTON_STATUS = to_ascii_int("BUTN"),
        };

        static std::string to_string(EventStringCodes enumCase) {
            return std::string{
                    static_cast<char>(static_cast<std::uint64_t>(enumCase) >> 24),
                    static_cast<char>(static_cast<std::uint64_t>(enumCase) >> 16),
                    static_cast<char>(static_cast<std::uint64_t>(enumCase) >> 8),
                    static_cast<char>(static_cast<std::uint64_t>(enumCase) >> 0),
            };
        }

        static EventStringCodes from(const std::string &str) {
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

        union EventDataDetails {
            struct {
                /// Vehicle index of car achieving fastest lap
                uint8 vehicleIdx;
                /// Lap time is in seconds
                float lapTime;
            } FastestLap;

            struct {
                uint8 vehicleIdx;
                /// Vehicle index of car retiring
            } Retirement;

            struct {
                uint8 vehicleIdx;
                /// Vehicle index of team mate
            } TeamMateInPits;

            struct {
                uint8 vehicleIdx;
                /// Vehicle index of the race winner
            } RaceWinner;

            struct {
                uint8 penaltyType;
                /// Penalty type – see Appendices
                uint8 infringementType;
                /// Infringement type – see Appendices
                uint8 vehicleIdx;
                /// Vehicle index of the car the penalty is applied to
                uint8 otherVehicleIdx;
                /// Vehicle index of the other car involved
                uint8 time;
                /// Time gained, or time spent doing action in seconds
                uint8 lapNum;
                /// Lap the penalty occurred on
                uint8 placesGained;
                /// Number of places gained by this
            } Penalty;

            struct {
                uint8 vehicleIdx;
                /// Vehicle index of the vehicle triggering speed trap
                float speed;
                /// Top speed achieved in kilometres per hour
                uint8 isOverallFastestInSession;
                /// Overall fastest speed in session = 1, otherwise 0
                uint8 isDriverFastestInSession;
                /// Fastest speed for driver in session = 1, otherwise 0
                uint8 fastestVehicleIdxInSession;
                /// Vehicle index of the vehicle that is the fastest in this session
                float fastestSpeedInSession;
                /// Speed of the vehicle that is the fastest in this session
            } SpeedTrap;

            struct {
                /// Number of lights showing
                uint8 numLights;
            } StartLights;

            struct {
                /// Vehicle index of the vehicle serving drive through
                uint8 vehicleIdx;
            } DriveThroughPenaltyServed;

            struct {
                /// Vehicle index of the vehicle serving stop go
                uint8 vehicleIdx;
            } StopGoPenaltyServed;

            struct {
                /// Frame identifier flashed back to
                uint32 flashbackFrameIdentifier;
                /// Session time flashed back to
                float flashbackSessionTime;
            } Flashback;

            struct {
                /// Bit flags specifying which buttons are being pressed currently - see appendices
                uint32 m_buttonStatus;
            } Buttons;

            [[nodiscard]] std::string to_string(EventStringCodes type) const {
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
        };

    public:
        PacketHeader m_header;
        /// Event string code @see EventStringCodes
        std::array<uint8, 4> m_eventStringCode;
        /// Event details - should be interpreted differently for each type
        EventDataDetails m_eventDetails;

        friend std::ostream &operator<<(std::ostream &os, const PacketEventData &data) {
            char cs[5] = {
                    static_cast<char>(data.m_eventStringCode[0]), static_cast<char>(data.m_eventStringCode[1]),
                    static_cast<char>(data.m_eventStringCode[2]), static_cast<char>(data.m_eventStringCode[3]), '\0'
            };
            EventStringCodes eventCode = from(std::string{cs});
            std::string eventCodeString = to_string(eventCode);

            os << "m_header: " << "\n" << data.m_header << "\n"
               << "m_eventStringCode: " << eventCodeString << "\n"
               << "m_eventDetails: " << "\n" << data.m_eventDetails.to_string(eventCode) << "\n";

            return os;
        }
    };
}

#pragma pack()
