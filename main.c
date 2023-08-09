/* Developer: Fateh Amjad.
  main.c - C file containing all codes to run the executable laserTank file */
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "map.h"
#include "movement.h"

int main(int argc, char *argv[])
{
	int i;
        int R, C, RE, CE;
	int barrelRow, barrelColumn;
	int* rp = malloc(sizeof(int));
	int* cp = malloc(sizeof(int));
	int lose;
	char move = 'w';					/* Initializes all variables that are being made used in the game. */
	char *DP = malloc(sizeof(char));
	char *DE = malloc(sizeof(char));
	char **array2;

   	/* The below opens the file map.txt to read the arguement details*/
	FILE *pointer_to_file = fopen(argv[1], "r");

 	/* After reading the map.txt file, it creates the map based on the values stored */
	fscanf(pointer_to_file, "%d,%d", &R, &C);
	array2 = map(R, C);

  	/* Positions are allocated to players by making the values read into pointers */
	fscanf(pointer_to_file, "%d,%d,%s", rp, cp, DP);
	players(*rp, *cp, DP, array2);   
      
    /* Reads and allocates enemy location on map */
	fscanf(pointer_to_file, "%d,%d,%s", &RE, &CE, DE);
	players(RE, CE, DE, array2);

	while(!feof(pointer_to_file)){
        	fscanf(pointer_to_file, "%d,%d", &barrelRow, &barrelColumn);
        	array2[barrelRow][barrelColumn] = 'B';
	}
	
    /* Closes the map.txt file sucessfully*/
	fclose(pointer_to_file);

	do{
		system("clear");
		printArray(R, C, array2);
		printf("To run the program, enter one of the commands:\n"
			"'w' -> Moves the player up\n"
			"'s' -> Moves the player down\n"
			"'d' -> Moves the player to the right\n"
			"'a' -> Moves the player to the left\n"
			"'f' -> Allows the player to shoot laser\n"
			"'q' -> Quit the program\n");
		scanf("%c", &move);
		if (move == 'f')
                {
                        shoot(rp, cp, array2);
			system("clear\n");
			printArray(R,C, array2);
			sleep(1);
			clearShoot(rp, cp, array2);
		}
		else {
			array2 = movement(rp, cp , move, array2);	/* The main execution of the laserTank program is done using the loops besides. */
			lose = enemyShoot(RE,CE,array2);
			/*system("clear\n");*/
			if (lose == 1)
			{
				system("clear");
				printArray(R,C,array2);
				printf("You lost!\n");
			}
			else {
			/*system("clear\n");*/
			clearShoot(&RE, &CE, array2);
			printArray(R,C,array2);
			}
		}
		if (array2[RE][CE] == 'X')
		{
			printf("You have won!\n");
		}
		if (move == 'q')
		{
			printf("You have sucessfully quit the laserTank game.\n");
		}
	}
	
	while (array2[RE][CE] != 'X' && lose != 1 && move != 'q');
	
  	/* To avoid memory leaks, the malloc'd arrays are freed below */
	for (i = 0; i < R+1; i++) 
	{
		free(array2[i]);
		array2[i] = NULL;
	}

        free(array2);
	array2 = NULL;
 
  	/* Further frees the below variables that were malloc'd */	
	free(rp);
	free(cp);
	free(DP);
	free(DE);
        return 0;
}
