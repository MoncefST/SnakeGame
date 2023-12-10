#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "../include/grille.h"
#include "../include/serpent.h"
#include "../include/pomme.h"
#include "../include/jeu.h"
#include "../include/menu.h"
#include "../include/timer.h"
#include "../include/obstacle.h"


void afficherScore(int score) {
    char scoreStr[20];
    /* Efface l'ancien score */
    ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
    RemplirRectangle(178, 946, 130, 40);
    /* Convertit le score en chaîne de caractères */
    snprintf(scoreStr, sizeof(scoreStr), "%d", score);
    /* Affiche le nouveau score */
    ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
    EcrireTexte(179, 976, scoreStr, 2);
}


void lancer_jeu1(void) {
    int fin = 1;
    Segment serpent[100];
    int longueur = 10;
    int direction_x = 1;
    int direction_y = 0;
    int score = 0;
    char scoreStr[20];
    Pomme pomme;
    int min, sec;


    initialiser_timer(&min, &sec);
    initialiserSerpent(serpent, &longueur);
    dessinerGrille();

    pomme = creerPomme();
    dessinerPomme(pomme);

    while (fin == 1) {
        update_timer(&min, &sec);
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
            afficher_seconde(sec);
            afficher_minute(min);
            afficherScore(score);
            /* Attend le choix du joueur après le game over */
            choixGameOver = attendreChoixGameOver();
        }

        dessinerSerpent(serpent, &longueur);
        afficherScore(score);
        update_timer(&min, &sec);

        attendreSerpent(150000);
    }
}


void lancer_jeu2(void) {
    int i;
    Segment serpent[100];
    int longueur = 10;
    int direction_x = 1;
    int direction_y = 0;
    unsigned long int vitesse = 200000;  /*vitesse de base*/
    int score = 0;
    char scoreStr[20];
    Pomme pommes[5];
    int min, sec;


    initialiser_timer(&min, &sec);
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
            afficher_seconde(sec);
            afficher_minute(min);
            afficherScore(score);

            /* Attend le choix du joueur après le game over */
            choixGameOver = attendreChoixGameOver();
        }

        dessinerSerpent(serpent, &longueur);

        afficherScore(score);
        update_timer(&min, &sec);

        attendreSerpent(vitesse); /*Gère la vitesse*/
    }
}


void lancer_jeu4(void) {
    int longueur = 10;
    int direction_x = 1;
    int direction_y = 0;
    int score = 0;
    unsigned long int vitesse = 300000;  /*vitesse de base*/
    char scoreStr[20];
    Pomme pomme;
    Segment serpent[100];
    int min, sec;


    initialiser_timer(&min, &sec);
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

            /* Augmenter la vitesse à chaque pomme mangée*/
            vitesse -= 5000;  /* Réduire la durée d'attente (augmenter la vitesse)*/
        }

        if (tuerSerpent(serpent, longueur)) {
            int choixGameOver;
            afficherMenuGameOver();
            afficherScore(score);
            afficher_minute(min);
            afficher_seconde(sec);

            /* Attend le choix du joueur après le game over */
            choixGameOver = attendreChoixGameOver();
        }

        dessinerSerpent(serpent, &longueur);
        afficherScore(score);
        update_timer(&min, &sec);

        attendreSerpent(vitesse);
    }
}

void lancer_jeu3(void) {
    int i,j;
    int longueur = 10;
    int direction_x = 1;
    int direction_y = 0;
    int score = 0;
    unsigned long int vitesse = 100000;  
    char scoreStr[20];
    Pomme pomme;
    int nombreObstacles = 10;
    Obstacle *obstacles = malloc(nombreObstacles * sizeof(Obstacle));
    Segment serpent[100];
    int min, sec;

    initialiser_timer(&min, &sec);
    initialiserSerpent(serpent, &longueur);
    dessinerGrille();

    pomme = creerPomme();
    dessinerPomme(pomme);

    placerObstacle(obstacles, nombreObstacles, LARGEUR_GRILLE, HAUTEUR_GRILLE);

    while (1) {
    gestionDeplacements(serpent, &direction_x, &direction_y);
    mettreAJourSerpent(serpent, &longueur, &direction_x, &direction_y);

    if (serpent[0].x == pomme.x && serpent[0].y == pomme.y) {
        longueur++;
        score += 5;
        pomme = creerPomme();
        dessinerPomme(pomme);

        
        vitesse -= 5000;
    }

    if (tuerSerpent(serpent, longueur)) {
        int choixGameOver;
        afficherMenuGameOver();
        afficher_seconde(sec);
        afficher_minute(min);
        afficherScore(score);
        /* Attend le choix du joueur après le game over */
        choixGameOver = attendreChoixGameOver();
    }

    /*Vérifier la collision avec les obstacles*/
    for (i = 0; i < nombreObstacles; i++) {
        if (estCollisionObstacle(obstacles[i], serpent, longueur)) {
            int choixGameOver;
            afficherMenuGameOver();
            afficher_seconde(sec);
            afficher_minute(min);
            afficherScore(score);

            /* Attend le choix du joueur après le game over */
            choixGameOver = attendreChoixGameOver();
            if (choixGameOver == 1) {
                /*Réinitialiser le jeu*/
                longueur = 10;
                score = 0;
                vitesse = 28000000;
                initialiserSerpent(serpent, &longueur);
                dessinerGrille();
                pomme = creerPomme();
                dessinerPomme(pomme);
                placerObstacle(obstacles, nombreObstacles, LARGEUR_GRILLE, HAUTEUR_GRILLE);
            } else if (choixGameOver == 2) {
                FermerGraphique();
            }
        }
    }

    /*Dessiner le serpent et les obstacles*/
    dessinerSerpent(serpent, &longueur);
    for (j = 0; j < nombreObstacles; j++) {
        dessinerObstacle(obstacles[j]);
    }

    afficherScore(score);
    update_timer(&min, &sec);


    /*Attendre en fonction de la vitesse actuelle*/
    attendreSerpent(vitesse);
    
}
free(obstacles);
}
