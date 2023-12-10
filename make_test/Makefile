Snake : jeu.o main.o grille.o menu.o obstacle.o pomme.o serpent.o timer.o
	gcc -ansi -pedantic -lgraph -o Snake main.o jeu.o grille.o menu.o obstacle.o pomme.o serpent.o timer.o

jeu.o : jeu.c grille.h serpent.h pomme.h jeu.h menu.h timer.h obstacle.h

	gcc -ansi -pedantic -lgraph jeu.c

main.o : main.c main.h menu.h jeu.h

	gcc -ansi -pedantic -lgraph main.c

grille.o : grille.c grille.h

	gcc -ansi -pedantic -lgraph grille.c

menu.o : menu.c menu.h main.h

	gcc -ansi -pedantic -lgraph menu.c

obstacle.o : obstacle.c grille.h serpent.h obstacle.h pomme.h

	gcc -ansi -pedantic -lgraph obstacle.c

pomme.o : pomme.c grille.h serpent.h

	gcc -ansi -pedantic -lgraph pomme.c

serpent.o : serpent.c serpent.h main.h timer.h

	gcc -ansi -pedantic -lgraph serpent.c

timer.o : timer.c timer.h

	gcc -ansi -pedantic -lgraph timer.c

clean : 
	-rm -f main.o jeu.o grille.o menu.o obstacle.o pomme.o serpent.o timer.o

.phony : clean