#include "application.h"
#include "menu.h"

/**************************************************************************************************************/

/*Constructs the app object*/
App::App(SDL_Renderer * inRenderer, int inWidth, int inHeight)
{
	/*set pointer to the renderer*/
	renderer = inRenderer;
	/*load the screen dimensions and scale them to the wanted dimensions*/
	screenWidth = inWidth * 3;
	screenHeight = inHeight * 3;
	/*initialise the sprite handler*/
	sprites = new SpriteHandler(renderer);
	/*setup state manager*/
	stateManager = new StateManager();
	/*set the initial state*/
	stateManager->addState(new Menu(stateManager, sprites, screenWidth, screenHeight));
	/*initialise the touch location to the center of the screen*/
	userX = screenWidth * 0.5f;
	userY = 0.0f;
}

/**************************************************************************************************************/

/*De-constructs the app object*/
App::~App()
{
	/*delete pointers*/
	delete stateManager;
	delete sprites;
}

/**************************************************************************************************************/

/*handles inputs*/
bool App::input()
{
	/*Check for user input*/
	SDL_Event incomingEvent;
	while (SDL_PollEvent(&incomingEvent))
	{

		switch (incomingEvent.type)
		{
		case SDL_QUIT: /*If player closes the window, end the game loop*/

			return false;
			break;

		case SDL_KEYDOWN:

			switch (incomingEvent.key.keysym.sym)
			{
			case SDLK_ESCAPE: /*If Escape is pressed, end the game loop*/

				return false;
				break;
			}

		case SDL_MOUSEBUTTONDOWN: /*If the mouse is pressed*/

			if (incomingEvent.button.button == SDL_BUTTON_LEFT)/*if the left mouse button*/
			{
				/*the screen is being pressed update the pressed positions scaled to the wanted positions*/
				userX = ((float)incomingEvent.motion.x) * 3;
				userY = ((float)incomingEvent.motion.y) * 3;
			}
			break;
		}
	}
	return true;
}

/**************************************************************************************************************/

/*updates the app*/
void App::update(float dt)
{
	/*get the current states name*/
	std::string currentState = stateManager->getName();

	/*update the current state*/
	stateManager->update(dt, userX, userY);

	/*test if the state has changed*/
	if (currentState != stateManager->getName())
	{
		/*reset the touch location to the center of the top of the screen*/
		userX = screenWidth * 0.5f;
		userY = 0.0f;
	}
}

/**************************************************************************************************************/

/*draws the app*/
void App::draw()
{
	/*set draw colour to white*/
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	/*Clear the entire screen to the set colour*/
	SDL_RenderClear(renderer);

	/*draw the state sprites that do not use alpha*/
	stateManager->drawSprites();

	/*draw the state sprites that use alpha*/
	stateManager->drawSpritesWithAlpha();

	/*display renderer*/
	SDL_RenderPresent(renderer);
}