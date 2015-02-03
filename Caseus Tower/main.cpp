#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include "application.h"

int main(int argc, char *argv[])
{
	/*Initialise SDL*/
	if (SDL_Init(SDL_INIT_VIDEO) < 0) /*Check SDL initialisation*/
	{
		/*Failed initialisation*/
		std::cout << "Failed to initialise SDL" << std::endl;
		return -1;
	}

	/*Initialise SDL_ttf*/
	if (TTF_Init() < 0) /*Check SDL_ttf initialisation*/
	{
		/*Failed initialisation*/
		std::cout << "SDL_ttf init failed: " << TTF_GetError << std::endl;
		return -1;
	}

	/*Initialise SDL_mixer*/
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cout << "Failed to initialise SDL Mixer, Error is: " << Mix_GetError() << std::endl;
		return -1;
	}

	/*Time Check*/
	unsigned int lastTime = SDL_GetTicks();

	/*Create Window 9:16 ratio*/
	int winPosX = 50;
	int winPosY = 50;
	int winWidth = 360;//x3 for 1080
	int winHeight = 640;//x3 for 1920
	SDL_Window *window = SDL_CreateWindow("Caseus Tower",  /*The first parameter is the window title*/
		winPosX, winPosY,
		winWidth, winHeight,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	/*Create Renderer from the window*/
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

	/*Create Game*/
	App * app = new App(renderer, winWidth, winHeight);

	/*Start Game Loop*/
	bool go = true;
	while (go)
	{
		/*Time Check*/
		unsigned int current = SDL_GetTicks();
		float deltaTime = (float)(current - lastTime) / 1000.0f;
		lastTime = current;

		/*handle the inputs to the game*/
		go = app->input();

		/*update the game*/
		app->update(deltaTime);

		/*draw the game*/
		app->draw();

		/*Wanted frame rate*/
		float FPS = 30.0f;

		/*Time Limiter*/
		if (deltaTime < (1.0f / FPS))
		{
			SDL_Delay((unsigned int)(((1.0f / FPS) - deltaTime)*1000.0f));
		}
	}
	/*destroy data*/
	delete app;
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}