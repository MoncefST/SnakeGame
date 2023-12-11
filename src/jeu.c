#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "../include/grille.h"
#include "../include/serpent.h"
#include "../include/pomme.h"
#include "../include/jeu.h"
#include "../include/menu.h"
#include "../include/timer.h"


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
    int id_pomme;
    int esc=0;


    initialiser_timer(&min, &sec);
    initialiserSerpent(serpent, &longueur);
    dessinerGrille();
    id_pomme=ChargerSprite("img/pomme1.png");

    pomme = creerPomme();
    dessinerPomme(pomme,id_pomme);

    while (fin == 1) {
        update_timer(&min, &sec);
        esc=gestionDeplacements(serpent, &direction_x, &direction_y);
        if(esc==1){ /*verifie si on appuie sur échap */
            return; /*quitte si on appuie sur échap*/
        }
        mettreAJourSerpent(serpent, &longueur, &direction_x, &direction_y);

        if (serpent[0].x == pomme.x && serpent[0].y == pomme.y) {
            longueur++;
            score += 5;
            pomme = creerPomme();
            dessinerPomme(pomme,id_pomme);
        }

        if (tuerSerpent(serpent, longueur)) {
            int choixGameOver;
            afficherMenuGameOver();
            afficher_seconde(sec);
            afficher_minute(min);
            afficherScore(score);
            /* Attend le choix du joueur après le game over */
            attendreChoixGameOver();
            return;
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
    int id_pomme;
    int esc;


    initialiser_timer(&min, &sec);
    initialiserSerpent(serpent, &longueur);
    dessinerGrille();
    id_pomme=ChargerSprite("img/pomme1.png");

    for (i = 0; i < 5; i++) {
        pommes[i] = creerPomme();
        dessinerPomme(pommes[i],id_pomme);
    }

    while (1) {
        esc=gestionDeplacements(serpent, &direction_x, &direction_y);
        if(esc==1){/*verifie si on appuie sur échap */
            return; /*quitte si on appuie sur échap*/
        }
        mettreAJourSerpent(serpent, &longueur, &direction_x, &direction_y);

        for (i = 0; i < 5; i++) {
            if (serpent[0].x == pommes[i].x && serpent[0].y == pommes[i].y) {
                longueur++;
                score += 5;
                pommes[i] = creerPomme();
                dessinerPomme(pommes[i],id_pomme);
            }
        }

        if (tuerSerpent(serpent, longueur)) {
            int choixGameOver;
            afficherMenuGameOver();
            afficher_seconde(sec);
            afficher_minute(min);
            afficherScore(score);

            /* Attend le choix du joueur après le game over */
            attendreChoixGameOver();
            return;
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
    int id_pomme;
    int esc=0;


    initialiser_timer(&min, &sec);
    initialiserSerpent(serpent, &longueur);
    dessinerGrille();
    
    id_pomme=ChargerSprite("img/pomme1.png");
    pomme = creerPomme();
    dessinerPomme(pomme,id_pomme);

    while (1) {
        esc=gestionDeplacements(serpent, &direction_x, &direction_y);
        if(esc==1){/*verifie si on appuie sur échap */
            return;/*quitte si on appuie sur echap*/
        }
        mettreAJourSerpent(serpent, &longueur, &direction_x, &direction_y);

        if (serpent[0].x == pomme.x && serpent[0].y == pomme.y) {
            longueur++;
            score += 5;
            pomme = creerPomme();
            dessinerPomme(pomme,id_pomme);

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
            attendreChoixGameOver();
            return;
        }

        dessinerSerpent(serpent, &longueur);
        afficherScore(score);
        update_timer(&min, &sec);

        attendreSerpent(vitesse);
    }
}

void lancer_jeu3(void) {
    int i;
    Segment serpent[100];
    int longueur = 10;
    int direction_x = 1;
    int direction_y = 0;
    unsigned long int vitesse = 90000;  /*vitesse de base*/
    int score = 0;
    char scoreStr[20];
    Pomme pommes[25];
    int min, sec;
    int id_pomme;
    int esc=0;


    initialiser_timer(&min, &sec);
    initialiserSerpent(serpent, &longueur);
    dessinerGrille();
    id_pomme=ChargerSprite("img/pomme1.png");
    for (i = 0; i < 25; i++) {
        pommes[i] = creerPomme();
        dessinerPomme(pommes[i],id_pomme);
    }

    while (1) {
        esc=gestionDeplacements(serpent, &direction_x, &direction_y);
        if(esc==1){
            return;
        }
        mettreAJourSerpent(serpent, &longueur, &direction_x, &direction_y);

        for (i = 0; i < 25; i++) {
            if (serpent[0].x == pommes[i].x && serpent[0].y == pommes[i].y) {
                longueur++;
                score += 5;
                vitesse -=2500;
                pommes[i] = creerPomme();
                dessinerPomme(pommes[i],id_pomme);
            }
        }

        if (tuerSerpent(serpent, longueur)) {
            int choixGameOver;
            afficherMenuGameOver();
            afficher_seconde(sec);
            afficher_minute(min);
            afficherScore(score);

            /* Attend le choix du joueur après le game over */
            attendreChoixGameOver();
            return;
        }

        dessinerSerpent(serpent, &longueur);

        afficherScore(score);
        update_timer(&min, &sec);

        attendreSerpent(vitesse); /*Gère la vitesse*/
    }
}