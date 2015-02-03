#include "credits.h"

/**************************************************************************************************************/

/*Constructs the credits state*/
Credits::Credits(StateManager * inStateManager, SpriteHandler* inSprites, int inWidth, int inHeight)
	: State(inStateManager, inSprites, inWidth, inHeight)
{
	/*loads the sprites used in the menu*/
	sprites->loadCreditsSprites();
	/*initialise pressed*/
	pressed = false;
	/*initialise button press animation timer*/
	buttonPress = new Animation(0.25f);
	/*initialise button*/
	button = new Entity((float)(screenWidth * 0.5f), (float)((screenHeight * 0.5f) + 675), screenWidth - 200, 175, 0);
	/*initialise button sprite indexes*/
	exitSprite = 0;
	/*set the state name*/
	name = "credits";
}

/**************************************************************************************************************/

/*Destructs the credits state*/
Credits::~Credits()
{
	/*delete pointers*/
	delete button;
	delete buttonPress;
}

/**************************************************************************************************************/

/*updates the credits state*/
void Credits::update(float dt, float pressLocationX, float pressLocationY)
{
	/*check if the exit button is pressed*/
	if (pressLocationX <= button->getX() + (button->getXScale()*0.5f)
		&& pressLocationX > button->getX() - (button->getXScale()*0.5f)
		&& pressLocationY <= button->getY() + (button->getYScale()*0.5f)
		&& pressLocationY > button->getY() - (button->getYScale()*0.5f))
	{
		/*A button has been pressed*/
		pressed = true;
		/*update the exit sprite*/
		exitSprite = 1;
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
		/*reset animation index*/
		exitSprite = 0;
		/*go back to the last state*/
		stateManager->removeLastState();
	}
}

/**************************************************************************************************************/

/*displays the sprites that do not use alpha*/
void Credits::drawSprites()
{
}

/**************************************************************************************************************/

/*displays the sprites that do use alpha*/
void Credits::drawSpritesWithAlpha()
{
	/*draw the credits*/
	sprites->drawCreditsSprite("creditScreen", 0, screenWidth * 0.5f, screenHeight * 0.5f, screenWidth, screenHeight);
	/*draw the exit button*/
	sprites->drawCreditsSprite("exit", exitSprite, button->getX(), button->getY(), button->getXScale(), button->getYScale());
}