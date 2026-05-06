//
// Created by adria on 12/26/2024.
//
#ifndef EVIDENCIA_H
#define EVIDENCIA_H
#include <stdlib.h>

#include "Hra.h"

#define VELKOST_EVIDENCIE 50


typedef struct {
    Hra *hry[VELKOST_EVIDENCIE];
    size_t velkost;
} Zaznam;

typedef struct {
    Hra hry[VELKOST_EVIDENCIE];
    size_t velkost;
} Evidencia;

void vypisVyber(const Evidencia *evid);

void vypisZaznam(const Zaznam *zoz);

void vyhladavanie(Evidencia *evid, const char *nazov);

void vyhladavanieVydavatel(Evidencia *evid, const char *vydavatel);

void vyhladavanieTypHry(Evidencia *evid, enum typ_hry typ);

void vyhladavanieVek(Evidencia *evid, unsigned char vek);

void vyhladavanieCena(Evidencia *evid, double cena);

void vyhladavanieOnline(Evidencia *evid, _Bool online);

void vyhladavanieHviezdicky(Evidencia *evid, double hviezdicky);

void vyhladavaniePodla(Evidencia *evid);

Hra *pridaj(Evidencia *evid, const Hra *h);

_Bool skusOdstranit(Evidencia *evid, const Hra *h);

void premena(Evidencia *evid, Zaznam *z);

void filter_TypHry(Zaznam *zoz,  enum typ_hry t);

void filter_cena(Zaznam *zoz, double cena);

_Bool pozicaj(Evidencia *evid, const Hra *h);

_Bool vrat(Evidencia *evid, const Hra *h);

_Bool nacitajZTxt(Evidencia *evid, const char *nazovSuboru);

double vypocitajZisk(const Evidencia *evid);

void generujStatistiky(const Evidencia *evid);

_Bool jeDostupna(const Evidencia *evid, const Hra *h);

void zoradPodlaNazvu(Evidencia *evid);

void zoradPodlaCeny(Evidencia *evid);

void zoradPodlaHodnotenia(Evidencia *evid);

void dostupneHry(const Evidencia *evid);

#endif //EVIDENCIA_H