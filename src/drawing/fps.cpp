#include "../../includes/Game.hpp"

void draw_text(const std::string& text, Point position,float color[3])
{
    glColor3f(color[0], color[1], color[2]);
    glRasterPos2f(position.x, position.y);
    
    int i = 0;
    while (text[i])
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
        i++;
    }
}

std::string get_fps(double last_time)
{
    static int frame_count;
    double current_time = glfwGetTime();
    double fps = frame_count / (current_time - last_time);
    frame_count++;
    return std::to_string(fps);
}
