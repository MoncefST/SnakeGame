#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "../include/main.h"
#include "../include/jeu.h"
#include "../include/menu.h"




void menus(void) {
    int choixMenuPrincipal = 0;
    int choixModesDeJeu = 0;
    while (1) {
        if (choixMenuPrincipal == 0) {
            afficherMenuPrincipal();
            choixMenuPrincipal = attendreChoixMenu();
        } else if (choixMenuPrincipal == 1) {
            afficherMenuModesDeJeu();
            choixModesDeJeu = attendreChoixModesDeJeu();
            if(choixModesDeJeu == 1){
                EffacerEcran(CouleurParNom("white"));
                lancer_jeu1();
            }
            if(choixModesDeJeu == 2){
                EffacerEcran(CouleurParNom("white"));
                lancer_jeu2();
            }
            if(choixModesDeJeu == 3){
                EffacerEcran(CouleurParNom("white"));
                lancer_jeu3();
            }
            if(choixModesDeJeu == 4){
                EffacerEcran(CouleurParNom("white"));
                lancer_jeu4();
            }
        } else if (choixMenuPrincipal == 2) {
            FermerGraphique();
        }
    }
    return;
}


int main(void){
    int choixMenuPrincipal = 0;
    int choixModesDeJeu = 0;
    InitialiserGraphique();
    CreerFenetre(0, 0, 1200, 1000);
    ChoisirTitreFenetre("Snake By Moncef & Marco");

    menus();
    return EXIT_SUCCESS;

}