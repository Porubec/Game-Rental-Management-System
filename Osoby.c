//
// Created by adria on 1/13/2025.
//

#include "Osoby.h"

#include "Evidencia.h"

/**
 * Tato trieda je len ako doplnok Evidencie hier, info o zakaznikoch.
 * Kedze Osoba by nemala ziadne funkcie, tak som ich dal do jedneho suboru.
 * K tejto triede je textak do ktoreho sa vypisuju zakaznici Osoby.txt.
 */

/**
 *Pridanie osoby do evidenie.
 */
Osoba *pridajOsobu(Evid_Oosb *evid, const Osoba *osoba) {

    if (evid->pocetOsob == MAX_VELKOST) {
        printf("Evidencia je plna \n");
        return NULL;
    }


    for (int i = 0; i < evid->pocetOsob; i++) {
        if (evid->osoby[i].id == osoba->id) {
            evid->osoby[i].pozicane++;
            return &evid->osoby[i];
        }
        if (strcmp(evid->osoby[i].meno, osoba->meno) == 0) {
            printf("Osoba s rovnakym menom u existuje\n");
            return NULL;
        }
    }

    for (unsigned int i = evid->pocetOsob; i > 0; i--) {

        if (evid->osoby[i - 1].id > osoba->id) {
            evid->osoby[i] = evid->osoby[i - 1];
        } else {
            evid->osoby[i] = *osoba;
            evid->pocetOsob++;
            return &evid->osoby[i];
        }
    }


    evid->osoby[0] = *osoba;
    evid->pocetOsob++;
    return &evid->osoby[0];

}

/**
 * Vypis evidencie do consoly.
 */
void vypisEvidenciu(Evid_Oosb *evid) {
    if (evid->pocetOsob == 0) {
        printf("Evidencia je prazdna.\n");
        return;
    }
    printf("|---------------------------Evidencia Pouzivatelov----------------------------------|\n");
    printf("  %-13s%-25s%s\n","ID","Meno a Priezvisko","Pozicania");
    printf("|-----------------------------------------------------------------------------------|\n");
    for (size_t i = 0; i < evid->pocetOsob; i++) {
        printf("  %-12d %-27s  %dx\n",
               evid->osoby[i].id,
               evid->osoby[i].meno,
               evid->osoby[i].pozicane);
        printf("|-----------------------------------------------------------------------------------|\n");
        zoradAbecedne(evid);
    }
}

/**
 * Funkcia pripocitava pozicanie zakaznikovy.
 */
_Bool pozicajHru(Evid_Oosb *evid, const Osoba *osoba) {
    for (int i = 0; i < evid->pocetOsob; i++) {
        if (evid->osoby[i].id == osoba->id){
            if (evid->osoby[i].pozicane < MAX_VELKOST) {
                evid->osoby[i].pozicane++;
            }
            printf("Hra pozicana %s ID: %d.\n",osoba->meno,osoba->id);
            return 1;
        }
    }
    return 0;
}

/**
 * Vymazanie osoby z evidencie.
 */
_Bool vymazOsobu(Evid_Oosb *evid, const Osoba *osoba) {
    if (evid->pocetOsob == 0) {
        printf("Ziadne osoby sa tu nenachadzaju\n");
        return 0;
    }
    for (Osoba *i = &evid->osoby[0]; i < &evid->osoby[evid->pocetOsob]; i++) {
        if (i->id == osoba->id) {

            for (Osoba *z = i; z < &evid->osoby[evid->pocetOsob - 1]; z++) {
                *z = *(z + 1);
            }
            evid->pocetOsob--;
            printf("%s s ID:%d bola vymazana.\n",osoba->meno,osoba->id);
            return 1;
        }
    }

    printf("Osoba sa nenasla.\n");
    return 0;
}

/**
 * Vypis do suboru Osoby.txt.
 */
void vypisDoSuboru(Evid_Oosb *evid, const char *filename) {
    FILE *subor = fopen(filename, "w");  // Open file for writing
    if (subor == NULL) {
        printf("Nepodarilo sa otvorit subor %s.\n", filename);
        return;
    }


    fprintf(subor, "|------------------------Zoznam zakaznikov----------------------|\n");
    fprintf(subor, "  %-18s %-28s %s\n", "ID", "Meno a Priezvisko", "Pozicania");
    fprintf(subor, "|---------------------------------------------------------------|\n");
    for (int i = 0; i < evid->pocetOsob; i++) {
        zoradAbecedne(evid);
        fprintf(subor, "  %-14d\t %-30s\t %dx\n",
            evid->osoby[i].id,
            evid->osoby[i].meno,
            evid->osoby[i].pozicane);
        fprintf(subor, "|---------------------------------------------------------------|\n");
    }

    fclose(subor);
    }

/**
 * Metoda na zoradenie abecedne.Vyuzita vo vypisoch.
 */
void zoradAbecedne(Evid_Oosb *evid) {
    for (unsigned int i = 0; i < evid->pocetOsob - 1; i++) {
        for (unsigned int j = 0; j < evid->pocetOsob - i - 1; j++) {
            if (strcmp(evid->osoby[j].meno, evid->osoby[j + 1].meno) > 0) {
                Osoba nahrad = evid->osoby[j];
                evid->osoby[j] = evid->osoby[j + 1];
                evid->osoby[j + 1] = nahrad;
            }
        }
    }
}