#pragma once
#include "constants.h"
#include "rigidbody.h"

class Ship : public Rigidbody
{
	void reset();
public:
	Ship();

	// Rigidbody overrides
	void draw() override;
	void simulatePhysics(float elapsedTime) override;
	void on_collision(Rigidbody* other) override;

	float shipThrust;
	float shipRotationSpeed;
	int shipID;
};