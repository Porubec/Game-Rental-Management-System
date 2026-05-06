//
// Created by adria on 12/26/2024.
//

#ifndef HRA_H
#define HRA_H

#define NAZOV 50
#define NAZOV_VYDAVATEL 50

//cas na dohratie
enum konzola { Xbox };

enum typ_hry { prazdna, AKCNA, STRATEGIA, RPG, SPORTOVA, LOGICKA };

//todo
typedef struct {


} Poziadavky;


typedef struct {
    char nazov[NAZOV];
    char vydavatel[NAZOV_VYDAVATEL];
    enum typ_hry typHry;
    unsigned char vek;
    double cena;
    _Bool online;
    double hviezdicky;
    unsigned int pozicane;
    unsigned int sklad;
} Hra;

int porovnajHry(const Hra *h, const Hra *h1);

void vypisHry(const Hra *h);


#endif //HRA_H
