#pragma once

#include "state.h"
#include "stateManager.h"
#include "spriteHandler.h"
#include "entity.h"
#include "animation.h"

/**
@brief Creates a Pause State.
Creates a Pause State that inherits State
*/
class Pause : public State
{
private:
	/**The buttons*/
	Entity * playButton;
	Entity * exitButton;
	/*The current index of the buttons*/
	int playSprite;
	int exitSprite;
	/**boolean for if a button is pressed*/
	bool pressed;
	/**The Animation timer for the button press*/
	Animation * buttonPress;
public:
	/**
	Constructs a Pause State
	@param StateManager * a pointer to the StateManager
	@param SpriteHandler* a pointer to the SpriteHandler.
	@param int the screen width.
	@param int the screen height.
	*/
	Pause(StateManager *, SpriteHandler*, int, int);

	/**
	A destructor for the Pause State
	*/
	~Pause();

	/**
	A function for updating the Pause State
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