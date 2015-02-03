#pragma once

#include <vector>
#include "state.h"
/**
@brief Creates a StateManager object.
Creates a StateManager object to be inherited.
DISCLAMER - This is a modified version of the state handling system that I used in my PGG SDL assignment.
This version is different however it is similar so I thought that I should mention it.
*/
class StateManager
{
private:
	/**the current states that are in use*/
	std::vector<State*> currentStates;
public:
	/**
	Constructs a StateManager object
	*/
	StateManager();

	/**
	Destructs a StateManager object
	*/
	~StateManager();

	/**
	Adds a new state
	Adds a new state to the current stack of states
	@param State * a pointer to the State in use
	*/
	void addState(State*);

	/**
	Changes to a new State
	Changes the current State to a new State
	@param State * a pointer to the State in use
	*/
	void changeState(State*);

	/**
	Removes the last State from the vector
	*/
	void removeLastState();

	/**
	Updates the current State
	The update function that will allow the equivalent update function to run in the current State
	@param float the delta time for use within the update function
	@param float the x touch location
	@param float the y touch location
	*/
	void update(float, float, float);

	/**
	Draws the current State Sprites without alpha
	The draw function that will allow the equivalent draw function to run in the current State
	*/
	void drawSprites();

	/**
	Draws the current State Sprites with alpha
	The draw function that will allow the equivalent draw function to run in the current State
	*/
	void drawSpritesWithAlpha();

	/**
	getter # the name of the current State
	@returns std::string the name of the state
	*/
	std::string getName();
};