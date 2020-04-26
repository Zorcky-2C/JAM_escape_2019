/*
** EPITECH PROJECT, 2020
** JAM_escape_2019
** File description:
** file
*/

#ifndef JAM_ESCAPE_2019_BAT_HPP
#define JAM_ESCAPE_2019_BAT_HPP

#include "Entity.hpp"

class Bat : public Entity
{
public:
    Bat();
    ~Bat();
    void Move(float x, float y);
    void Update();
};

#endif //JAM_ESCAPE_2019_BAT_HPP
