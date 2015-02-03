#include "spriteHandler.h"

/**************************************************************************************************************/

/*Constructs the sprite handler object*/
SpriteHandler::SpriteHandler(SDL_Renderer * inRenderer)
{
	/*initialises the pointer to the renderer*/
	renderer = inRenderer;
	/*initialise the scale*/
	scale = 1.0f / 3.0f;
}

/**************************************************************************************************************/

/*Destructs the sprite handler object*/
SpriteHandler::~SpriteHandler()
{
	/*delete texture pointers*/
	delete backgroundImage;
	delete platformSafe;
	delete credits;
	for (unsigned int i = 0; i < platformDanger.size(); i++)
	{
		platformDanger[i];
	}
	for (unsigned int i = 0; i < playerSprite.size(); i++)
	{
		playerSprite[i];
	}
	for (unsigned int i = 0; i < symbols.size(); i++)
	{
		symbols[i];
	}
	for (unsigned int i = 0; i < playButton.size(); i++)
	{
		playButton[i];
	}
	for (unsigned int i = 0; i < creditsButton.size(); i++)
	{
		creditsButton[i];
	}
	for (unsigned int i = 0; i < exitButton.size(); i++)
	{
		exitButton[i];
	}
	for (unsigned int i = 0; i < pauseButton.size(); i++)
	{
		pauseButton[i];
	}
}

/**************************************************************************************************************/

/*Load the sprites used in the game*/
void SpriteHandler::loadGameSprites()
{
	/*load a TGA files from the files.*/
	backgroundImage = new Texture("img/background.tga", renderer);
	platformSafe = new Texture("img/platform.tga", renderer);
	playerSprite.push_back(new Texture("img/cheeseNinja.tga", renderer));
	playerSprite.push_back(new Texture("img/cheeseNinjaJump.tga", renderer));
	platformDanger.push_back(new Texture("img/ballonPlatform.tga", renderer));
	platformDanger.push_back(new Texture("img/ballonPlatformPop1.tga", renderer));
	platformDanger.push_back(new Texture("img/ballonPlatformPop2.tga", renderer));
	platformDanger.push_back(new Texture("img/ballonPlatformPop3.tga", renderer));
	pauseButton.push_back(new Texture("img/pause.tga", renderer));
	pauseButton.push_back(new Texture("img/pauseSelected.tga", renderer));

	/*load the symbols for use with text*/
	loadSymbols();
}

/**************************************************************************************************************/

/*Load the sprites used in the menu*/
void SpriteHandler::loadMenuSprites()
{
	/*load a TGA files from the files.*/
	backgroundImage = new Texture("img/menuBackground.tga", renderer);
	playButton.push_back(new Texture("img/playButton.tga", renderer));
	playButton.push_back(new Texture("img/playButtonSelected.tga", renderer));
	creditsButton.push_back(new Texture("img/creditsButton.tga", renderer));
	creditsButton.push_back(new Texture("img/creditsButtonSelected.tga", renderer));
	exitButton.push_back(new Texture("img/exitButton.tga", renderer));
	exitButton.push_back(new Texture("img/exitButtonSelected.tga", renderer));
}

/**************************************************************************************************************/

/*Load the sprites used in the credits*/
void SpriteHandler::loadCreditsSprites()
{
	/*load a TGA files from the files.*/
	credits = new Texture("img/credits.tga", renderer);
	exitButton.push_back(new Texture("img/exitButton.tga", renderer));
	exitButton.push_back(new Texture("img/exitButtonSelected.tga", renderer));
}


/**************************************************************************************************************/

/*Load the sprites used in the lose*/
void SpriteHandler::loadLoseSprites()
{
	/*load a TGA files from the files.*/
	backgroundImage = new Texture("img/lose.tga", renderer);
	playButton.push_back(new Texture("img/playButton.tga", renderer));
	playButton.push_back(new Texture("img/playButtonSelected.tga", renderer));
	exitButton.push_back(new Texture("img/exitButton.tga", renderer));
	exitButton.push_back(new Texture("img/exitButtonSelected.tga", renderer));

	/*load the symbols for use with text*/
	loadSymbols();
}

/**************************************************************************************************************/

/*Deletes the sprites used in the game*/
void SpriteHandler::deleteGameSprites()
{

}

/**************************************************************************************************************/

/*Deletes the sprites used in the menu*/
void SpriteHandler::deleteMenuSprites()
{

}

/**************************************************************************************************************/

/*Deletes the sprites used in the credits*/
void SpriteHandler::deleteCreditsSprites()
{

}

/**************************************************************************************************************/

/*Deletes the sprites used in the lose*/
void SpriteHandler::deleteLoseSprites()
{

}

/**************************************************************************************************************/

/*Load the symbols for Sprite objects for use with displaying the score*/
void SpriteHandler::loadSymbols()
{
	/*load a TGA files from the asset manager.*/
	symbols.push_back(new Texture("img/0.tga", renderer));
	symbols.push_back(new Texture("img/1.tga", renderer));
	symbols.push_back(new Texture("img/2.tga", renderer));
	symbols.push_back(new Texture("img/3.tga", renderer));
	symbols.push_back(new Texture("img/4.tga", renderer));
	symbols.push_back(new Texture("img/5.tga", renderer));
	symbols.push_back(new Texture("img/6.tga", renderer));
	symbols.push_back(new Texture("img/7.tga", renderer));
	symbols.push_back(new Texture("img/8.tga", renderer));
	symbols.push_back(new Texture("img/9.tga", renderer));
}

/**************************************************************************************************************/

