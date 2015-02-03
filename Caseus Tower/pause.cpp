#include "pause.h"
#include "menu.h"

/**************************************************************************************************************/

/*Constructs the pause state*/
Pause::Pause(StateManager * inStateManager, SpriteHandler* inSprites, int inWidth, int inHeight)
	: State(inStateManager, inSprites, inWidth, inHeight)
{
	/*initialise pressed*/
	pressed = false;
	/*initialise button press animation timer*/
	buttonPress = new Animation(0.25f);
	/*initialise buttons*/
	playButton = new Entity((float)(screenWidth * 0.5f), (float)(screenHeight * 0.5f), screenWidth - 200, 170, 0);
	exitButton = new Entity((float)(screenWidth * 0.5f), (float)((screenHeight * 0.5f) + 225), screenWidth - 200, 175, 0);
	/*initialise button sprite indexes*/
	exitSprite = playSprite = 0;
	/*set the state name*/
	name = "pause";
}

/**************************************************************************************************************/

/*Destructs the pause state*/
Pause::~Pause()
{
	/*delete pointers*/
	delete playButton;
	delete exitButton;
	delete buttonPress;
}

/**************************************************************************************************************/

/*updates the pause state*/
void Pause::update(float dt, float pressLocationX, float pressLocationY)
{
	/*check if the play button is pressed*/
	if (pressLocationX <= playButton->getX() + (playButton->getXScale() * 0.5f) 
		&& pressLocationX > playButton->getX() - (playButton->getXScale() * 0.5f)
		&& pressLocationY <= playButton->getY() + (playButton->getYScale() * 0.5f) 
		&& pressLocationY > playButton->getY() - (playButton->getYScale() * 0.5f))
	{
		/*set the play button to be highlighted*/
		playSprite = 1;
		/*A button has been pressed*/
		pressed = true;
	}
	/*check if the exit button is pressed*/
	if (pressLocationX <= exitButton->getX() + (exitButton->getXScale() * 0.5f) 
		&& pressLocationX > exitButton->getX() - (exitButton->getXScale() * 0.5f)
		&& pressLocationY <= exitButton->getY() + (exitButton->getYScale() * 0.5f) 
		&& pressLocationY > exitButton->getY() - (exitButton->getYScale() * 0.5f))
	{
		/*set the play button to be highlighted*/
		exitSprite = 1;
		/*A button has been pressed*/
		pressed = true;
	}

	/*update the press animation timer if pressed*/
	if (pressed)
	{
		/*update button animation timer*/
		buttonPress->updateTimer(dt);
	}

	/*check if pressed is true and the timer has reset*/
	if (pressed && buttonPress->getCurrentTime() == 0.0f)
	{
		/*reset the pressed*/
		pressed = false;
		/*if exit was pressed exit*/
		if (exitSprite == 1)
		{
			/*reset animation index*/
			exitSprite = 0;
			/*return to menu*/
			stateManager->changeState(new Menu(stateManager, sprites, screenWidth, screenHeight));
			return;
		}
		/*if play was pressed return to game*/
		else
		{
			/*reset animation index*/
			playSprite = 0;
			/*go back to the last state*/
			stateManager->removeLastState();
		}

	}
}

/**************************************************************************************************************/

/*displays the sprites that do not use alpha*/
void Pause::drawSprites()
{
}

/**************************************************************************************************************/

/*displays the sprites that do use alpha*/
void Pause::drawSpritesWithAlpha()
{
	/*draw the play button*/
	sprites->drawGameSprite("play", playSprite, playButton->getX(),
		playButton->getY(), playButton->getXScale(), playButton->getYScale());

	/*draw the exit button*/
	sprites->drawGameSprite("exit", exitSprite, exitButton->getX(),
		exitButton->getY(), exitButton->getXScale(), exitButton->getYScale());
}