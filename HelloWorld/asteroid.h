#pragma once
#include "constants.h"
#include "rigidbody.h"

class Asteroid : public Rigidbody
{
	float scale;
	float rotationSpeed;
	int spriteId;

};