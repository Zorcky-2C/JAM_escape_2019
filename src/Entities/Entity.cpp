/*
** EPITECH PROJECT, 2020
** JAM_escape_2019
** File description:
** file
*/

#include "Entity.hpp"

Entity::Entity()
{

}

void Entity::setSpriteSheet(std::string path)
{
    this->_texture.loadFromFile(path);
    this->_sprite.setTexture(this->_texture);
    this->_sprite.setScale(3, 3);
}