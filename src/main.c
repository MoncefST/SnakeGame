#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "../include/jeu.h"
#include "../include/menu.h"

int main(void) {
    int choixMenuPrincipal = 0;
    int choixModesDeJeu = 0;
    InitialiserGraphique();
    CreerFenetre(0, 0, 1200, 1000);


    while (1) {
        if (choixMenuPrincipal == 0) {
            afficherMenuPrincipal();
            choixMenuPrincipal = attendreChoixMenu();
        } else if (choixMenuPrincipal == 1) {
            afficherMenuModesDeJeu();
            choixModesDeJeu = attendreChoixModesDeJeu();
            if(choixModesDeJeu == 1){
                lancer_jeu1();
            }
            if(choixModesDeJeu == 2){
                lancer_jeu2();
            }
            if(choixModesDeJeu == 3){
                lancer_jeu3();
            }
            if(choixModesDeJeu == 4){
                lancer_jeu4();
            }
        } else if (choixMenuPrincipal == 2) {
            FermerGraphique();
            return EXIT_SUCCESS;
        }
    }
    
    return EXIT_SUCCESS;
}
