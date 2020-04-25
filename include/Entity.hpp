/*
** EPITECH PROJECT, 2020
** JAM_escape_2019
** File description:
** file
*/

#ifndef JAM_ESCAPE_2019_ENTITY_HPP
#define JAM_ESCAPE_2019_ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity
{
    public:
        Entity();
        virtual void Move(float x, float y) = 0;
        virtual void Update() = 0;

        void setSpriteSheet(std::string path);

        void setTexture(sf::Texture texture) { _texture = texture; }
        void setSprite(sf::Sprite sprite) { _sprite = sprite; }
        void setTextureRect(sf::IntRect rect) { _rect = rect; }
        sf::Texture &getTexture() { return (this->_texture); }
        sf::Sprite &getSprite() { return (this->_sprite); }
        sf::IntRect &getTextureRect() { return (this->_rect); }
        sf::Clock &getClock() { return (this->_clock); }

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::IntRect _rect;
        sf::Clock _clock;
};

#endif //JAM_ESCAPE_2019_ENTITY_HPP
