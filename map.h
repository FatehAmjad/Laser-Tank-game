/* Developer: Fateh Amjad.
   map.h - Header file which links main.c with map.c functionality */

#include <stdlib.h>
#include <stdio.h>

#ifndef maps
#define maps

void printArray(int R, int C, char **array);
char** map(int R, int C);
char** players(int R, int C, char *direction, char **array);

#endif
