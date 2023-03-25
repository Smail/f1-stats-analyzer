#include "ButtonFlags.h"

namespace F122 {
    std::string to_string(ButtonFlags value) {
        switch (value) {
            // @formatter:off
            case ButtonFlags::CROSS_OR_A:        return "CROSS_OR_A";
            case ButtonFlags::TRIANGLE_OR_Y:     return "TRIANGLE_OR_Y";
            case ButtonFlags::CIRCLE_OR_B:       return "CIRCLE_OR_B";
            case ButtonFlags::SQUARE_OR_X:       return "SQUARE_OR_X";
            case ButtonFlags::D_PAD_LEFT:        return "D_PAD_LEFT";
            case ButtonFlags::D_PAD_RIGHT:       return "D_PAD_RIGHT";
            case ButtonFlags::D_PAD_UP:          return "D_PAD_UP";
            case ButtonFlags::D_PAD_DOWN:        return "D_PAD_DOWN";
            case ButtonFlags::OPTIONS_OR_MENU:   return "OPTIONS_OR_MENU";
            case ButtonFlags::L1_OR_LB:          return "L1_OR_LB";
            case ButtonFlags::R1_OR_RB:          return "R1_OR_RB";
            case ButtonFlags::L2_OR_LT:          return "L2_OR_LT";
            case ButtonFlags::R2_OR_RT:          return "R2_OR_RT";
            case ButtonFlags::LEFT_STICK_CLICK:  return "LEFT_STICK_CLICK";
            case ButtonFlags::RIGHT_STICK_CLICK: return "RIGHT_STICK_CLICK";
            case ButtonFlags::RIGHT_STICK_LEFT:  return "RIGHT_STICK_LEFT";
            case ButtonFlags::RIGHT_STICK_RIGHT: return "RIGHT_STICK_RIGHT";
            case ButtonFlags::RIGHT_STICK_UP:    return "RIGHT_STICK_UP";
            case ButtonFlags::RIGHT_STICK_DOWN:  return "RIGHT_STICK_DOWN";
            case ButtonFlags::SPECIAL:           return "SPECIAL";
            case ButtonFlags::UDP_ACTION_1:      return "UDP_ACTION_1";
            case ButtonFlags::UDP_ACTION_2:      return "UDP_ACTION_2";
            case ButtonFlags::UDP_ACTION_3:      return "UDP_ACTION_3";
            case ButtonFlags::UDP_ACTION_4:      return "UDP_ACTION_4";
            case ButtonFlags::UDP_ACTION_5:      return "UDP_ACTION_5";
            case ButtonFlags::UDP_ACTION_6:      return "UDP_ACTION_6";
            case ButtonFlags::UDP_ACTION_7:      return "UDP_ACTION_7";
            case ButtonFlags::UDP_ACTION_8:      return "UDP_ACTION_8";
            case ButtonFlags::UDP_ACTION_9:      return "UDP_ACTION_9";
            case ButtonFlags::UDP_ACTION_10:     return "UDP_ACTION_10";
            case ButtonFlags::UDP_ACTION_11:     return "UDP_ACTION_11";
            case ButtonFlags::UDP_ACTION_12:     return "UDP_ACTION_12";
            default: throw std::invalid_argument("Unknown enum value: " +
                                                 std::to_string(static_cast<std::uint32_t>(value)));
            // @formatter:on
        }
    }
}
