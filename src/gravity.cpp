#include <iostream>

#include "gravity.h"
#include "constants.h"

GLFWwindow *StartGLFW()
{
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n"
                  << std::endl;
        return nullptr;
    }

    GLFWwindow *window = glfwCreateWindow(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT, "gravity_sim", NULL, NULL);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(window);
    glOrtho(0.0, Constants::WINDOW_WIDTH, 0.0, Constants::WINDOW_HEIGHT, -1.0, 1.0); // recenters window
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);                                            // dark gray background

    return window;
}

void DrawCircle(float centerX, float centerY, float radius, int res)
{
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
}