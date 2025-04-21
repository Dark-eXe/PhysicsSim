#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

class Object
{
public:
    std::vector<float> position;
    std::vector<float> velocity;
    float radius;

    Object(std::vector<float> position, std::vector<float> velocity, float radius);
    void accelerate(float x, float y, float deltaTime);
    void updatePos(float deltaTime);
    void drawCircle(int resolution = 100);
};

#endif