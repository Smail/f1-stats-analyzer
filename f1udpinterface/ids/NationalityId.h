#pragma once

#include <string>

namespace F122 {
    enum class NationalityId {
        AMERICAN = 1,
        GREEK = 31,
        PARAGUAYAN = 61,
        ARGENTINEAN = 2,
        GUATEMALAN = 32,
        PERUVIAN = 62,
        AUSTRALIAN = 3,
        HONDURAN = 33,
        POLISH = 63,
        AUSTRIAN = 4,
        HONG_KONGER = 34,
        PORTUGUESE = 64,
        AZERBAIJANI = 5,
        HUNGARIAN = 35,
        QATARI = 65,
        BAHRAINI = 6,
        ICELANDER = 36,
        ROMANIAN = 66,
        BELGIAN = 7,
        INDIAN = 37,
        RUSSIAN = 67,
        BOLIVIAN = 8,
        INDONESIAN = 38,
        SALVADORAN = 68,
        BRAZILIAN = 9,
        IRISH = 39,
        SAUDI = 69,
        BRITISH = 10,
        ISRAELI = 40,
        SCOTTISH = 70,
        BULGARIAN = 11,
        ITALIAN = 41,
        SERBIAN = 71,
        CAMEROONIAN = 12,
        JAMAICAN = 42,
        SINGAPOREAN = 72,
        CANADIAN = 13,
        JAPANESE = 43,
        SLOVAKIAN = 73,
        CHILEAN = 14,
        JORDANIAN = 44,
        SLOVENIAN = 74,
        CHINESE = 15,
        KUWAITI = 45,
        SOUTH_KOREAN = 75,
        COLOMBIAN = 16,
        LATVIAN = 46,
        SOUTH_AFRICAN = 76,
        COSTA_RICAN = 17,
        LEBANESE = 47,
        SPANISH = 77,
        CROATIAN = 18,
        LITHUANIAN = 48,
        SWEDISH = 78,
        CYPRIOT = 19,
        LUXEMBOURGER = 49,
        SWISS = 79,
        CZECH = 20,
        MALAYSIAN = 50,
        THAI = 80,
        DANISH = 21,
        MALTESE = 51,
        TURKISH = 81,
        DUTCH = 22,
        MEXICAN = 52,
        URUGUAYAN = 82,
        ECUADORIAN = 23,
        MONEGASQUE = 53,
        UKRAINIAN = 83,
        ENGLISH = 24,
        NEW_ZEALANDER = 54,
        VENEZUELAN = 84,
        EMIRIAN = 25,
        NICARAGUAN = 55,
        BARBADIAN = 85,
        ESTONIAN = 26,
        NORTHERN_IRISH = 56,
        WELSH = 86,
        FINNISH = 27,
        NORWEGIAN = 57,
        VIETNAMESE = 87,
        FRENCH = 28,
        OMANI = 58,
        GERMAN = 29,
        PAKISTANI = 59,
        GHANAIAN = 30,
        PANAMANIAN = 60,
    };

