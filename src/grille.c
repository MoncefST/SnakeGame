#include <graph.h>

/* Dessine une grille de 60 colonnes sur 40 lignes */
void dessinerGrille() {
    ChargerImageFond("../img/grille.png");
    int i, j;
    int tailleCase = 20;
    couleur couleur1 = CouleurParComposante(170, 215, 82); /* Vert clair */
    couleur couleur2 = CouleurParComposante(54, 103, 0);    /* Vert foncé */

    for (i = 0; i < 40; i++) {
        for (j = 0; j < 60; j++) {
            /* Alterner les couleurs en fonction de la case (1 case sur deux...) */
            couleur couleurCase = (i + j) % 2 == 0 ? couleur1 : couleur2;

            /* Dessiner la case */
            ChoisirCouleurDessin(couleurCase);
            RemplirRectangle(j * tailleCase, i * tailleCase, tailleCase, tailleCase);
        }
    }
}
/* UNIQUEMENT POUR TESTER LA GRILLE
int main() {
    InitialiserGraphique();
    CreerFenetre(0, 0, 1200, 1000);

    dessinerGrille();

    Touche();
    FermerGraphique();
    return 0;
}
*/