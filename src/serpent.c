#include <stdio.h>
#include <graph.h>
#include "../include/serpent.h"
#define TAILLE_CASE 20
#define LARGEUR_GRILLE 60
#define HAUTEUR_GRILLE 40


void initialiserSerpent(Segment serpent[], int *longueur) {
    int i;
    for (i = 0; i < 10; ++i) {
        serpent[i].x = 10 - i;
        serpent[i].y = 10;
    }

    *longueur = 10;
}

void gestionDeplacements(Segment serpent[], int *direction_x, int *direction_y) {
    int touche;
    if (ToucheEnAttente()) {
        touche = Touche();
        if (touche == XK_Up && *direction_y == 0) {
            *direction_x = 0;
            *direction_y = -1;
        } else if (touche == XK_Down && *direction_y == 0) {
            *direction_x = 0;
            *direction_y = 1;
        } else if (touche == XK_Left && *direction_x == 0) {
            *direction_x = -1;
            *direction_y = 0;
        } else if (touche == XK_Right && *direction_x == 0) {
            *direction_x = 1;
            *direction_y = 0;
        }
    }
}

int tuerSerpent(Segment serpent[], int longueur) {
    int i;
    /*Vérifier si la tête du serpent est sortie de la grille après le déplacement*/
    if (serpent[0].x < 0 || serpent[0].x >= LARGEUR_GRILLE || serpent[0].y < 0 || serpent[0].y >= HAUTEUR_GRILLE) {
        return 1; /*il est mort*/
    }

    /*Vérifier si la tête du serpent entre en collision avec son propre corps*/
    for (i = 1; i < longueur; ++i) {
        if (serpent[0].x == serpent[i].x && serpent[0].y == serpent[i].y) {
            return 1; /*il est mort*/
        }
    }

    return 0; /*le serpent est en vie*/
}



void mettreAJourSerpent(Segment serpent[], int *longueur, int *direction_x, int *direction_y) {
    int i;
    int ancienX = serpent[*longueur - 1].x;
    int ancienY = serpent[*longueur - 1].y;
    couleur couleurFond = (ancienX + ancienY) % 2 == 0 ? CouleurParComposante(170, 215, 82) : CouleurParComposante(54, 103, 0);

    ChoisirCouleurDessin(couleurFond);
    RemplirRectangle(ancienX * TAILLE_CASE, ancienY * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);

    for (i = *longueur - 1; i > 0; --i) {
        serpent[i] = serpent[i - 1];
    }
    serpent[0].x += *direction_x;
    serpent[0].y += *direction_y;

    tuerSerpent(serpent,*longueur); /*Appeler la fonction pour vérifier si le serpent est mort*/
}

void dessinerSerpent(Segment serpent[], int *longueur) {
    int i;
    for (i = 0; i < *longueur; ++i) {
        ChoisirCouleurDessin(CouleurParNom("yellow"));
        RemplirRectangle(serpent[i].x * TAILLE_CASE, serpent[i].y * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
    }
}
