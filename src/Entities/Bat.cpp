/*
** EPITECH PROJECT, 2020
** JAM_escape_2019
** File description:
** file
*/

#include "Bat.hpp"

Bat::Bat()
{
    this->setSpriteSheet("resources/bat.png");
    this->setTextureRect((sf::IntRect){0, 166, 32, 21});
    this->getSprite().setTextureRect(this->getTextureRect());
}

void Bat::Move(float x, float y)
{
    this->getSprite().setPosition(x, y);
}

void Bat::Update()
{
    sf::Time time;
    float seconds;

    time = this->getClock().getElapsedTime();
    seconds = time.asMicroseconds();
    if (seconds > 100000.0) {
        if (this->getTextureRect().left >= 32 * 9)
            this->getTextureRect().left = 0;
       this->getTextureRect().left += 32;
        this->getSprite().setTextureRect(this->getTextureRect());
        this->getClock().restart();
    }
}