#pragma once

#include <SDL.h>
#include "texture.h"
#include "spriteHandler.h"
#include "stateManager.h"

/**
@brief Creates an App object that runs the application
Creates an App object that runs the application.
*/
class App
{
private:
	/**a pointer to the renderer*/
	SDL_Renderer * renderer;
	/**the dimensions of the screen*/
	int screenWidth;
	int screenHeight;
	/**a pointer to the sprites*/
	SpriteHandler * sprites;
	/**a pointer to the stateManager*/
	StateManager * stateManager;
	/*the pressed locations*/
	float userX;
	float userY;
public:
	/**
	Constructs an App object
	@param SDL_Renderer * a pointer to the renderer
	@param int the screen width
	@param int the screen height
	*/
	App(SDL_Renderer *, int, int);

	/**
	Destructs an App object
	*/
	~App();

	/**
	Handles the App input
	@returns bool if false the quit App
	*/
	bool input();

	/**
	Update the App object
	@param float the deltaTime
	*/
	void update(float);

	/**
	Draws the Game object
	*/
	void draw();
};