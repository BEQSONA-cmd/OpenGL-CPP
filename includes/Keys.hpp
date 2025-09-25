#ifndef KEYS_HPP
#define KEYS_HPP

#include "Game.hpp"
#include <vector>

#define ESC 256
#define SPACE 32
#define ENTER 257
#define W 87
#define A 65
#define S 83
#define D 68
#define M 77

class Keys
{
    private:
        static std::vector<int> keys;
    public:
        static void print_key(int key);
        static bool Close(GLFWwindow *window);
        static int key_pressed(GLFWwindow *window);
};

#endif