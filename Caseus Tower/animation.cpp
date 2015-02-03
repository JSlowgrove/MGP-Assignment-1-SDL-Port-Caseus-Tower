#include "animation.h"

/**************************************************************************************************************/

/*Constructs the animation object*/
Animation::Animation(float inDuration)
{
	/*initialise the duration*/
	duration = inDuration;
	/*initialise current time*/
	currentTime = 0.0f;	
}

/**************************************************************************************************************/

/*Destructs the animation object*/
Animation::~Animation()
{
}

/**************************************************************************************************************/

/*update timer for animation*/
void Animation::updateTimer(float dt)
{
	/*time for duration then rest timer*/
	currentTime += dt;
	if (currentTime >= duration)
	{
		/*reset timer to 0*/
		currentTime = 0.0f;
	}
}

/**************************************************************************************************************/

/*returns the current time*/
float Animation::getCurrentTime()
{
	/*returns the current time*/
	return currentTime;
}