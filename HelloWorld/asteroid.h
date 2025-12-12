#pragma once
#include "constants.h"
#include "rigidbody.h"

class Asteroid : public Rigidbody
{
public:
	Asteroid();

	// Rigidbody overrides
	void draw() override;
	void simulatePhysics(float elapsedTime) override;
	void collisions(Rigidbody* other) override;

	float scale;
	float rotationSpeed;
	int asteroidID;

};