#include "Evidencia.h"
#include <stdio.h>
#include <string.h>
/**
 *Trieda je Evidencia hier, Pozicovna hier htrora ma prehlad o hrach stavu skladov, poctom pozicanych a roznych inych vlastnosti ktore by mala pozicovna mat.
*Taktiez je k tejto triede textak Hry.txt z ktoreho sa daju nacitat Hry.
*/

/**
 * Vypis evidencie.
 */
void vypisVyber(const Evidencia *evid) {
    if (evid->velkost == 0) {
        printf("Evidencia je prazdna.\n");
    }
    printf("|------------------------------------------EVIDENCIA HIER--------------------------------------------|\n");
    printf("  %-21s%-25s%-11s%-14s%-15s %s\n", "Nazov:", "Vydavatel:", "Cena($)", "Pozicane(ks)", "Sklad(ks)", "Hodnotenie");
    printf("|----------------------------------------------------------------------------------------------------|\n");

    for (int i = 0; i < evid->velkost; i++) {
        vypisHry(&evid->hry[i]);
        printf(
            "|----------------------------------------------------------------------------------------------------|\n");
    }
}

/**
 * Vypis zoznamu.
 */
void vypisZaznam(const Zaznam *zoz) {
    if (zoz->velkost == 0) {
        printf("Zoznam je prazdny alebo si ho neurobil z evidencie.\n");
        return;
    }
    printf("|----------------------------------------------ZAZNAM HIER-------------------------------------------|\n");
    printf("  %-21s%-25s%-11s%-14s%-15s %s\n", "Nazov:", "Vydavatel:", "Cena($)", "Pozicane(ks)", "Sklad(ks)", "Hodnotenie");
    printf("|----------------------------------------------------------------------------------------------------|\n");

    for (int i = 0; i < zoz->velkost; i++) {
        vypisHry(zoz->hry[i]);
        printf(
            "|----------------------------------------------------------------------------------------------------|\n");
    }
}

/**
 * Metoda na vyhladavanie podla nazvu.
 */
void vyhladavanie(Evidencia *evid, const char *nazov) {
    if (evid->velkost == 0) {
        printf("Nic neni v Evidencii\n");
        return;
    }
    printf("------------------------Zhoda-------------------------\n");
    printf("  %-21s%-25s%-11s%-14s%-15s %s\n", "Nazov:", "Vydavatel:", "Cena($)", "Pozicane(ks)", "Sklad(ks)", "Hodnotenie");
    printf("-------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < evid->velkost; i++) {
        if (!strcmp(evid->hry[i].nazov, nazov)) {
            vypisHry(&evid->hry[i]);
        }
    }
}

/**
 * Metoda na vyhladavanie podla vydavatela.
 */
void vyhladavanieVydavatel(Evidencia *evid, const char *vydavatel) {
    if (evid->velkost == 0) {
        printf("Nic neni v Evidencii\n");
        return;
    }
    printf("------------------------Zhody-------------------------\n");
    printf("  %-21s%-25s%-11s%-14s%-15s %s\n", "Nazov:", "Vydavatel:", "Cena($)", "Pozicane(ks)", "Sklad(ks)", "Hodnotenie");
    printf("-------------------------------------------------------------------------------------------------------\n");
    size_t a = 0;
    for (int i = 0; i < evid->velkost; i++) {
        if (strcmp(evid->hry[i].vydavatel, vydavatel) == 0) {
            vypisHry(&evid->hry[i]);
            a++;
        }
    }
    if (!a) {
        printf("Ziadne hry od vydavatela '%s' sa nenasli.\n", vydavatel);
    }
}

// Vyhľadávanie podľa veku
void vyhladavanieVek(Evidencia *evid, unsigned char vek) {
    if (evid->velkost == 0) {
        printf("Nic neni v Evidencii\n");
        return;
    }
    printf("------------------------Zhody-------------------------\n");
    printf("  %-21s%-25s%-11s%-14s%-15s %s\n", "Nazov:", "Vydavatel:", "Cena($)", "Pozicane(ks)", "Sklad(ks)", "Hodnotenie");
    printf("-------------------------------------------------------------------------------------------------------\n");
    size_t a = 0;
    for (int i = 0; i < evid->velkost; i++) {
        if (evid->hry[i].vek == vek) {
            vypisHry(&evid->hry[i]);
            a++;
        }
    }
    if (!a) {
        printf("Ziadne hry pre vek '%d' sa nenasli.\n", vek);
    }
}

