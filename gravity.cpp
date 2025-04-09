#include <iostream>

#include "gravity.h"

GLFWwindow *StartGLFW()
{
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n"
                  << std::endl;
        return nullptr;
    }

    GLFWwindow *window = glfwCreateWindow(800, 600, "gravity_sim", NULL, NULL);

    return window;
}