#pragma once

#include <cstdint>
#include <tuple>
#include "../f1udpinterface/ids/TeamId.h"

namespace F122 {
    enum class TeamColorMapping : std::uint32_t {
        MERCEDES = 0x00D2BEFF,
        FERRARI = 0xDC0000FF,
        RED_BULL_RACING = 0x0600EFFF,
        WILLIAMS = 0x005AFFFF,
        ASTON_MARTIN = 0x006F62FF,
        ALPINE = 0x0090FFFF,
        ALPHA_TAURI = 0x2B4562FF,
        HAAS = 0xF9F2F2FF,
        MCLAREN = 0xFF8700FF,
        ALFA_ROMEO = 0x900000FF,
        UNKNOWN = 0x505050FF,
    };

    TeamColorMapping from_team_id(TeamId teamId);

    std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> to_rgba(TeamColorMapping value);
}
