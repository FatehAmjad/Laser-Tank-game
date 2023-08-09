/* Developer: Fateh Amjad.
   movement.h - Header file which links main.c with movement.c functionality */

#include <stdlib.h>
#include <stdio.h>

#ifndef movements
#define movements

char** movement(int* rp, int* cp, char move, char** array);
void shoot(int *rp, int* cp, char **array);
void clearShoot(int *rp, int* cp, char **array);
int enemyShoot(int rp, int cp, char **array);

#endif

