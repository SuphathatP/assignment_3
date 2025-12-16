#pragma once
#include "Play.h"

// Display
const int DISPLAY_WIDTH = 1920;
const int DISPLAY_HEIGHT = 1080;
const int DISPLAY_SCALE = 1;

// For screen wrap around
const float width = static_cast<float>(DISPLAY_WIDTH);
const float height = static_cast<float>(DISPLAY_HEIGHT);

// Asteroid Value
const float minScale = 0.5f;
const float maxScale = 5.0f;
const float minRotationSpeed = -2.0f;
const float maxRotationSpeed = 2.0f;
const float minVelocity = -150.0f;
const float maxVelocity = 150.0f;

const float TWO_PI = 2.0f * 3.14159265358979323846f; // for rotation