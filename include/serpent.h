#ifndef SERPENT_H
#define SERPENT_H

typedef struct {
    int x, y;
} Segment;
typedef Segment* Serpent;

void initialiserSerpent(Serpent serpent, int *longueur);
int gestionTouches(Serpent serpent, int *direction_x, int *direction_y);
int tuerSerpent(Serpent serpent, int longueur);
void mettreAJourSerpent(Serpent serpent, int *longueur, int *direction_x, int *direction_y);
void dessinerSerpent(Serpent serpent, int *longueur);
void attendreSerpent(unsigned long int microseconds);

#endif /*SERPENT_H*/
