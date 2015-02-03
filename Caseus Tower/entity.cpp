#include "entity.h"

/**************************************************************************************************************/

/*Constructs the entity object*/
Entity::Entity(float inX, float inY, int inXScale, int inYScale, int inAnimIndex)
{
	/*sets the scale of the entity to the input scale*/
	xScale = inXScale; 
	yScale = inYScale;
	/*sets the initial position of the Entity to the input positions*/
	x = inX;
	y = inY;
	/*sets the initial y velocity*/
	yVelocity = 0.0f;
	/*initialise display*/
	display = true;
	/*initialise the animation index*/
	animationIndex = inAnimIndex;
}

/**************************************************************************************************************/

/*Destructs the entity object*/
Entity::~Entity()
{
}


/**************************************************************************************************************/

/*sets the x position of the entity*/
void Entity::setX(float inX)
{
	/*sets the x position to the value of the inputed x position*/
	x = inX;
}

/**************************************************************************************************************/

/*sets the y position of the entity*/
void Entity::setY(float inY)
{
	/*sets the y position to the value of the inputed y position*/
	y = inY;
}

/**************************************************************************************************************/

/*sets the x scale of the entity*/
void Entity::setXScale(int inXScale)
{
	/*sets the x scale to the value of the inputed x scale*/
	xScale = inXScale;
}

/**************************************************************************************************************/

/*sets the y scale of the entity*/
void Entity::setYScale(int inYScale)
{
	/*sets the y scale to the value of the inputed y scale*/
	yScale = inYScale;
}

/**************************************************************************************************************/

/*sets the y velocity of the entity*/
void Entity::setYVelocity(float inVelocity)
{
	/*sets the y velocity to the value of the inputed y velocity*/
	yVelocity = inVelocity;
}

/**************************************************************************************************************/

/*sets the animation index of the entity*/
void Entity::setAnimationIndex(int inIndex)
{
	/*sets the animation index to the value of the inputed index*/
	animationIndex = inIndex;
}

/**************************************************************************************************************/

/*sets the display of the entity*/
void Entity::setDisplay(bool inDisplay)
{
	/*sets the display boolean*/
	display = inDisplay;
}

/**************************************************************************************************************/

/*returns the x position*/
float Entity::getX()
{
	/*returns the x position*/
	return x;
}

/**************************************************************************************************************/

/*returns the y position*/
float Entity::getY()
{
	/*returns the y position*/
	return y;
}

/**************************************************************************************************************/

/*returns the x scale*/
int Entity::getXScale()
{
	/*returns the x scale*/
	return xScale;
}

/**************************************************************************************************************/

/*returns the y scale*/
int Entity::getYScale()
{
	/*returns the y scale*/
	return yScale;
}

/**************************************************************************************************************/

/*returns the y velocity*/
float Entity::getYVelocity()
{
	/*returns the y velocity*/
	return yVelocity;
}

/**************************************************************************************************************/

/*returns the display bool*/
bool Entity::getDisplay()
{
	/*returns the display*/
	return display;
}

/**************************************************************************************************************/

/*returns the animation index*/
int Entity::getAnimationIndex()
{
	/*returns the animation index*/
	return animationIndex;
}

/**************************************************************************************************************/

/*updates the entities y position using its velocity and the dt*/
void Entity::updateY(float dt)
{
	/*updates the entities position using the velocity and dt*/
	y += yVelocity * dt;
}