#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include "../include/menu.h"
#include "../include/main.h"

void afficherMenuPrincipal(){
    ChargerImageFond("../img/menu_principal.png");

    /*Affiche le bouton "Jouer"*/
    ChoisirCouleurDessin(CouleurParComposante(0,151,178));
    RemplirRectangle(67, 850, 300, 100);
    ChoisirCouleurDessin(CouleurParNom("black"));
    EcrireTexte(180, 910, "Jouer", 2);

    /*Affiche le bouton "Quitter"*/
    ChoisirCouleurDessin(CouleurParComposante(0,151,178));
    RemplirRectangle(800, 850, 300, 100);
    ChoisirCouleurDessin(CouleurParNom("black"));
    EcrireTexte(910, 910, "Quitter", 2);

}


void afficherMenuModesDeJeu(){

    /*Affiche l'image de fond des modes de jeu*/
    ChargerImageFond("../img/modes_de_jeu.png");

    /*Affiche le bouton n°1*/
    ChoisirCouleurDessin(CouleurParComposante(168,116,67));
    RemplirRectangle(38.7, 639.9, 241.6, 103);
    ChoisirCouleurDessin(CouleurParNom("black"));
    EcrireTexte(87.6, 700, "Classique", 2);

    /*Affiche le bouton n°2*/
    ChoisirCouleurDessin(CouleurParComposante(168,116,67));
    RemplirRectangle(332.6, 639.9, 241.6, 103);
    ChoisirCouleurDessin(CouleurParNom("black"));
    EcrireTexte(360.4, 700, "MultiPommes", 2);

    /*Affiche le bouton n°3*/
    ChoisirCouleurDessin(CouleurParComposante(168,116,67));
    RemplirRectangle(626.2, 639.9, 241.6, 103);
    ChoisirCouleurDessin(CouleurParNom("black"));
    EcrireTexte(700.1, 700, "Rapide", 2);

    /*Affiche le bouton n°4*/
    ChoisirCouleurDessin(CouleurParComposante(168,116,67));
    RemplirRectangle(919.7, 639.9, 241.6, 103);
    ChoisirCouleurDessin(CouleurParNom("black"));
    EcrireTexte(960.7, 700, "Ultra rapide", 2);
}


void afficherMenuGameOver(void) {
    /* Affiche l'image game over */
    ChargerImageFond("../img/game_over.png");
}


int attendreChoixGameOver() {
    int x, y;

    while (1) {
        if (SourisCliquee()) {
            SourisPosition();
            x = _X;
            y = _Y;

            /* Vérifie si le bouton "Menu Principal" est cliqué */
            if (x >= 379 && x <= 830.7 && y >= 530.3 && y <= 670.1) {
                FermerGraphique();
                main(); /* Renvoie vers le menu principal" */
            }

        }
    }
}


int attendreChoixModesDeJeu(){
    int x, y;

    while (1){
        if(SourisCliquee()){
            SourisPosition();
            x = _X;
            y = _Y;

            /*Vérifie si le bouton n°1 est cliqué*/
            if (x >= 38.7 && x <= 280.3 && y >= 639.9 && y <= 742.9) {
                return 1;  /*Renvoie le choix bouton n°1*/
            }

            /*Vérifie si le bouton n°2 est cliqué*/
            if (x >= 332.6 && x <= 574.2 && y >= 639.9 && y <= 742.9) {
                return 2;  /*Renvoie le choix bouton n°2*/
            }

            /*Vérifie si le bouton n°3 est cliqué*/
            if (x >= 626.2 && x <= 867.8 && y >= 639.9 && y <= 742.9) {
                return 3;  /*Renvoie le choix bouton n°3*/
            }

            /*Vérifie si le bouton n°4 est cliqué*/
            if (x >= 919.7 && x <= 1161.3 && y >= 639.9 && y <= 742.9) {
                return 4;  /*Renvoie le choix bouton n°4*/
            }

        }
    }
}


int attendreChoixMenu(){
    int x, y;

    while (1){
        if (SourisCliquee()){
            SourisPosition();
            x = _X;
            y = _Y;

            /*Vérifie si le bouton "Jouer" est cliqué*/
            if (x >= 67 && x <= 367 && y >= 850 && y <= 950) {
                return 1; /*Renvoie le choix bouton "Jouer"*/
            }

            /*Vérifie si le bouton "Quitter" est cliqué*/
            if (x >= 800 && x <= 1100 && y >= 850 && y <= 950) {
                return 2; /*Renvoie le choix bouton "Quitter"*/
            }
        }
    }
}
