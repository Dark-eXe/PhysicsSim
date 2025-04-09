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

    // Run GLFW window
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Circle
        glBegin(GL_TRIANGLE_FAN);
        glVertex2d(centerX, centerY);
        for (int i = 0; i <= res; ++i)
        {
            float angle = 2.0f * Constants::PI * (static_cast<float>(i) / res);
            float x = centerX + cos(angle) * radius;
            float y = centerY + sin(angle) * radius;
            glVertex2d(x, y);
        }
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}