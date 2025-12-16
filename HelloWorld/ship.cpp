#include "ship.h"
#include "asteroid.h"

void Ship::reset() {
	// Start at center of the screen
	position.x = static_cast<float>(DISPLAY_WIDTH) * 0.5f;
	position.y = static_cast<float>(DISPLAY_HEIGHT) * 0.5f;

	velocity.x = velocity.y = 0.0f;
	acceleration.x = acceleration.y = 0.0f;
	rotation = 0.0f;
}

Ship::Ship()
{
	// Get sprite ID
	shipID = Play::GetSpriteId("ship");

	shipThrust = 400.0f;
	shipRotationSpeed = 4.0f;

	this->reset();

	// Collision radius
	int spriteWidth = Play::GetSpriteWidth(shipID);
	int spriteHeight = Play::GetSpriteHeight(shipID);
	radius = static_cast<int>((std::max(width, height) * 0.5f));
}

void Ship::simulatePhysics(float elapsedTime)
{
	// Input: rotate
	if (Play::KeyDown(Play::KEY_LEFT) || Play::KeyDown(Play::KEY_A))
	{
		rotation += shipRotationSpeed * elapsedTime;
	}

	if (Play::KeyDown(Play::KEY_RIGHT) || Play::KeyDown(Play::KEY_D))
	{
		rotation -= shipRotationSpeed * elapsedTime;
	}

	// Normalize rotation
	if (rotation >= TWO_PI) rotation = std::fmod(rotation, TWO_PI);
	else if (rotation < 0.0f) rotation += TWO_PI;

	// Input: thrust
	if (Play::KeyDown(Play::KEY_SPACE))
	{
		acceleration.x -= shipThrust * std::sin(rotation);
		acceleration.y += shipThrust * std::cos(rotation);
	}

	// Call base Rigidbody
	Rigidbody::simulatePhysics(elapsedTime);
}

void Ship::draw()
{
	// Draw the ship rotated at its position
	Play::DrawSpriteRotated(shipID, position, 0, rotation, 1.0f);
}

void Ship::on_collision(Rigidbody* other)
{
	// (void)other; // Not finished, forcing Johan to doing this :p
	bool check = (
		(position.x - other->position.x) * (position.x - other->position.x) // (p.x-q.x)^{2}
		+ (position.y - other->position.y) * (position.y - other->position.y) // (p.y-q.y)^{2}
		)
		< this->radius + other->radius;
	if (check) {
		reset();
	}
}

/*	Note: The fmod() function returns the floating point remainder of the division dividend / divisor where the result of the division is truncated(the decimal part is removed).
	link https://www.w3schools.com/cpp/ref_math_fmod.asp */