#pragma once

#include <string>
#include <ostream>

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

    std::string to_string(RulesetId id);

    std::ostream& operator<<(std::ostream& os, const RulesetId& id);
}
