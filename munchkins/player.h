#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
using namespace std;

class Player {

public:
	Player( string n ); //constructor - make player (default class is none, default level is 1, default combat strength is 1)
	void changeLevel( int change ); //changes the player's level - also changes player's combat strength
	void changeCombatStrength( int change ); //changes the player's combat strength
	void changeClass( string change ); //changes player's class
	void displayCurrentScores(); //display the current status and scores of players
	string getName(); //return the name of the player 


private:
	string name, playerClass;
	int level, combatScore;
};




#endif