#include "game.h"
#include "pause.h"
#include "menu.h"
#include "lose.h"

/**************************************************************************************************************/

/*Constructs the game object*/
Game::Game(StateManager * inStateManager, SpriteHandler* inSprites, int inWidth, int inHeight) 
	: State(inStateManager, inSprites, inWidth, inHeight)
{
	/*initialize random seed*/
	srand((unsigned int)time(NULL));
	/*loads the sprites used in the game*/
	sprites->loadGameSprites();
	/*initialise game entities*/
	background.push_back(new Entity((float)(screenWidth * 0.5f), (float)(screenHeight * 0.5f), screenWidth, screenHeight, 0));
	background.push_back(new Entity((float)(screenWidth * 0.5f), (float)(-screenHeight * 0.5f), screenWidth, screenHeight, 0));
	background.push_back(new Entity((float)(screenWidth * 0.5f), (float)((screenHeight * 0.5f) + screenHeight), screenWidth, screenHeight, 0));
	pauseButton = new Entity((float)(screenWidth - 100), 100.0f, 150, 150, 0);
	playButton = new Entity((float)(screenWidth * 0.5f), (float)(screenHeight * 0.5f), screenWidth - 200, 170, 0);
	exitButton = new Entity((float)(screenWidth * 0.5f), (float)((screenHeight * 0.5f) + 225), screenWidth - 200, 175, 0);
	/*initial platforms*/
	safePlatforms.push_back(new Entity((float)((screenWidth * 0.5f) - 300), (float)((screenHeight * 0.5f) + 200), 200, 200, 0));
	safePlatforms.push_back(new Entity((float)(screenWidth * 0.5f), (float)((screenHeight * 0.5f) + 200), 200, 200, 0));
	safePlatforms.push_back(new Entity((float)((screenWidth * 0.5f) + 300), (float)((screenHeight * 0.5f) + 200), 200, 200, 0));
	/*initialise animations*/
	buttonPress = new Animation(0.25f);
	playerAnim = new Animation(0.15f);
	/*initialise the player*/
	player = new Player((float)(screenWidth * 0.5f), (float)(screenHeight * 0.5f), 160, 160, 0);
	/*initialise the score*/
	score = 0;
	highestScore = 0;
	/*initialise the gravity*/
	gravity = 98.1f;
	/*initialise the animation indexes*/
	pauseSprite = playSprite = exitSprite = 0;
	/*initialise pressed*/
	pressed = false;
	/*set the state name*/
	name = "game";
	/*generate the initial random platforms*/
	generatePlatforms((float)((screenHeight * 0.5f) - 400.0f));
	generatePlatforms((float)((screenHeight * 0.5f) - 1000.0f));
	generatePlatforms((float)((screenHeight * 0.5f) - 1600.0f));
	generatePlatforms((float)((screenHeight * 0.5f) - 2200.0f));

	/*initialise and start the music*/
	jumpSafe = new Audio("aud/phaseJump1.ogg", false);
	jumpDanger = new Audio("aud/phaserDown3.ogg", false);
	music = new Audio("aud/ShinyTech.ogg", true);
	music->startAudio();
}

/**************************************************************************************************************/

/*Destructs the game object*/
Game::~Game()
{
	/*stop music*/
	music->stopAudio();
	/*delete audio pointers*/
	delete music;
	delete jumpSafe;
	delete jumpDanger;
	/*delete entities*/
	for (unsigned int i = 0; i < background.size(); i++)
	{
		delete background[i];
	}
	for (unsigned int i = 0; i < safePlatforms.size(); i++)
	{
		delete safePlatforms[i];
	}
	for (unsigned int i = 0; i < dangerPlatforms.size(); i++)
	{
		delete dangerPlatforms[i];
	}
	delete pauseButton;
	delete playButton;
	delete exitButton;
	delete player;
	delete buttonPress;
}

/**************************************************************************************************************/

