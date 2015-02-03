#include "menu.h"

/**************************************************************************************************************/

/*Constructs the menu object*/
Menu::Menu(StateManager * inStateManager,  SpriteHandler* inSprites, int inWidth, int inHeight)
	: State(inStateManager, inSprites, inWidth, inHeight)
{
	/*loads the sprites used in the menu*/
	sprites->loadMenuSprites();
	/*initialise pressed*/
	pressed = false;
	/*initialise button press animation timer*/
	buttonPress = new Animation(0.25f);
	/*initialise button sprite indexes*/
	playSprite = creditSprite = exitSprite = 0;
	/*initialise buttons*/
	buttons.push_back(new Entity((float)(screenWidth * 0.5f), (float)(screenHeight * 0.5f), screenWidth - 200, 170, 0));
	buttons.push_back(new Entity((float)(screenWidth * 0.5f), (float)((screenHeight * 0.5f) + 225), screenWidth - 200, 175, 0));
	buttons.push_back(new Entity((float)(screenWidth * 0.5f), (float)((screenHeight * 0.5f) + 450), screenWidth - 200, 175, 0));
	/*initialise selected*/
	selected = -1;
	/*set the state name*/
	name = "menu";
}

/**************************************************************************************************************/

/*Destructs the menu object*/
Menu::~Menu()
{
	/*delete entities*/
	for (unsigned int i = 0; i < buttons.size(); i++)
	{
		delete buttons[i];
	}
	/*delete animations*/
	delete buttonPress;
}

/**************************************************************************************************************/

/*updates the menu object*/
void Menu::update(float dt, float pressLocationX, float pressLocationY)
{
	/*check if the play button is pressed*/
	if (pressLocationX <= buttons[0]->getX() + (buttons[0]->getXScale()*0.5f) 
		&& pressLocationX > buttons[0]->getX() - (buttons[0]->getXScale()*0.5f)
		&& pressLocationY <= buttons[0]->getY() + (buttons[0]->getYScale()*0.5f) 
		&& pressLocationY > buttons[0]->getY() - (buttons[0]->getYScale()*0.5f))
	{
		/*set the play button to be highlighted*/
		playSprite = 1;
		/*A button has been pressed*/
		pressed = true;
		/*set the selected to be01 so the next state is play*/
		selected = 0;
	}

	/*check if the credits button is pressed*/
	if (pressLocationX <= buttons[1]->getX() + (buttons[1]->getXScale()*0.5f)
		&& pressLocationX > buttons[1]->getX() - (buttons[1]->getXScale()*0.5f)
		&& pressLocationY <= buttons[1]->getY() + (buttons[1]->getYScale()*0.5f)
		&& pressLocationY > buttons[1]->getY() - (buttons[1]->getYScale()*0.5f))
	{
		/*set the credits button to be highlighted*/
		creditSprite = 1;
		/*A button has been pressed*/
		pressed = true;
		/*set the selected to be 1 so the credits will open*/
		selected = 1;
	}

	/*check if the exit button is pressed*/
	if (pressLocationX <= buttons[2]->getX() + (buttons[2]->getXScale()*0.5f)
		&& pressLocationX > buttons[2]->getX() - (buttons[2]->getXScale()*0.5f)
		&& pressLocationY <= buttons[2]->getY() + (buttons[2]->getYScale()*0.5f)
		&& pressLocationY > buttons[2]->getY() - (buttons[2]->getYScale()*0.5f))
	{
		/*set the exit button to be highlighted*/
		exitSprite = 1;
		/*A button has been pressed*/
		pressed = true;
		/*set the selected to be 2 so the next state is exit*/
		selected = 2;
	}

	/*update the animation timer if pressed*/
	if (pressed)
	{
		/*update button animation timer*/
		buttonPress->updateTimer(dt);
	}

	/*check if pressed is true and the timer has reset*/
	if (pressed && buttonPress->getCurrentTime() == 0.0f)
	{
		/*check what should happen next*/
		switch (selected)
		{
		/*the game should open*/
		case 0:
			/*play game*/
			stateManager->changeState(new Game(stateManager, sprites, screenWidth, screenHeight));
			return;
			break;
		/*the credits should open*/
		case 1:
			/*open up the credits*/
			stateManager->addState(new Credits(stateManager, sprites, screenWidth, screenHeight));
			break;
		}
		/*reset the pressed*/
		pressed = false;
		playSprite = creditSprite = exitSprite = 0;
		/*reset selected*/
		selected = -1;
	}
}

/**************************************************************************************************************/

/*displays the sprites that do not use alpha*/
void Menu::drawSprites()
{
	/*draw the background*/
	sprites->drawMenuSprite("background", 0, screenWidth * 0.5f, screenHeight * 0.5f, screenWidth, screenHeight);
}

/**************************************************************************************************************/

/*displays the sprites that do use alpha*/
void Menu::drawSpritesWithAlpha()
{
	/*draw the play button*/
	sprites->drawMenuSprite("play", playSprite, buttons[0]->getX(), buttons[0]->getY(), buttons[0]->getXScale(), buttons[0]->getYScale());
	/*draw the credits button*/
	sprites->drawMenuSprite("credits", creditSprite, buttons[1]->getX(), buttons[1]->getY(), buttons[1]->getXScale(), buttons[1]->getYScale());
	/*draw the exit button*/
	//sprites->drawMenuSprite("exit", exitSprite, buttons[2]->getX(), buttons[2]->getY(), buttons[2]->getXScale(), buttons[2]->getYScale());
}