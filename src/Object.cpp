#include "Object.h"
#include "constants.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

Object::Object(std::vector<float> position, std::vector<float> velocity, float radius)
    : position(position), velocity(velocity), radius(radius) {}

void Object::accelerate(float x, float y, float deltaTime)
{
    velocity[0] += x * deltaTime;
    velocity[1] += y * deltaTime;
}

void Object::updatePos(float deltaTime)
{
    position[0] += velocity[0] * deltaTime * Constants::PIXELS_PER_METER;
    position[1] += velocity[1] * deltaTime * Constants::PIXELS_PER_METER;
}

void Object::drawCircle(int res)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(position[0], position[1]);
    for (int i = 0; i <= res; ++i)
    {
        float angle = 2.0f * Constants::PI * (static_cast<float>(i) / res);
        float x = position[0] + cos(angle) * radius;
        float y = position[1] + sin(angle) * radius;
        glVertex2f(x, y);
    }
    glEnd();
}
