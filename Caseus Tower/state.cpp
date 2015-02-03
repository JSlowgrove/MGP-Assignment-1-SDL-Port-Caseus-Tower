#include "state.h"

/**************************************************************************************************************/

/*Constructs the State object*/
State::State(StateManager * inStateManager, SpriteHandler * inSprites, int inWidth, int inHeight)
{
	/*sets the pointer to the state manager*/
	stateManager = inStateManager;
	/*initialises the sprite handler pointer*/
	sprites = inSprites;
	/*initialises the screen dimensions*/
	screenWidth = inWidth;
	screenHeight = inHeight;
	/*set the program to run*/
	runCheck = true;
}

/**************************************************************************************************************/

/*Destructs the entity object*/
State::~State()
{

}

/**************************************************************************************************************/

/*returns the name of the state*/
std::string State::GetStateName() 
{
	/*returns the name*/
	return name;
}

/**************************************************************************************************************/

/*returns if the program should run*/
bool State::runProgram() 
{
	/*returns the bool*/
	return runCheck;
}