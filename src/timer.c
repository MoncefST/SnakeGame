#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#define delta 1000000L

void creer_timer(void){
    int sec;
    unsigned long temps;
    temps=Microsecondes();
    while(sec!=10){
        temps=Microsecondes+delta;
        printf("%d\n",sec);
        sec=temps%11;
    }
}







int main(void){
    InitialiserGraphique();
    CreerFenetre(0,0,1300,1300);
    creer_timer();
    FermerGraphique();
}