// Vyhľadávanie podľa ceny
void vyhladavanieCena(Evidencia *evid, double cena) {
    if (evid->velkost == 0) {
        printf("Nic neni v Evidencii\n");
        return;
    }
    printf("------------------------Zhody-------------------------\n");
    printf("  %-21s%-25s%-11s%-14s%-15s %s\n", "Nazov:", "Vydavatel:", "Cena($)", "Pozicane(ks)", "Sklad(ks)", "Hodnotenie");
    printf("-------------------------------------------------------------------------------------------------------\n");
    size_t a = 0;
    for (int i = 0; i < evid->velkost; i++) {
        if (evid->hry[i].cena == cena) {
            vypisHry(&evid->hry[i]);
            a++;
        }
    }
    if (!a) {
        printf("Ziadne hry s cenou '%f' sa nenasli.\n", cena);
    }
}

// Vyhľadávanie podľa stavu online
void vyhladavanieOnline(Evidencia *evid, _Bool online) {
    if (evid->velkost == 0) {
        printf("Nic neni v Evidencii\n");
        return;
    }
    printf("------------------------Zhody-------------------------\n");
    printf("  %-21s%-25s%-11s%-14s%-15s %s\n", "Nazov:", "Vydavatel:", "Cena($)", "Pozicane(ks)", "Sklad(ks)", "Hodnotenie");
    printf("-------------------------------------------------------------------------------------------------------\n");
    size_t a = 0;
    for (int i = 0; i < evid->velkost; i++) {
        if (evid->hry[i].online == online) {
            vypisHry(&evid->hry[i]);
            a++;
        }
    }
    if (!a) {
        printf("Ziadne hry s online stavom '%s' sa nenasli.\n", online ? "Ano" : "Nie");
    }
}

// Vyhľadávanie podľa hodnotenia hviezdičkami
void vyhladavanieHviezdicky(Evidencia *evid, double hviezdicky) {
    if (evid->velkost == 0) {
        printf("Nic neni v Evidencii\n");
        return;
    }
    printf("------------------------Zhody-------------------------\n");
    printf("  %-21s%-25s%-11s%-14s%-15s %s\n", "Nazov:", "Vydavatel:", "Cena($)", "Pozicane(ks)", "Sklad(ks)", "Hodnotenie");
    printf("-------------------------------------------------------------------------------------------------------\n");
    size_t a = 0;
    for (int i = 0; i < evid->velkost; i++) {
        if (evid->hry[i].hviezdicky == hviezdicky) {
            vypisHry(&evid->hry[i]);
            a++;
        }
    }
    if (!a) {
        printf("Ziadne hry s hodnotenim %.1f hviezdiciek sa nenasli.\n", hviezdicky);
    }
}

// Funkcia na vyhľadávanie podľa zvolenej kategórie
void vyhladavaniePodla(Evidencia *evid) {
    char kriterium[20];
    printf("Moznosti: nazov,vydavatel, vek, cena, online, hviezdicky\n");
    printf("Zadajte kriterium:\n ");
    scanf(" %99[^\n]", kriterium);

    if (!evid) {
        printf("Nespravne zadane parametre alebo prazdna evidencia!\n");
        return;
    }
    if (strcmp(kriterium, "nazov") == 0) {
        char nazov[NAZOV];
        printf("Zadaj nazov: ");
        scanf(" %29[^\n]", nazov);
        vyhladavanie(evid, nazov);
    } else if (strcmp(kriterium, "vydavatel") == 0) {
        char vydavatel[NAZOV_VYDAVATEL];
        printf("Zadajte vydavatela: ");
        scanf(" %29[^\n]", vydavatel);
        vyhladavanieVydavatel(evid, vydavatel);
    } else if (strcmp(kriterium, "vek") == 0) {
        unsigned char vek;
        printf("Zadajte vek: ");
        scanf("%hhu", &vek);
        vyhladavanieVek(evid, vek);
    } else if (strcmp(kriterium, "cena") == 0) {
        double cena;
        printf("Zadajte cenu: ");
        scanf("%lf", &cena);
        vyhladavanieCena(evid, cena);
    } else if (strcmp(kriterium, "online") == 0) {
        _Bool online;
        printf("Zadajte online stav (0 = Nie, 1 = Ano): ");
        scanf("%hhu", &online);
        vyhladavanieOnline(evid, online);
    } else if (strcmp(kriterium, "hviezdicky") == 0) {
        double hviezdicky;
        printf("Zadajte pocet hviezdiciek: ");
        scanf("%lf", &hviezdicky);
        vyhladavanieHviezdicky(evid, hviezdicky);
    } else {
        printf("Nezname kriterium '%s'.\n", kriterium);
    }
}

