#pragma once

#include <string>
#include <ostream>

namespace F122 {
    enum class GameModeId {
        EVENT_MODE = 0,
        GRAND_PRIX = 3,
        TIME_TRIAL = 5,
        SPLITSCREEN = 6,
        ONLINE_CUSTOM = 7,
        ONLINE_LEAGUE = 8,
        CAREER_INVITATIONAL = 11,
        CHAMPIONSHIP_INVITATIONAL = 12,
        CHAMPIONSHIP = 13,
        ONLINE_CHAMPIONSHIP = 14,
        ONLINE_WEEKLY_EVENT = 15,
        CAREER_22 = 19,
        CAREER_22_ONLINE = 20,
        BENCHMARK = 127,
    };

    std::string to_string(GameModeId id);

    std::ostream& operator<<(std::ostream& os, const GameModeId& id);
}
