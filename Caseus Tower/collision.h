#pragma once

#include "player.h"
#include "entity.h"

/**
@brief a namespace for Collision
A namespace containing functions to test for Collision.
*/
namespace Collision
{
	/**
	Checks if the Player intersects with the platform
	Checks if the Player intersects with the platform using the velocity and the dt for the updated positions.
	@param Player * a pointer to the player
	@param Entity * a pointer to the platform
	@param float the dt
	*/
	bool playerPlatformIntersectCheck(Player *, Entity *, float);
};