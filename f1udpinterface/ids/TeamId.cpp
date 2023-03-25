#include "TeamId.h"

namespace F122 {
    std::string to_string(TeamId id) {
        switch (id) {
            // @formatter:off
            case TeamId::MERCEDES:                                return "Mercedes";
            case TeamId::FERRARI:                                 return "Ferrari";
            case TeamId::RED_BULL_RACING:                         return "Red Bull Racing";
            case TeamId::WILLIAMS:                                return "Williams";
            case TeamId::ASTON_MARTIN:                            return "Aston Martin";
            case TeamId::ALPINE:                                  return "Alpine";
            case TeamId::ALPHA_TAURI:                             return "Alpha Tauri";
            case TeamId::HAAS:                                    return "Haas";
            case TeamId::MCLAREN:                                 return "McLaren";
            case TeamId::ALFA_ROMEO:                              return "Alfa Romeo";
            case TeamId::MERCEDES_2020:                           return "Mercedes 2020";
            case TeamId::FERRARI_2020:                            return "Ferrari 2020";
            case TeamId::RED_BULL_2020:                           return "Red Bull 2020";
            case TeamId::WILLIAMS_2020:                           return "Williams 2020";
            case TeamId::RACING_POINT_2020:                       return "Racing Point 2020";
            case TeamId::RENAULT_2020:                            return "Renault 2020";
            case TeamId::ALPHA_TAURI_2020:                        return "Alpha Tauri 2020";
            case TeamId::HAAS_2020:                               return "Haas 2020";
            case TeamId::MCLAREN_2020:                            return "McLaren 2020";
            case TeamId::ALFA_ROMEO_2020:                         return "Alfa Romeo 2020";
            case TeamId::FERRARI_ROMA:                            return "Ferrari Roma";
            case TeamId::MCLAREN_720S:                            return "McLaren 720S";
            case TeamId::MCLAREN_ARTURA:                          return "McLaren Artura";
            case TeamId::F1_CUSTOM_TEAM:                          return "F1 Custom Team";
            case TeamId::PREMA_21:                                return "Prema '21";
            case TeamId::CARLIN_21:                               return "Carlin '21";
            case TeamId::HITECH_21:                               return "Hitech '21";
            case TeamId::ART_GP_21:                               return "Art GP '21";
            case TeamId::CHAROUZ_21:                              return "Charouz '21";
            case TeamId::DAMS_21:                                 return "Dams '21";
            case TeamId::CAMPOS_21:                               return "Campos '21";
            case TeamId::BWT_21:                                  return "BWT '21";
            case TeamId::TRIDENT_21:                              return "Trident '21";
            case TeamId::PREMA_22:                                return "Prema '22";
            case TeamId::VIRTUOSI_22:                             return "Virtuosi '22";
            case TeamId::CARLIN_22:                               return "Carlin '22";
            case TeamId::HITECH_22:                               return "Hitech '22";
            case TeamId::ART_GP_22:                               return "Art GP '22";
            case TeamId::DAMS_22:                                 return "Dams '22";
            case TeamId::CAMPOS_22:                               return "Campos '22";
            case TeamId::CHAROUZ_22:                              return "Charouz '22";
            case TeamId::TRIDENT_22:                              return "Trident '22";
            case TeamId::UNI_VIRTUOSI_21:                         return "Uni-Virtuosi '21";
            case TeamId::MP_MOTORSPORT_21:                        return "MP Motorsport '21";
            case TeamId::MP_MOTORSPORT_22:                        return "MP Motorsport '22";
            case TeamId::FERRARI_F8_TRIBUTO:                      return "Ferrari F8 Tributo";
            case TeamId::MERCEDES_AMG_GTR_PRO:                    return "Mercedes AMG GTR Pro";
            case TeamId::ASTON_MARTIN_DB11_V12:                   return "Aston Martin DB11 V12";
            case TeamId::VAN_AMERSFOORT_RACING_22:                return "Van Amersfoort Racing '22";
            case TeamId::MERCEDES_AMG_GT_BLACK_SERIES:            return "Mercedes AMG GT Black Series";
            case TeamId::ASTON_MARTIN_VANTAGE_F1_EDITION:         return "Aston Martin Vantage F1 Edition";
            case TeamId::ASTON_MARTIN_VANTAGE_SAFETY_CAR:         return "Aston Martin Vantage Safety Car";
            case TeamId::MERCEDES_AMG_GT_BLACK_SERIES_SAFETY_CAR: return "Mercedes AMG GT Black Series Safety Car";
            // @formatter:on
        }
    }
}