/*draw the game sprite*/
void SpriteHandler::drawGameSprite(std::string type, int index, float transformX, float transformY, int inScaleX, int inScaleY)
{
	/*scale down the sizes and offset them to change their coordinate system*/
	transformX *= scale;
	transformY *= scale;
	float scaleX = inScaleX * scale;
	float scaleY = inScaleY * scale;
	transformX -= scaleX * 0.5f;
	transformY -= scaleY * 0.5f;

	/*check what the type of sprite is*/
	if (type == "player")
	{
		/*draw the sprite on screen*/
		playerSprite[index]->pushToScreen(renderer, (int)transformX, (int)transformY, (int)scaleX, (int)scaleY);
	}
	if (type == "background")
	{
		/*draw the sprite on screen*/
		backgroundImage->pushToScreen(renderer, (int)transformX, (int)transformY, (int)scaleX, (int)scaleY);
	}
	if (type == "safePlatform")
	{
		/*draw the sprite on screen*/
		platformSafe->pushToScreen(renderer, (int)transformX, (int)transformY, (int)scaleX, (int)scaleY);
	}
	if (type == "dangerPlatform")
	{
		/*draw the sprite on screen*/
		platformDanger[index]->pushToScreen(renderer, (int)transformX, (int)transformY, (int)scaleX, (int)scaleY);
	}
	if (type == "symbol")
	{
		/*draw the sprite on screen*/
		symbols[index]->pushToScreen(renderer, (int)transformX, (int)transformY, (int)scaleX, (int)scaleY);
	}
	if (type == "pause")
	{
		/*draw the sprite on screen*/
		pauseButton[index]->pushToScreen(renderer, (int)transformX, (int)transformY, (int)scaleX, (int)scaleY);
	}
	if (type == "play")
	{
		/*draw the sprite on screen*/
		playButton[index]->pushToScreen(renderer, (int)transformX, (int)transformY, (int)scaleX, (int)scaleY);
	}
	if (type == "exit")
	{
		/*draw the sprite on screen*/
		exitButton[index]->pushToScreen(renderer, (int)transformX, (int)transformY, (int)scaleX, (int)scaleY);
	}
}

/**************************************************************************************************************/

/*draw the menu sprite*/
void SpriteHandler::drawMenuSprite(std::string type, int index, float transformX, float transformY, int inScaleX, int inScaleY)
{
	/*scale down the sizes and offset them to change their coordinate system for use with SDL*/
	transformX *= scale;
	transformY *= scale;
	float scaleX = inScaleX * scale;
	float scaleY = inScaleY * scale;
	transformX -= scaleX * 0.5f;
	transformY -= scaleY * 0.5f;

	/*check what the type of sprite is*/
	if (type == "background")
	{
		/*draw the sprite on screen*/
		backgroundImage->pushToScreen(renderer, (int)transformX, (int)transformY, (int)scaleX, (int)scaleY);
	}
	if (type == "play")
	{
		/*draw the sprite on screen*/
		playButton[index]->pushToScreen(renderer, (int)transformX, (int)transformY, (int)scaleX, (int)scaleY);
	}
	if (type == "credits")
	{
		/*draw the sprite on screen*/
		creditsButton[index]->pushToScreen(renderer, (int)transformX, (int)transformY, (int)scaleX, (int)scaleY);
	}
	if (type == "exit")
	{
		/*draw the sprite on screen*/
		exitButton[index]->pushToScreen(renderer, (int)transformX, (int)transformY, (int)scaleX, (int)scaleY);
	}
}

/**************************************************************************************************************/

/*draw the credits sprite*/
void SpriteHandler::drawCreditsSprite(std::string type, int index, float transformX, float transformY, int inScaleX, int inScaleY)
{
	/*scale down the sizes and offset them to change their coordinate system for use with SDL*/
	transformX *= scale;
	transformY *= scale;
	float scaleX = inScaleX * scale;
	float scaleY = inScaleY * scale;
	transformX -= scaleX * 0.5f;
	transformY -= scaleY * 0.5f;

	/*check what the type of sprite is*/
	if (type == "exit")
	{
		/*draw the sprite on screen*/
		exitButton[index]->pushToScreen(renderer, (int)transformX, (int)transformY, (int)scaleX, (int)scaleY);
	}
	if (type == "creditScreen")
	{
		/*draw the sprite on screen*/
		credits->pushToScreen(renderer, (int)transformX, (int)transformY, (int)scaleX, (int)scaleY);
	}
}

/**************************************************************************************************************/

/*draw the lose sprite*/
void SpriteHandler::drawLoseSprite(std::string type, int index, float transformX, float transformY, int inScaleX, int inScaleY)
{
	/*scale down the sizes and offset them to change their coordinate system for use with SDL*/
	transformX *= scale;
	transformY *= scale;
	float scaleX = inScaleX * scale;
	float scaleY = inScaleY * scale;
	transformX -= scaleX * 0.5f;
	transformY -= scaleY * 0.5f;

	/*check what the type of sprite is*/
	if (type == "background")
	{
		/*draw the sprite on screen*/
		backgroundImage->pushToScreen(renderer, (int)transformX, (int)transformY, (int)scaleX, (int)scaleY);
	}
	if (type == "symbol")
	{
		/*draw the sprite on screen*/
		symbols[index]->pushToScreen(renderer, (int)transformX, (int)transformY, (int)scaleX, (int)scaleY);
	}
	if (type == "play")
	{
		/*draw the sprite on screen*/
		playButton[index]->pushToScreen(renderer, (int)transformX, (int)transformY, (int)scaleX, (int)scaleY);
	}
	if (type == "exit")
	{
		/*draw the sprite on screen*/
		exitButton[index]->pushToScreen(renderer, (int)transformX, (int)transformY, (int)scaleX, (int)scaleY);
	}
}