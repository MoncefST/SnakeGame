#ifndef SERPENT_H
#define SERPENT_H


typedef struct {
    int x, y;
} Segment;

void initialiserSerpent(Segment serpent[], int *longueur);
void gestionDeplacements(Segment serpent[], int *direction_x, int *direction_y);
int tuerSerpent(Segment serpent[]);
void mettreAJourSerpent(Segment serpent[], int *longueur, int *direction_x, int *direction_y);
void dessinerSerpent(Segment serpent[], int *longueur);
int seMangerQueue(Segment serpent[], int longueur);

#endif /*SERPENT_H*/