/*updates the game object*/
void Game::update(float dt, float pressLocationX, float pressLocationY)
{
	/*check the music is still playing if not start again*/
	music->startAudio();

	/*apply gravity (decrease the background and entities velocity)*/
	for (unsigned int i = 0; i < background.size(); i++)
	{
		background[i]->setYVelocity(background[i]->getYVelocity() - gravity);
	}
	for (unsigned int i = 0; i < safePlatforms.size(); i++)
	{
		safePlatforms[i]->setYVelocity(safePlatforms[i]->getYVelocity() - gravity);
	}
	for (unsigned int i = 0; i < dangerPlatforms.size(); i++)
	{
		dangerPlatforms[i]->setYVelocity(dangerPlatforms[i]->getYVelocity() - gravity);
	}

	/*check if the pause button is pressed*/
	if (pressLocationX <= pauseButton->getX() + (pauseButton->getXScale() * 0.5f)
		&& pressLocationX > pauseButton->getX() - (pauseButton->getXScale() * 0.5f)
		&& pressLocationY <= pauseButton->getY() + (pauseButton->getYScale() * 0.5f) 
		&& pressLocationY > pauseButton->getY() - (pauseButton->getYScale() * 0.5f))
	{
		/*set the pause button to be highlighted*/
		pauseSprite = 1;
		/*A button has been pressed*/
		pressed = true;
	}
	/*if the user presses to the left side of the player*/
	else if (pressLocationX < player->getX() - (player->getXScale()*0.5f)
		&& player->getX() + (player->getXScale()*0.5f) > 0.0f)
	{
		/*the player moves left*/
		player->setXVelocity(-1000.0f);
	}
	/*if the user presses to the right side of the player*/
	else if (pressLocationX > player->getX() + (player->getXScale()*0.5f)
		&& player->getX() < screenWidth - (player->getXScale()*0.5f))
	{
		/*the player moves right*/
		player->setXVelocity(1000.0f);
	}
	/*if the player should not move*/
	else
	{
		/*the player stops moving*/
		player->setXVelocity(0.0f);
	}

	/*used in collision tests*/
	bool collisionTest = false;

	/*player safe platform collision check*/
	for (unsigned int i = 0; i < safePlatforms.size(); i++)
	{
		/*if the platform is displayed and there is a collision*/
		if (safePlatforms[i]->getDisplay() && Collision::playerPlatformIntersectCheck(player, safePlatforms[i], dt))
		{
			/*there was a collision*/
			collisionTest = true;

			/*plays the collision safe sound*/
			jumpSafe->playEffect();
		}
	}

	/*player danger platform collision check*/
	for (unsigned int i = 0; i < dangerPlatforms.size(); i++)
	{
		if (Collision::playerPlatformIntersectCheck(player, dangerPlatforms[i], dt))
		{
			/*there was a collision*/
			collisionTest = true;
			dangerPlatforms[i]->setYVelocity(6000.0f);
			/*update the platform animation*/
			dangerPlatforms[i]->setAnimationIndex(1);
			platformAnim[i]->updateTimer(dt);

			/*plays the collision safe sound*/
			jumpDanger->playEffect();
		}
	}

	/*if there was a collision*/
	if (collisionTest)
	{
		/*update velocities so player appears to go up*/
		for (unsigned int i = 0; i < background.size(); i++)
		{
			background[i]->setYVelocity(3000.0f);
		}
		for (unsigned int i = 0; i < safePlatforms.size(); i++)
		{
			safePlatforms[i]->setYVelocity(3000.0f);
		}
		for (unsigned int i = 0; i < dangerPlatforms.size(); i++)
		{
			if (dangerPlatforms[i]->getYVelocity() != 6000.0f)
			{
				dangerPlatforms[i]->setYVelocity(3000.0f);
			}
		}
		/*update the player animation*/
		player->setAnimationIndex(1);
		playerAnim->updateTimer(dt);
	}

	/*update the backgrounds*/
	for (unsigned int i = 0; i < background.size(); i++)
	{
		background[i]->updateY(dt);
	}

	/*update the safe platforms*/
	for (unsigned int i = 0; i < safePlatforms.size(); i++)
	{
		safePlatforms[i]->updateY(dt);
	}

	/*update the danger platforms*/
	for (unsigned int i = 0; i < dangerPlatforms.size(); i++)
	{
		dangerPlatforms[i]->updateY(dt);
	}

	/*check to see if the backgrounds position need to be reset*/
	if (background[0]->getY() >= (float)((screenHeight * 0.5f) + screenHeight) && background[0]->getYVelocity() > 0
		|| background[0]->getY() <= (float)(-screenHeight * 0.5f) && background[0]->getYVelocity() < 0)
	{
		/*reset the background*/
		background[0]->setY((float)(screenHeight * 0.5f));
		background[1]->setY((float)(-screenHeight * 0.5f));
		background[2]->setY((float)((screenHeight * 0.5f) + screenHeight));
	}

	/*update the player*/
	player->updateX(dt);
	player->updateY(dt);

	/*bool for a check if a platform has gone off the screen*/
	bool platformCheck = false;

	/*check if the safe platforms are off the screen*/
	for (int i = (int)safePlatforms.size() - 1; i >= 0; i--)
	{
		if (safePlatforms[i]->getY() - safePlatforms[i]->getYScale() > screenHeight)
		{
			/*erase the platform*/
			safePlatforms.erase(safePlatforms.begin() + i);
			/*set the platform check to true*/
			platformCheck = true;
		}
	}

	/*check if the danger platforms are off the screen*/
	for (int i = (int)dangerPlatforms.size() - 1; i >= 0; i--)
	{
		if (dangerPlatforms[i]->getY() - dangerPlatforms[i]->getYScale() > screenHeight)
		{
			/*erase the platform*/
			dangerPlatforms.erase(dangerPlatforms.begin() + i);
			/*erase the platform animation*/
			platformAnim.erase(platformAnim.begin() + i);
		}
	}

	/*does a new set of platforms need to be generated*/
	if (platformCheck)
	{
		/*generate the new platforms*/
		generatePlatforms((float)((screenHeight * 0.5f) - 1600.0f));
	}


	/*increases the number of the score by the amount traveled up or down, don not go less than 0*/
	if (score > 99998){ score = 0; }
	else if (background[0]->getYVelocity() > 0){ score++; }
	else if (score < 1){ score = 0; }
	else { score--; };

	/*if the score is at its highest store it*/
	if (score > highestScore)
	{
		/*update the highest score*/
		highestScore = score;
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
		pauseSprite = 0;
		/*open pause screen*/
		stateManager->addState(new Pause(stateManager, sprites, screenWidth, screenHeight));
	}

	/*update the player animation timer if the player is animating*/
	if (player->getAnimationIndex() == 1)
	{
		/*update player animation timer*/
		playerAnim->updateTimer(dt);
	}

	/*check if pressed is true and the timer has reset*/
	if (player->getAnimationIndex() == 1 && playerAnim->getCurrentTime() == 0.0f)
	{
		/*reset the player sprite*/
		player->setAnimationIndex(0);
	}

	/*check danger platforms animations*/
	for (int i = (int)dangerPlatforms.size() - 1; i >= 0; i--)
	{
		/*update the player animation timer if the player is animating*/
		if (dangerPlatforms[i]->getAnimationIndex() > 0 && dangerPlatforms[i]->getAnimationIndex() < 3)
		{
			/*update platform animation timer*/
			platformAnim[i]->updateTimer(dt);
			/*check if animating and the timer has reset*/
			if (platformAnim[i]->getCurrentTime() == 0.0f)
			{
				/*reset the player sprite*/
				dangerPlatforms[i]->setAnimationIndex(dangerPlatforms[i]->getAnimationIndex() + 1);
			}
		}		
	}


	/*check if player has fallen to their death*/
	if (background[0]->getYVelocity() < -10000)
	{
		/*open the lose state*/
		stateManager->changeState(new Lose(stateManager, sprites, screenWidth, screenHeight, highestScore));
		return;
	}
}

