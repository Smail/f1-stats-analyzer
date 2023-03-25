#include "TrackId.h"

namespace F122 {
    std::string to_string(TrackId id) {
        switch (id) {
            case TrackId::MELBOURNE:
                return "Melbourne";
            case TrackId::PAUL_RICARD:
                return "Paul Ricard";
            case TrackId::SHANGHAI:
                return "Shanghai";
            case TrackId::SAKHIR_BAHRAIN:
                return "Sakhir (Bahrain)";
            case TrackId::CATALUNYA:
                return "Catalunya";
            case TrackId::MONACO:
                return "Monaco";
            case TrackId::MONTREAL:
                return "Montreal";
            case TrackId::SILVERSTONE:
                return "Silverstone";
            case TrackId::HOCKENHEIM:
                return "Hockenheim";
            case TrackId::HUNGARORING:
                return "Hungaroring";
            case TrackId::SPA:
                return "Spa";
            case TrackId::MONZA:
                return "Monza";
            case TrackId::SINGAPORE:
                return "Singapore";
            case TrackId::SUZUKA:
                return "Suzuka";
            case TrackId::ABU_DHABI:
                return "Abu Dhabi";
            case TrackId::TEXAS:
                return "Texas";
            case TrackId::BRAZIL:
                return "Brazil";
            case TrackId::AUSTRIA:
                return "Austria";
            case TrackId::SOCHI:
                return "Sochi";
            case TrackId::MEXICO:
                return "Mexico";
            case TrackId::BAKU_AZERBAIJAN:
                return "Baku (Azerbaijan)";
            case TrackId::SAKHIR_SHORT:
                return "Sakhir Short";
            case TrackId::SILVERSTONE_SHORT:
                return "Silverstone Short";
            case TrackId::TEXAS_SHORT:
                return "Texas Short";
            case TrackId::SUZUKA_SHORT:
                return "Suzuka Short";
            case TrackId::HANOI:
                return "Hanoi";
            case TrackId::ZANDVOORT:
                return "Zandvoort";
            case TrackId::IMOLA:
                return "Imola";
            case TrackId::PORTIMAO:
                return "Portimão";
            case TrackId::JEDDAH:
                return "Jeddah";
            case TrackId::MIAMI:
                return "Miami";
        }
    }
}
