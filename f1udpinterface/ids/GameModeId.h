#pragma once

#include <string>

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

    std::string to_string(GameModeId id) {
        switch (id) {
            case GameModeId::EVENT_MODE:
                return "Event Mode";
            case GameModeId::GRAND_PRIX:
                return "Grand Prix";
            case GameModeId::TIME_TRIAL:
                return "Time Trial";
            case GameModeId::SPLITSCREEN:
                return "Splitscreen";
            case GameModeId::ONLINE_CUSTOM:
                return "Online Custom";
            case GameModeId::ONLINE_LEAGUE:
                return "Online League";
            case GameModeId::CAREER_INVITATIONAL:
                return "Career Invitational";
            case GameModeId::CHAMPIONSHIP_INVITATIONAL:
                return "Championship Invitational";
            case GameModeId::CHAMPIONSHIP:
                return "Championship";
            case GameModeId::ONLINE_CHAMPIONSHIP:
                return "Online Championship";
            case GameModeId::ONLINE_WEEKLY_EVENT:
                return "Online Weekly Event";
            case GameModeId::CAREER_22:
                return "Career '22";
            case GameModeId::CAREER_22_ONLINE:
                return "Career '22 Online";
            case GameModeId::BENCHMARK:
                return "Benchmark";
        }
    }
}
