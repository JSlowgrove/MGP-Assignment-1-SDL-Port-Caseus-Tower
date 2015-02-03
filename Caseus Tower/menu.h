#pragma once

#include <vector>
#include "state.h"
#include "spriteHandler.h"
#include "credits.h"
#include "game.h"
#include "entity.h"
#include "animation.h"
#include "audio.h"

/**
@brief Creates an Menu object
Creates an Menu object which inherits State.
*/
class Menu : public State
{
private:
	/**Audio*/
	Audio * music;
	/**The buttons*/
	std::vector<Entity *> buttons;
	/**boolean for if a button is pressed*/
	bool pressed;
	/**The Animation timer for the button press*/
	Animation * buttonPress;
	/*The current index of the button Sprite objects*/
	int playSprite, creditSprite, exitSprite;
	/*the button that was pressed (0 = play, 1 = credits, 2 = exit)*/
	int selected;
public:
	/**
	Constructs a Menu object
	@param StateManager * a pointer to the StateManager
	@param SpriteHandler* a pointer to the SpriteHandler.
	@param int the screen width.
	@param int the screen height.
	*/
	Menu(StateManager *, SpriteHandler*, int, int);

	/**
	A destructor for the Menu object
	*/
	~Menu();

	/**
	A function for updating the Menu object
	@param float the delta time
	@param float the x touch location
	@param float the y touch location
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

