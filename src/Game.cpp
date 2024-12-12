#include "../includes/Game.hpp"

void Game::init_opengl()
{

    if (!glfwInit())
    {
        std::cerr << RED << "Failed to initialize GLFW" << RESET << std::endl;
        return;
    }

    this->window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, this->Name.c_str(), NULL, NULL);

    if (!this->window)
    {
        std::cerr << RED << "Failed to create GLFW window" << RESET << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(this->window);

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    // Set orthographic projection
    glOrtho(-1, 1, -1, 1, -1, 1);

    // Initialize GLUT
    int argc = 0;
    char *argv[] = {nullptr};
    glutInit(&argc, argv);

    // disable vsync
    // glfwSwapInterval(0);
}


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

void draw_fps(float fps)
{
    std::ostringstream fps_text;

    fps_text << std::fixed << std::setprecision(1) << "FPS: " << fps;

    float text_color[3] = {0.0f, 1.0f, 1.0f};

    Point text_position;
    text_position.x = 0.8f;
    text_position.y = 0.9f;

    draw_text(fps_text.str(), text_position, text_color);
}

double get_fps(double last_time)
{
    static int frame_count;
    double current_time = glfwGetTime();
    double fps = frame_count / (current_time - last_time);
    frame_count++;
    return fps;
}

void draw_square(Point pos, Point size, float color[3])
{
    glBegin(GL_QUADS);

    float x_range = size.x / 2;
    float y_range = size.y / 2;
    glColor3f(1.0f, 1.0f, 0.0f);

    Point square[4];
    square[0] = {-1 + X_TRANS * (pos.x - x_range), 1 - Y_TRANS * (pos.y - y_range)};
    square[1] = {-1 + X_TRANS * (pos.x + x_range), 1 - Y_TRANS * (pos.y - y_range)},
    square[2] = {-1 + X_TRANS * (pos.x + x_range), 1 - Y_TRANS * (pos.y + y_range)},
    square[3] = {-1 + X_TRANS * (pos.x - x_range), 1 - Y_TRANS * (pos.y + y_range)};
    
    int i = 0;
    while(i < 4)
    {
        glVertex2f(square[i].x, square[i].y);
        i++;
    }
    glEnd();
    glBegin(GL_QUADS);

    x_range -= size.x - 1;
    y_range -= size.y - 1;

    glColor3f(color[0], color[1], color[2]);

    square[0] = {-1 + X_TRANS * (pos.x - x_range), 1 - Y_TRANS * (pos.y - y_range)};
    square[1] = {-1 + X_TRANS * (pos.x + x_range), 1 - Y_TRANS * (pos.y - y_range)},
    square[2] = {-1 + X_TRANS * (pos.x + x_range), 1 - Y_TRANS * (pos.y + y_range)},
    square[3] = {-1 + X_TRANS * (pos.x - x_range), 1 - Y_TRANS * (pos.y + y_range)};

    i = 0;
    while(i < 4)
    {
        glVertex2f(square[i].x, square[i].y);
        i++;
    }
    
    glEnd();

    // Draw the outline
}

std::vector<std::string> get_map()
{
    std::vector<std::string> map = {
        "11111111111",
        "10000000001",
        "10000000001",
        "10000000001",
        "10000000001",
        "10000000001",
        "10000000001",
        "10000000001",
        "10000000001",
        "11111111111"
    };

    return(map);
}

void draw_map(std::vector<std::string> map)
{
    float color[3] = {0.0f, 0.0f, 1.0f};
    Point size = {64, 64};
    Point pos = {0, 0};

    size_t y = 0;

    while (y < map.size())
    {
        size_t x = 0;
        while (x < map[y].size())
        {
            if(map[y][x] == '1')
            {
                pos.x = (x * (size.x) + size.x / 2);
                pos.y = (y * (size.y) + size.y / 2);
                draw_square(pos, size, color);
            }
            x++;
        }
        y++;
    }
}

void Game::run()
{
    init_opengl();
    this->player = Player();

    float color[3] = {1.0f, 1.0f, 0.0f};
    
    std::vector<std::string> map = get_map();

    int key = 0;

    double last_time = glfwGetTime();

    while (!Keys::Close(this->window))
    {
        if ((key = Keys::key_pressed(this->window)))
            player.move(key);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        draw_square({player.x, player.y}, this->player.size, color);
        draw_map(map);

        draw_fps(get_fps(last_time));

        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }
}
