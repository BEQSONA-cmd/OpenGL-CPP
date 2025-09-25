#include "../../includes/Game.hpp"

void Game::draw_ui(double last_time)
{
    // Draw button
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    // Draw placeholder text
    float color[3] = {1.0f, 1.0f, 1.0f};
    Point pos = {10.0f, 10.0f};
    if(typed_text.empty())
        draw_text("Type here...", pos, color);
    else
        draw_text(typed_text, pos, color);
    pos = {10.0f, WINDOW_HEIGHT - 20.0f};
    std::string fps_text = get_fps(last_time);
    draw_text("FPS: " + fps_text, pos, color);

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}