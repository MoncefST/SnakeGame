#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "timer.h"

#define cycle 1000000L

void initialiser_timer(int *min, int *sec) {
    *min = 0;
    *sec = 0;
}

int afficher_seconde(int sec){
    char timer[50];
    int x = 230 ,y = 850;
    if(sec<=9){
        ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
        RemplirRectangle(x-3,y-25,40,30);
        ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
        EcrireTexte(x,y,"0",2);
        snprintf(timer,sizeof(timer),"%d",sec);
        EcrireTexte(x+15,y,timer,2);
    } else {
        ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
        RemplirRectangle(x-3,y-25,40,25);
        ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
        snprintf(timer,sizeof(timer),"%d",sec);
        EcrireTexte(x,y,timer,2);
    }
    return sec;
}

int afficher_minute(int min){
    char timer[50];
    int x = 190 ,y = 850;
    if(min<=9){
        ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
        RemplirRectangle(x-3,y-25,40,30);
        ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
        EcrireTexte(x,y,"0",2);
        snprintf(timer,sizeof(timer),"%d",min);
        EcrireTexte(x+30,y,":",2);
        EcrireTexte(x+15,y,timer,2);
    } else {
        ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
        RemplirRectangle(x-3,y-25,40,25);
        ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
        snprintf(timer,sizeof(timer),"%d",min);
        EcrireTexte(x+30,y,":",2);
        EcrireTexte(x,y,timer,2);
    }
    return min;
}

void update_timer(int *min, int *sec) {
    static unsigned long int temps_precedent = 0;
    unsigned long int temps_actuel = Microsecondes();
    unsigned long int temps_ecoule = temps_actuel - temps_precedent;

    if (temps_ecoule >= cycle) {
        temps_precedent = temps_actuel;
        
        if (*sec < 59) {
            (*sec)++;
        } else {
            *sec = 0;
            (*min)++;
        }

        /* Afficher le timer */
        afficher_seconde(*sec);
        afficher_minute(*min);
    }
}

void pause(void) {
    while (1) {
        if (ToucheEnAttente() && Touche() == XK_space) {
            break;
        }
    }
}
