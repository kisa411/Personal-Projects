#ifndef
#define
#include <iostream>
#include <string>
using namespace std;

class Munchkin {

public:
	Munchkin( string n, int l, int cS ); //constructor - make player (default class is none)
	void changeLevel( int change ); //changes the player's level - also changes player's combat strength
	void changeCombatStrength( int change ); //changes the player's combat strength
	void changeClass( string change ); //changes player's class 


private:
	string name, playerClass;
	int level, combatScore;
};




#endif


