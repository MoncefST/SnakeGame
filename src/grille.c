#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

int* creer_grille(void){
    int* Grille=NULL;
    Grille=(int*) malloc(40*60*sizeof(int));
    return Grille;
}

void creer_grille_graph(){
<<<<<<< HEAD
    int x_grille=0,y_grille=0,x,y;
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    DessinerRectangle(x_grille,y_grille,1200,1000);
    DessinerRectangle(x_grille,y_grille,900,600);
    for(x=x_grille;x<1100;x=x+15){
        DessinerSegment(x,y_grille,x,800);
    }
    for(y=y_grille;y<800;y=y+15){
        DessinerSegment(x_grille,y,1100,y);
=======
    int x=200,y=200;
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    DessinerRectangle(x,y,1200,1000);
    DessinerRectangle(x,y,900,600);
    for(x=200;x<1100;x=x+15){
        DessinerSegment(x,y,x,800);
    }
    x=200;
    y=200;
    for(y=200;y<800;y=y+15){
        DessinerSegment(x,y,1100,y);
>>>>>>> 03cdfc71722afd1d8631e3ed432af6d031cd9b7e
    }

}

int main(void){
    char x;
    InitialiserGraphique();
    CreerFenetre(0,0,1300,1300);
    creer_grille_graph();
    while(x != 'q'){
        scanf("%c",&x);
    }
}