#pragma once

#include <string>
#include <array>
#include <sstream>
#include <ostream>
#include "PacketHeader.h"

namespace F122::Network {
    constexpr std::uint64_t to_ascii_int(const std::string& str) {
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

        static std::string to_string(EventStringCodes enumCase);

        static EventStringCodes from(const std::string& str);

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

            [[nodiscard]] std::string to_string(EventStringCodes type) const;
        };

    public:
        explicit PacketEventData(const std::array<std::uint8_t, 40>& bytes);

        PacketHeader m_header;
        /// Event string code @see EventStringCodes
        std::array<uint8, 4> m_eventStringCode;
        /// Event details - should be interpreted differently for each type
        EventDataDetails m_eventDetails;

        friend std::ostream& operator<<(std::ostream& os, const PacketEventData& data);
    };

    std::ostream& operator<<(std::ostream& os, const PacketEventData& data);
}
