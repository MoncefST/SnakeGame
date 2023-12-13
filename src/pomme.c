#include <stdlib.h>
#include <graph.h>
#include "../include/grille.h"
#include "../include/serpent.h"
#include "../include/pomme.h"

Pomme creerPomme(Segment serpent[], int longueur) {
    Pomme pomme;
    int i;
    int serpentOccupation[LARGEUR_GRILLE][HAUTEUR_GRILLE] = {0};  /*Utiliser les constantes de grille.h*/

    /*Marquer les cases occupées par le serpent*/
    for (i = 0; i < longueur; ++i) {
        serpentOccupation[serpent[i].x][serpent[i].y] = 1;
    }

    do {
        pomme.x = rand() % LARGEUR_GRILLE;
        pomme.y = rand() % HAUTEUR_GRILLE;
    } while (serpentOccupation[pomme.x][pomme.y]);

    return pomme;
}

void dessinerPomme(Pomme pomme, int id_pomme) {
    /* Affichez une pomme */
    AfficherSprite(id_pomme, pomme.x * TAILLE_CASE, pomme.y * TAILLE_CASE);
}

int verifierCollisionPommeSerpent(Pomme pomme, Segment serpent[], int longueur) {
    int i;
    /* Vérifie si la pomme est sur une case occupée par le serpent */
    for (i = 0; i < longueur; ++i) {
        if (pomme.x == serpent[i].x && pomme.y == serpent[i].y) {
            return 1; /* Collision */
        }
    }
    return 0; /* Pas de collision */
}
