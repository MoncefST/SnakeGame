#include <graph.h>
#include "../include/grille.h"


void dessinerGrille(void) {
    /* Dessine une grille de 60 colonnes sur 40 lignes */
    int i, j;
    int tailleCase = 20; /* Taille d'une case */
    couleur couleur1 = CouleurParComposante(170, 215, 82); /* Vert clair */
    couleur couleur2 = CouleurParComposante(180, 220, 90);    /* Vert foncé */
    ChargerImageFond("img/bas_grille.png"); /*Affiche l'image du bas =>  Score... Timer...*/

    for (i = 0; i < 40; i++) {
        for (j = 0; j < 60; j++) {
            /* Alterner les couleurs en fonction de la case (1 case sur deux...) */
            couleur couleurCase = (i + j) % 2 == 0 ? couleur1 : couleur2;

            /* Dessiner la case */
            ChoisirCouleurDessin(couleurCase);
            RemplirRectangle(j * tailleCase, i * tailleCase, tailleCase, tailleCase);
        }
    }
}