#pragma once
#include "constants.h"
#include "rigidbody.h"

class Ship : public Rigidbody
{
	float thrust;
	int spriteId;
};