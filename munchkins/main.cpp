#include "munchkin.h"
#include <iostream>
#include <string>
using namespace std;

int main () {
	int loop = 1, action, playerCount=0, player, change;
	string name, playerClass;

	while (loop) {
		cout << "Would you like to create a new player?\n1. Yes\n2. No" << endl;

		cin >> action;

		switch(action) {
			case 1: //create a new player object
				playerCount++;
				cout << "What is the player's name?" << endl;
				cin >> name;
				cout << "Creating player: " << playerCount << endl;
				//TODO - Munchkin playerCount( name ); 
				cout << "Player " << playerCount << " has been created!" << endl;
				break;

			case 2: //finished creating player objects, 
				cout << "Okay, I've finished making all the players! Let's continue with the game:)." << endl;
				loop = 0; 
				break;
		}
	}

	loop = 1;

	while (loop) {
		printf("What happened?\n 1. Lost a level\n 2. Gained a level\n 3. Gained a class\n 4. Gained combat strength\n 5. Lost combat strength\n 6. Quit\n");
		cin >> action;

		cout << "Which player did it happen to? Put in the number of the player." << endl;
		for ( int i=1; i<=playerCount; i++ ) {
			cout << i << ". " << i.getName() << endl;
		}
		cin >> player;


		//TODO - change member operation accessor objects
		switch(action) {
			case 1: //lost levels, need to decrease level combat strength
				cout << "How many levels did the player lose?" << endl;
				cin >> change;
				player.changeLevel( -change );
				cout << "Here are the changed stats." << endl << endl;
				for ( int i=1; i<=playerCount; i++ ) {
					i.displayCurrentScore(); //print current score
				}

				break;

			case 2: //gained level, need to increase level and combat strength
				cout << "How many levels did the player gain?" << endl;
				cin >> change;
				player.changeLevel( change );
				cout << "Here are the changed stats." << endl << endl;
				for ( int i=1; i<=playerCount; i++ ) {
					i.displayCurrentScore(); //print current score
				}
				break;

			case 3: //character gains a class
				cout << "What class did the player gain?" << endl;
				cin >> playerClass;
				classchange( playerClass );
				cout << "Here are the changed stats." << endl << endl;
				for ( int i=1; i<=playerCount; i++ ) {
					i.displayCurrentScore(); //print current score
				}
				break;

			case 4: //character gains combat strength without gaining a level
				cout << "How many points of combat strength did the player gain?" << endl;
				cin >> change;
				player.changeCombatStrength( change );
				cout << "Here are the changed stats." << endl << endl;
				for ( int i=1; i<=playerCount; i++ ) {
					i.displayCurrentScore(); //print current score
				}
				break;

			case 5: //character loses combat strength without losing a level
				cout << "How many points of combat strength did the player lose?" << endl;
				cin >> change;
				player.changeCombatStrength( -change );
				cout << "Here are the changed stats." << endl << endl;
				for ( int i=1; i<=playerCount; i++ ) {
					i.displayCurrentScore(); //print current score
				}
				break;

			case 6: //when game is over, quits score keeping
				loop = 0;
				cout << "Here are the final scores:" << endl;
				for ( int i=1; i<=playerCount; i++ ) {
					i.displayCurrentScore(); //print current score
				}
				break;
		}
	}



	return 0;

}




