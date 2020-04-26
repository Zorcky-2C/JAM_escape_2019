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
#include "GameOverState.hpp"
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

template<typename T1,typename T2>
bool check_collision(const T1 &a,const T2 &b){
    sf::FloatRect box1 = a.getGlobalBounds();
    sf::FloatRect box2 = b.getGlobalBounds();
    return box1.intersects(box2);
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
        void win();
        void check_win();

    private:
        sf::Texture _wall;
        sf::Texture _player;
        sf::Texture _door;
        sf::Sprite s_wall;
        sf::Sprite s_player;
        sf::Sprite s_door;
        sf::Texture _bg;
        sf::Sprite s_bg;

        sf::Clock timer_clock;
        sf::Clock player_clock;
        sf::Time _seed;
        sf::Font _font;
        sf::Text _text;
        sf::Text _win;
        sf::View player_view;
        sf::IntRect _rect;
        sf::Vector2f velocity;

        float frametime;
        const float player_speed = 500;
        int _maxtime;
        int _level;
        bool check;
};

#endif /* !GAMESTATE_HPP_ */
