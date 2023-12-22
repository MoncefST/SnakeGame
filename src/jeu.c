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

void jouer(int nbPommes, unsigned long int vitesse,int acceleration) {      /*fait marcher le jeu avec, en paramètre, le nombre de pommes, la vitesse e si le serpent accèlere ou non*/
    int i;
    Serpent serpent=(Serpent) malloc(2400*sizeof(int));
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
        pommes[i] = creerPomme(serpent,longueur);
        dessinerPomme(pommes[i], id_pomme);
    }

    while (1) {
        esc = gestionTouches(serpent, &direction_x, &direction_y);
        if (esc == 1) {
            return;
        }
        mettreAJourSerpent(serpent, &longueur, &direction_x, &direction_y);

        for (i = 0; i < nbPommes; i++) {
            if (serpent[0].x == pommes[i].x && serpent[0].y == pommes[i].y) {
                longueur += 2;
                score += 5;
                if (vitesse >=60000) {      /*la vitesse maximal s'atteint au bout après 100 pommes consommées*/
                    vitesse -= 400;
                }
                pommes[i] = creerPomme(serpent,longueur);
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
            free(serpent);
            return;
        }

        dessinerSerpent(serpent, &longueur);

        afficherScore(score);
        update_timer(&min, &sec);

        attendreSerpent(vitesse); /* Gère la vitesse */
    }
}


void lancer_jeu1(void) {
    jouer(1, 100000,0);
}

void lancer_jeu2(void) {
    jouer(5, 100000,0);
}

void lancer_jeu3(void) {
    jouer(25, 100000,1);
}

void lancer_jeu4(void) {
    jouer(1, 100000,1);
}