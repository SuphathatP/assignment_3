#include "rigidbody.h"

void Rigidbody::simulatePhysics(float elapsedTime)
{
	// Frame rate independent velocity acceleration
	velocity.x += acceleration.x * elapsedTime;
	velocity.y += acceleration.y * elapsedTime;
	
	position.x += velocity.x * elapsedTime;
	position.y += velocity.y * elapsedTime;

	// Reset acceleration for the next frame
	acceleration.x = 0.0f;
	acceleration.y = 0.0f;

	// Screen wrap around
	if (position.x < 0.0f) position.x += width;
	else if (position.x > width) position.x -= width;

	if (position.y < 0.0f) position.y += height;
	else if (position.y > height) position.y -= height;
}

void Rigidbody::collisions(Rigidbody* other)
{
	(void)other;
}