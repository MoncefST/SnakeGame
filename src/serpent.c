#include <stdio.h>
#include <graph.h>
#include "../include/serpent.h"
#include "../include/main.h"
#define TAILLE_CASE 20
#define LARGEUR_GRILLE 60
#define HAUTEUR_GRILLE 40


void initialiserSerpent(Segment serpent[], int *longueur) {
    int i;
    int centreX = LARGEUR_GRILLE / 2;
    int centreY = HAUTEUR_GRILLE / 2;

    for (i = 0; i < 10; ++i) {
        serpent[i].x = centreX - i;
        serpent[i].y = centreY;
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
        } else if (touche == XK_Escape) {
            FermerGraphique();
            main();
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

    /* Déterminer la couleur de fond en fonction de la position de la case dans la grille */
    couleur couleurFond = (ancienX + ancienY) % 2 == 0 ? CouleurParComposante(170, 215, 82) : CouleurParComposante(180, 220, 90);

    /* Remplir la case avec la couleur de fond appropriée */
    ChoisirCouleurDessin(couleurFond);
    RemplirRectangle(ancienX * TAILLE_CASE, ancienY * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);

    /* Remplir la case avec la couleur de la grille à cet endroit précis */
    ChoisirCouleurDessin(CouleurParComposante(170, 215, 82)); 
    RemplirRectangle(0, 0, TAILLE_CASE, TAILLE_CASE);

    for (i = *longueur - 1; i > 0; --i) {
        serpent[i] = serpent[i - 1];
    }
    serpent[0].x += *direction_x;
    serpent[0].y += *direction_y;

    tuerSerpent(serpent, *longueur); /*Appeler la fonction pour vérifier si le serpent est mort*/
}


void dessinerSerpent(Segment serpent[], int *longueur) {
    int i;
    for (i = 0; i < *longueur; ++i) {
        ChoisirCouleurDessin(CouleurParNom("yellow"));
        RemplirRectangle(serpent[i].x * TAILLE_CASE, serpent[i].y * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
    }
}

void attendreSerpent(unsigned long int microseconds) {
    unsigned long int attente_jusqu_a = Microsecondes() + microseconds;
    while (Microsecondes() < attente_jusqu_a) {
        /*Attendre jusqu'au temps données en paramètre de la fonction*/
    }
}