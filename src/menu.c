#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <graph.h>
#include "../include/menu.h"



void afficherMenuPrincipal() {
    ChargerImageFond("img/menu_principal.png");

    /* Affiche le bouton "Jouer" */
    afficherBouton(67, 850, 367, 950, "Jouer", CouleurParComposante(0,151,178), CouleurParNom("black"), CouleurParNom("black"), 2);

    /* Affiche le bouton "Quitter" */
    afficherBouton(800, 850, 1100, 950, "Quitter", CouleurParComposante(0,151,178), CouleurParNom("black"), CouleurParNom("black"), 2);
}

void afficherMenuModesDeJeu() {
    /* Affiche l'image de fond des modes de jeu */
    ChargerImageFond("img/modes_de_jeu.png");

    /* Affiche les boutons des modes de jeu */
    afficherBouton(38.7, 639.9, 280.3, 742.9, "Classique", CouleurParComposante(168, 116, 67), CouleurParNom("black"), CouleurParNom("black"), 2);
    afficherBouton(332.6, 639.9, 574.2, 742.9, "MultiPommes", CouleurParComposante(168, 116, 67), CouleurParNom("black"), CouleurParNom("black"), 2);
    afficherBouton(626.2, 639.9, 867.8, 742.9, "Glouton", CouleurParComposante(168, 116, 67), CouleurParNom("black"), CouleurParNom("black"), 2);
    afficherBouton(919.7, 639.9, 1161.3, 742.9, "Acceleration", CouleurParComposante(168, 116, 67), CouleurParNom("black"), CouleurParNom("black"), 2);
}





void afficherMenuGameOver(void) {
    /* Affiche l'image game over */
    ChargerImageFond("img/game_over.png");
}


void attendreChoixGameOver(void) {
    int x, y;

    while (1) {
        if (SourisCliquee()) {
            SourisPosition();
            x = _X;
            y = _Y;

            /* Vérifie si le bouton "Menu Principal" est cliqué */
            if (x >= 379 && x <= 830.7 && y >= 530.3 && y <= 670.1) {
                return;
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

void afficherBouton(double x1, double y1, double x2, double y2, const char *texte, couleur arriere_plan, couleur bordure, couleur couleur_texte, int taille_texte) {
    /* Copie la chaîne constante dans une nouvelle chaîne non constante */
    char *texte_modifiable = malloc(strlen((const char *)texte) + 1);
    strcpy(texte_modifiable, (const char *)texte);

    /* Affiche le bouton avec la couleur d'arrière-plan spécifiée */
    ChoisirCouleurDessin(arriere_plan);
    RemplirRectangle(x1, y1, x2 - x1, y2 - y1);

    /* Affiche la bordure avec la couleur spécifiée */
    ChoisirCouleurDessin(bordure);
    DessinerRectangle(x1, y1, x2 - x1, y2 - y1);

    /* Affiche le texte centré sur le bouton avec la couleur de texte spécifiée */
    ChoisirCouleurDessin(couleur_texte);
    EcrireTexte((int)((x1 + x2) / 2 - TailleChaineEcran(texte_modifiable, taille_texte) / 2), (int)((y1 + y2) / 2 + TailleSupPolice(taille_texte) / 2), texte_modifiable, taille_texte);

    /* Libère la mémoire allouée pour la copie de la chaîne */
    free(texte_modifiable);
}