#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "gravity.h"
#include "constants.h"

int main()
{
    // Create GLFW window
    GLFWwindow *window = StartGLFW();

    // Circle
    float centerX = Constants::WINDOW_WIDTH / 2.0f;
    float centerY = Constants::WINDOW_HEIGHT / 2.0f;
    float radius = 50.0f;
    int res = 100;

    // Vectors
    std::vector<float> position = {centerX, centerY};
    std::vector<float> velocity = {0.0f, 0.0f};

    // Frames
    float deltaTime = 0.0f;
    float lastFrame, currentFrame = 0.0f;

    // Run GLFW window
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Circle
        DrawCircle(position[0], position[1], radius = radius, res = res);

        // Frames
        while (glfwGetTime() - currentFrame < 1.0 / 60.0) // cap frame rate to 60 fps
        {
        }
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Vector Updates with Time
        velocity[1] += -Constants::GRAVITY * deltaTime;
        position[0] += velocity[0] * deltaTime * Constants::PIXELS_PER_METER;
        position[1] += velocity[1] * deltaTime * Constants::PIXELS_PER_METER;

        // Border Collision
        if (position[1] - radius < 0) // vertical
        {
            position[1] = radius;
            velocity[1] *= -0.95f;
        }
        else if (position[1] + radius > Constants::WINDOW_HEIGHT)
        {
            position[1] = Constants::WINDOW_HEIGHT - radius;
            velocity[1] *= -0.95f;
        }
        if (position[0] - radius < 0) // horizontal
        {
            position[0] = radius;
            velocity[0] *= -0.95f;
        }
        else if (position[0] + radius > Constants::WINDOW_WIDTH)
        {
            position[0] = Constants::WINDOW_WIDTH - radius;
            velocity[0] *= -0.95f;
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}