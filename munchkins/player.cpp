#include <iostream>
#include <string>
#include "player.h"
using namespace std;

Player::Player( string n ) {
	
	name = n;
	playerClass = "none";
	level = 1;
	combatScore = 1;

}

void Player::changeLevel( int change ) {
	
	level+=change;
	
}

void Player::changeCombatStrength( int change ) {
	
	combatScore+=change;

}

void Player::changeClass( string change ) {
	int answer; 

	if ( playerClass == "none" ) { //player doesn't have previously assigned class, just assign new class to player
		playerClass = change;
	} else {
		cout << "This player already has a class assigned to them. Only munchkin or supermunchkins can have multiple classes. Is the player's a munchkin or super munchkin? Put in '1' for yes or '0' for no." << endl;
		cin >> answer;
		if ( answer == 1 ) {
			playerClass = "Munchkin/Supermunchkin"; //set the player's class to munchkin
		} else {
			cout << "Since the player is not a munchkin or supermunchkin, he/she must discard the current class. The class will be changed to the newly acquired class." << endl;
			playerClass = change;
		}
	}
	

}

void Player::displayCurrentScores() {

	cout << "Player: " << name << endl;
	cout << "Class: " << playerClass << endl;
	cout << "Level: " << level << endl;
	cout << "Combat Score: " << combatScore << endl << endl;

}

string Player::getName() {
	
	return name;

}




