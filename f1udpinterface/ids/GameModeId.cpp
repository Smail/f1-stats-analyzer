#include "GameModeId.h"

namespace F122 {
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
