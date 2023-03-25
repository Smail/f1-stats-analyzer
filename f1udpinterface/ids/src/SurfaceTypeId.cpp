#include <stdexcept>
#include "../SurfaceTypeId.h"

namespace F122 {
    std::string to_string(SurfaceTypeId id) {
        switch (id) {
            // @formatter:off
            case SurfaceTypeId::MUD:          return "Mud";
            case SurfaceTypeId::SAND:         return "Sand";
            case SurfaceTypeId::ROCK:         return "Rock";
            case SurfaceTypeId::GRASS:        return "Grass";
            case SurfaceTypeId::METAL:        return "Metal";
            case SurfaceTypeId::WATER:        return "Water";
            case SurfaceTypeId::GRAVEL:       return "Gravel";
            case SurfaceTypeId::TARMAC:       return "Tarmac";
            case SurfaceTypeId::RIDGED:       return "Ridged";
            case SurfaceTypeId::CONCRETE:     return "Concrete";
            case SurfaceTypeId::COBBLESTONE:  return "Cobblestone";
            case SurfaceTypeId::RUMBLE_STRIP: return "Rumble strip";
            default: throw std::invalid_argument("Unknown enum value: " + std::to_string(
                                                 static_cast<std::underlying_type<SurfaceTypeId>::type>(id)));
            // @formatter:on
        }
    }

    std::ostream& operator<<(std::ostream& os, const SurfaceTypeId& id) {
        return (os << to_string(id));
    }
}
