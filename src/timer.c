#include<stdio.h>
#include<stdlib.h>
#include<graph.h>

void creer_timer(void){
    int sec = 0,mil_sec=0,min=0;
    unsigned long temps = 0;
    printf("temps : %lu\n",temps);
    while(min<=2){
        printf("[%d:%d,%d]\n",min,sec,mil_sec);
        temps=Microsecondes();
        printf("temps : %lu\n",temps);
        sec=(temps/1000000)%60;
        mil_sec=(temps/1000)%101;
        min=(temps/60000000)%60;
        printf("[%d:%d,%d]\n",min,sec,mil_sec);
    }
}

int main(void){
    InitialiserGraphique();
    creer_timer();
    FermerGraphique();
    return EXIT_SUCCESS;
}