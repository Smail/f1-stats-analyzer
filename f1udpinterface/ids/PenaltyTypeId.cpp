#include "PenaltyTypeId.h"

namespace F122 {
    std::string to_string(PenaltyTypeId id) {
        switch (id) {
            case PenaltyTypeId::DRIVE_THROUGH:
                return "Drive through";
            case PenaltyTypeId::STOP_GO:
                return "Stop Go";
            case PenaltyTypeId::GRID_PENALTY:
                return "Grid penalty";
            case PenaltyTypeId::PENALTY_REMINDER:
                return "Penalty reminder";
            case PenaltyTypeId::TIME_PENALTY:
                return "Time penalty";
            case PenaltyTypeId::WARNING:
                return "Warning";
            case PenaltyTypeId::DISQUALIFIED:
                return "Disqualified";
            case PenaltyTypeId::REMOVED_FROM_FORMATION_LAP:
                return "Removed from formation lap";
            case PenaltyTypeId::PARKED_TOO_LONG_TIMER:
                return "Parked too long timer";
            case PenaltyTypeId::TYRE_REGULATIONS:
                return "Tyre regulations";
            case PenaltyTypeId::THIS_LAP_INVALIDATED:
                return "This lap invalidated";
            case PenaltyTypeId::THIS_AND_NEXT_LAP_INVALIDATED:
                return "This and next lap invalidated";
            case PenaltyTypeId::THIS_LAP_INVALIDATED_WITHOUT_REASON:
                return "This lap invalidated without reason";
            case PenaltyTypeId::THIS_AND_NEXT_LAP_INVALIDATED_WITHOUT_REASON:
                return "This and next lap invalidated without reason";
            case PenaltyTypeId::THIS_AND_PREVIOUS_LAP_INVALIDATED:
                return "This and previous lap invalidated";
            case PenaltyTypeId::THIS_AND_PREVIOUS_LAP_INVALIDATED_WITHOUT_REASON:
                return "This and previous lap invalidated without reason";
            case PenaltyTypeId::RETIRED:
                return "Retired";
            case PenaltyTypeId::BLACK_FLAG_TIMER:
                return "Black flag timer";
        }
    }
}
