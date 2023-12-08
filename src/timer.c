#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#define cycle 1000000L

unsigned long int attendre(void){
    int x=1;
    unsigned long int temps_pause;
    unsigned long int t1=Microsecondes();
    while(x==1){
        if(Touche()==XK_space){
            x=0;
        }
    }
    temps_pause=Microsecondes()-t1;
    return temps_pause;
}

int afficher_seconde(int sec){
    char timer[50];
    int x = 120 ,y = 100;
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
    int x = 80 ,y = 100;
    if(min<=9){
        ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
        RemplirRectangle(x-3,y-25,40,30);
        ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
        EcrireTexte(x,y,"0",2);
        snprintf(timer,sizeof(timer),"%d",min);
        EcrireTexte(110,100,":",2);
        EcrireTexte(x+15,y,timer,2);
    } else {
        ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
        RemplirRectangle(x-3,y-25,40,25);
        ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
        snprintf(timer,sizeof(timer),"%d",min);
        EcrireTexte(110,100,":",2);
        EcrireTexte(x,y,timer,2);
    }
    return min;
}

void creer_timer(void){
    int sec = 0,min=0,x=1;
    unsigned long int temps = 0,seconde,pause=0;
    seconde=Microsecondes()+cycle;
    afficher_seconde(sec);
    afficher_minute(min);
    EcrireTexte(110,100,":",2);
    while(x=1){
	    if(Microsecondes()>seconde){
            sec++;
            printf("%d\n",sec);
            afficher_seconde(sec);
            seconde=Microsecondes()+cycle;
            if(sec==60){
                sec=0;
                min++;
                afficher_seconde(sec);
                afficher_minute(min);
            }
            
        }
        if(ToucheEnAttente()==1){
                if(Touche()==XK_space){
                    pause=attendre();
                }
                if(Touche()==XK_Escape){
                    x=0;
                }
        }
    }
}

int main(void){
    InitialiserGraphique();
    CreerFenetre(1000,0,1000,1000);
    creer_timer();
    FermerGraphique();
    return EXIT_SUCCESS;
}
