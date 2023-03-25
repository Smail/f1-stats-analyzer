#include <stdexcept>
#include "InfringementTypeId.h"

namespace F122 {
    std::string to_string(InfringementTypeId id) {
        switch (id) {
            case InfringementTypeId::BLOCKING_BY_SLOW_DRIVING:
                return "Blocking by slow driving";
            case InfringementTypeId::BLOCKING_BY_WRONG_WAY_DRIVING:
                return "Blocking by wrong way driving";
            case InfringementTypeId::REVERSING_OFF_THE_START_LINE:
                return "Reversing off the start line";
            case InfringementTypeId::BIG_COLLISION:
                return "Big Collision";
            case InfringementTypeId::SMALL_COLLISION:
                return "Small Collision";
            case InfringementTypeId::COLLISION_FAILED_TO_HAND_BACK_POSITION_SINGLE:
                return "Collision failed to hand back position single";
            case InfringementTypeId::COLLISION_FAILED_TO_HAND_BACK_POSITION_MULTIPLE:
                return "Collision failed to hand back position multiple";
            case InfringementTypeId::CORNER_CUTTING_GAINED_TIME:
                return "Corner cutting gained time";
            case InfringementTypeId::CORNER_CUTTING_OVERTAKE_SINGLE:
                return "Corner cutting overtake single";
            case InfringementTypeId::CORNER_CUTTING_OVERTAKE_MULTIPLE:
                return "Corner cutting overtake multiple";
            case InfringementTypeId::CROSSED_PIT_EXIT_LANE:
                return "Crossed pit exit lane";
            case InfringementTypeId::IGNORING_BLUE_FLAGS:
                return "Ignoring blue flags";
            case InfringementTypeId::IGNORING_YELLOW_FLAGS:
                return "Ignoring yellow flags";
            case InfringementTypeId::IGNORING_DRIVE_THROUGH:
                return "Ignoring drive through";
            case InfringementTypeId::TOO_MANY_DRIVE_THROUGHS:
                return "Too many drive throughs";
            case InfringementTypeId::DRIVE_THROUGH_REMINDER_SERVE_WITHIN_N_LAPS:
                return "Drive through reminder serve within n laps";
            case InfringementTypeId::DRIVE_THROUGH_REMINDER_SERVE_THIS_LAP:
                return "Drive through reminder serve this lap";
            case InfringementTypeId::PIT_LANE_SPEEDING:
                return "Pit lane speeding";
            case InfringementTypeId::PARKED_FOR_TOO_LONG:
                return "Parked for too long";
            case InfringementTypeId::IGNORING_TYRE_REGULATIONS:
                return "Ignoring tyre regulations";
            case InfringementTypeId::TOO_MANY_PENALTIES:
                return "Too many penalties";
            case InfringementTypeId::MULTIPLE_WARNINGS:
                return "Multiple warnings";
            case InfringementTypeId::APPROACHING_DISQUALIFICATION:
                return "Approaching disqualification";
            case InfringementTypeId::TYRE_REGULATIONS_SELECT_SINGLE:
                return "Tyre regulations select single";
            case InfringementTypeId::TYRE_REGULATIONS_SELECT_MULTIPLE:
                return "Tyre regulations select multiple";
            case InfringementTypeId::LAP_INVALIDATED_CORNER_CUTTING:
                return "Lap invalidated corner cutting";
            case InfringementTypeId::LAP_INVALIDATED_RUNNING_WIDE:
                return "Lap invalidated running wide";
            case InfringementTypeId::CORNER_CUTTING_RAN_WIDE_GAINED_TIME_MINOR:
                return "Corner cutting ran wide gained time minor";
            case InfringementTypeId::CORNER_CUTTING_RAN_WIDE_GAINED_TIME_SIGNIFICANT:
                return "Corner cutting ran wide gained time significant";
            case InfringementTypeId::CORNER_CUTTING_RAN_WIDE_GAINED_TIME_EXTREME:
                return "Corner cutting ran wide gained time extreme";
            case InfringementTypeId::LAP_INVALIDATED_WALL_RIDING:
                return "Lap invalidated wall riding";
            case InfringementTypeId::LAP_INVALIDATED_FLASHBACK_USED:
                return "Lap invalidated flashback used";
            case InfringementTypeId::LAP_INVALIDATED_RESET_TO_TRACK:
                return "Lap invalidated reset to track";
            case InfringementTypeId::BLOCKING_THE_PITLANE:
                return "Blocking the pitlane";
            case InfringementTypeId::JUMP_START:
                return "Jump start";
            case InfringementTypeId::SAFETY_CAR_TO_CAR_COLLISION:
                return "Safety car to car collision";
            case InfringementTypeId::SAFETY_CAR_ILLEGAL_OVERTAKE:
                return "Safety car illegal overtake";
            case InfringementTypeId::SAFETY_CAR_EXCEEDING_ALLOWED_PACE:
                return "Safety car exceeding allowed pace";
            case InfringementTypeId::VIRTUAL_SAFETY_CAR_EXCEEDING_ALLOWED_PACE:
                return "Virtual safety car exceeding allowed pace";
            case InfringementTypeId::FORMATION_LAP_BELOW_ALLOWED_SPEED:
                return "Formation lap below allowed speed";
            case InfringementTypeId::FORMATION_LAP_PARKING:
                return "Formation lap parking";
            case InfringementTypeId::RETIRED_MECHANICAL_FAILURE:
                return "Retired mechanical failure";
            case InfringementTypeId::RETIRED_TERMINALLY_DAMAGED:
                return "Retired terminally damaged";
            case InfringementTypeId::SAFETY_CAR_FALLING_TOO_FAR_BACK:
                return "Safety car falling too far back";
            case InfringementTypeId::BLACK_FLAG_TIMER:
                return "Black flag timer";
            case InfringementTypeId::UNSERVED_STOP_GO_PENALTY:
                return "Unserved stop go penalty";
            case InfringementTypeId::UNSERVED_DRIVE_THROUGH_PENALTY:
                return "Unserved drive through penalty";
            case InfringementTypeId::ENGINE_COMPONENT_CHANGE:
                return "Engine component change";
            case InfringementTypeId::GEARBOX_CHANGE:
                return "Gearbox change";
            case InfringementTypeId::PARC_FERME_CHANGE:
                return "Parc Fermé change";
            case InfringementTypeId::LEAGUE_GRID_PENALTY:
                return "League grid penalty";
            case InfringementTypeId::RETRY_PENALTY:
                return "Retry penalty";
            case InfringementTypeId::ILLEGAL_TIME_GAIN:
                return "Illegal time gain";
            case InfringementTypeId::MANDATORY_PITSTOP:
                return "Mandatory pitstop";
            case InfringementTypeId::ATTRIBUTE_ASSIGNED:
                return "Attribute assigned";
            default:
                throw std::invalid_argument("Unknown enum value: " + std::to_string(
                        static_cast<std::underlying_type<InfringementTypeId>::type>(id)));
        }
    }

    std::ostream& operator<<(std::ostream& os, const InfringementTypeId& id) {
        return (os << to_string(id));
    }
}
