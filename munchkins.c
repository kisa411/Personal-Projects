#include <stdio.h>

/* function prototypes */

int makeplayers(int players);
void currentscore(char names[][10], int stats[][3], int players); //first number is level, second number is combat score, third number is class (default is 1)
void gainlevel(int stats[][3], char names[][10], int players);
void loselevel(int stats[][3], char names[][10], int players);
void gaincombatstrength(int stats[][3], char names[][10], int players);
void losecombatstrength(int stats[][3], char names[][10], int players);
void classchange(int stats[][3], char names[][10], int players);

/*-----------------------------------------------------------------------------------------*/

int main () {
	int players, action, loop = 1; //stats contains player levels and combat strength
	char names[][10], temporary[10]; //names[][10] contains player names


	printf("How many players are there?");
	scanf("%d", &players);

	printf("What are the names of the players?"); //starting from the first slot, put in player names
	for ( i=0; i<=players; i++ ) {
		scanf("%s", names[i]);
	}

	stats = makeplayers(players); //initialize player info based on the number of players 
	currentscore(stats, names, players); //print initial scores

	while (loop) {
		printf("What happened?\n 1. Lost to monster\n 2. Won monster\n 3. Equipped armor\n 4. Gained a class\n 5. Gained combat strength\n 6. Lost combat strength\n 7. Quit\n");
		scanf("%d", &action);
		switch(action) {
			case 1: //lost to monster, need to decrease level by one and combat strength by one
				loselevel(stats, names, players);
				currentscore(stats, names, players); //print current score
				break;

			case 2: //won monster, need to increase level by one and combat strength by one
				gainlevel(stats, names, players);
				currentscore(stats, names, players);
				break;

			case 3: //equipped armor, need to increase combat strength by appropriate amount
				statuschange(stats, names, players);
				currentscore(stats, names, players);
				break;
				
			case 4: //character gains a class
				classchange(stats, names, players);
				currentscore(stats, names, players);
				break;

			case 5: //character gains combat strength without gaining a level
				gaincombatstrength(stats, names, players);
				currentscore(stats, names, players);
				break;

			case 6: //character loses combat strength without losing a level
				losecombatstrength(stats, names, players);
				currentscore(stats, names, players);
				break;

			case 7: //when game is over, quits score keeping
				loop = 0;
				break;
		}
	}

	return 0;
}


int makeplayers(int players) {
	int i, j, stats[][3]; 

	for ( i=0; i<players; i++ ) {
		for ( j=0; j<3; j++ ) {
			stats[i][j] = 1; //array[row][column] - initializes everyone's level to 1 and combat strength to 1 and class to 1 (nothing)
		}
	}

	return stats[][3];

}


void gainlevel(int stats[][3], char names[][10], int players) {
	char temporary[10];

	printf("Which player gained a level?\n");
	scanf("%s", temporary);

	for ( i=0; i<=players; i++ ) {
		if (names[i] == temporary) { //increase level & combat strength
			stats[i][0]++;
			stats[i][1]++;
		} 
		if (stats[i][0] == 10) { //if a player reaches level 10 then print congratulations
			printf("Congratulations! %s has won the game. Heheheh\n", temporary);
		}
	}

}


void loselevel(int stats[][3], char names[][10], int players) {
	char temporary[10];

	printf("Which player lost a level?\n");
	scanf("%s", temporary);

	for ( i=0; i<=players; i++ ) {
		if (names[i] == temporary) {
			if (stats[i][0] != 1) { //lower level & combat strength
				stats[i][0]--;
			} if (stats[i][1] != 1) {
				stats[i][1]--;
			}
		} 
		if (stats[i][0] == 10) { //if a player reaches level 10 then print congratulations
			printf("Congratulations! %s has won the game. Heheheh\n", temporary);
		}
	}

}


void gaincombatstrength(int stats[][3], char names[][10], int players) {
	char temporary[10];
	int value;

	printf("Which player gained combat strength?\n");
	scanf("%s", temporary);
	printf("By how much?\n");
	scanf("%d", &value);

	for ( i=0; i<=players; i++ ) {
		if (names[i] == temporary) {
			stats[i][1] += value;
		} 
	}

}


void losecombatstrength(int stats[][3], char names[][10], int players) {
	char temporary[10];
	int value;

	printf("Which player lost combat strength?\n");
	scanf("%s", temporary);
	printf("By how much?\n");
	scanf("%d", &value);

	for ( i=0; i<=players; i++ ) {
		if (names[i] == temporary) {
			} if (stats[i][1] -= value >= 0) {
				stats[i][1] -= value;
			}
		} 
	}
}


void classchange(int stats[][3], char names[][10], int players) {
	int munchkin, i;
	char player[10], class[10];
	

	printf("Which player changed class?");
	scanf("%s", player);
	printf("What class is the player now?");
	scanf("%s", class);
	class = tolower(class);

	for ( i=0; i<players, i++ ) {
		if (names[i] == player && stats[i][3] == 1) { //if the player doesn't already have a class assigned to them
			if (class == "hero") {
				stats[i][2] = 2 //2 = Hero
				printf("Player %s's class has been changed to %s", player, class);
			} else if (class == "musician") {
				stats[i][2] = 3 //3 = Musician
				printf("Player %s's class has been changed to %s", player, class);
			} else if (class == "royalty") {
				stats[i][2] = 4 //4 = Royalty
				printf("Player %s's class has been changed to %s", player, class);
			} else if (class == "wizard") {
				stats[i][2] = 5 //5 = Wizard
				printf("Player %s's class has been changed to %s", player, class);	
			} else if (names[i] == player && stats[i][3] != 1) {
				printf("This player already has a class. Additional classes can only be added if the player is a Super Munchkin. If the player is a Super Munchkin, type '1' for yes - if not then type '0' for no.\n");
				scanf("%d", &munchkin);
				if (munchkin == 1) {
					stats[i][2] = 6; //6 = Munchkin
					printf("Player %s is now a Super Munchkin.");	
				}
			}
		}
	}

}


void currentscore(char names[][10], int stats[][3], int players) { //print out player names and current scores
	
	printf("***Current Standings***\n");

	for ( i=0; i<=players; i++ ) {
		printf("%s - Level: %d, Combat Strength: %d  ", names[i], stats[i][0], stats[1]);
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






