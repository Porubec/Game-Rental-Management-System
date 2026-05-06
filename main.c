#include "Hra.h"
#include "Evidencia.h"
#include "Osoby.h"

int main(void) {
    Hra hry[] = {
        {
            .nazov = "Minecraft",
            .vydavatel = "Mojang",
            .typHry = LOGICKA,
            .vek = 7,
            .cena = 2.5,
            .online = 1,
            .hviezdicky = 4.8,
            .pozicane = 0,
            .sklad = 1
        },
        {
            .nazov = "FIFA 24",
            .vydavatel = "EA Sports",
            .typHry = SPORTOVA,
            .vek = 3,
            .cena = 4.00,
            .online = 1,
            .hviezdicky = 4.2,
            .pozicane = 9,
            .sklad = 5
        },
        {
            .nazov = "The Witcher 3",
            .vydavatel = "CD Projekt Red",
            .typHry = RPG,
            .vek = 18,
            .cena = 3.30,
            .online = 0,
            .hviezdicky = 4.9,
            .pozicane = 5,
            .sklad = 1
        },
        {
            .nazov = "Age of Empires IV",
            .vydavatel = "Mojang",
            .typHry = AKCNA,
            .vek = 12,
            .cena = 2.20,
            .online = 1,
            .hviezdicky = 4.5,
            .pozicane = 100,
            .sklad = 5
        },
        {
            .nazov = "Counter-Strike 2",
            .vydavatel = "Valve",
            .typHry = AKCNA,
            .vek = 16,
            .cena = 0,
            .online = 1,
            .hviezdicky = 4.7,
            .pozicane = 7,
            .sklad = 1
        }
    };
    Evidencia evid = {};
    Zaznam zoz = {};

    nacitajZTxt(&evid, "../Hry.txt");
    pridaj(&evid, &hry[0]);
    pridaj(&evid, &hry[1]);
    pridaj(&evid, &hry[2]);
    pridaj(&evid, &hry[3]);
    pridaj(&evid, &hry[4]);


/**
 *funkcie s pouzitim zaznamu, najprv musi byt funkcia premena, aby sa dalo narabat so zaznmaom.
 */

    //premena(&evid, &zoz);
    //filter_cena(&zoz, 2.00);
   // filter_TypHry(&zoz, AKCNA);
    //vypisZaznam(&zoz);
/**
 *Funkcie s evidenciou hier
 */
    //vyhladavaniePodla(&evid);
    //generujStatistiky(&evid);
    //vypocitajZisk(&evid);
    //zoradPodlaNazvu(&evid);
    //zoradPodlaCeny(&evid);
    //zoradPodlaHodnotenia(&evid);
    //skusOdstranit(&evid, &hry[4]);
    //pozicaj(&evid, &hry[1]);
    //vrat(&evid, &hry[3]);
    //vypocitajZisk(&evid);
    //generujStatistiky(&evid);
    //jeDostupna(&evid, &hry[1]);
    //dostupneHry(&evid);
    vypisVyber(&evid);

/**
 *Funkcie s evidenciou osob(zakaznikmi).
 */
    Evid_Oosb evidencia = { .pocetOsob = 0 };

    Osoba osoba1 = { .id = 235, .meno = "Jozef Novak", .pozicane = 1 };
    Osoba osoba2 = { .id = 458, .meno = "Marek Kral", .pozicane = 1};
    Osoba osoba3 = { .id = 234, .meno = "Anna Kovačová", .pozicane = 1 };
    Osoba osoba4 = { .id = 345, .meno = "Peter Horváth", .pozicane =1 };
    Osoba osoba5 = { .id = 523, .meno = "Eva Poláková", .pozicane = 1 };
    Osoba osoba6 = { .id = 673, .meno = "Martin Mažár", .pozicane = 1 };
    Osoba osoba7 = { .id = 790, .meno = "Zuzana Černá", .pozicane = 1 };
    Osoba osoba8 = { .id = 892, .meno = "Tomas Kucera", .pozicane = 1 };
    Osoba osoba9 = { .id = 413, .meno = "Ivana Mlynarová", .pozicane = 1 };
    Osoba osoba10 = { .id = 567, .meno = "Katarína Božiková", .pozicane = 1 };
    Osoba osoba11 = { .id = 762, .meno = "Lukas Molnar", .pozicane = 1 };
    Osoba osoba12 = { .id = 348, .meno = "Denisa Novotná", .pozicane = 1 };
    Osoba osoba13 = { .id = 411, .meno = "Radovan Smutný", .pozicane = 1 };
    Osoba osoba14 = { .id = 635, .meno = "Pavol Straka", .pozicane = 1 };
    Osoba osoba15 = { .id = 931, .meno = "Simona Kováčová", .pozicane = 1 };
    Osoba osoba16 ={.id = 1,.meno = "Adrian Porubec", .pozicane = 1 };
    Osoba osoba17 ={.id = 5,.meno = "Adrian Porubec", .pozicane = 1 };

    pridajOsobu(&evidencia, &osoba1);
    pridajOsobu(&evidencia, &osoba2);
    pridajOsobu(&evidencia, &osoba3);
    pridajOsobu(&evidencia, &osoba4);
    pridajOsobu(&evidencia, &osoba5);
    pridajOsobu(&evidencia, &osoba6);
    pridajOsobu(&evidencia, &osoba7);
    pridajOsobu(&evidencia, &osoba8);
    pridajOsobu(&evidencia, &osoba9);
    pridajOsobu(&evidencia, &osoba10);
    pridajOsobu(&evidencia, &osoba11);
    pridajOsobu(&evidencia, &osoba12);
    pridajOsobu(&evidencia, &osoba13);
    pridajOsobu(&evidencia, &osoba14);
    pridajOsobu(&evidencia, &osoba15);
    pridajOsobu(&evidencia, &osoba16);
    pridajOsobu(&evidencia, &osoba17);


    //pozicajHru(&evidencia,&osoba16);
    //vymazOsobu(&evidencia, &osoba1);
    //zoradAbecedne(&evidencia);
    //vypisEvidenciu(&evidencia);
    //ypisDoSuboru(&evidencia,"../Osoby.txt");


    return 0;
}
