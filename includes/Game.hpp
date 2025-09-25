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
#include <cmath>
#include <iomanip>
#include "Keys.hpp"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

typedef struct s_Point
{
    float x;
    float y;
} Point;


class Game
{
private:
    GLFWwindow *window;
    std::string Name;

    // Camera rotation
    float cam_angle_x = 30.0f;
    float cam_angle_y = -45.0f;
    float cam_distance = 5.0f;

    // Mouse    
    double last_mouse_x = 0;
    double last_mouse_y = 0;
    bool mouse_pressed = false;
    std::string typed_text = "";  // placeholder for input text

public:
    Game(std::string name) { this->Name = name; }
    ~Game() { 
        std::cout << YELLOW << "Game Closed." << RESET << std::endl; 
        if(this->window)
            glfwDestroyWindow(this->window);
        glfwTerminate();
    }

    void draw_grid();
    void update_camera();
    void mouse_callbacks();
    void draw_ui(double last_time);

    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

    void init_opengl();
    void run();
};


void draw_text(const std::string& text, Point position,float color[3]);
std::string get_fps(double last_time);

#endif
