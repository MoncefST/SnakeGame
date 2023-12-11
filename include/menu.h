#ifndef MENU_H
#define MENU_H

void afficherBouton(double x1, double y1, double x2, double y2, const char *texte, couleur arriere_plan, couleur bordure, couleur couleur_texte, int taille_texte);
void afficherMenuPrincipal(void);
void afficherMenuModesDeJeu(void);
void afficherMenuGameOver(void);
void attendreChoixGameOver(void);
int attendreChoixModesDeJeu(void);
int attendreChoixMenu(void);

#endif  /*MENU_H*/
