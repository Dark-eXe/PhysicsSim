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

    return window;
}