/**
 *Metoda na pridavanie hier do evidencie
*/
Hra *pridaj(Evidencia *evid, const Hra *h) {
    if (evid->velkost == VELKOST_EVIDENCIE)
        return NULL;

    for (int i = 0; i < evid->velkost; i++)
        if (strcmp(evid->hry[i].nazov, h->nazov) == 0) {
            evid->hry->sklad++;
            return &evid->hry[i];
        }

    for (unsigned int i = evid->velkost; i > 0; i--) {
        if (porovnajHry(h, &evid->hry[i - 1]) == -1) {
            evid->hry[i] = evid->hry[i - 1];
        } else {
            evid->hry[i] = *h;
            evid->velkost++;
            return &evid->hry[i];
        }
    }

    evid->hry[0] = *h;
    evid->velkost++;
    return &evid->hry[0];
}

/**
 *Metoda na odstranenie hry z evidencie.
*/
_Bool skusOdstranit(Evidencia *evid, const Hra *h) {
    if (evid->velkost == 0) {
        printf("Ziadna hra sa tu nenachadza");
        return 0;
    }
    for (Hra *i = &evid->hry[0]; i < &evid->hry[evid->velkost]; i++) {
        if (strcmp(h->nazov, i->nazov) == 0) {
            for (Hra *z = i; z < &evid->hry[evid->velkost - 1]; z++) {
                *z = *(z + 1);
            }
            evid->velkost--;
            return 1;
        }
    }
    return 0;
}

/**
 * Funkcia spravi kopiu evidencie do zoznamu.
 */
void premena(Evidencia *evid, Zaznam *z) {
    for (int i = 0; i < evid->velkost; i++) {
        z->hry[i] = &evid->hry[i];
    }
    z->velkost = evid->velkost;
}

/**
 * Funkcia vracia kopiu evidencie (zoznam) na hry ktore su nejakeho urciteho typu (AKCNE,RPG...).
 */
void filter_TypHry(Zaznam *zoz, const enum typ_hry t) {
    if (zoz->velkost == 0) {
        printf("Nic neni v Evidencii\n");
        return;
    }
    for (int i = 0; i < zoz->velkost; i++) {
        if (zoz->hry[i]->typHry != t) {
            for (int z = i; z < zoz->velkost - 1; z++) {
                zoz->hry[z] = zoz->hry[z + 1];
            }
            zoz->hry[--zoz->velkost] = NULL;
            i--; // Musi zacinat vzdy od 0 prvku  "overflow if unsigned"
        }
    }
}

/**
 * Funkcia vracia kopiu evidencie (zoznam) na hry ktore su pod nejaku urcitu sumu.
 */
void filter_cena(Zaznam *zoz, const double cena) {
    if (zoz->velkost == 0) {
        printf("Nic neni v Zozname\n");
        return;
    }
    for (int i = 0; i < zoz->velkost; i++) {
        if (zoz->hry[i]->cena > cena) {
            for (int z = i; z < zoz->velkost - 1; z++) {
                zoz->hry[z] = zoz->hry[z + 1];
            }
            zoz->hry[--zoz->velkost] = NULL;
            i--; // Musi zacinat vzdy od 0 prvku "overflow if unsigned"
        }
    }
}

/**
 * Metoda ppozicia 1 kus ak je na sklade.
 */
_Bool pozicaj(Evidencia *evid, const Hra *h) {
    if (evid == NULL || h == NULL) {
        printf("Neplatné vstupy\n");
        return 0;
    }

    for (int i = 0; i < evid->velkost; i++) {
        if (strcmp(evid->hry[i].nazov, h->nazov) == 0) {
            if (evid->hry[i].sklad <= 0) {
                printf("%s není na sklade\n", evid->hry[i].nazov);
                return 0;
            }
            evid->hry[i].pozicane ++;
            evid->hry[i].sklad --;
            return 1;
        }
    }
    printf("Hra s názvom %s nebola nájdená v evidencii.\n", h->nazov);
    return 0;
}
/**
 *Funkcia vrati pozicanu hru.
 */
_Bool vrat(Evidencia *evid, const Hra *h) {
    if (evid == NULL || h == NULL) {
        printf("Neplatné vstupy\n");
        return 0;
    }
    for (int i = 0; i < evid->velkost; i++)
        if (strcmp(evid->hry[i].nazov, h->nazov) == 0) {
            if (evid->hry[i].pozicane == 0) {
                printf("%s Profit\n", evid->hry[i].nazov);
                evid->hry[i].sklad++;
                return 0;
            }
            evid->hry[i].pozicane--;
            evid->hry[i].sklad++;
            return 1;
        }
    pridaj(evid, h);
    return 1;
}

