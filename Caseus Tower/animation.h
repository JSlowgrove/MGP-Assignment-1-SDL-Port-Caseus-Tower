#pragma once

/**
@brief Creates an Animation object
Creates an Animation object to handle the timing of when an Animation should run.
DISCLAMER - This is the animation class that I used in my PGG SDL assignment.
*/
class Animation
{
private:
	/**The current time of the Animation timer*/
	float currentTime;
	/**The duration of the Animation timer*/
	float duration;

public:
	/**
	Constructs a Animation object
	@param float the wanted duration of the Animation
	*/
	Animation(float);

	/**
	A destructor for the Animation object
	*/
	~Animation();

	/**
	A timer for Animation
	The timer is updated with the current time and resets to 0 when the time is the duration.
	@param float the delta time
	*/
	void updateTimer(float dt);

	/**
	Getter # returns the current time.
	@returns float the current time
	*/
	float getCurrentTime();
};