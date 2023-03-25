#include <stdexcept>
#include "TrackId.h"

namespace F122 {
    std::string to_string(TrackId id) {
        switch (id) {
            // @formatter:off
            case TrackId::SPA:               return "Spa";
            case TrackId::TEXAS:             return "Texas";
            case TrackId::IMOLA:             return "Imola";
            case TrackId::MONZA:             return "Monza";
            case TrackId::MIAMI:             return "Miami";
            case TrackId::HANOI:             return "Hanoi";
            case TrackId::SOCHI:             return "Sochi";
            case TrackId::JEDDAH:            return "Jeddah";
            case TrackId::MONACO:            return "Monaco";
            case TrackId::SUZUKA:            return "Suzuka";
            case TrackId::BRAZIL:            return "Brazil";
            case TrackId::MEXICO:            return "Mexico";
            case TrackId::AUSTRIA:           return "Austria";
            case TrackId::MONTREAL:          return "Montreal";
            case TrackId::SHANGHAI:          return "Shanghai";
            case TrackId::PORTIMAO:          return "Portimão";
            case TrackId::ABU_DHABI:         return "Abu Dhabi";
            case TrackId::MELBOURNE:         return "Melbourne";
            case TrackId::SINGAPORE:         return "Singapore";
            case TrackId::CATALUNYA:         return "Catalunya";
            case TrackId::ZANDVOORT:         return "Zandvoort";
            case TrackId::HOCKENHEIM:        return "Hockenheim";
            case TrackId::PAUL_RICARD:       return "Paul Ricard";
            case TrackId::SILVERSTONE:       return "Silverstone";
            case TrackId::HUNGARORING:       return "Hungaroring";
            case TrackId::TEXAS_SHORT:       return "Texas Short";
            case TrackId::SUZUKA_SHORT:      return "Suzuka Short";
            case TrackId::SAKHIR_SHORT:      return "Sakhir Short";
            case TrackId::SAKHIR_BAHRAIN:    return "Sakhir (Bahrain)";
            case TrackId::BAKU_AZERBAIJAN:   return "Baku (Azerbaijan)";
            case TrackId::SILVERSTONE_SHORT: return "Silverstone Short";
            default: throw std::invalid_argument("Unknown enum value: " + std::to_string(
                        static_cast<std::underlying_type<TrackId>::type>(id)
                     ));
            // @formatter:on
        }
    }

    std::ostream& operator<<(std::ostream& os, const TrackId& id) {
        return (os << to_string(id));
    }
}
