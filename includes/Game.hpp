#ifndef GAME_HPP
#define GAME_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

#include <iostream>
#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include <sstream>
#include <iomanip>
#include "Keys.hpp"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define X_TRANS 2.0f / 1280
#define Y_TRANS 2.0f / 720

typedef struct s_Point
{
    float x;
    float y;
} Point;

class Player
{
    private:

    public:
        Player();
        ~Player();

        float x;
        float y;

        Point size;

        void move(int key);
};

class Game
{
    private:
        GLFWwindow *window;
        std::string Name;
        Player player;
    public:
        Game(std::string name) { this->Name = name; }
        ~Game() 
        { 
            std::cout << YELLOW << "Game Closed." << RESET << std::endl; 
            if(this->window)
                glfwDestroyWindow(this->window);
            glfwTerminate();
        }

        void init_opengl();

        void run();
};

#endif
