#pragma once

#include <vector>
#include <time.h>
#include "state.h"
#include "spriteHandler.h"
#include "entity.h"
#include "player.h"
#include "collision.h"
#include "animation.h"

/**
@brief Creates an Game object
Creates an Game object which inherits State.
*/
class Game : public State
{
private:
	/**The Game entities*/
	std::vector<Entity *> background;
	std::vector<Entity *> safePlatforms;
	std::vector<Entity *> dangerPlatforms;
	Entity * pauseButton;
	Entity * playButton;
	Entity * exitButton;
	Player * player;
	/**Animation objects*/
	std::vector<Animation *> platformAnim;
	Animation * buttonPress;
	Animation * playerAnim;
	/**Animation indexes*/
	int pauseSprite;
	int playSprite;
	int exitSprite;
	/**The players score*/
	int score;
	int highestScore;
	/**The gravity*/
	float gravity;
	/**boolean for if a button is pressed*/
	bool pressed;

	/**
	Draws the score to the screen
	*/
	void displayScore();

	/**
	Generates the new platforms
	Generates a new row of random platforms
	@param float the x position
	*/
	void generatePlatforms(float);

public:
	/**
	Constructs a Game object
	@param StateManager * a pointer to the StateManager
	@param SpriteHandler* a pointer to the SpriteHandler.
	@param int the screen width.
	@param int the screen height.
	*/
	Game(StateManager *, SpriteHandler*, int, int);

	/**
	A destructor for the Game object
	*/
	~Game();

	/**
	A function for updating the Game object
	@param float the delta time
	@param float the x touch location
	@param float the y touch location
	*/
	void update(float,float,float);

	/**
	A function for displaying the Sprite objects which do not use alpha.
	*/
	void drawSprites();

	/**
	A function for displaying the Sprite objects which do use alpha.
	*/
	void drawSpritesWithAlpha();
};

