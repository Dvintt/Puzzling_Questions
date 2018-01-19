//DAVID ALDAY

#include "PlayerHeader.h"
using namespace std;


//Constructor, starts player out with 3 lives
Player::Player()
{
	lives = 4;
}



//returns the amount of lives
int Player:: get_Lives()
{
	return lives;
}

//Take away a life from a player
void Player::lose_Life()
{
	lives--;
}

