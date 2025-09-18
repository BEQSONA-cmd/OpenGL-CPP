#include "../../includes/Game.hpp"

void Game::draw_grid()
{
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f);

    int grid_size = 25;
    for (int i = -grid_size; i <= grid_size; i++)
    {
        // X lines
        glVertex3f((float)i, 0, (float)-grid_size);
        glVertex3f((float)i, 0, (float)grid_size);

        // Z lines
        glVertex3f((float)-grid_size, 0, (float)i);
        glVertex3f((float)grid_size, 0, (float)i);
    }

    glEnd();
}