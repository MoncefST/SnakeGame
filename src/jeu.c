#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "../include/grille.h"
#include "../include/serpent.h"
#include "../include/pomme.h"
#include "../include/jeu.h"
#include "../include/menu.h"
#include "../include/timer.h"

void jouer(int nbPommes, unsigned long int vitesse) {
    int i;
    Segment serpent[2400];
    int longueur = 10;
    int direction_x = 1;
    int direction_y = 0;
    int score = 0;
    char scoreStr[20];
    Pomme pommes[25];
    int min, sec;
    int id_pomme;
    int esc = 0;

    initialiser_timer(&min, &sec);
    initialiserSerpent(serpent, &longueur);
    dessinerGrille();
    id_pomme = ChargerSprite("img/pomme1.png");

    for (i = 0; i < nbPommes; i++) {
        pommes[i] = creerPomme();
        dessinerPomme(pommes[i], id_pomme);
    }

    while (1) {
        esc = gestionDeplacements(serpent, &direction_x, &direction_y);
        if (esc == 1) {
            return;
        }
        mettreAJourSerpent(serpent, &longueur, &direction_x, &direction_y);

        for (i = 0; i < nbPommes; i++) {
            if (serpent[0].x == pommes[i].x && serpent[0].y == pommes[i].y) {
                longueur += 2;
                score += 5;
                if (vitesse >= 15000) {
                    vitesse -= 40;
                }
                pommes[i] = creerPomme();
                dessinerPomme(pommes[i], id_pomme);
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

void lancer_jeu1(void) {
    jouer(1, 100000);
}

void lancer_jeu2(void) {
    jouer(2, 100000);
}

void lancer_jeu3(void) {
    jouer(10, 90000);
}

void lancer_jeu4(void) {
    jouer(25, 100000);
}