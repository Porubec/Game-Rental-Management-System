//
// Created by adria on 1/13/2025.
//

#ifndef OSOBY_H
#define OSOBY_H
#define MENO_A_PRIEZVISKO 100
#define MAX_VELKOST 100
#include <string.h>
//#include<stdlib.h>
#include<stdio.h>

/**
 * Tento subor je len ako doplnok Evidencie hier, info o zakaznikoch.
 * Kedze Osoba by nemala ziadne funkcie, tak som ich dal do jedneho suboru.
 * K tomuto suboru je textak do ktoreho sa vypisuju zakaznici Osoby.txt.
 */
typedef struct {
    unsigned id;
    char meno[MENO_A_PRIEZVISKO];  // Meno a Priezvisko používateľa
    int pozicane;
} Osoba;

typedef struct {
    Osoba osoby[MAX_VELKOST];
    size_t pocetOsob;
}Evid_Oosb;

Osoba *pridajOsobu(Evid_Oosb *evid, const Osoba *osoba);

void vypisEvidenciu(Evid_Oosb *evid);

_Bool pozicajHru(Evid_Oosb *evid, const Osoba *osoba);

_Bool vymazOsobu(Evid_Oosb *evid, const Osoba *osoba);

void vypisDoSuboru(Evid_Oosb *evid, const char *filename);

void zoradAbecedne(Evid_Oosb *evid);
#endif //OSOBY_H
