#include "DriverId.h"

namespace F122 {
    std::string to_string(DriverId id) {
        switch (id) {
            // @formatter:off
            case DriverId::CARLOS_SAINZ:         return "Carlos Sainz";
            case DriverId::LOUIS_DELETRAZ:       return "Louis Delétraz";
            case DriverId::THEO_POURCHAIRE:      return "Theo Pourchaire";
            case DriverId::DANIIL_KVYAT:         return "Daniil Kvyat";
            case DriverId::ANTONIO_FUOCO:        return "Antonio Fuoco";
            case DriverId::RICHARD_VERSCHOOR:    return "Richard Verschoor";
            case DriverId::DANIEL_RICCIARDO:     return "Daniel Ricciardo";
            case DriverId::CHARLES_LECLERC:      return "Charles Leclerc";
            case DriverId::LIRIM_ZENDELI:        return "Lirim Zendeli";
            case DriverId::FERNANDO_ALONSO:      return "Fernando Alonso";
            case DriverId::PIERRE_GASLY:         return "Pierre Gasly";
            case DriverId::DAVID_BECKMANN:       return "David Beckmann";
            case DriverId::FELIPE_MASSA:         return "Felipe Massa";
            case DriverId::ALEXANDER_ALBON:      return "Alexander Albon";
            case DriverId::ALESSIO_DELEDDA:      return "Alessio Deledda";
            case DriverId::KIMI_RAIKKONEN:       return "Kimi Räikkönen";
            case DriverId::NICHOLAS_LATIFI:      return "Nicholas Latifi";
            case DriverId::BENT_VISCAAL:         return "Bent Viscaal";
            case DriverId::LEWIS_HAMILTON:       return "Lewis Hamilton";
            case DriverId::DORIAN_BOCCOLACCI:    return "Dorian Boccolacci";
            case DriverId::ENZO_FITTIPALDI:      return "Enzo Fittipaldi";
            case DriverId::MAX_VERSTAPPEN:       return "Max Verstappen";
            case DriverId::NIKO_KARI:            return "Niko Kari";
            case DriverId::MARK_WEBBER:          return "Mark Webber";
            case DriverId::NICO_HULKENBURG:      return "Nico Hulkenburg";
            case DriverId::ROBERTO_MERHI:        return "Roberto Merhi";
            case DriverId::JACQUES_VILLENEUVE:   return "Jacques Villeneuve";
            case DriverId::KEVIN_MAGNUSSEN:      return "Kevin Magnussen";
            case DriverId::ARJUN_MAINI:          return "Arjun Maini";
            case DriverId::JAKE_HUGHES:          return "Jake Hughes";
            case DriverId::ROMAIN_GROSJEAN:      return "Romain Grosjean";
            case DriverId::ALESSIO_LORANDI:      return "Alessio Lorandi";
            case DriverId::FREDERIK_VESTI:       return "Frederik Vesti";
            case DriverId::SEBASTIAN_VETTEL:     return "Sebastian Vettel";
            case DriverId::RUBEN_MEIJER:         return "Ruben Meijer";
            case DriverId::OLLI_CALDWELL:        return "Olli Caldwell";
            case DriverId::SERGIO_PEREZ:         return "Sergio Perez";
            case DriverId::RASHID_NAIR:          return "Rashid Nair";
            case DriverId::LOGAN_SARGEANT:       return "Logan Sargeant";
            case DriverId::VALTTERI_BOTTAS:      return "Valtteri Bottas";
            case DriverId::JACK_TREMBLAY:        return "Jack Tremblay";
            case DriverId::CEM_BOLUKBASI:        return "Cem Bolukbasi";
            case DriverId::ESTEBAN_OCON:         return "Esteban Ocon";
            case DriverId::DEVON_BUTLER:         return "Devon Butler";
            case DriverId::AYUMA_IWASA:          return "Ayuma Iwasa";
            case DriverId::LANCE_STROLL:         return "Lance Stroll";
            case DriverId::LUKAS_WEBER:          return "Lukas Weber";
            case DriverId::CLEMENT_NOVOLAK:      return "Clement Novolak";
            case DriverId::ARRON_BARNES:         return "Arron Barnes";
            case DriverId::ANTONIO_GIOVINAZZI:   return "Antonio Giovinazzi";
            case DriverId::DENNIS_HAUGER:        return "Dennis Hauger";
            case DriverId::MARTIN_GILES:         return "Martin Giles";
            case DriverId::ROBERT_KUBICA:        return "Robert Kubica";
            case DriverId::CALAN_WILLIAMS:       return "Calan Williams";
            case DriverId::ALEX_MURRAY:          return "Alex Murray";
            case DriverId::ALAIN_PROST:          return "Alain Prost";
            case DriverId::JACK_DOOHAN:          return "Jack Doohan";
            case DriverId::LUCAS_ROTH:           return "Lucas Roth";
            case DriverId::AYRTON_SENNA:         return "Ayrton Senna";
            case DriverId::AMAURY_CORDEEL:       return "Amaury Cordeel";
            case DriverId::IGOR_CORREIA:         return "Igor Correia";
            case DriverId::NOBUHARU_MATSUSHITA:  return "Nobuharu Matsushita";
            case DriverId::MIKA_HAKKINEN:        return "Mika Hakkinen";
            case DriverId::SOPHIE_LEVASSEUR:     return "Sophie Levasseur";
            case DriverId::NIKITA_MAZEPIN:       return "Nikita Mazepin";
            case DriverId::JONAS_SCHIFFER:       return "Jonas Schiffer";
            case DriverId::GUANYA_ZHOU:          return "Guanya Zhou";
            case DriverId::ALAIN_FOREST:         return "Alain Forest";
            case DriverId::MICK_SCHUMACHER:      return "Mick Schumacher";
            case DriverId::JAY_LETOURNEAU:       return "Jay Letourneau";
            case DriverId::CALLUM_ILOTT:         return "Callum Ilott";
            case DriverId::ESTO_SAARI:           return "Esto Saari";
            case DriverId::JUAN_MANUEL_CORREA:   return "Manuel Correa";
            case DriverId::YASAR_ATIYEH:         return "Yasar Atiyeh";
            case DriverId::JORDAN_KING:          return "Jordan King";
            case DriverId::CALLISTO_CALABRESI:   return "Callisto Calabresi";
            case DriverId::MAHAVEER_RAGHUNATHAN: return "Mahaveer Raghunathan";
            case DriverId::NAOTA_IZUM:           return "Naota Izum";
            case DriverId::TATIANA_CALDERON:     return "Tatiana Calderon";
            case DriverId::HOWARD_CLARKE:        return "Howard Clarke";
            case DriverId::ANTHOINE_HUBERT:      return "Anthoine Hubert";
            case DriverId::WILHEIM_KAUFMANN:     return "Wilheim Kaufmann";
            case DriverId::GUILIANO_ALESI:       return "Guiliano Alesi";
            case DriverId::MARIE_LAURSEN:        return "Marie Laursen";
            case DriverId::RALPH_BOSCHUNG:       return "Ralph Boschung";
            case DriverId::FLAVIO_NIEVES:        return "Flavio Nieves";
            case DriverId::MICHAEL_SCHUMACHER:   return "Michael Schumacher";
            case DriverId::PETER_BELOUSOV:       return "Peter Belousov";
            case DriverId::DAN_TICKTUM:          return "Dan Ticktum";
            case DriverId::KLIMEK_MICHALSKI:     return "Klimek Michalski";
            case DriverId::MARCUS_ARMSTRONG:     return "Marcus Armstrong";
            case DriverId::SANTIAGO_MORENO:      return "Santiago Moreno";
            case DriverId::CHRISTIAN_LUNDGAARD:  return "Christian Lundgaard";
            case DriverId::BENJAMIN_COPPENS:     return "Benjamin Coppens";
            case DriverId::YUKI_TSUNODA:         return "Yuki Tsunoda";
            case DriverId::NOAH_VISSER:          return "Noah Visser";
            case DriverId::JEHAN_DARUVALA:       return "Jehan Daruvala";
            case DriverId::GERT_WALDMULLER:      return "Gert Waldmuller";
            case DriverId::GULHERME_SAMAIA:      return "Gulherme Samaia";
            case DriverId::JULIAN_QUESADA:       return "Julian Quesada";
            case DriverId::PEDRO_PIQUET:         return "Pedro Piquet";
            case DriverId::DANIEL_JONES:         return "Daniel Jones";
            case DriverId::FELIPE_DRUGOVICH:     return "Felipe Drugovich";
            case DriverId::ARTEM_MARKELOV:       return "Artem Markelov";
            case DriverId::ROBERT_SCHWARTZMAN:   return "Robert Schwartzman";
            case DriverId::TADASUKE_MAKINO:      return "Tadasuke Makino";
            case DriverId::ROY_NISSANY:          return "Roy Nissany";
            case DriverId::SEAN_GELAEL:          return "Sean Gelael";
            case DriverId::MARINO_SATO:          return "Marino Sato";
            case DriverId::NYCK_DE_VRIES:        return "De Vries";
            case DriverId::AIDAN_JACKSON:        return "Aidan Jackson";
            case DriverId::JACK_AITKEN:          return "Jack Aitken";
            case DriverId::CASPER_AKKERMAN:      return "Casper Akkerman";
            case DriverId::GEORGE_RUSSELL:       return "George Russell";
            case DriverId::JENSON_BUTTON:        return "Jenson Button";
            case DriverId::MAXIMILIAN_GUNTHER:   return "Maximilian Günther";
            case DriverId::DAVID_COULTHARD:      return "David Coulthard";
            case DriverId::NIREI_FUKUZUMI:       return "Nirei Fukuzumi";
            case DriverId::NICO_ROSBERG:         return "Nico Rosberg";
            case DriverId::LUCA_GHIOTTO:         return "Luca Ghiotto";
            case DriverId::OSCAR_PIASTRI:        return "Oscar Piastri";
            case DriverId::LANDO_NORRIS:         return "Lando Norris";
            case DriverId::LIAM_LAWSON:          return "Liam Lawson";
            case DriverId::SERGIO_SETTE_CAMARA:  return "Sérgio Sette Câmara";
            case DriverId::JURI_VIPS:            return "Juri Vips";
            default: throw std::invalid_argument("Unknown enum case." + std::to_string(
                                                            static_cast<std::underlying_type<DriverId>::type>(id)
                                                ));
            // @formatter:on
        }
    }

    std::ostream& operator<<(std::ostream& os, DriverId obj) {
        return (os << to_string(obj));
    }
}
