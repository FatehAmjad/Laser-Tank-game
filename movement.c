/* Developer: Fateh Amjad.
   movement.c - C file which is used to move the player across the map, based on the user input */

#include <stdio.h>
#include <stdlib.h>
#include "movement.h"

char** movement(int* rp, int* cp, char move, char** array2)
{
	char** array = array2;

	if (move == 'w')
	{
		if (array[*rp][*cp] != '^')
		{
			array[*rp][*cp] = '^';
		}
		else {
		array[*rp][*cp] = ' ';
		*rp -= 1;
		array[*rp][*cp] = '^';
		}
	}

	if (move == 's')
        {										
                if (array[*rp][*cp] != 'v')						/* The "movement" function basically makes use of an array, which is used to navigate player across the map */
                {									/* based on what the user enters in the command line. In other words, it basically moves the player as per*/
                        array[*rp][*cp] = 'v';								/* the commands that have been provided between 'w', 'd', 's', 'a', and 'f'.*/
                }
                else {
                array[*rp][*cp] = ' ';
                *rp += 1;
                array[*rp][*cp] = 'v';
                }
        }

	if (move == 'd')
        {
                if (array[*rp][*cp] != '>')
                {
                        array[*rp][*cp] = '>';
                }
                else {
                array[*rp][*cp] = ' ';
                *cp += 1;
                array[*rp][*cp] = '>';
                }

   	}

	if (move == 'a')
        {
                if (array[*rp][*cp] != '<')
                {
                        array[*rp][*cp] = '<';
                }
                else {
                array[*rp][*cp] = ' ';
                *cp -= 1;
                array[*rp][*cp] = '<';
                }
        }

	return array;
}

void shoot(int *rp, int* cp, char **array)
{
	int a;

	if (array[*rp][*cp] == 'v')
	{
		a = *rp + 1;
	       	while (array[a][*cp] == ' ')
		{
			array[a][*cp] = '|';
		       	a++;
		}

		if (array[a][*cp] == 'v' || array[a][*cp] == '^' || array[a][*cp] == '<' || array[a][*cp] == '>')
		{
			array[a][*cp] = 'X';
		}
		{

		}
	}
	else if (array[*rp][*cp] == '^')					/* The shoot function is responsible for the firing of laser from the player, to its target(enemy), whenever 'f' is input*/
	{															  /* as an command to execute */
		a = *rp - 1;
		while (array[a][*cp] == ' ')
		{
			array[a][*cp] = '|';
			a--;
		}

		if (array[a][*cp] == '^' || array[a][*cp] == 'v' || array[a][*cp] == '<' || array[a][*cp] == '>')	
		{
			array[a][*cp] = 'X';
		}
	}
	else if (array[*rp][*cp] == '>')					
	{															
		a = *cp + 1;
		while (array[*rp][a] == ' ')
		{
			array[*rp][a] = '-';
			a++;
		}
		if (array[*rp][a] == '>' || array[*rp][a] == 'v' || array[*rp][a] == '<' || array[*rp][a] == '^')
		{
			array[*rp][a] = 'X';
		}
	}
	else if (array[*rp][*cp] == '<')
        {
                a = *cp - 1;
                while (array[*rp][a] == ' ')
                {
                        array[*rp][a] = '-';
                        a--;
                }                               
                if (array[*rp][a] == '<' || array[*rp][a] == '^' || array[*rp][a] == '>' || array[*rp][a] == 'v')
                {
                        array[*rp][a] = 'X';
                }
        }
}

void clearShoot(int *rp, int* cp, char **array)
{
        int a;

        if (array[*rp][*cp] == 'v')
        {
                a = *rp + 1;
                while (array[a][*cp] == '|')
                {
                        array[a][*cp] = ' ';
                        a++;
                }
	}
	 else if (array[*rp][*cp] == '^')                                     
        {                                                                                                                     
                a = *rp - 1;
                while (array[a][*cp] == '|')
                {
                        array[a][*cp] = ' ';
                        a--;
                }
	}
	 else if (array[*rp][*cp] == '>')
        {
                a = *cp + 1;
                while (array[*rp][a] == '-')						/* The clearShoot function is used to erase the laser if the target has been missed by the player */
                {								        /* With the help of "system("clear");", the screen erases the laser missed, for better visibility of the map */
                        array[*rp][a] = ' ';
                        a++;
                }
        }
	  else if (array[*rp][*cp] == '<')
        {
                a = *cp - 1;
                while (array[*rp][a] == '-')
                {
                        array[*rp][a] = ' ';
                        a--;
                }
        }
}

int enemyShoot(int rp, int cp, char **array)
{
        int a;
	int lose = 0;

        if (array[rp][cp] == 'v')
        {
                a = rp + 1;
                while (array[a][cp] == ' ')
                {
                        array[a][cp] = '|';
                        a++;
                }

                if (array[a][cp] == 'v' || array[a][cp] == '^' || array[a][cp] == '<' || array[a][cp] == '>')
                {
                        array[a][cp] = 'X';
			lose = 1;
                }
        }
        else if (array[rp][cp] == '^')                        /* The enemyShoot function is responsible for the firing of laser BUT FROM THE ENEMY INSTEAD, to its target(player), whenever 'f' is input*/
        {                                                     /* as a command to execute by the user; it is different from the function above in the sense that this returns a value "lose" if the enemy */
                a = rp - 1;				      /* has sucessfully shot the player tank. Moreover, as mentioned, it has a new int variable called "lose", which is used to output the loss */
                while (array[a][cp] == ' ')		      							/* result when killed by the enemy tank */
                {
                        array[a][cp] = '|';
                        a--;
                }

                if (array[a][cp] == '^' || array[a][cp] == 'v' || array[a][cp] == '<' || array[a][cp] == '>')
                {
                        array[a][cp] = 'X';
			lose = 1;
                }
        }
        else if (array[rp][cp] == '>')
        {
                a = cp + 1;
                while (array[rp][a] == ' ')
                {
                        array[rp][a] = '-';
                        a++;
                }
                if (array[rp][a] == '>' || array[rp][a] == 'v' || array[rp][a] == '<' || array[rp][a] == '^')
			 {
                        array[rp][a] = 'X';
			lose = 1;
                }
        }
        else if (array[rp][cp] == '<')
        {
                a = cp - 1;
                while (array[rp][a] == ' ')
                {
                        array[rp][a] = '-';
                        a--;
                }
                if (array[rp][a] == '<' || array[rp][a] == '^' || array[rp][a] == '>' || array[rp][a] == 'v')
                {
                        array[rp][a] = 'X';
			lose = 1;
                }
        }
	return lose;
}
