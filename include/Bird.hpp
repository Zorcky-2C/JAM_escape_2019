/*
** EPITECH PROJECT, 2020
** JAM_escape_2019
** File description:
** file
*/

#ifndef JAM_ESCAPE_2019_BIRD_HPP
#define JAM_ESCAPE_2019_BIRD_HPP

#include "Entity.hpp"

class Bird : public Entity
{
public:
    Bird();
    ~Bird();
    void Move(float x, float y);
    void Update();
};

#endif //JAM_ESCAPE_2019_BIRD_HPP