/**************************************************************************************************************/

/*displays the sprites that do not use alpha*/
void Game::drawSprites()
{
	/*draw the backgrounds*/
	for (unsigned int i = 0; i < background.size(); i++)
	{
		sprites->drawGameSprite("background", 0, background[i]->getX(),
			background[i]->getY(), background[i]->getXScale(), background[i]->getYScale());
	}
}

/**************************************************************************************************************/

/*displays the sprites that do use alpha*/
void Game::drawSpritesWithAlpha()
{
	/*draw the safe platforms*/
	for (unsigned int i = 0; i < safePlatforms.size(); i++)
	{
		/*display if they can be displayed*/
		if (safePlatforms[i]->getDisplay())
		{
			sprites->drawGameSprite("safePlatform", 0, safePlatforms[i]->getX(),
				safePlatforms[i]->getY(), safePlatforms[i]->getXScale(), safePlatforms[i]->getYScale());
		}
	}
	
	/*draw the dangerPlatforms*/
	for (unsigned int i = 0; i < dangerPlatforms.size(); i++)
	{
		sprites->drawGameSprite("dangerPlatform", dangerPlatforms[i]->getAnimationIndex(), dangerPlatforms[i]->getX(),
			dangerPlatforms[i]->getY(), dangerPlatforms[i]->getXScale(), dangerPlatforms[i]->getYScale());
	}

	/*draw the pause button*/
	sprites->drawGameSprite("pause", pauseSprite, pauseButton->getX(),
		pauseButton->getY(), pauseButton->getXScale(), pauseButton->getYScale());

	/*draw the score to the screen*/
	displayScore();

	/*draw the player*/
	sprites->drawGameSprite("player", player->getAnimationIndex(), player->getX(),
		player->getY(), player->getXScale(), player->getYScale());

}

