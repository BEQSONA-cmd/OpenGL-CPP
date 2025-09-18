#include "../includes/Keys.hpp"

std::vector<int> Keys::keys = {ESC, SPACE, ENTER, W, A, S, D};

void Keys::print_key(int key)
{
    switch(key)
    {
        case ESC: std::cout << BLUE "ESC" RESET << std::endl; break;
        case SPACE: std::cout << BLUE "SPACE" RESET << std::endl; break;
        case ENTER: std::cout << BLUE "ENTER" RESET << std::endl; break;
        case W: std::cout << BLUE "W" RESET << std::endl; break;
        case A: std::cout << BLUE "A" RESET << std::endl; break;
        case S: std::cout << BLUE "S" RESET << std::endl; break;
        case D: std::cout << BLUE "D" RESET << std::endl; break;
        default: std::cout << BLUE "Unknown key" RESET << std::endl; break;
    }
}

bool Keys::Close(GLFWwindow *window)
{
    if(glfwWindowShouldClose(window) || glfwGetKey(window, ESC) == GLFW_PRESS)
        return true;
    return false;
}

int Keys::key_pressed(GLFWwindow *window)
{
    size_t i = 0;
    while(i < keys.size())
    {
        if(glfwGetKey(window, keys[i]) == GLFW_PRESS)
            return keys[i];
        i++;
    }
    return 0;
}

