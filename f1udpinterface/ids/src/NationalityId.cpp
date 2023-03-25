#include <stdexcept>
#include "../NationalityId.h"

namespace F122 {
    std::string to_string(NationalityId id) {
        switch (id) {
            // @formatter:off
            case NationalityId::AMERICAN:       return "American";
            case NationalityId::GREEK:          return "Greek";
            case NationalityId::PARAGUAYAN:     return "Paraguayan";
            case NationalityId::ARGENTINEAN:    return "Argentinean";
            case NationalityId::GUATEMALAN:     return "Guatemalan";
            case NationalityId::PERUVIAN:       return "Peruvian";
            case NationalityId::AUSTRALIAN:     return "Australian";
            case NationalityId::HONDURAN:       return "Honduran";
            case NationalityId::POLISH:         return "Polish";
            case NationalityId::AUSTRIAN:       return "Austrian";
            case NationalityId::HONG_KONGER:    return "Hong Konger";
            case NationalityId::PORTUGUESE:     return "Portuguese";
            case NationalityId::AZERBAIJANI:    return "Azerbaijani";
            case NationalityId::HUNGARIAN:      return "Hungarian";
            case NationalityId::QATARI:         return "Qatari";
            case NationalityId::BAHRAINI:       return "Bahraini";
            case NationalityId::ICELANDER:      return "Icelander";
            case NationalityId::ROMANIAN:       return "Romanian";
            case NationalityId::BELGIAN:        return "Belgian";
            case NationalityId::INDIAN:         return "Indian";
            case NationalityId::RUSSIAN:        return "Russian";
            case NationalityId::BOLIVIAN:       return "Bolivian";
            case NationalityId::INDONESIAN:     return "Indonesian";
            case NationalityId::SALVADORAN:     return "Salvadoran";
            case NationalityId::BRAZILIAN:      return "Brazilian";
            case NationalityId::IRISH:          return "Irish";
            case NationalityId::SAUDI:          return "Saudi";
            case NationalityId::BRITISH:        return "British";
            case NationalityId::ISRAELI:        return "Israeli";
            case NationalityId::SCOTTISH:       return "Scottish";
            case NationalityId::BULGARIAN:      return "Bulgarian";
            case NationalityId::ITALIAN:        return "Italian";
            case NationalityId::SERBIAN:        return "Serbian";
            case NationalityId::CAMEROONIAN:    return "Cameroonian";
            case NationalityId::JAMAICAN:       return "Jamaican";
            case NationalityId::SINGAPOREAN:    return "Singaporean";
            case NationalityId::CANADIAN:       return "Canadian";
            case NationalityId::JAPANESE:       return "Japanese";
            case NationalityId::SLOVAKIAN:      return "Slovakian";
            case NationalityId::CHILEAN:        return "Chilean";
            case NationalityId::JORDANIAN:      return "Jordanian";
            case NationalityId::SLOVENIAN:      return "Slovenian";
            case NationalityId::CHINESE:        return "Chinese";
            case NationalityId::KUWAITI:        return "Kuwaiti";
            case NationalityId::SOUTH_KOREAN:   return "South Korean";
            case NationalityId::COLOMBIAN:      return "Colombian";
            case NationalityId::LATVIAN:        return "Latvian";
            case NationalityId::SOUTH_AFRICAN:  return "South African";
            case NationalityId::COSTA_RICAN:    return "Costa Rican";
            case NationalityId::LEBANESE:       return "Lebanese";
            case NationalityId::SPANISH:        return "Spanish";
            case NationalityId::CROATIAN:       return "Croatian";
            case NationalityId::LITHUANIAN:     return "Lithuanian";
            case NationalityId::SWEDISH:        return "Swedish";
            case NationalityId::CYPRIOT:        return "Cypriot";
            case NationalityId::LUXEMBOURGER:   return "Luxembourger";
            case NationalityId::SWISS:          return "Swiss";
            case NationalityId::CZECH:          return "Czech";
            case NationalityId::MALAYSIAN:      return "Malaysian";
            case NationalityId::THAI:           return "Thai";
            case NationalityId::DANISH:         return "Danish";
            case NationalityId::MALTESE:        return "Maltese";
            case NationalityId::TURKISH:        return "Turkish";
            case NationalityId::DUTCH:          return "Dutch";
            case NationalityId::MEXICAN:        return "Mexican";
            case NationalityId::URUGUAYAN:      return "Uruguayan";
            case NationalityId::ECUADORIAN:     return "Ecuadorian";
            case NationalityId::MONEGASQUE:     return "Monegasque";
            case NationalityId::UKRAINIAN:      return "Ukrainian";
            case NationalityId::ENGLISH:        return "English";
            case NationalityId::NEW_ZEALANDER:  return "New Zealander";
            case NationalityId::VENEZUELAN:     return "Venezuelan";
            case NationalityId::EMIRIAN:        return "Emirian";
            case NationalityId::NICARAGUAN:     return "Nicaraguan";
            case NationalityId::BARBADIAN:      return "Barbadian";
            case NationalityId::ESTONIAN:       return "Estonian";
            case NationalityId::NORTHERN_IRISH: return "Northern Irish";
            case NationalityId::WELSH:          return "Welsh";
            case NationalityId::FINNISH:        return "Finnish";
            case NationalityId::NORWEGIAN:      return "Norwegian";
            case NationalityId::VIETNAMESE:     return "Vietnamese";
            case NationalityId::FRENCH:         return "French";
            case NationalityId::OMANI:          return "Omani";
            case NationalityId::GERMAN:         return "German";
            case NationalityId::PAKISTANI:      return "Pakistani";
            case NationalityId::GHANAIAN:       return "Ghanaian";
            case NationalityId::PANAMANIAN:     return "Panamanian";
            default: throw std::invalid_argument("Unknown enum value: " + std::to_string(
                                                 static_cast<std::underlying_type<NationalityId>::type>(id)));
            // @formatter:on
        }
    }

    std::ostream& operator<<(std::ostream& os, const NationalityId& id) {
        return (os << to_string(id));
    }
}
