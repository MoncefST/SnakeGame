#ifndef POMME_H
#define POMME_H

#include "../include/grille.h"
#include "../include/serpent.h"

typedef struct {
    int x;
    int y;
} Pomme;

Pomme creerPomme(Serpent serpent, int longueur);
void dessinerPomme(Pomme pomme,int id_pomme);
int mangerPomme(Serpent serpent[], Pomme pomme);

#endif /*POMME_H*/
