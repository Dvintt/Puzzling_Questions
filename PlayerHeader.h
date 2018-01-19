//DAVID ALDAY
//Header for Player Class
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

//Player class : Includes accessor methods
class Player
{

//Public player class accessor methods
public:
	Player();
	int get_Lives();
	void lose_Life();

//Player lives varible
private:
	int lives;


};

#endif