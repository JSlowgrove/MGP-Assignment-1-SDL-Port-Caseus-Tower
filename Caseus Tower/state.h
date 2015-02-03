#pragma once

#include "spriteHandler.h"

/**forward declaration of StateManager for the pointer to the StateManager*/
class StateManager;

/**
@brief Creates an State object
Creates an State object with virtual functions and the SpriteHandler * and width and height variables.
*/
class State
{
protected:
	/*A pointer to the state manager*/
	StateManager * stateManager;
	/**the screen dimensions*/
	int screenWidth;
	int screenHeight;
	/*the pointer to the SpriteHandler*/
	SpriteHandler * sprites;
	/*The name of the State*/
	std::string name;
	/*Should the program run*/
	bool runCheck;
public:
	/**
	Constructs a State object
	@param StateManager * a pointer to the StateManager
	@param SpriteHandler* a pointer to the SpriteHandler.
	@param int the screen width.
	@param int the screen height.
	*/
	State(StateManager *, SpriteHandler*, int, int);

	/**
	A virtual destructor for the State object
	*/
	virtual ~State();

	/**
	A pure virtual function for updating the State object
	@param float the delta time
	@param float the x touch location
	@param float the y touch location
	*/
	virtual void update(float, float, float) = 0;

	/**
	A pure virtual function for displaying the Sprite objects which do not use alpha.
	*/
	virtual void drawSprites() = 0;

	/**
	A pure virtual function for displaying the Sprite objects which do use alpha.
	*/
	virtual void drawSpritesWithAlpha() = 0;

	/**
	Getter # State name
	@returns std::string the name of the State.
	*/
	std::string GetStateName();

	/**
	Getter # runCheck
	@returns bool if the program should run.
	*/
	bool runProgram();
};

