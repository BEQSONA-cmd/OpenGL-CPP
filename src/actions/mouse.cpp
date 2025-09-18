#include "../../includes/Game.hpp"

void Game::update_camera()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Clamp cam_angle_x to avoid flipping at the poles
    if (cam_angle_x > 89.0f) cam_angle_x = 89.0f;
    if (cam_angle_x < -89.0f) cam_angle_x = -89.0f;

    // Wrap cam_angle_y to stay within 0-360 degrees
    if (cam_angle_y > 360.0f) cam_angle_y -= 360.0f;
    if (cam_angle_y < 0.0f) cam_angle_y += 360.0f;

    float rad_y = cam_angle_y * 3.14159f / 180.0f;
    float rad_x = cam_angle_x * 3.14159f / 180.0f;

    float camX = cam_distance * sin(rad_y) * cos(rad_x);
    float camY = cam_distance * sin(rad_x);
    float camZ = cam_distance * cos(rad_y) * cos(rad_x);

    gluLookAt(camX, camY, camZ, 0, 0, 0, 0, 1, 0);
}

void Game::mouse_callbacks()
{
    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        if(mouse_pressed)
        {
            cam_angle_y += (float)(xpos - last_mouse_x) * 0.3f;
            cam_angle_x += (float)(ypos - last_mouse_y) * 0.3f;
        }

        last_mouse_x = xpos;
        last_mouse_y = ypos;
        mouse_pressed = true;
    }
    else
    {
        mouse_pressed = false;
    }
}

void Game::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    Game* game = static_cast<Game*>(glfwGetWindowUserPointer(window));
    if (!game) return;
    (void)xoffset;
    // Zoom in/out by adjusting cam_distance
    game->cam_distance -= (float)yoffset;  // scroll up -> zoom in, scroll down -> zoom out

    // Clamp camera distance
    if (game->cam_distance < 5.0f) game->cam_distance = 5.0f;    // min zoom
    if (game->cam_distance > 100.0f) game->cam_distance = 100.0f; // max zoom
}
