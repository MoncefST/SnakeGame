#ifndef TIMER_H
#define TIMER_H

void initialiser_timer(int *min, int *sec);
int afficher_seconde(int sec);
int afficher_minute(int min);
void update_timer(int *min, int *sec);
void pause(void);

#endif /* TIMER_H */
