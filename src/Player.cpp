#include "../includes/Game.hpp"

Player::Player()
{
    this->x = WINDOW_WIDTH / 2;
    this->y = WINDOW_HEIGHT / 2;

    this->size = {10, 10};
}

Player::~Player() {};

void Player::move(int key)
{
    int speed = 5;
    if (key == W)
        this->y -= speed;
    else if (key == S)
        this->y += speed;
    else if (key == A)
        this->x -= speed;
    else if (key == D)
        this->x += speed;
}