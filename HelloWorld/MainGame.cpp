#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "constants.h"
#include "game.h"

#include "rigidbody.h"
#include "ship.h"
#include "asteroid.h"

// currently = 1 (ship)
constexpr int NUM_RIGIDBODIES = 12; // evaluated at compile time???? https://www.geeksforgeeks.org/cpp/understanding-constexper-specifier-in-cpp/
Rigidbody** rigidbody = nullptr;

// The entry point for a PlayBuffer program
void MainGameEntry(PLAY_IGNORE_COMMAND_LINE)
{
	Play::CreateManager(DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE);
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	// Center sprite origins!!!!!!
	Play::CentreAllSpriteOrigins();

	// Allocate array and objects
	rigidbody = new Rigidbody * [NUM_RIGIDBODIES];
	rigidbody[0] = new Ship();

	for (int i = 1; i < NUM_RIGIDBODIES; i++)
	{
		rigidbody[i] = new Asteroid();
	}
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate(float elapsedTime)
{
	Play::ClearDrawingBuffer(Play::cBlack);

	// Update and draw all rigid bodies (polymorphic ?? not sure) // I don't think so?
	for (int i = 0; i < NUM_RIGIDBODIES; i++)
	{
		rigidbody[i]->simulatePhysics(elapsedTime);
		rigidbody[i]->draw();
		Play::DrawCircle(rigidbody[i]->position, rigidbody[i]->radius, Play::cRed);
		if (i != 0)
			rigidbody[0]->on_collision(rigidbody[i]);
	}

	Play::DrawDebugText({ DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 - 200 }, "Asteroid by nEwNEwnEW and Johan the carrot :)");

	Play::PresentDrawingBuffer();
	return Play::KeyDown(KEY_ESCAPE);
}

// Gets called once when the player quits the game 
int MainGameExit(void)
{
	// Clean up
	if (rigidbody)
	{
		for (int i = 0; i < NUM_RIGIDBODIES; ++i)
			delete rigidbody[i];
		delete[] rigidbody;
		rigidbody = nullptr;
	}

	Play::DestroyManager();
	return PLAY_OK;
}

