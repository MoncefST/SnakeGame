#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include "../include/grille.h"
#include "../include/serpent.h"
#include "../include/pomme.h"
#include "../include/jeu.h"
#include "../include/menu.h"




void lancer_jeu1(void) {
    Segment serpent[100];
    int longueur = 10;
    int direction_x = 1;
    int direction_y = 0;
    int score = 0;
    char scoreStr[20];
    Pomme pomme;
    
    FermerGraphique();
    InitialiserGraphique();
    CreerFenetre(0, 0, 1200, 1000);

    initialiserSerpent(serpent, &longueur);
    dessinerGrille();

    pomme = creerPomme();
    dessinerPomme(pomme);

    while (1) {
        gestionDeplacements(serpent, &direction_x, &direction_y);
        mettreAJourSerpent(serpent, &longueur, &direction_x, &direction_y);

        if (serpent[0].x == pomme.x && serpent[0].y == pomme.y) {
            longueur++;
            score += 5;
            pomme = creerPomme();
            dessinerPomme(pomme);
        }

        if (tuerSerpent(serpent, longueur)) {
            int choixGameOver;
            afficherMenuGameOver();

            /* Attend le choix du joueur après le game over */
            choixGameOver = attendreChoixGameOver();
        }

        dessinerSerpent(serpent, &longueur); 

        /* Efface l'ancien score */
        ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
        RemplirRectangle(178, 946, 200, 40);
        /* Convertit le score en chaîne de caractères */
        snprintf(scoreStr, sizeof(scoreStr), "%d", score);
        /* Affiche le nouveau score */
        ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
        EcrireTexte(178, 976, scoreStr, 2);

        struct timespec delai = {0, 55000000};  /*50 000 000 nanosecondes (0.05 seconde)*/
        nanosleep(&delai, NULL);
    }
}

void lancer_jeu2(void) {
    int i;
    Segment serpent[100];
    int longueur = 10;
    int direction_x = 1;
    int direction_y = 0;
    int score = 0;
    char scoreStr[20];
    Pomme pommes[5];

    FermerGraphique();
    InitialiserGraphique();
    CreerFenetre(0, 0, 1200, 1000);

    initialiserSerpent(serpent, &longueur);
    dessinerGrille();

    for (i = 0; i < 5; i++) {
        pommes[i] = creerPomme();
        dessinerPomme(pommes[i]);
    }

    while (1) {
        gestionDeplacements(serpent, &direction_x, &direction_y);
        mettreAJourSerpent(serpent, &longueur, &direction_x, &direction_y);

        for (i = 0; i < 5; i++) {
            if (serpent[0].x == pommes[i].x && serpent[0].y == pommes[i].y) {
                longueur++;
                score += 5;
                pommes[i] = creerPomme();
                dessinerPomme(pommes[i]);
            }
        }

        if (tuerSerpent(serpent, longueur)) {
            int choixGameOver;
            afficherMenuGameOver();

            /* Attend le choix du joueur après le game over */
            choixGameOver = attendreChoixGameOver();
        }

        dessinerSerpent(serpent, &longueur);

        /* Efface l'ancien score */
        ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
        RemplirRectangle(178, 946, 200, 40);
        /* Convertit le score en chaîne de caractères */
        snprintf(scoreStr, sizeof(scoreStr), "%d", score);
        /* Affiche le nouveau score */
        ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
        EcrireTexte(178, 976, scoreStr, 2);

        struct timespec delai = {0, 55000000};  /*50 000 000 nanosecondes (0.05 seconde)*/
        nanosleep(&delai, NULL);
    }
}


void lancer_jeu3(void) {
    struct timespec delai = {0, 40000000};  /*40 000 000 nanosecondes (0.04 seconde)*/
    Segment serpent[100];
    int longueur = 10;
    int direction_x = 1;
    int direction_y = 0;
    int score = 0;
    char scoreStr[20];
    Pomme pomme;
    
    FermerGraphique();
    InitialiserGraphique();
    CreerFenetre(0, 0, 1200, 1000);

    initialiserSerpent(serpent, &longueur);
    dessinerGrille();

    pomme = creerPomme();
    dessinerPomme(pomme);

    while (1) {
        gestionDeplacements(serpent, &direction_x, &direction_y);
        mettreAJourSerpent(serpent, &longueur, &direction_x, &direction_y);

        if (serpent[0].x == pomme.x && serpent[0].y == pomme.y) {
            longueur++;
            score += 5;
            pomme = creerPomme();
            dessinerPomme(pomme);
        }

        if (tuerSerpent(serpent, longueur)) {
            int choixGameOver;
            afficherMenuGameOver();

            /* Attend le choix du joueur après le game over */
            choixGameOver = attendreChoixGameOver();
        }

        dessinerSerpent(serpent, &longueur); 

        /* Efface l'ancien score */
        ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
        RemplirRectangle(178, 946, 200, 40);
        /* Convertit le score en chaîne de caractères */
        snprintf(scoreStr, sizeof(scoreStr), "%d", score);
        /* Affiche le nouveau score */
        ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
        EcrireTexte(178, 976, scoreStr, 2);
        /*Permet de gérer la vitesse du serpent*/
        nanosleep(&delai, NULL);
    }
}

void lancer_jeu4(void) {
    struct timespec delai = {0, 30000000};  /*40 000 000 nanosecondes (0.04 seconde)*/
    Segment serpent[100];
    int longueur = 10;
    int direction_x = 1;
    int direction_y = 0;
    int score = 0;
    char scoreStr[20];
    Pomme pomme;
    
    FermerGraphique();
    InitialiserGraphique();
    CreerFenetre(0, 0, 1200, 1000);

    initialiserSerpent(serpent, &longueur);
    dessinerGrille();

    pomme = creerPomme();
    dessinerPomme(pomme);

    while (1) {
        gestionDeplacements(serpent, &direction_x, &direction_y);
        mettreAJourSerpent(serpent, &longueur, &direction_x, &direction_y);

        if (serpent[0].x == pomme.x && serpent[0].y == pomme.y) {
            longueur++;
            score += 5;
            pomme = creerPomme();
            dessinerPomme(pomme);
        }

        if (tuerSerpent(serpent, longueur)) {
            int choixGameOver;
            afficherMenuGameOver();

            /* Attend le choix du joueur après le game over */
            choixGameOver = attendreChoixGameOver();
        }

        dessinerSerpent(serpent, &longueur); 

        /* Efface l'ancien score */
        ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
        RemplirRectangle(178, 946, 200, 40);
        /* Convertit le score en chaîne de caractères */
        snprintf(scoreStr, sizeof(scoreStr), "%d", score);
        /* Affiche le nouveau score */
        ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
        EcrireTexte(178, 976, scoreStr, 2);
        /*Permet de gérer la vitesse du serpent*/
        nanosleep(&delai, NULL);
    }
}