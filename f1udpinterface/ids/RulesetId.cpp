#include "RulesetId.h"

namespace F122 {
    std::string to_string(RulesetId id) {
        switch (id) {
            case RulesetId::PRACTICE_AND_QUALIFYING :
                return "Practice & Qualifying";
            case RulesetId::RACE:
                return "Race";
            case RulesetId::TIME_TRIAL:
                return "Time Trial";
            case RulesetId::TIME_ATTACK:
                return "Time Attack";
            case RulesetId::CHECKPOINT_CHALLENGE:
                return "Checkpoint Challenge";
            case RulesetId::AUTOCROSS:
                return "Autocross";
            case RulesetId::DRIFT:
                return "Drift";
            case RulesetId::AVERAGE_SPEED_ZONE:
                return "Average Speed Zone";
            case RulesetId::RIVAL_DUEL:
                return "Rival Duel";
        }
    }
}
