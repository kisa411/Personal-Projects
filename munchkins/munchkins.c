#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Adventure Time Munchkin Score Keeper

/*how to return an array from a function?

assigning specific values in an array to specific variable names?
*/


/* function prototypes */


int makeplayers(int players);
void currentscore(int *statsptr, char names[][10], int players); //first number is level, second number is combat score, third number is class (default is 1)
void gainlevel(int *statsptr, char names[][10], int players);
void loselevel(int *statsptr, char names[][10], int players);
void gaincombatstrength(int *statsptr, char names[][10], int players);
void losecombatstrength(int *statsptr, char names[][10], int players);
void classchange(int *statsptr, char names[][10], int players);

/*-----------------------------------------------------------------------------------------*/

int main () {
	int players, action, loop = 1, i; //stats contains player levels and combat strength
	char temporary[10]; //names[][10] contains player names


	printf("How many players are there?\n");
	scanf("%d", &players);

	printf("What are the names of the players?\n"); //starting from the first slot, put in player names

	char names[players][10];

	for ( i=0; i<=players; i++ ) {
		scanf("%s", temporary);
		strcpy(names[i], temporary);
	}

	int *statsptr = makeplayers(players); //initialize player info based on the number of players 
	currentscore(statsptr, names, players); //print initial scores

	while (loop) {
		printf("What happened?\n 1. Lost to monster\n 2. Won monster\n 3. Gained a class\n 4. Gained combat strength\n 5. Lost combat strength\n 6. Quit\n");
		scanf("%d", &action);
		switch(action) {
			case 1: //lost to monster, need to decrease level by one and combat strength by one
				loselevel(statsptr, names, players);
				currentscore(statsptr, names, players); //print current score
				break;

			case 2: //won monster, need to increase level by one and combat strength by one
				gainlevel(statsptr, names, players);
				currentscore(statsptr, names, players);
				break;

			case 3: //character gains a class
				classchange(statsptr, names, players);
				currentscore(statsptr, names, players);
				break;

			case 4: //character gains combat strength without gaining a level
				gaincombatstrength(statsptr, names, players);
				currentscore(statsptr, names, players);
				break;

			case 5: //character loses combat strength without losing a level
				losecombatstrength(statsptr, names, players);
				currentscore(statsptr, names, players);
				break;

			case 6: //when game is over, quits score keeping
				loop = 0;
				printf("Here are the final scores:\n");
				currentscore(statsptr, names, players);
				break;
		}
	}

	return 0;
}


int makeplayers(int players) {
	int i, j, *ptrstats, stats[players][3]; //stats is an 2-D array
	ptrstats = stats[players][3]; //reference the pointer - make statsptr point to location of stats[][] array
	int statsptr = (*ptrstats); //dereference pointer

	for ( i=0; i<players; i++ ) {
		for ( j=0; j<3; j++ ) {
			stats[i][j] = 1; //array[row][column] - initializes everyone's level to 1 and combat strength to 1 and class to 1 (nothing)
		}
	}

	return statsptr; //returns the array of ints

}


void gainlevel(int *statsptr, char names[][10], int players) {
	char temporary[10];
	int *stats = *(&statsptr);
	int i, level = stats[i][0], combat = stats[i][1];

	printf("Which player gained a level?\n");
	scanf("%s", temporary);

	for ( i=0; i<=players; i++ ) {
		if (names[i] == temporary) { //increase level & combat strength
			level++;
			combat++;
		} 
		if (stats[i][0] == 10) { //if a player reaches level 10 then print congratulations
			printf("Congratulations! %s has won the game. Heheheh\n", temporary);
		}
	}

}


