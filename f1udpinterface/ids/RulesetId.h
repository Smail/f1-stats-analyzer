#pragma once

#include <string>

namespace F122 {
    enum class RulesetId {
        PRACTICE_AND_QUALIFYING = 0,
        RACE = 1,
        TIME_TRIAL = 2,
        TIME_ATTACK = 4,
        CHECKPOINT_CHALLENGE = 6,
        AUTOCROSS = 8,
        DRIFT = 9,
        AVERAGE_SPEED_ZONE = 10,
        RIVAL_DUEL = 11,
    };

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
