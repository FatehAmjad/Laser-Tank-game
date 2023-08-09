/* Developer: Fateh Amjad.
  map.c - File used to display the map, player, and enemy onto the user screen when run */

#include <stdlib.h>
#include <stdio.h>
#include "map.h"

char** map(int R, int C)
{
        int a, b;
        char **array;

        array = (char**)malloc(R * sizeof(char*));
									/* The map funciton creates a 2D array, which further gets used for the directing and moving the player accross the map, */
        for(a=0; a<=R; a++)						/*   and also for initializing the position of the enemy tank */  
        {								   	
		array[a] = malloc(R * sizeof(char));

                for(b=0; b<=C; b++)
            {
		    if (array[a][b] != '-' && array[a][b] != '|' && array[a][b] != 'X' && array[a][b] != 'B') 
		    {
		    	if(a==0 || a==R || b==0 || b==C)
			{
				array[a][b] = '*';
			}
			else
			{
				array[a][b] = ' ';
			}
		    }
	    } 
	}

	return array;
}

void printArray(int R, int C, char **array)
{
        int a, b;

        for(a=0; a<=R; a++)						/* The printArray function returns nothing. However, it contains the code to display the map(2D array) of the game onto the user */
        {										/* screen when run. */
            for(b=0; b<=C; b++)
            {
                    printf("%c", array[a][b]);
            }
            printf("\n");
        }
}

char** players(int R, int C, char *direction, char **array)
{
	char c = *(direction);

	if (c == 'u')
	{	
		array[R][C] = '^';
	}
	else if ( c == 'd')
	{
		array[R][C] = 'v';					/* The players function returns an array; this array would now include both the player tank and the enemy tank, and according */
	}										/* to what the user inputs in the command line for the direction of the player-tank and enemy-tank, those will be the */
	else if ( c == 'r')						/* starting positions of both tanks at the beginning of the game. */
	{
		array[R][C] = '>';
	}
	else if ( c == 'l')
	{
		array[R][C] = '<';
	}

	return array;	
}

