#include "TeamColorMapping.h"

namespace F122 {
    TeamColorMapping from_team_id(TeamId teamId) {
        // @formatter:off
        switch (teamId) {
            case TeamId::MERCEDES: return TeamColorMapping::MERCEDES;
            case TeamId::FERRARI: return TeamColorMapping::FERRARI;
            case TeamId::RED_BULL_RACING: return TeamColorMapping::RED_BULL_RACING;
            case TeamId::WILLIAMS: return TeamColorMapping::WILLIAMS;
            case TeamId::ASTON_MARTIN: return TeamColorMapping::ASTON_MARTIN;
            case TeamId::ALPINE: return TeamColorMapping::ALPINE;
            case TeamId::ALPHA_TAURI: return TeamColorMapping::ALPHA_TAURI;
            case TeamId::HAAS: return TeamColorMapping::HAAS;
            case TeamId::MCLAREN: return TeamColorMapping::MCLAREN;
            case TeamId::ALFA_ROMEO: return TeamColorMapping::ALFA_ROMEO;
            default: return TeamColorMapping::UNKNOWN;
        }
        // @formatter:on
    }

    std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> to_rgba(TeamColorMapping value) {
        auto x = static_cast<std::uint32_t>(value);
        return {static_cast<std::uint8_t>((x & 0xFF000000) >> 24),
                static_cast<std::uint8_t>((x & 0xFF0000) >> 16),
                static_cast<std::uint8_t>((x & 0xFF00) >> 8),
                static_cast<std::uint8_t>(x & 0xFF)};
    }
}
