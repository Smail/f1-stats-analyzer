#include <stdexcept>
#include "RulesetId.h"

namespace F122 {
    std::string to_string(RulesetId id) {
        switch (id) {
            // @formatter:off
            case RulesetId::RACE:                    return "Race";
            case RulesetId::DRIFT:                   return "Drift";
            case RulesetId::TIME_TRIAL:              return "Time Trial";
            case RulesetId::AUTOCROSS:               return "Autocross";
            case RulesetId::RIVAL_DUEL:              return "Rival Duel";
            case RulesetId::TIME_ATTACK:             return "Time Attack";
            case RulesetId::AVERAGE_SPEED_ZONE:      return "Average Speed Zone";
            case RulesetId::CHECKPOINT_CHALLENGE:    return "Checkpoint Challenge";
            case RulesetId::PRACTICE_AND_QUALIFYING: return "Practice & Qualifying";
            default: throw std::invalid_argument("Unknown enum value: " + std::to_string(
                                                            static_cast<std::underlying_type<RulesetId>::type>(id)
                                                ));
            // @formatter:on
        }
    }

    std::ostream& operator<<(std::ostream& os, const RulesetId& id) {
        return (os << to_string(id));
    }
}