/**
 * Funkcia nacita hry z Hry.txt a prida ich ,ak neni evidencia plna.
 */
_Bool nacitajZTxt(Evidencia *evid, const char *nazovSuboru) {
    FILE *subor = fopen(nazovSuboru, "r");
    if (subor == NULL) {
        perror("Nepodarilo sa otvoriť súbor");
        return 0;
    }

    int velkostRiadku = NAZOV + NAZOV_VYDAVATEL + 32 + 2 + 20 + 2 + 10 + 500 + 500; // Maximálna veľkosť riadku
    char buffer[velkostRiadku];

    while (fgets(buffer, velkostRiadku, subor)) {
        Hra hra = {}; // Inicializácia novej hry
        char typHry[32]; // Na načítanie kategórie ako reťazca

        // Názov
        char *pom = strchr(buffer, '|');
        if (pom == NULL) continue; // Skip if there's no delimiter
        strncpy(hra.nazov, buffer, pom - buffer);
        hra.nazov[pom - buffer] = '\0';

        // Vydavateľ
        char *pom2 = pom + 1;
        pom = strchr(pom2, '|');
        if (pom == NULL) continue;
        strncpy(hra.vydavatel, pom2, pom - pom2);
        hra.vydavatel[pom - pom2] = '\0';

        // Typ hry
        pom2 = pom + 1;
        pom = strchr(pom2, '|');
        if (pom == NULL) continue;
        strncpy(typHry, pom2, pom - pom2);
        typHry[pom - pom2] = '\0';

        // Vek
        pom2 = pom + 1;
        pom = strchr(pom2, '|');
        if (pom == NULL) continue;
        sscanf(pom2, "%hhu", &hra.vek);

        // Cena
        pom2 = pom + 1;
        pom = strchr(pom2, '|');
        if (pom == NULL) continue;
        sscanf(pom2, "%lf", &hra.cena);

        // Online
        pom2 = pom + 1;
        pom = strchr(pom2, '|');
        if (pom == NULL) continue;
        hra.online = (_Bool) atoi(pom2);

        // Hviezdičky
        pom2 = pom + 1;
        pom = strchr(pom2, '|');
        if (pom == NULL) continue;
        sscanf(pom2, "%lf", &hra.hviezdicky);

        // Počet požičaných
        pom2 = pom + 1;
        pom = strchr(pom2, '|');
        if (pom == NULL) continue;
        sscanf(pom2, "%d", &hra.pozicane);

        // Skladové zásoby
        pom2 = pom + 1;
        pom = strchr(pom2, '\n');
        if (pom == NULL) continue;
        sscanf(pom2, "%d", &hra.sklad);

        // Konverzia typu hry
        if (strcmp(typHry, "AKCNA") == 0) {
            hra.typHry = AKCNA;
        } else if (strcmp(typHry, "RPG") == 0) {
            hra.typHry = RPG;
        } else if (strcmp(typHry, "LOGICKA") == 0) {
            hra.typHry = LOGICKA;
        } else if (strcmp(typHry, "SPORTOVA") == 0) {
            hra.typHry = SPORTOVA;
        } else if (strcmp(typHry, "STRATEGIA") == 0) {
            hra.typHry = STRATEGIA;
        } else {
            printf("Neznáma kategória: %s\n", typHry);
            continue;
        }

        // Pridanie hry do evidencie
        if (!pridaj(evid, &hra)) {
            printf("Evidencia je plná, hra %s sa nedala pridať.\n", hra.nazov);
        }
    }
    fclose(subor);
    return 1;
}

/**
 * Vypise zisk z aktualne pozicanych hier.
 */
double vypocitajZisk(const Evidencia *evid) {
    double zisk = 0.0;


    for (unsigned int i = 0; i < evid->velkost; i++) {
        Hra hra = evid->hry[i];
        zisk += hra.cena * hra.pozicane;
    }

    printf("Celkovy zisk = %2.f$\n", zisk);
    return zisk;
}

/**
 * Vypise statistiku najpoziciavanejsia/najmenej poziciavana
 */
