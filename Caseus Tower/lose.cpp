#include "lose.h"
#include "menu.h"
#include "game.h"

/**************************************************************************************************************/

/*Constructs the lose state*/
Lose::Lose(StateManager * inStateManager, SpriteHandler* inSprites, int inWidth, int inHeight, int inScore)
	: State(inStateManager, inSprites, inWidth, inHeight)
{
	/*loads the sprites used in the lose state*/
	sprites->loadLoseSprites();
	/*set the score*/
	score = inScore;
	/*initialise pressed*/
	pressed = false;
	/*initialise button press animation timer*/
	buttonPress = new Animation(0.25f);
	/*initialise buttons*/
	playButton = new Entity((float)(screenWidth * 0.5f), (float)(screenHeight * 0.5f + 220), screenWidth - 200, 170, 0);
	exitButton = new Entity((float)(screenWidth * 0.5f), (float)((screenHeight * 0.5f) + 450), screenWidth - 200, 175, 0);
	/*initialise button sprite indexes*/
	exitSprite = playSprite = 0;
	/*set the state name*/
	name = "lose";

	/*initialise and start the music*/
	lose = new Audio("aud/jingles_HIT15.ogg", false);
	music = new Audio("aud/TheWayOut.ogg", true);
	music->startAudio();
	/*plays the lose sound*/
	lose->playEffect();
}

/**************************************************************************************************************/

/*Destructs the lose state*/
Lose::~Lose()
{
	/*stop music*/
	music->stopAudio();
	/*delete audio pointers*/
	delete music;
	delete lose;
	/*delete pointers*/
	delete playButton;
	delete exitButton;
	delete buttonPress;
}

/**************************************************************************************************************/

/*updates the lose state*/
void Lose::update(float dt, float pressLocationX, float pressLocationY)
{
	/*check the music is still playing if not start again*/
	music->startAudio();

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
		/*if play was pressed start a new game*/
		else
		{
			/*reset animation index*/
			playSprite = 0;
			/*start a new game*/
			stateManager->changeState(new Game(stateManager, sprites, screenWidth, screenHeight));
			return;
		}

	}
}

/**************************************************************************************************************/

/*displays the sprites that do not use alpha*/
void Lose::drawSprites()
{
	/*draw the background*/
	sprites->drawLoseSprite("background", 0, (float)(screenWidth * 0.5f),
		(float)(screenHeight * 0.5f), screenWidth, screenHeight);
}

/**************************************************************************************************************/

/*displays the sprites that do use alpha*/
void Lose::drawSpritesWithAlpha()
{
	/*draw the score to the screen*/
	displayScore();

	/*draw the play button*/
	sprites->drawLoseSprite("play", playSprite, playButton->getX(),
		playButton->getY(), playButton->getXScale(), playButton->getYScale());

	/*draw the exit button*/
	sprites->drawLoseSprite("exit", exitSprite, exitButton->getX(),
		exitButton->getY(), exitButton->getXScale(), exitButton->getYScale());
}

/**************************************************************************************************************/

/*draw the score to the screen*/
void Lose::displayScore()
{
	int currentScore = score;
	/*Loop for 5 digits*/
	for (int i = 0; i < 5; i++)
	{
		/*display the number*/
		sprites->drawLoseSprite("symbol", currentScore % 10, (float)((screenWidth * 0.5f) - 600.0f) + (200.0f * (5 - i)),
			(float)((screenHeight * 0.5f) - 300.0f), 200, 200);
		currentScore = currentScore / 10;
	}
}