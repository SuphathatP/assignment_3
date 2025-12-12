#pragma once
#include "constants.h"

class Rigidbody
{
public:
	
	Play::Point2f position;
	Play::Vector2D velocity;
	Play::Vector2D acceleration;
	float rotation;
	int radius;

	virtual void draw() = 0;
	virtual void simulatePhysics(float elapsedTime);
	virtual void collisions(Rigidbody* other);

};