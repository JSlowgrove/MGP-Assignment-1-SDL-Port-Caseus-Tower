#pragma once

#include "state.h"
#include "stateManager.h"
#include "spriteHandler.h"
#include "entity.h"
#include "animation.h"

/**
@brief Creates a Credits State.
Creates a Credits State that inherits State
*/
class Credits : public State
{
private:
	/**The buttons*/
	Entity * button;
	/*The current index of the button Sprite object*/
	int exitSprite;
	/**boolean for if a button is pressed*/
	bool pressed;
	/**The Animation timer for the button press*/
	Animation * buttonPress;
public:
	/**
	Constructs a Credits State
	@param StateManager * a pointer to the StateManager
	@param SpriteHandler* a pointer to the SpriteHandler.
	@param int the screen width.
	@param int the screen height.
	*/
	Credits(StateManager *, SpriteHandler*, int, int);

	/**
	A destructor for the Credits State
	*/
	~Credits();

	/**
	A function for updating the Credits State
	@param float the delta time
	@param float the x touch location
	@param float the y touch location
	@returns int the next command the application should do
	*/
	void update(float, float, float);

	/**
	A function for displaying the Sprite objects which do not use alpha.
	*/
	void drawSprites();

	/**
	A function for displaying the Sprite objects which do use alpha.
	*/
	void drawSpritesWithAlpha();
};