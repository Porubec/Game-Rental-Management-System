//
// Created by adria on 12/26/2024.
//

#include <string.h>
#include "Hra.h"

#include <stdio.h>

/**
 * Trieda Hra len vytvara hru a jej parametre v .h subore.
 */

/**
 *Funkcia porovnava medzi sebou hry.
 */
int porovnajHry(const Hra *h, const Hra *h1) {
    if (h1->hviezdicky > h->hviezdicky)
        return 1;
    if (h1->hviezdicky < h->hviezdicky)
        return -1;
    return strcmp(h1->nazov, h->nazov);
}

/**
 * Funkcia vypisuje hru.
 */
void vypisHry(const Hra *h) {
    if(h == NULL) {
        printf("Ziadna Hra sa nenasla\n");

    }else{
        printf("  %-20s %-26s %-14.2f %-11d %-14d %.2f\n",
            h->nazov,
            h->vydavatel,
            h->cena,
            h->pozicane,
            h->sklad,
            h->hviezdicky);
    }
}
