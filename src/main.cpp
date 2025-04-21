#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Object.h"
#include "gravity.h"
#include "constants.h"

int main()
{
    // Create GLFW window
    GLFWwindow *window = StartGLFW();

    // Frames
    float deltaTime = 0.0f;
    float lastFrame = glfwGetTime();

    // Circle
    float centerX = Constants::WINDOW_WIDTH / 2.0f;
    float centerY = Constants::WINDOW_HEIGHT;

    std::vector<Object> objs = {
        Object(std::vector<float>{centerX / 2, centerY}, std::vector<float>{0.0f, 0.0f}, 50.0f),
        Object(std::vector<float>{centerX * 3 / 2, centerY}, std::vector<float>{0.0f, 0.0f}, 50.0f)};

    // Run GLFW window
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        for (auto &obj : objs)
        {
            obj.accelerate(5.0f, -Constants::GRAVITY, deltaTime);
            obj.updatePos(deltaTime);
            obj.drawCircle();

            // Border Collision
            if (obj.position[1] - obj.radius < 0) // vertical
            {
                obj.position[1] = obj.radius;
                obj.velocity[1] *= -0.95f;
            }
            else if (obj.position[1] + obj.radius > Constants::WINDOW_HEIGHT)
            {
                obj.position[1] = Constants::WINDOW_HEIGHT - obj.radius;
                obj.velocity[1] *= -0.95f;
            }
            if (obj.position[0] - obj.radius < 0) // horizontal
            {
                obj.position[0] = obj.radius;
                obj.velocity[0] *= -0.95f;
            }
            else if (obj.position[0] + obj.radius > Constants::WINDOW_WIDTH)
            {
                obj.position[0] = Constants::WINDOW_WIDTH - obj.radius;
                obj.velocity[0] *= -0.95f;
            }
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}