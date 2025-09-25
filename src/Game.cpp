#include "../includes/Game.hpp"

void Game::init_opengl()
{
    if (!glfwInit())
        return;

    this->window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, this->Name.c_str(), NULL, NULL);

    if (!this->window) {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(this->window);

    // Set viewport
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    glfwSetWindowUserPointer(this->window, this); // so callback knows this Game instance
    glfwSetScrollCallback(this->window, Game::scroll_callback);
    glfwSetCharCallback(this->window, [](GLFWwindow* window, unsigned int codepoint){
        Game* game = static_cast<Game*>(glfwGetWindowUserPointer(window));
        if(!game) return;
        game->typed_text += static_cast<char>(codepoint);
    });



    // Projection for 3D
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
        90.0,                                // FOV
        (double)WINDOW_WIDTH / WINDOW_HEIGHT,// Aspect ratio
        0.1,                                 // Near plane
        500.0                                // Far plane (increase)
    );
    glEnable(GL_DEPTH_TEST);

    int argc = 0;
    char *argv[] = {nullptr};
    glutInit(&argc, argv);

    // disable vsync
    glfwSwapInterval(0);
}

void Game::run()
{
    init_opengl();
    double last_time = glfwGetTime();

    glEnable(GL_DEPTH_TEST);

    while (!Keys::Close(this->window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        mouse_callbacks();
        update_camera();
        draw_grid();
        draw_ui(last_time);   

        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }
}
