#include "player.h"

/**************************************************************************************************************/

/*Constructs the player object*/
Player::Player(float inX, float inY, int xScale, int yScale, int inAnimIndex) : Entity(inX, inY, xScale, yScale, inAnimIndex)
{
	/*initialise the x velocity*/
	xVelocity = 0.0f;
}

/**************************************************************************************************************/

/*Destructs the player object*/
Player::~Player()
{
}

/**************************************************************************************************************/

/*sets the x velocity of the player*/
void Player::setXVelocity(float inVelocity)
{
	/*sets the x velocity to the value of the inputed x velocity*/
	xVelocity = inVelocity;
}

/**************************************************************************************************************/

/*returns the x velocity*/
float Player::getXVelocity()
{
	/*returns the velocity*/
	return xVelocity;
}

/**************************************************************************************************************/

/*updates the players x position using its velocity and the dt*/
void Player::updateX(float dt)
{
	/*updates the players position using the velocity and dt*/
	x += xVelocity * dt;
}