    std::string to_string(NationalityId id) {
        switch (id) {
            case NationalityId::AMERICAN:
                return "American ";
            case NationalityId::GREEK:
                return "Greek ";
            case NationalityId::PARAGUAYAN:
                return "Paraguayan";
            case NationalityId::ARGENTINEAN:
                return "Argentinean ";
            case NationalityId::GUATEMALAN:
                return "Guatemalan ";
            case NationalityId::PERUVIAN:
                return "Peruvian";
            case NationalityId::AUSTRALIAN:
                return "Australian ";
            case NationalityId::HONDURAN:
                return "Honduran ";
            case NationalityId::POLISH:
                return "Polish";
            case NationalityId::AUSTRIAN:
                return "Austrian ";
            case NationalityId::HONG_KONGER:
                return "Hong Konger ";
            case NationalityId::PORTUGUESE:
                return "Portuguese";
            case NationalityId::AZERBAIJANI:
                return "Azerbaijani ";
            case NationalityId::HUNGARIAN:
                return "Hungarian ";
            case NationalityId::QATARI:
                return "Qatari";
            case NationalityId::BAHRAINI:
                return "Bahraini ";
            case NationalityId::ICELANDER:
                return "Icelander ";
            case NationalityId::ROMANIAN:
                return "Romanian";
            case NationalityId::BELGIAN:
                return "Belgian ";
            case NationalityId::INDIAN:
                return "Indian ";
            case NationalityId::RUSSIAN:
                return "Russian";
            case NationalityId::BOLIVIAN:
                return "Bolivian ";
            case NationalityId::INDONESIAN:
                return "Indonesian ";
            case NationalityId::SALVADORAN:
                return "Salvadoran";
            case NationalityId::BRAZILIAN:
                return "Brazilian ";
            case NationalityId::IRISH:
                return "Irish ";
            case NationalityId::SAUDI:
                return "Saudi";
            case NationalityId::BRITISH:
                return "British ";
            case NationalityId::ISRAELI:
                return "Israeli ";
            case NationalityId::SCOTTISH:
                return "Scottish";
            case NationalityId::BULGARIAN:
                return "Bulgarian ";
            case NationalityId::ITALIAN:
                return "Italian ";
            case NationalityId::SERBIAN:
                return "Serbian";
            case NationalityId::CAMEROONIAN:
                return "Cameroonian ";
            case NationalityId::JAMAICAN:
                return "Jamaican ";
            case NationalityId::SINGAPOREAN:
                return "Singaporean";
            case NationalityId::CANADIAN:
                return "Canadian ";
            case NationalityId::JAPANESE:
                return "Japanese ";
            case NationalityId::SLOVAKIAN:
                return "Slovakian";
            case NationalityId::CHILEAN:
                return "Chilean ";
            case NationalityId::JORDANIAN:
                return "Jordanian ";
            case NationalityId::SLOVENIAN:
                return "Slovenian";
            case NationalityId::CHINESE:
                return "Chinese ";
            case NationalityId::KUWAITI:
                return "Kuwaiti ";
            case NationalityId::SOUTH_KOREAN:
                return "South Korean";
            case NationalityId::COLOMBIAN:
                return "Colombian ";
            case NationalityId::LATVIAN:
                return "Latvian ";
            case NationalityId::SOUTH_AFRICAN:
                return "South African";
            case NationalityId::COSTA_RICAN:
                return "Costa Rican ";
            case NationalityId::LEBANESE:
                return "Lebanese ";
            case NationalityId::SPANISH:
                return "Spanish";
            case NationalityId::CROATIAN:
                return "Croatian ";
            case NationalityId::LITHUANIAN:
                return "Lithuanian ";
            case NationalityId::SWEDISH:
                return "Swedish";
            case NationalityId::CYPRIOT:
                return "Cypriot ";
            case NationalityId::LUXEMBOURGER:
                return "Luxembourger ";
            case NationalityId::SWISS:
                return "Swiss";
            case NationalityId::CZECH:
                return "Czech ";
            case NationalityId::MALAYSIAN:
                return "Malaysian ";
            case NationalityId::THAI:
                return "Thai";
            case NationalityId::DANISH:
                return "Danish ";
            case NationalityId::MALTESE:
                return "Maltese ";
            case NationalityId::TURKISH:
                return "Turkish";
            case NationalityId::DUTCH:
                return "Dutch ";
            case NationalityId::MEXICAN:
                return "Mexican ";
            case NationalityId::URUGUAYAN:
                return "Uruguayan";
            case NationalityId::ECUADORIAN:
                return "Ecuadorian ";
            case NationalityId::MONEGASQUE:
                return "Monegasque ";
            case NationalityId::UKRAINIAN:
                return "Ukrainian";
            case NationalityId::ENGLISH:
                return "English ";
            case NationalityId::NEW_ZEALANDER:
                return "New Zealander ";
            case NationalityId::VENEZUELAN:
                return "Venezuelan";
            case NationalityId::EMIRIAN:
                return "Emirian ";
            case NationalityId::NICARAGUAN:
                return "Nicaraguan ";
            case NationalityId::BARBADIAN:
                return "Barbadian";
            case NationalityId::ESTONIAN:
                return "Estonian ";
            case NationalityId::NORTHERN_IRISH:
                return "Northern Irish ";
            case NationalityId::WELSH:
                return "Welsh";
            case NationalityId::FINNISH:
                return "Finnish ";
            case NationalityId::NORWEGIAN:
                return "Norwegian ";
            case NationalityId::VIETNAMESE:
                return "Vietnamese";
            case NationalityId::FRENCH:
                return "French ";
            case NationalityId::OMANI:
                return "Omani";
            case NationalityId::GERMAN:
                return "German ";
            case NationalityId::PAKISTANI:
                return "Pakistani";
            case NationalityId::GHANAIAN:
                return "Ghanaian ";
            case NationalityId::PANAMANIAN:
                return "Panamanian";
        }
    }
}