/**************************************************************************************************************/

/*draw the score to the screen*/
void Game::displayScore()
{
	int currentScore = highestScore;
	/*Loop for 5 digits*/
	for (int i = 0; i < 5; i++)
	{
		/*display the number*/
		sprites->drawGameSprite("symbol", currentScore % 10, 100.0f * (5 - i), 100.0f, 100, 100);
		currentScore = currentScore / 10;
	}
}

/**************************************************************************************************************/

/*generates the new platforms*/
void Game::generatePlatforms(float yPosition)
{
	/*create a vector of taken x positions for checking*/
	std::vector<int> takenXPositions;
	/*loop through the number of platforms*/
	for (int i = 0; i < ((rand() % 3) + 1); i++)
	{
		/*generate a random x position (between 0 and 2)*/
		takenXPositions.push_back(rand() % 3);
		/*set the position to not be unique for checking*/
		bool uniquePosition = false;
		/*while the position is not unique*/
		while (!uniquePosition)
		{
			/*bool for checking*/
			bool successfulGeneration = true;
			/*loop through all of the currently generated new platforms (except the current one)*/
			for (unsigned int j = 0; j < takenXPositions.size() - 1; j++)
			{
				/*check if the new x position is already taken*/
				if (takenXPositions[i] == takenXPositions[j])
				{
					/*if so generate a new position*/
					takenXPositions[i] = rand() % 3;
					/*set the generation to have failed*/
					successfulGeneration = false;
				}
			}
			/*check if the generation succeeded*/
			if (successfulGeneration)
			{
				/*set unique position to true*/
				uniquePosition = true;
			}			
		}
		/*if 0 or 1 the the new platform is a safe platform*/
		if (rand() % 3 < 2)
		{
			/*generate a new safe platform*/
			safePlatforms.push_back(new Entity((float)(((screenWidth * 0.5f) - 300) + (takenXPositions[i] * 300)), yPosition, 200, 200, 0));
			/*set the velocity to the current velocity of the other objects*/
			safePlatforms[safePlatforms.size()-1]->setYVelocity(background[i]->getYVelocity());
		}
		/*if 2 the the new platform is a danger platform*/
		else
		{
			/*generate a new safe platform*/
			dangerPlatforms.push_back(new Entity((float)(((screenWidth * 0.5f) - 300) + (takenXPositions[i] * 300)), yPosition, 200, 200, 0));
			/*set the velocity to the current velocity of the other objects*/
			dangerPlatforms[dangerPlatforms.size() - 1]->setYVelocity(background[i]->getYVelocity());
			/*generate a new safe platform*/
			safePlatforms.push_back(new Entity((float)(((screenWidth * 0.5f) - 300) + (takenXPositions[i] * 300)), yPosition, 200, 200, 0));
			/*disable the display and set the velocity to the current velocity of the other objects*/
			safePlatforms[safePlatforms.size() - 1]->setYVelocity(background[i]->getYVelocity());
			safePlatforms[safePlatforms.size() - 1]->setDisplay(false);
			/*create the animation for the danger platform*/
			platformAnim.push_back(new Animation(0.05f));
		}
	}
}