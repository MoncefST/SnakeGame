#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include "grille.h"
#include "serpent.h"
#include "obstacle.h"
#include "pomme.h"



void dessinerObstacle(Obstacle obstacle) {
    int id_bombe;
    id_bombe = ChargerSprite("../img/bombe.png");
    AfficherSprite(id_bombe,obstacle.x * TAILLE_CASE, obstacle.y * TAILLE_CASE);
}


int estCollisionObstacle(Obstacle obstacle, Segment serpent[], int longueur) {
    int i;
    for (i = 0; i < longueur; i++) {
        if (serpent[i].x == obstacle.x && serpent[i].y == obstacle.y) {
            return 1;  /*Collision avec un obstacle*/
        }
    }
    return 0;  /*Pas de collision*/
}

Obstacle creerObstacle(int largeurGrille, int hauteurGrille) {
    Obstacle obstacle;
    obstacle.x = rand() % largeurGrille;
    obstacle.y = rand() % hauteurGrille;
    return obstacle;
}

void placerObstacle(Obstacle obstacles[], int nombreObstacles, int largeurGrille, int hauteurGrille) {
    int i;
    for (i = 0; i < nombreObstacles; i++) {
        obstacles[i] = creerObstacle(largeurGrille, hauteurGrille);
    }
}

