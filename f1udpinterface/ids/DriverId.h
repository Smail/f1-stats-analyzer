#pragma once

#include <string>


namespace F122 {
    enum class DriverId {
        CARLOS_SAINZ = 0,
        LOUIS_DELETRAZ = 56,
        THEO_POURCHAIRE = 115,
        DANIIL_KVYAT = 1,
        ANTONIO_FUOCO = 57,
        RICHARD_VERSCHOOR = 116,
        DANIEL_RICCIARDO = 2,
        CHARLES_LECLERC = 58,
        LIRIM_ZENDELI = 117,
        FERNANDO_ALONSO = 3,
        PIERRE_GASLY = 59,
        DAVID_BECKMANN = 118,
        FELIPE_MASSA = 4,
        ALEXANDER_ALBON = 62,
        ALESSIO_DELEDDA = 121,
        KIMI_RAIKKONEN = 6,
        NICHOLAS_LATIFI = 63,
        BENT_VISCAAL = 122,
        LEWIS_HAMILTON = 7,
        DORIAN_BOCCOLACCI = 64,
        ENZO_FITTIPALDI = 123,
        MAX_VERSTAPPEN = 9,
        NIKO_KARI = 65,
        MARK_WEBBER = 125,
        NICO_HULKENBURG = 10,
        ROBERTO_MERHI = 66,
        JACQUES_VILLENEUVE = 126,
        KEVIN_MAGNUSSEN = 11,
        ARJUN_MAINI = 67,
        JAKE_HUGHES = 127,
        ROMAIN_GROSJEAN = 12,
        ALESSIO_LORANDI = 68,
        FREDERIK_VESTI = 128,
        SEBASTIAN_VETTEL = 13,
        RUBEN_MEIJER = 69,
        OLLI_CALDWELL = 129,
        SERGIO_PEREZ = 14,
        RASHID_NAIR = 70,
        LOGAN_SARGEANT = 130,
        VALTTERI_BOTTAS = 15,
        JACK_TREMBLAY = 71,
        CEM_BOLUKBASI = 131,
        ESTEBAN_OCON = 17,
        DEVON_BUTLER = 72,
        AYUMA_IWASA = 132,
        LANCE_STROLL = 19,
        LUKAS_WEBER = 73,
        CLEMENT_NOVOLAK = 133,
        ARRON_BARNES = 20,
        ANTONIO_GIOVINAZZI = 74,
        DENNIS_HAUGER = 134,
        MARTIN_GILES = 21,
        ROBERT_KUBICA = 75,
        CALAN_WILLIAMS = 135,
        ALEX_MURRAY = 22,
        ALAIN_PROST = 76,
        JACK_DOOHAN = 136,
        LUCAS_ROTH = 23,
        AYRTON_SENNA = 77,
        AMAURY_CORDEEL = 137,
        IGOR_CORREIA = 24,
        NOBUHARU_MATSUSHITA = 78,
        MIKA_HAKKINEN = 138,
        SOPHIE_LEVASSEUR = 25,
        NIKITA_MAZEPIN = 79,
        JONAS_SCHIFFER = 26,
        GUANYA_ZHOU = 80,
        ALAIN_FOREST = 27,
        MICK_SCHUMACHER = 81,
        JAY_LETOURNEAU = 28,
        CALLUM_ILOTT = 82,
        ESTO_SAARI = 29,
        JUAN_MANUEL_Correa = 83,
        YASAR_ATIYEH = 30,
        JORDAN_KING = 84,
        CALLISTO_CALABRESI = 31,
        MAHAVEER_RAGHUNATHAN = 85,
        NAOTA_IZUM = 32,
        TATIANA_CALDERON = 86,
        HOWARD_CLARKE = 33,
        ANTHOINE_HUBERT = 87,
        WILHEIM_KAUFMANN = 34,
        GUILIANO_ALESI = 88,
        MARIE_LAURSEN = 35,
        RALPH_BOSCHUNG = 89,
        FLAVIO_NIEVES = 36,
        MICHAEL_SCHUMACHER = 90,
        PETER_BELOUSOV = 37,
        DAN_TICKTUM = 91,
        KLIMEK_MICHALSKI = 38,
        MARCUS_ARMSTRONG = 92,
        SANTIAGO_MORENO = 39,
        CHRISTIAN_LUNDGAARD = 93,
        BENJAMIN_COPPENS = 40,
        YUKI_TSUNODA = 94,
        NOAH_VISSER = 41,
        JEHAN_DARUVALA = 95,
        GERT_WALDMULLER = 42,
        GULHERME_SAMAIA = 96,
        JULIAN_QUESADA = 43,
        PEDRO_PIQUET = 97,
        DANIEL_JONES = 44,
        FELIPE_DRUGOVICH = 98,
        ARTEM_MARKELOV = 45,
        ROBERT_SCHWARTZMAN = 99,
        TADASUKE_MAKINO = 46,
        ROY_NISSANY = 100,
        SEAN_GELAEL = 47,
        MARINO_SATO = 101,
        NYCK_DE_Vries = 48,
        AIDAN_JACKSON = 102,
        JACK_AITKEN = 49,
        CASPER_AKKERMAN = 103,
        GEORGE_RUSSELL = 50,
        JENSON_BUTTON = 109,
        MAXIMILIAN_GUNTHER = 51,
        DAVID_COULTHARD = 110,
        NIREI_FUKUZUMI = 52,
        NICO_ROSBERG = 111,
        LUCA_GHIOTTO = 53,
        OSCAR_PIASTRI = 112,
        LANDO_NORRIS = 54,
        LIAM_LAWSON = 113,
        SERGIO_SETTE_CAMARA = 55,
        JURI_VIPS = 114,
    };

