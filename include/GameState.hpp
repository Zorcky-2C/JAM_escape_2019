/*
** EPITECH PROJECT, 2020
** JAM_escape_2019
** File description:
** GameState
*/

#ifndef GAMESTATE_HPP_
#define GAMESTATE_HPP_

#include "State.hpp"
#include "StateMachine.hpp"
#include "MenuState.hpp"
#include <SFML/Graphics.hpp>
#include <chrono>
#include <vector>
#include <iostream>
#include <string>

class StateMachine;

namespace sf
{
	class RenderWindow;
}

class GameState : public State
{
    public:
        GameState( StateMachine &game, sf::RenderWindow& _window, bool replace = true);
        ~GameState();
        void pause();
        void resume();
        void update();
        void draw();
        void DisplayMap();
        void DisplayPlayer();
        void DisplayTime();
        void setRect(int x, int y, int index_x_pos, int index_y_pos);
        void MovePlayer();
        void check_player_collision();
        void display_ghosts();
        void move_player();

    private:
        sf::Texture _wall;
        sf::Texture _player;
        sf::Sprite s_wall;
        sf::Sprite s_player;

        sf::Clock timer_clock;
        sf::Clock player_clock;
        sf::Time _seed;
        sf::Font _font;
        sf::Text _text;
        sf::View player_view;
        sf::IntRect _rect;

        const float player_speed = 500;
        int _maxtime;
        int _level;
};

#endif /* !GAMESTATE_HPP_ */
