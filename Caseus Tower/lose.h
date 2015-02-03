#pragma once

#include "state.h"
#include "stateManager.h"
#include "spriteHandler.h"
#include "entity.h"
#include "animation.h"

/**
@brief Creates a Lose State.
Creates a Lose State that inherits State
*/
class Lose : public State
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
	/**the last score*/
	int score;

	/**
	Draws the score to the screen
	*/
	void displayScore();

public:
	/**
	Constructs a Lose State
	@param StateManager * a pointer to the StateManager
	@param SpriteHandler* a pointer to the SpriteHandler.
	@param int the screen width.
	@param int the screen height.
	@param int the score.
	*/
	Lose(StateManager *, SpriteHandler*, int, int, int);

	/**
	A destructor for the Lose State
	*/
	~Lose();

	/**
	A function for updating the Lose State
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