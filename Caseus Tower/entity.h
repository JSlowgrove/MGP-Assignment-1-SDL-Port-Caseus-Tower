#pragma once

/**
@brief Creates an Entity object
Creates an Entity object with all the information about the Entity.
*/
class Entity
{
protected:
	/*dimensions*/
	int xScale;
	int yScale;
	/*position*/
	float x;
	float y;
	/*y velocity*/
	float yVelocity;
	/*should the entity be displayed*/
	bool display;
	/*current animation index*/
	int animationIndex;
public:
	/**
	Constructs an Entity object
	@param float initial x position.
	@param float initial y position.
	@param int initial x scale.
	@param int initial y scale.
	@param int the current animation index;
	*/
	Entity(float, float, int, int, int);

	/**
	Destructs an Entity object
	*/
	~Entity();

	/**
	Setter # x position
	Sets the x position of the Entity object to the inputed x position.
	@param float the inputed x position
	*/
	void setX(float);

	/**
	Setter # y position
	Sets the y position of the Entity object to the inputed y position.
	@param float the inputed y position
	*/
	void setY(float);

	/**
	Setter # x scale
	Sets the x scale of the Entity object to the inputed x scale.
	@param int the inputed x scale
	*/
	void setXScale(int);

	/**
	Setter # y scale
	Sets the y scale of the Entity object to the inputed y scale.
	@param int the inputed y scale
	*/
	void setYScale(int);

	/**
	Setter # y velocity
	Sets the y velocity of the Entity object to the inputed y velocity.
	@param float the inputed y velocity
	*/
	void setYVelocity(float);

	/**
	Setter # display
	Sets the display boolean of the Entity object.
	@param bool the inputed display bool
	*/
	void setDisplay(bool);

	/**
	Setter # animation index
	Sets the animation index of the Entity object to the inputed index.
	@param int the inputed animation index
	*/
	void setAnimationIndex(int);
	
	/**
	Getter # x position
	@returns float the x position of the Entity object.
	*/
	float getX();

	/**
	Getter # y position
	@returns float the y position of the Entity object.
	*/
	float getY();

	/**
	Getter # x scale
	@returns int the x scale of the Entity object.
	*/
	int getXScale();

	/**
	Getter # y scale
	@returns int the y scale of the Entity object.
	*/
	int getYScale();

	/**
	Getter # y velocity
	@returns float the y velocity of the Entity object.
	*/
	float getYVelocity();

	/**
	Getter # display
	@returns bool if the Entity object will display.
	*/
	bool getDisplay();

	/**
	Getter # animation index
	@returns int the animation index of the Entity object.
	*/
	int getAnimationIndex();

	/**
	Updates the Entity y position
	Updates the Entity y position using the velocity and the dt.
	@param float the dt
	*/
	void updateY(float);	
};