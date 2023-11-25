#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

void creer_grille(void){
    CreerFenetre(100,100,600,400);
}

int main(void){
    char** x;
    InitialiserGraphique();
    creer_grille();
    while(!SourisCliquee()){
        scanf("%c",&x);
    }
    return EXIT_SUCCESS;
}