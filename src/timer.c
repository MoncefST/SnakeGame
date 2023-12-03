#include<stdio.h>
#include<stdlib.h>
#include<graph.h>

void creer_timer(void){
    int sec = 0,mil_sec=0,min=0;
    unsigned long temps = 0,t1=0;
    t1=Microsecondes();
    while(sec<=12){
        printf("[%0.2d:%0.2d]\n",min,sec);
        temps=Microsecondes()-t1;
        min=(temps/60000000)%60;
        temps=temps%60000000;
        sec=(temps/1000000)%60;
    }
}

int main(void){
    InitialiserGraphique();
    creer_timer();
    FermerGraphique();
    return EXIT_SUCCESS;
}