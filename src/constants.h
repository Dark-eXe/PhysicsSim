#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cmath>
#include <numbers>

namespace Constants
{
    // Math/Physics
    constexpr double PI = 3.141592658979323846;
    constexpr float GRAVITY = 9.81f;

    // Main
    constexpr float WINDOW_WIDTH = 800.0f;
    constexpr float WINDOW_HEIGHT = 600.0f;
    constexpr float PIXELS_PER_METER = 100.0f; // 100 pixels = 1 meter
}

#endif