#pragma once

#include "entity.h"

/**
@brief Creates an Player object that inherits Entity
Creates an Player object that inherits Entity with a x velocity.
*/
class Player : public Entity
{
private:
	/*x velocity*/
	float xVelocity;
public:
	/**
	Constructs the Player object
	@param float the initial x position
	@param float the initial y position
	@param int the Player sprite's x scale
	@param int the Player sprite's y scale
	@param int the Player current animation index;
	*/
	Player(float, float, int, int, int);

	/**
	Destructs an Player object
	*/
	~Player();

	/**
	Setter # x velocity
	Sets the x velocity of the Player object to the inputed velocity.
	@param float the inputed x velocity
	*/
	void setXVelocity(float);

	/**
	Getter # x velocity
	@returns the x velocity of the Player object.
	*/
	float getXVelocity();

	/**
	Updates the Player x position
	Updates the Player x position using the velocity and the dt.
	@param float the dt
	*/
	void updateX(float);
};