void generujStatistiky(const Evidencia *evid) {
    if (evid->velkost == 0) {
        printf("Nic neni v Evidencii\n");
        return;
    }
    double celkoveHodnotenie = 0.0;
    unsigned int celkovyPocetPozicani = 0;
    unsigned int najviacPozicaneHry = 0;
    unsigned int najmenejPozicanych = 0;
    unsigned int MaxPozicani = 0;
    unsigned int MinPozicani = 0;

    for (unsigned int i = 0; i < evid->velkost; i++) {
        Hra hra = evid->hry[i];
        celkoveHodnotenie += hra.hviezdicky;

        celkovyPocetPozicani += hra.pozicane;

        if (hra.pozicane > MaxPozicani) {
            MaxPozicani = hra.pozicane;
            najviacPozicaneHry = i;
        }
        if (hra.pozicane < MinPozicani) {
            MinPozicani = hra.pozicane;
            najmenejPozicanych = i;
        }
    }
    double priemerneHodnotenie = celkoveHodnotenie / (double) evid->velkost;
    double priemernyPocetPozicani = (double) celkovyPocetPozicani / MaxPozicani;

    printf("Priemerne hodnotenie Hier: %.2f\n", priemerneHodnotenie);
    printf("Priemerne pozicania Najoblubenejsej Hry: %.2f\n", priemernyPocetPozicani);


    Hra najviacPozicanaHra = evid->hry[najviacPozicaneHry];
    printf("Najviac pozicani: %s, Pozicane: %dx\n", najviacPozicanaHra.nazov, MaxPozicani);
    printf("Hodnotenie: %.2f\n", najviacPozicanaHra.hviezdicky);
    Hra najmenejPozicanaHra = evid->hry[najmenejPozicanych];
    printf("Najmenej pozicani: %s, Pozicane: %dx\n", najmenejPozicanaHra.nazov, MinPozicani);
}

/**
 * Kontrola ci je vybrata hra dostupna.
 */
_Bool jeDostupna(const Evidencia *evid, const Hra *h) {
    if (h->sklad != 0) {
        printf("Dostupny pocet %d\n", h->sklad);
        return 1;
    }
    return 0;
}

/**
 *
 * Zoradenie Hier podla mena.
 */
void zoradPodlaNazvu(Evidencia *evid) {
    if (evid->velkost == 0) {
        printf("Nic neni v Evidencii\n");
        return;
    }
    for (unsigned int i = 0; i < evid->velkost - 1; i++) {
        for (unsigned int j = 0; j < evid->velkost - i - 1; j++) {
            if (strcmp(evid->hry[j].nazov, evid->hry[j + 1].nazov) > 0) {
                Hra hra = evid->hry[j];
                evid->hry[j] = evid->hry[j + 1];
                evid->hry[j + 1] = hra;
            }
        }
    }
}

void zoradPodlaCeny(Evidencia *evid) {
    if (evid->velkost == 0) {
        printf("Nic neni v Evidencii\n");
        return;
    }
    for (unsigned int i = 0; i < evid->velkost - 1; i++) {
        for (unsigned int j = 0; j < evid->velkost - i - 1; j++) {
            if (evid->hry[j].cena > evid->hry[j + 1].cena) {
                Hra hra = evid->hry[j];
                evid->hry[j] = evid->hry[j + 1];
                evid->hry[j + 1] = hra;
            }
        }
    }
}

void zoradPodlaHodnotenia(Evidencia *evid) {
    if (evid->velkost == 0) {
        printf("Nic neni v Evidencii\n");
        return;
    }
    for (unsigned int i = 0; i < evid->velkost - 1; i++) {
        for (unsigned int j = 0; j < evid->velkost - i - 1; j++) {
            if (evid->hry[j].hviezdicky > evid->hry[j + 1].hviezdicky) {
                Hra hra = evid->hry[j];
                evid->hry[j] = evid->hry[j + 1];
                evid->hry[j + 1] = hra;
            }
        }
    }
}

/**
 * Vypis vsetkych dostupnych hier.
 */
void dostupneHry(const Evidencia *evid) {
    if (evid->velkost == 0) {
        printf("Nic neni v Evidencii\n");
        return;
    }
    int dostupne = 0;
    printf("------------------------Dostupne-------------------------\n");
    printf("  %-21s%-25s%-11s%-14s%-15s %s\n", "Nazov:", "Vydavatel:", "Cena($)", "Pozicane(ks)", "Sklad(ks)", "Hodnotenie");
    printf("-------------------------------------------------------------------------------------------------------\n");
    for (unsigned int i = 0; i < evid->velkost; i++) {
        if (evid->hry[i].sklad != 0) {
            vypisHry(&evid->hry[i]);
            dostupne++;
        }
    }
    if (dostupne == 0) {
        printf("Nic neni dostupne.");
    }
}
