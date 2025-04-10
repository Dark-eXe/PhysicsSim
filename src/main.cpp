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

    // Run GLFW window
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Circle
        DrawCircle(position[0], position[1], radius = radius, res = res);

        // Vector Updates with Time
        position[0] += velocity[0];
        position[1] += velocity[1];
        velocity[1] += -9.81 / 20.0f;

        // Border Collision
        if (position[1] < 0 || position[1] > Constants::WINDOW_HEIGHT)
            velocity[1] *= -0.95f;
        if (position[0] < 0 || position[0] > Constants::WINDOW_WIDTH)
            velocity[0] *= -0.95f;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}