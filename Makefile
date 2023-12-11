Snake : main.o jeu.o grille.o menu.o obstacle.o pomme.o serpent.o timer.o
	gcc -lgraph -o Snake main.o jeu.o grille.o menu.o obstacle.o pomme.o serpent.o timer.o

main.o : ./src/main.c ./include/main.h ./include/menu.h ./include/jeu.h

	gcc -ansi -pedantic -c ./src/main.c

jeu.o : ./src/jeu.c ./include/grille.h ./include/serpent.h ./include/pomme.h ./include/jeu.h ./include/menu.h ./include/timer.h ./include/obstacle.h

	gcc -ansi -pedantic -c ./src/jeu.c

grille.o : ./src/grille.c ./include/grille.h

	gcc -ansi -pedantic -c ./src/grille.c

menu.o : ./src/menu.c ./include/menu.h ./include/main.h

	gcc -ansi -pedantic -c ./src/menu.c

obstacle.o : ./src/obstacle.c ./include/grille.h ./include/serpent.h ./include/obstacle.h ./include/pomme.h

	gcc -ansi -pedantic -c ./src/obstacle.c

pomme.o : ./src/pomme.c ./include/grille.h ./include/serpent.h

	gcc -ansi -pedantic -c ./src/pomme.c

serpent.o : ./src/serpent.c ./include/serpent.h ./include/main.h ./include/timer.h

	gcc -ansi -pedantic -c ./src/serpent.c

timer.o : ./src/timer.c ./include/timer.h

	gcc -ansi -pedantic -c ./src/timer.c

clean : 
	-rm -f main.o jeu.o grille.o menu.o obstacle.o pomme.o serpent.o timer.o

.phony : clean