    std::string to_string(DriverId id) {
        switch (id) {
            case DriverId::CARLOS_SAINZ:
                return "Carlos Sainz";
            case DriverId::LOUIS_DELETRAZ:
                return "Louis Delétraz";
            case DriverId::THEO_POURCHAIRE:
                return "Theo Pourchaire";
            case DriverId::DANIIL_KVYAT:
                return "Daniil Kvyat";
            case DriverId::ANTONIO_FUOCO:
                return "Antonio Fuoco";
            case DriverId::RICHARD_VERSCHOOR:
                return "Richard Verschoor";
            case DriverId::DANIEL_RICCIARDO:
                return "Daniel Ricciardo";
            case DriverId::CHARLES_LECLERC:
                return "Charles Leclerc";
            case DriverId::LIRIM_ZENDELI:
                return "Lirim Zendeli";
            case DriverId::FERNANDO_ALONSO:
                return "Fernando Alonso";
            case DriverId::PIERRE_GASLY:
                return "Pierre Gasly";
            case DriverId::DAVID_BECKMANN:
                return "David Beckmann";
            case DriverId::FELIPE_MASSA:
                return "Felipe Massa";
            case DriverId::ALEXANDER_ALBON:
                return "Alexander Albon";
            case DriverId::ALESSIO_DELEDDA:
                return "Alessio Deledda";
            case DriverId::KIMI_RAIKKONEN:
                return "Kimi Räikkönen";
            case DriverId::NICHOLAS_LATIFI:
                return "Nicholas Latifi";
            case DriverId::BENT_VISCAAL:
                return "Bent Viscaal";
            case DriverId::LEWIS_HAMILTON:
                return "Lewis Hamilton";
            case DriverId::DORIAN_BOCCOLACCI:
                return "Dorian Boccolacci";
            case DriverId::ENZO_FITTIPALDI:
                return "Enzo Fittipaldi";
            case DriverId::MAX_VERSTAPPEN:
                return "Max Verstappen";
            case DriverId::NIKO_KARI:
                return "Niko Kari";
            case DriverId::MARK_WEBBER:
                return "Mark Webber";
            case DriverId::NICO_HULKENBURG:
                return "Nico Hulkenburg";
            case DriverId::ROBERTO_MERHI:
                return "Roberto Merhi";
            case DriverId::JACQUES_VILLENEUVE:
                return "Jacques Villeneuve";
            case DriverId::KEVIN_MAGNUSSEN:
                return "Kevin Magnussen";
            case DriverId::ARJUN_MAINI:
                return "Arjun Maini";
            case DriverId::JAKE_HUGHES:
                return "Jake Hughes";
            case DriverId::ROMAIN_GROSJEAN:
                return "Romain Grosjean";
            case DriverId::ALESSIO_LORANDI:
                return "Alessio Lorandi";
            case DriverId::FREDERIK_VESTI:
                return "Frederik Vesti";
            case DriverId::SEBASTIAN_VETTEL:
                return "Sebastian Vettel";
            case DriverId::RUBEN_MEIJER:
                return "Ruben Meijer";
            case DriverId::OLLI_CALDWELL:
                return "Olli Caldwell";
            case DriverId::SERGIO_PEREZ:
                return "Sergio Perez";
            case DriverId::RASHID_NAIR:
                return "Rashid Nair";
            case DriverId::LOGAN_SARGEANT:
                return "Logan Sargeant";
            case DriverId::VALTTERI_BOTTAS:
                return "Valtteri Bottas";
            case DriverId::JACK_TREMBLAY:
                return "Jack Tremblay";
            case DriverId::CEM_BOLUKBASI:
                return "Cem Bolukbasi";
            case DriverId::ESTEBAN_OCON:
                return "Esteban Ocon";
            case DriverId::DEVON_BUTLER:
                return "Devon Butler";
            case DriverId::AYUMA_IWASA:
                return "Ayuma Iwasa";
            case DriverId::LANCE_STROLL:
                return "Lance Stroll";
            case DriverId::LUKAS_WEBER:
                return "Lukas Weber";
            case DriverId::CLEMENT_NOVOLAK:
                return "Clement Novolak";
            case DriverId::ARRON_BARNES:
                return "Arron Barnes";
            case DriverId::ANTONIO_GIOVINAZZI:
                return "Antonio Giovinazzi";
            case DriverId::DENNIS_HAUGER:
                return "Dennis Hauger";
            case DriverId::MARTIN_GILES:
                return "Martin Giles";
            case DriverId::ROBERT_KUBICA:
                return "Robert Kubica";
            case DriverId::CALAN_WILLIAMS:
                return "Calan Williams";
            case DriverId::ALEX_MURRAY:
                return "Alex Murray";
            case DriverId::ALAIN_PROST:
                return "Alain Prost";
            case DriverId::JACK_DOOHAN:
                return "Jack Doohan";
            case DriverId::LUCAS_ROTH:
                return "Lucas Roth";
            case DriverId::AYRTON_SENNA:
                return "Ayrton Senna";
            case DriverId::AMAURY_CORDEEL:
                return "Amaury Cordeel";
            case DriverId::IGOR_CORREIA:
                return "Igor Correia";
            case DriverId::NOBUHARU_MATSUSHITA:
                return "Nobuharu Matsushita";
            case DriverId::MIKA_HAKKINEN:
                return "Mika Hakkinen";
            case DriverId::SOPHIE_LEVASSEUR:
                return "Sophie Levasseur";
            case DriverId::NIKITA_MAZEPIN:
                return "Nikita Mazepin";
            case DriverId::JONAS_SCHIFFER:
                return "Jonas Schiffer";
            case DriverId::GUANYA_ZHOU:
                return "Guanya Zhou";
            case DriverId::ALAIN_FOREST:
                return "Alain Forest";
            case DriverId::MICK_SCHUMACHER:
                return "Mick Schumacher";
            case DriverId::JAY_LETOURNEAU:
                return "Jay Letourneau";
            case DriverId::CALLUM_ILOTT:
                return "Callum Ilott";
            case DriverId::ESTO_SAARI:
                return "Esto Saari";
            case DriverId::JUAN_MANUEL_Correa:
                return "Manuel Correa";
            case DriverId::YASAR_ATIYEH:
                return "Yasar Atiyeh";
            case DriverId::JORDAN_KING:
                return "Jordan King";
            case DriverId::CALLISTO_CALABRESI:
                return "Callisto Calabresi";
            case DriverId::MAHAVEER_RAGHUNATHAN:
                return "Mahaveer Raghunathan";
            case DriverId::NAOTA_IZUM:
                return "Naota Izum";
            case DriverId::TATIANA_CALDERON:
                return "Tatiana Calderon";
            case DriverId::HOWARD_CLARKE:
                return "Howard Clarke";
            case DriverId::ANTHOINE_HUBERT:
                return "Anthoine Hubert";
            case DriverId::WILHEIM_KAUFMANN:
                return "Wilheim Kaufmann";
            case DriverId::GUILIANO_ALESI:
                return "Guiliano Alesi";
            case DriverId::MARIE_LAURSEN:
                return "Marie Laursen";
            case DriverId::RALPH_BOSCHUNG:
                return "Ralph Boschung";
            case DriverId::FLAVIO_NIEVES:
                return "Flavio Nieves";
            case DriverId::MICHAEL_SCHUMACHER:
                return "Michael Schumacher";
            case DriverId::PETER_BELOUSOV:
                return "Peter Belousov";
            case DriverId::DAN_TICKTUM:
                return "Dan Ticktum";
            case DriverId::KLIMEK_MICHALSKI:
                return "Klimek Michalski";
            case DriverId::MARCUS_ARMSTRONG:
                return "Marcus Armstrong";
            case DriverId::SANTIAGO_MORENO:
                return "Santiago Moreno";
            case DriverId::CHRISTIAN_LUNDGAARD:
                return "Christian Lundgaard";
            case DriverId::BENJAMIN_COPPENS:
                return "Benjamin Coppens";
            case DriverId::YUKI_TSUNODA:
                return "Yuki Tsunoda";
            case DriverId::NOAH_VISSER:
                return "Noah Visser";
            case DriverId::JEHAN_DARUVALA:
                return "Jehan Daruvala";
            case DriverId::GERT_WALDMULLER:
                return "Gert Waldmuller";
            case DriverId::GULHERME_SAMAIA:
                return "Gulherme Samaia";
            case DriverId::JULIAN_QUESADA:
                return "Julian Quesada";
            case DriverId::PEDRO_PIQUET:
                return "Pedro Piquet";
            case DriverId::DANIEL_JONES:
                return "Daniel Jones";
            case DriverId::FELIPE_DRUGOVICH:
                return "Felipe Drugovich";
            case DriverId::ARTEM_MARKELOV:
                return "Artem Markelov";
            case DriverId::ROBERT_SCHWARTZMAN:
                return "Robert Schwartzman";
            case DriverId::TADASUKE_MAKINO:
                return "Tadasuke Makino";
            case DriverId::ROY_NISSANY:
                return "Roy Nissany";
            case DriverId::SEAN_GELAEL:
                return "Sean Gelael";
            case DriverId::MARINO_SATO:
                return "Marino Sato";
            case DriverId::NYCK_DE_Vries:
                return "De Vries";
            case DriverId::AIDAN_JACKSON:
                return "Aidan Jackson";
            case DriverId::JACK_AITKEN:
                return "Jack Aitken";
            case DriverId::CASPER_AKKERMAN:
                return "Casper Akkerman";
            case DriverId::GEORGE_RUSSELL:
                return "George Russell";
            case DriverId::JENSON_BUTTON:
                return "Jenson Button";
            case DriverId::MAXIMILIAN_GUNTHER  :
                return "Maximilian Günther";
            case DriverId::DAVID_COULTHARD:
                return "David Coulthard";
            case DriverId::NIREI_FUKUZUMI:
                return "Nirei Fukuzumi";
            case DriverId::NICO_ROSBERG:
                return "Nico Rosberg";
            case DriverId::LUCA_GHIOTTO:
                return "Luca Ghiotto";
            case DriverId::OSCAR_PIASTRI:
                return "Oscar Piastri";
            case DriverId::LANDO_NORRIS:
                return "Lando Norris";
            case DriverId::LIAM_LAWSON:
                return "Liam Lawson";
            case DriverId::SERGIO_SETTE_CAMARA :
                return "Sérgio Sette Câmara";
            case DriverId::JURI_VIPS:
                return "Juri Vips";
        }
    }
}
