#include <stdlib.h>
#include <graph.h>
#include "../include/grille.h"
#include "../include/serpent.h"

typedef struct {
    int x;
    int y;
} Pomme;

Pomme creerPomme() {
    Pomme pomme;
    pomme.x = rand() % 59;
    pomme.y = rand() % 39;
    return pomme;
}

void dessinerPomme(Pomme pomme,int id_pomme) {
    /* Affichez une pomme*/
    AfficherSprite(id_pomme,pomme.x * TAILLE_CASE, pomme.y * TAILLE_CASE);
}

int verifierCollisionPommeSerpent(Pomme pomme, Segment serpent[], int longueur) {
    int i;
    /*Vérifie si la pomme est sur une case occupée par le serpent*/
    for (i = 0; i < longueur; ++i) {
        if (pomme.x == serpent[i].x && pomme.y == serpent[i].y) {
            return 1; /* Collision */
        }
    }
    return 0; /* Pas de collision */
}
