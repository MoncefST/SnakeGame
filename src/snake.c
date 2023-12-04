#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <unistd.h>

#define TAILLE_CASE 20
#define TEMPS_ATTENTE 100000

typedef struct {
    int x, y;
} Segment;

int main() {
    int touche,i,j,longueur,direction_x,direction_y;
    /*A SUPPRIMER : (uniquement pour tester le serpent)*/
    InitialiserGraphique();
    CreerFenetre(0, 0, 1200, 1000);
    ChoisirCouleurDessin(CouleurParComposante(170,215,82));

    Segment serpent[10];
    longueur = 10;
    for (i = 0; i < longueur; i++) {
        serpent[i].x = 5 + i;
        serpent[i].y = 5;
    }

    direction_x = 1;
    direction_y = 0;

    while (1) {
        EffacerEcran(CouleurParComposante(170, 215, 82));
        for (i = longueur - 1; i > 0; i--) {
            serpent[i] = serpent[i - 1];
        }
        serpent[0].x += direction_x;
        serpent[0].y += direction_y;

        for (i = 0; i < longueur; ++i) {
            ChoisirCouleurDessin(CouleurParNom("yellow"));
            RemplirRectangle(serpent[i].x * TAILLE_CASE, serpent[i].y * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
        }




        usleep(TEMPS_ATTENTE);  /*Attendre 100 millisecondes -> ça nous permet de "gérer" la vitesse du serpent*/ 


        if (ToucheEnAttente()) {
            touche = Touche();
            if (touche == XK_Up) {
                direction_x = 0;
                direction_y = -1;
            } else if (touche == XK_Down) {
                direction_x = 0;
                direction_y = 1;
            } else if (touche == XK_Left) {
                direction_x = -1;
                direction_y = 0;
            } else if (touche == XK_Right) {
                direction_x = 1;
                direction_y = 0;
            }
        }
    }

    FermerGraphique();
    return EXIT_SUCCESS;
}