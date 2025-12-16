#include "asteroid.h"

static float randRange(float minValue, float maxValue)
{
	return minValue + (static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) * (maxValue - minValue); // Note: RAND_MAX Maximum value return by rand function https://cplusplus.com/reference/cstdlib/RAND_MAX/.
}

Asteroid::Asteroid()
{
	// Get sprite ID
	asteroidID = Play::GetSpriteId("asteroid");

	// Randomize scale and rotation speed
	scale = randRange(minScale, maxScale);
	rotationSpeed = randRange(minRotationSpeed, maxRotationSpeed);

	// Random spawn rotation
	rotation = randRange(0.0f, TWO_PI);

	// Random position on screen
	position.x = randRange(0.0f, static_cast<float>(DISPLAY_WIDTH));
	position.y = randRange(0.0f, static_cast<float>(DISPLAY_HEIGHT));

	// Random velocity
	velocity.x = randRange(minVelocity, maxVelocity);
	velocity.y = randRange(minVelocity, maxVelocity);

	// No acceleration spawn
	acceleration.x = 0.0f;
	acceleration.y = 0.0f;

	// Collision radius
	int spriteWidth = Play::GetSpriteWidth(asteroidID);
	int spriteHeight = Play::GetSpriteHeight(asteroidID);
	radius = static_cast<int>((std::max(spriteWidth, spriteHeight) * scale) * 0.5f);
}

void Asteroid::simulatePhysics(float elapsedTime)
{
	// Call base Rigidbody
	Rigidbody::simulatePhysics(elapsedTime);

	// Add rotation speed
	rotation += rotationSpeed * elapsedTime;

	// Normalize rotation
	if (rotation >= TWO_PI) rotation = std::fmod(rotation, TWO_PI); // using fmod for floating-point remainder
	else if (rotation < 0.0f) rotation += TWO_PI;
}

void Asteroid::draw()
{
	Play::DrawSpriteRotated(asteroidID, position, 0, rotation, scale);
}

void Asteroid::on_collision(Rigidbody* other)
{
	(void)other; // Will come back to this or forcing Johan to doing this
}