#pragma once

#include <SDL.h>
#include <vector>
#include <string>
#include "texture.h"

/**
@brief Creates an SpriteHandler object
Creates an SpriteHandler object to deal with all of the applications sprites.
*/
class SpriteHandler
{
private:
	/**a pointer to the renderer*/
	SDL_Renderer * renderer;
	/**The background image*/
	Texture * backgroundImage;
	/**
	The game sprites (vectors of sprites mean they can be animated).
	*/
	Texture * platformSafe;
	std::vector<Texture*> platformDanger;
	std::vector<Texture*> playerSprite;
	std::vector<Texture*> symbols;
	std::vector<Texture*> pauseButton;
	/**
	The menu sprites (vectors of sprites mean they can be animated).
	*/
	std::vector<Texture*> playButton;
	std::vector<Texture*> creditsButton;
	std::vector<Texture*> exitButton;
	/**
	The credit sprites.
	*/
	Texture * credits;
	/**
	A scale value to help scale down numbers to the SDL screen
	*/
	float scale;
public:
	/**
	Constructs a SpriteHandler object
	@param SDL_Renderer* a pointer to the renderer.
	*/
	SpriteHandler(SDL_Renderer *);

	/**
	Destructs the SpriteHandler object
	*/
	~SpriteHandler();

	/**
	Loads the Game Sprite objects
	Loads the Sprite objects to be used in the Game.
	*/
	void loadGameSprites();

	/**
	Loads the Menu Sprite objects
	Loads the Sprite objects to be used in the Menu.
	*/
	void loadMenuSprites();

	/**
	Loads the Credits Sprite objects
	Loads the Sprite objects to be used in the Credits.
	*/
	void loadCreditsSprites();

	/**
	Loads the Lose Sprite objects
	Loads the Sprite objects to be used in the Lose State.
	*/
	void loadLoseSprites();

	/**
	Deletes the Game Sprite objects
	Deletes the Sprite objects used in the Game.
	*/
	void deleteGameSprites();

	/**
	Deletes the Menu Sprite objects
	Deletes the Sprite objects used in the Menu.
	*/
	void deleteMenuSprites();

	/**
	Deletes the Credits Sprite objects
	Deletes the Sprite objects used in the Credits.
	*/
	void deleteCreditsSprites();

	/**
	Deletes the Lose Sprite objects
	Deletes the Sprite objects used in the Lose State.
	*/
	void deleteLoseSprites();

	/**
	Load the symbols for Sprite objects
	Load the symbols for Sprite objects for use with displaying the score.
	*/
	void loadSymbols();

	/**
	Draw the Game Sprite to the screen
	Draws the Game Sprite to the screen using the input variables.
	@param std::String the type of Sprite
	@param int the index of the Sprite
	@param float the x position of the Sprite
	@param float the y position of the Sprite
	@param int the width of the Sprite
	@param int the height of the Sprite
	*/
	void drawGameSprite(std::string, int, float, float, int, int);

	/**
	Draw the Menu Sprite to the screen
	Draws the Menu Sprite to the screen using the input variables.
	@param std::String the type of Sprite
	@param int the index of the Sprite
	@param float the x position of the Sprite
	@param float the y position of the Sprite
	@param int the width of the Sprite
	@param int the height of the Sprite
	*/
	void drawMenuSprite(std::string, int, float, float, int, int);

	/**
	Draw the Credits Sprite to the screen
	Draws the Credits Sprite to the screen using the input variables.
	@param std::String the type of Sprite
	@param int the index of the Sprite
	@param float the x position of the Sprite
	@param float the y position of the Sprite
	@param int the width of the Sprite
	@param int the height of the Sprite
	*/
	void drawCreditsSprite(std::string, int, float, float, int, int);

	/**
	Draw the Lose Sprite to the screen
	Draws the Lose Sprite to the screen using the input variables.
	@param std::String the type of Sprite
	@param int the index of the Sprite
	@param float the x position of the Sprite
	@param float the y position of the Sprite
	@param int the width of the Sprite
	@param int the height of the Sprite
	*/
	void drawLoseSprite(std::string, int, float, float, int, int);
};