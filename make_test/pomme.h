#ifndef POMME_H
#define POMME_H

#include "../include/grille.h"
#include "../include/serpent.h"

typedef struct {
    int x;
    int y;
} Pomme;

Pomme creerPomme();
void dessinerPomme(Pomme pomme);
int verifierCollisionPommeSerpent(Pomme pomme, Segment serpent[], int longueur);

#endif /*POMME_H*/
