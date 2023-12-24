#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "../include/jeu.h"
#include "../include/menu.h"




int menus(void) {
    int choixMenuPrincipal = 0;
    int choixModesDeJeu = 0;
    if (choixMenuPrincipal == 0) {
        afficherMenuPrincipal();
        choixMenuPrincipal = attendreChoixMenu();
    } 
    if (choixMenuPrincipal == 1) {
        afficherMenuModesDeJeu();
        choixModesDeJeu = attendreChoixModesDeJeu();
        if(choixModesDeJeu == 1){
                EffacerEcran(CouleurParNom("white"));
                jouer(1, 100000,0);  /* Jeu n°1 */
            }
            if(choixModesDeJeu == 2){
                EffacerEcran(CouleurParNom("white"));
                jouer(5, 100000,0);  /* Jeu n°2 */
            }
            if(choixModesDeJeu == 3){
                EffacerEcran(CouleurParNom("white"));
                jouer(25, 100000,1);  /* Jeu n°3 */
            }
            if(choixModesDeJeu == 4){
                EffacerEcran(CouleurParNom("white"));
                jouer(1, 100000,1);  /*  Jeu n°4 */
            }
        }
    if (choixMenuPrincipal == 2) {
        return 1;
    }
    
    return 0;
}


int main(void){
    int choixMenuPrincipal = 0;
    int choixModesDeJeu = 0;
    int quitter=0;
    InitialiserGraphique();
    CreerFenetre(0, 0, 1200, 1000);
    ChoisirTitreFenetre("Snake By Moncef & Marco");
    while(quitter==0){
        quitter=menus();
    }
    FermerGraphique();
    return EXIT_SUCCESS;
}