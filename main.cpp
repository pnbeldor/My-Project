#include <iostream>
#include "MyProjectConfig.h"
#include "NearlyMath.hpp"
#include "GLFW/glfw3.h"
#include "lvgl.h"

#include "example_generated.h"

//using namespace nearlymath;

auto main(int argc, char**argv) -> int
{
    std::cout << argv[0] << " Version " << MyProject_VERSION_MAJOR << "." << MyProject_VERSION_MINOR << "\n" << MyProject_DESCRIPTION << "\n";
    nearlymath::NearlyMath nearlyMath;
    auto result = nearlyMath.Add(30, 60);

    std::cout << "The sum of 30 and 60 is: " << nearlyMath.Add(30, 60) <<"\n";
    std::cout << "The diff of 60 and 30 is: " << nearlyMath.Subtract(60, 30) <<"\n";
    std::cout << "The sum of the 2 default value is: " << nearlyMath.Sum() <<"\n";

    nearlyMath.SetValue(100, 300);

    std::cout << "The sum of the 2 default value is: " << nearlyMath.Sum() <<"\n";
    std::cout << "Welcome to cpp\n\n\n";

    GLFWwindow* window;
    int width, height;

    //If fails to
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_DEPTH_BITS, 16);
    glfwWindowHint(GLFW_ACCUM_GREEN_BITS, GLFW_TRUE);

    window = glfwCreateWindow(600, 500, "Pierre Nicolson Beldor", NULL, NULL);

    // Terminate the application if fails to create the window
    if (!window)
    {
        fprintf(stderr, "Failed to open window\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Keep the window open until it needs to be closed
    while(!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
