#include <stdio.h>
#include <graph.h>
#include <unistd.h>
#include "../include/grille.h"
#include "../include/serpent.h"
#include "../include/pomme.h"
#include "../include/jeu.h"


void lancer_jeu1(void) {
    Segment serpent[100];
    int longueur = 5;
    int direction_x = 1;
    int direction_y = 0;
    int i;
    InitialiserGraphique();
    CreerFenetre(0, 0, 1200, 1000);


    initialiserSerpent(serpent, &longueur);
    dessinerGrille(); /*Dessiner la grille*/

    Pomme pomme = creerPomme();
    dessinerPomme(pomme);     

    while (1) {
        gestionDeplacements(serpent, &direction_x, &direction_y);
        mettreAJourSerpent(serpent, &longueur, &direction_x, &direction_y);

        if (serpent[0].x == pomme.x && serpent[0].y == pomme.y) {
            longueur++;
            pomme = creerPomme(); /*Générer une pomme*/
            dessinerPomme(pomme);
        }

        if (tuerSerpent(serpent) || seMangerQueue(serpent, longueur)) {
            /*Si le serpent est mort, gestion du game over*
            /*Ajoutez ici menu game over*/
            /*ChargerImageFond("../img/game_over.png");*/
        }

        dessinerSerpent(serpent, &longueur);
        usleep(100000);
    }
}