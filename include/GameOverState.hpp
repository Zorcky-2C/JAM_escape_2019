/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** file
*/

#ifndef JAM_ESCAPE_2019_GAMEOVERSTATE_H
#define JAM_ESCAPE_2019_GAMEOVERSTATE_H

#include "State.hpp"
#include "StateMachine.hpp"
#include <sstream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "PlayState.hpp"

namespace sf
{
    class RenderWindow;
}

class StateMachine;

class GameOverState  : public State
{
public:
    GameOverState( StateMachine& game, sf::RenderWindow& window, bool replace = true );
    ~GameOverState();
    void pause();
    void update();
    void resume();
    void draw();
private:
    sf::Texture m_bgTex;
    sf::Sprite m_bg;
    sf::Text m_text;
    sf::Text r_text;
    sf::Text v_text;
    sf::Text e_text;
    sf::Text d_text;
    sf::Font m_font;
    sf::RectangleShape m_fader;
    sf::Color m_alpha;
};

#endif //JAM_ESCAPE_2019_GAMEOVERSTATE_H
