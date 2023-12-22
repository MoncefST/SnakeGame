#include <stdlib.h>
#include <graph.h>
#include "../include/grille.h"
#include "../include/serpent.h"
#include "../include/pomme.h"

int estSurSerpent(Pomme pomme, Serpent serpent, int longueur) {
    int i;
    for (i = 0; i < longueur; ++i) {
        if (pomme.x == serpent[i].x && pomme.y == serpent[i].y) {
            return 1;  /*La pomme est sur le serpent*/
        }
    }
    return 0;  /*La pomme n'est pas sur le serpent*/
}

Pomme creerPomme(Serpent serpent, int longueur) {
    Pomme pomme;
    do {
        pomme.x = rand() % LARGEUR_GRILLE;
        pomme.y = rand() % HAUTEUR_GRILLE;
    } while (estSurSerpent(pomme, serpent, longueur));
    return pomme;
}


void dessinerPomme(Pomme pomme, int id_pomme) {
    /* Affichez une pomme */
    AfficherSprite(id_pomme, pomme.x * TAILLE_CASE, pomme.y * TAILLE_CASE);
}

int mangerPomme(Serpent serpent[], Pomme pomme) {
    return serpent[0]->x == pomme.x && serpent[0]->y == pomme.y;
}