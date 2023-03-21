#pragma once

#include <string>

namespace F122 {
    enum class TeamId {
        MERCEDES = 0,
        FERRARI = 1,
        RED_BULL_RACING = 2,
        WILLIAMS = 3,
        ASTON_MARTIN = 4,
        ALPINE = 5,
        ALPHA_TAURI = 6,
        HAAS = 7,
        MCLAREN = 8,
        ALFA_ROMEO = 9,
        MERCEDES_2020 = 85,
        FERRARI_2020 = 86,
        RED_BULL_2020 = 87,
        WILLIAMS_2020 = 88,
        RACING_POINT_2020 = 89,
        RENAULT_2020 = 90,
        ALPHA_TAURI_2020 = 91,
        HAAS_2020 = 92,
        MCLAREN_2020 = 93,
        ALFA_ROMEO_2020 = 94,
        ASTON_MARTIN_DB11_V12 = 95,
        ASTON_MARTIN_VANTAGE_F1_EDITION = 96,
        ASTON_MARTIN_VANTAGE_SAFETY_CAR = 97,
        FERRARI_F8_TRIBUTO = 98,
        FERRARI_ROMA = 99,
        MCLAREN_720S = 100,
        MCLAREN_ARTURA = 101,
        MERCEDES_AMG_GT_BLACK_SERIES_SAFETY_CAR = 102,
        MERCEDES_AMG_GTR_PRO = 103,
        F1_CUSTOM_TEAM = 104,
        PREMA_21 = 106,
        UNI_VIRTUOSI_21 = 107,
        CARLIN_21 = 108,
        HITECH_21 = 109,
        ART_GP_21 = 110,
        MP_MOTORSPORT_21 = 111,
        CHAROUZ_21 = 112,
        DAMS_21 = 113,
        CAMPOS_21 = 114,
        BWT_21 = 115,
        TRIDENT_21 = 116,
        MERCEDES_AMG_GT_BLACK_SERIES = 117,
        PREMA_22 = 118,
        VIRTUOSI_22 = 119,
        CARLIN_22 = 120,
        HITECH_22 = 121,
        ART_GP_22 = 122,
        MP_MOTORSPORT_22 = 123,
        CHAROUZ_22 = 124,
        DAMS_22 = 125,
        CAMPOS_22 = 126,
        VAN_AMERSFOORT_RACING_22 = 127,
        TRIDENT_22 = 128,
    };

    std::string to_string(TeamId id) {
        switch (id) {
            case TeamId::MERCEDES:
                return "Mercedes";
            case TeamId::FERRARI:
                return "Ferrari";
            case TeamId::RED_BULL_RACING:
                return "Red Bull Racing";
            case TeamId::WILLIAMS:
                return "Williams";
            case TeamId::ASTON_MARTIN:
                return "Aston Martin";
            case TeamId::ALPINE:
                return "Alpine";
            case TeamId::ALPHA_TAURI:
                return "Alpha Tauri";
            case TeamId::HAAS:
                return "Haas";
            case TeamId::MCLAREN:
                return "McLaren";
            case TeamId::ALFA_ROMEO:
                return "Alfa Romeo";
            case TeamId::MERCEDES_2020:
                return "Mercedes 2020";
            case TeamId::FERRARI_2020:
                return "Ferrari 2020";
            case TeamId::RED_BULL_2020:
                return "Red Bull 2020";
            case TeamId::WILLIAMS_2020:
                return "Williams 2020";
            case TeamId::RACING_POINT_2020:
                return "Racing Point 2020";
            case TeamId::RENAULT_2020:
                return "Renault 2020";
            case TeamId::ALPHA_TAURI_2020:
                return "Alpha Tauri 2020";
            case TeamId::HAAS_2020:
                return "Haas 2020";
            case TeamId::MCLAREN_2020:
                return "McLaren 2020";
            case TeamId::ALFA_ROMEO_2020:
                return "Alfa Romeo 2020";
            case TeamId::ASTON_MARTIN_DB11_V12:
                return "Aston Martin DB11 V12";
            case TeamId::ASTON_MARTIN_VANTAGE_F1_EDITION:
                return "Aston Martin Vantage F1 Edition";
            case TeamId::ASTON_MARTIN_VANTAGE_SAFETY_CAR:
                return "Aston Martin Vantage Safety Car";
            case TeamId::FERRARI_F8_TRIBUTO:
                return "Ferrari F8 Tributo";
            case TeamId::FERRARI_ROMA:
                return "Ferrari Roma";
            case TeamId::MCLAREN_720S:
                return "McLaren 720S";
            case TeamId::MCLAREN_ARTURA:
                return "McLaren Artura";
            case TeamId::MERCEDES_AMG_GT_BLACK_SERIES_SAFETY_CAR:
                return "Mercedes AMG GT Black Series Safety Car";
            case TeamId::MERCEDES_AMG_GTR_PRO:
                return "Mercedes AMG GTR Pro";
            case TeamId::F1_CUSTOM_TEAM:
                return "F1 Custom Team";
            case TeamId::PREMA_21:
                return "Prema '21";
            case TeamId::UNI_VIRTUOSI_21:
                return "Uni-Virtuosi '21";
            case TeamId::CARLIN_21:
                return "Carlin '21";
            case TeamId::HITECH_21:
                return "Hitech '21";
            case TeamId::ART_GP_21:
                return "Art GP '21";
            case TeamId::MP_MOTORSPORT_21:
                return "MP Motorsport '21";
            case TeamId::CHAROUZ_21:
                return "Charouz '21";
            case TeamId::DAMS_21:
                return "Dams '21";
            case TeamId::CAMPOS_21:
                return "Campos '21";
            case TeamId::BWT_21:
                return "BWT '21";
            case TeamId::TRIDENT_21:
                return "Trident '21";
            case TeamId::MERCEDES_AMG_GT_BLACK_SERIES:
                return "Mercedes AMG GT Black Series";
            case TeamId::PREMA_22:
                return "Prema '22";
            case TeamId::VIRTUOSI_22:
                return "Virtuosi '22";
            case TeamId::CARLIN_22:
                return "Carlin '22";
            case TeamId::HITECH_22:
                return "Hitech '22";
            case TeamId::ART_GP_22:
                return "Art GP '22";
            case TeamId::MP_MOTORSPORT_22:
                return "MP Motorsport '22";
            case TeamId::CHAROUZ_22:
                return "Charouz '22";
            case TeamId::DAMS_22:
                return "Dams '22";
            case TeamId::CAMPOS_22:
                return "Campos '22";
            case TeamId::VAN_AMERSFOORT_RACING_22:
                return "Van Amersfoort Racing '22";
            case TeamId::TRIDENT_22:
                return "Trident '22";
        }
    }
}
