#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "../include/grille.h"
#include "../include/serpent.h"

typedef struct {
    int x;
    int y;
} Obstacle;

void dessinerObstacle(Obstacle obstacle);
int estCollisionObstacle(Obstacle obstacle, Segment serpent[], int longueur);
Obstacle creerObstacle(int largeurGrille, int hauteurGrille);
void placerObstacle(Obstacle obstacles[], int nombreObstacles, int largeurGrille, int hauteurGrille);

#endif /*OBSTACLE_H*/
