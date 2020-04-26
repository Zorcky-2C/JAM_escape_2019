/*
** EPITECH PROJECT, 2020
** JAM_escape_2019
** File description:
** file
*/

#include "Bird.hpp"

Bird::Bird()
{
    this->setSpriteSheet("resources/bird_right.png");
    this->setTextureRect((sf::IntRect){0, 16, 16, 16});
    this->getSprite().setTextureRect(this->getTextureRect());
    this->getPos().x = -100;
    this->getPos().y = 100;
}

void Bird::Move(float x, float y)
{
    sf::Time time;
    float seconds;
    static int tick = 0;
    static float moove_up_and_down = 2;

    time = this->getClock().getElapsedTime();
    seconds = time.asMicroseconds();
    if (seconds > 1000.0) {
        if (tick > 50) {
            moove_up_and_down = -moove_up_and_down;
            tick = 0;
        }
        ++tick;
        this->getPos().y += moove_up_and_down;
    }
    if (seconds > 1000.0) {
        if (this->getPos().x > 800) {
            this->getPos().x = -100;
        }
        this->getPos().x += 5;
    }
    this->getSprite().setPosition(this->getPos());
}

void Bird::Update()
{
    sf::Time time;
    float seconds;

    time = this->getClock().getElapsedTime();
    seconds = time.asMicroseconds();
    if (seconds > 100000.0) {
        if (this->getTextureRect().left >= 16 * 7)
            this->getTextureRect().left = 0;
        this->getTextureRect().left += 16;
        this->getSprite().setTextureRect(this->getTextureRect());
        this->getClock().restart();
    }
}