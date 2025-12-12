#pragma once
#include "constants.h"
#include "rigidbody.h"

class Ship : public Rigidbody
{
public:
	Ship();

	// Rigidbody overrides
	void draw() override;
	void simulatePhysics(float elapsedTime) override;
	void collisions(Rigidbody* other) override;

	float shipThrust;
	float shipRotationSpeed;
	int shipID;
};