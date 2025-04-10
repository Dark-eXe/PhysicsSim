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

    // Position
    std::vector<float> position = {centerX, centerY};

    // Run GLFW window
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Circle
        DrawCircle(position[0], position[1], radius = radius, res = res);
        position[1] -= 0.5f;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}