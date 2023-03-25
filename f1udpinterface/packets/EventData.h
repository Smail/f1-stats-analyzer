#pragma once

#include <string>
#include <array>
#include <sstream>
#include <ostream>
#include <cstdint>
#include "PacketHeader.h"
#include "Packet.h"

namespace F122::Network::Packets {
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
    struct EventData : public Packet {
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
                std::uint8_t vehicleIdx;
                /// Lap time is in seconds
                float lapTime;
            } FastestLap;

            struct {
                std::uint8_t vehicleIdx;
                /// Vehicle index of car retiring
            } Retirement;

            struct {
                std::uint8_t vehicleIdx;
                /// Vehicle index of team mate
            } TeamMateInPits;

            struct {
                std::uint8_t vehicleIdx;
                /// Vehicle index of the race winner
            } RaceWinner;

            struct {
                std::uint8_t penaltyType;
                /// Penalty type – see Appendices
                std::uint8_t infringementType;
                /// Infringement type – see Appendices
                std::uint8_t vehicleIdx;
                /// Vehicle index of the car the penalty is applied to
                std::uint8_t otherVehicleIdx;
                /// Vehicle index of the other car involved
                std::uint8_t time;
                /// Time gained, or time spent doing action in seconds
                std::uint8_t lapNum;
                /// Lap the penalty occurred on
                std::uint8_t placesGained;
                /// Number of places gained by this
            } Penalty;

            struct {
                std::uint8_t vehicleIdx;
                /// Vehicle index of the vehicle triggering speed trap
                float speed;
                /// Top speed achieved in kilometres per hour
                std::uint8_t isOverallFastestInSession;
                /// Overall fastest speed in session = 1, otherwise 0
                std::uint8_t isDriverFastestInSession;
                /// Fastest speed for driver in session = 1, otherwise 0
                std::uint8_t fastestVehicleIdxInSession;
                /// Vehicle index of the vehicle that is the fastest in this session
                float fastestSpeedInSession;
                /// Speed of the vehicle that is the fastest in this session
            } SpeedTrap;

            struct {
                /// Number of lights showing
                std::uint8_t numLights;
            } StartLights;

            struct {
                /// Vehicle index of the vehicle serving drive through
                std::uint8_t vehicleIdx;
            } DriveThroughPenaltyServed;

            struct {
                /// Vehicle index of the vehicle serving stop go
                std::uint8_t vehicleIdx;
            } StopGoPenaltyServed;

            struct {
                /// Frame identifier flashed back to
                std::uint32_t flashbackFrameIdentifier;
                /// Session time flashed back to
                float flashbackSessionTime;
            } Flashback;

            struct {
                /// Bit flags specifying which buttons are being pressed currently - see appendices
                std::uint32_t m_buttonStatus;
            } Buttons;

            [[nodiscard]] std::string to_string(EventStringCodes type) const;
        };

    public:
        static constexpr size_t SIZE = 40;

        explicit EventData(const std::array<std::uint8_t, SIZE>& bytes);

        ~EventData() override;

        friend std::ostream& operator<<(std::ostream& os, const EventData& data);

        PacketHeader m_header;
        /// Event string code @see EventStringCodes
        std::array<std::uint8_t, 4> m_eventStringCode;
        /// Event details - should be interpreted differently for each type
        EventDataDetails m_eventDetails;
        // TODO
//        static_assert(PacketHeader::SIZE + sizeof(m_suspensionPosition) + sizeof(m_suspensionVelocity) +
//                      sizeof(m_suspensionAcceleration) + sizeof(m_wheelSpeed) + sizeof(m_wheelSlip) +
//                      sizeof(m_localVelocityX) + sizeof(m_localVelocityY) + sizeof(m_localVelocityZ) +
//                      sizeof(m_angularVelocityX) + sizeof(m_angularVelocityY) + sizeof(m_angularVelocityZ) +
//                      sizeof(m_angularAccelerationX) + sizeof(m_angularAccelerationY) + sizeof(m_angularAccelerationZ) +
//                      sizeof(m_frontWheelsAngle) + 22 * Data::SIZE == SIZE, "Invalid size 2");
    };

    std::ostream& operator<<(std::ostream& os, const EventData& data);
}
