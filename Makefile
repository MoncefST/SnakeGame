Snake : main.o jeu.o grille.o menu.o obstacle.o pomme.o serpent.o timer.o
	gcc -ansi -pedantic -lgraph -o Snake ../src/main.c ../src/jeu.c ../src/grille.c ../src/menu.c ../src/obstacle.c ../src/pomme.c ../src/serpent.c ../src/timer.c

main.o : ../src/main.c ../include/menu.h ../include/jeu.h

	gcc -ansi -pedantic -lgraph ../src/main.c

jeu.o : ../src/jeu.c ../include/grille.h ../include/serpent.h ../include/pomme.h ../include/jeu.h ../include/menu.h ../include/timer.h ../include/obstacle.h

	gcc -ansi -pedantic -lgraph ../src/jeu.c

grille.o : ../src/grille.c ../include/grille.h

	gcc -ansi -pedantic -lgraph ../src/grille.c

menu.o : ../src/menu.c ../include/menu.h ../include/main.h

	gcc -ansi -pedantic -lgraph ../src/menu.c

obstacle.o : ../src/obstacle.c ../include/grille.h ../include/serpent.h ../include/obstacle.h ../include/pomme.h

	gcc -ansi -pedantic -lgraph ../src/obstacle.c

pomme.o : ../src/pomme.c ../include/grille.h ../include/serpent.h

	gcc -ansi -pedantic -lgraph ../src/pomme.c

serpent.o : ../src/serpent.c ../include/serpent.h ../include/main.h ../include/timer.h

	gcc -ansi -pedantic -lgraph ../src/serpent.c

timer.o : ../src/timer.c ../include/timer.h

	gcc -ansi -pedantic -lgraph ../src/timer.c

clean : 
	-rm -f main.o jeu.o grille.o menu.o obstacle.o pomme.o serpent.o timer.o

.phony : clean