void loselevel(int *statsptr, char names[][10], int players) {
	char temporary[10];
	int *stats = *(&statsptr);
	int i, level = stats[i][0], combat = stats[i][1];

	printf("Which player lost a level?\n");
	scanf("%s", temporary);

	for ( i=0; i<=players; i++ ) {
		if (names[i] == temporary) {
			if (stats[i][0] != 1) { //lower level & combat strength
				level--;
			} if (stats[i][1] != 1) {
				combat--;
			}
		} 
		if (stats[i][0] == 10) { //if a player reaches level 10 then print congratulations
			printf("Congratulations! %s has won the game. Heheheh\n", temporary);
		}
	}

}


void gaincombatstrength(int *statsptr, char names[][10], int players) {
	char temporary[10];
	int *stats = *(&statsptr);
	int value, i, level = stats[i][0], combat = stats[i][1];

	printf("Which player gained combat strength?\n");
	scanf("%s", temporary);
	printf("By how much?\n");
	scanf("%d", &value);

	for ( i=0; i<=players; i++ ) {
		if (names[i] == temporary) {
			combat += value;
		} 
	}

}


void losecombatstrength(int *statsptr, char names[][10], int players) {
	char temporary[10];
	int *stats = *(&statsptr);
	int value, i, level = stats[i][0], combat = stats[i][1];

	printf("Which player lost combat strength?\n");
	scanf("%s", temporary);
	printf("By how much?\n");
	scanf("%d", &value);

	for ( i=0; i<=players; i++ ) {
		if (names[i] == temporary) {
			combat -= value; //combat strength can go below 1
		} 
	}
}


void classchange(int *statsptr, char names[][10], int players) {
	int munchkin, i, level = stats[i][0], combat = stats[i][1], class = stats[i][2];
	int *stats = *(&statsptr);
	char player[10], classname[10];
	

	printf("Which player changed class?\n");
	scanf("%s", player);
	printf("What class is the player now?\n");
	scanf("%s", classname);
	while (class[i]) {
		strcpy(class[i], tolower(classname[i])); //copy what's in classname[i] to class[i]
	  	i++;
    }

	for ( i=0; i<players; i++ ) {
		if (names[i] == player && class == 1) { //if the player doesn't already have a class assigned to them
			if (strncmp(class, "hero", 4) == 0) {
				class = 2; //2 = Hero
				printf("Player %s's class has been changed to %s", player, class);
			} else if (strncmp(class, "musician", 8) == 0) {
				class = 3; //3 = Musician
				printf("Player %s's class has been changed to %s", player, class);
			} else if (strncmp(class, "royalty", 7) == 0) {
				class = 4; //4 = Royalty
				printf("Player %s's class has been changed to %s", player, class);
			} else if (strncmp(class, "wizard", 6) == 0) {
				class = 5; //5 = Wizard
				printf("Player %s's class has been changed to %s", player, class);	
			} else if (names[i] == player && class != 1) {
				printf("This player already has a class. Additional classes can only be added if the player is a Super Munchkin. If the player is a Super Munchkin, type '1' for yes - if not then type '0' for no.\n");
				scanf("%d", &munchkin);
				if (munchkin == 1) {
					class = 6; //6 = Munchkin
					printf("Player %s is now a Super Munchkin.\n", player);	
				}
			}
		}
	}

}


void currentscore(int *statsptr, char names[][10], int players) { //print out player names and current scores
	int i;
	int *stats = *(&statsptr);

	printf("***Current Standings***\n");

	for ( i=0; i<=players; i++ ) {
		printf("%s - Level: %d, Combat Strength: %d  ", names[i], stats[i][0], stats[i][1]);
		if (stats[i][2] == 2) {
			printf("Class: Hero\n");
		} else if (stats[i][2] == 3) {
			printf("Class: Musician\n");
		} else if (stats[i][2] == 4) {
			printf("Class: Royalty\n");
		} else if (stats[i][2] == 5) {
			printf("Class: Wizard\n");
		} else if (stats[i][2] == 6) {
			printf("Class: Munchkin\n");
	    } else {
			printf("Class: None\n");
		}
	} printf("\n\n");

}






