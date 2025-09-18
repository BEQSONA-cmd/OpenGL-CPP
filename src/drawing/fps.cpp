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

double get_fps(double last_time)
{
    static int frame_count;
    double current_time = glfwGetTime();
    double fps = frame_count / (current_time - last_time);
    frame_count++;
    return fps;
}

void draw_fps(float fps)
{
    float new_fps = get_fps(fps);
    std::ostringstream fps_text;

    fps_text << std::fixed << std::setprecision(1) << "FPS: " << new_fps;

    float text_color[3] = {0.0f, 1.0f, 1.0f};

    Point text_position;
    text_position.x = 0.8f;
    text_position.y = 0.9f;

    draw_text(fps_text.str(), text_position, text_color);
}
