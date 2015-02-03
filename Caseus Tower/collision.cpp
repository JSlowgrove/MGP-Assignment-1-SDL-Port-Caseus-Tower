#include "collision.h"

/**************************************************************************************************************/

/*checks if the player intersects with the platform*/
bool Collision::playerPlatformIntersectCheck(Player * player, Entity * entity, float dt)
{
	/*initialise variables for use with checking*/
	float extraPloatformPosition = (entity->getYScale()*0.25f) * 3.0f; //as the collision on the platform is not the top of the sprite
	float currentPlayerCollisonY = player->getY() + player->getYScale();
	float currentEntityCollisionY = entity->getY() + extraPloatformPosition;
	float updatedPlayerCollisonY = player->getY() + (player->getYVelocity() * dt) + player->getYScale();
	float updatedEntityCollisionY = entity->getY() + (entity->getYVelocity() * dt)  + extraPloatformPosition;
	float playerCollsionMinX = player->getX() + (player->getXVelocity() * dt);
	float playerCollsionMaxX = player->getX() + (player->getXVelocity() * dt) + player->getXScale();
	float entityCollsionMinX = entity->getX();
	float entityCollsionMaxX = entity->getX() + entity->getXScale();

	/*test if the player is currently above the entity*/
	if (currentPlayerCollisonY < currentEntityCollisionY)
	{
		/*test if the updated player will collide with the updated entity*/
		if (updatedPlayerCollisonY >= updatedEntityCollisionY
			&& playerCollsionMinX >= entityCollsionMinX
			&& playerCollsionMinX <= entityCollsionMaxX
			|| updatedPlayerCollisonY >= updatedEntityCollisionY
			&& entityCollsionMinX >= playerCollsionMinX
			&& entityCollsionMinX <= playerCollsionMaxX)
		{
			/*collision*/
			return true;
		}
	}
	/*no collision*/
	return false;
}