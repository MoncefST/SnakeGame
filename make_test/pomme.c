#include <stdlib.h>
#include <graph.h>
#include "grille.h"
#include "serpent.h"

typedef struct {
    int x;
    int y;
} Pomme;

Pomme creerPomme() {
    Pomme pomme;
    pomme.x = rand() % 60;
    pomme.y = rand() % 40;
    return pomme;
}

void dessinerPomme(Pomme pomme) {
    /* Affichez une pomme*/
    int id_pomme;
    id_pomme = ChargerSprite("../img/pomme1.png");
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
