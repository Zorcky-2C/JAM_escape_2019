/*
** EPITECH PROJECT, 2020
** JAM_escape_2019
** File description:
** game
*/

#include "StateMachine.hpp"
#include "MenuState.hpp"
#include "GameState.hpp"
#include "PlayState.hpp"

#include "Bat.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <memory>
#include <iostream>
#include "Bird.hpp"

const int ScreenX = 800;
const int ScreenY = 600;

MenuState::MenuState( StateMachine& machine, sf::RenderWindow& window, bool replace )
: State{ machine, window, replace }
{
	m_bgTex.loadFromFile( "resources/background.png" );

	m_bg.setTexture( m_bgTex, true );

	font.loadFromFile("resources/pixel.ttf");

	gameName.setString("Escape the Maze!");
	gameName.setFont(font);
	gameName.setCharacterSize(65);
	gameName.setPosition((800 / 2) - ((38 * 16) / 2), 120);
	gameName.setFillColor(sf::Color::White);

	playText.setString("Play Game");
	playText.setFont(font);
	playText.setCharacterSize(51);
	playText.setPosition((800 / 2) - ((30 * 9) / 2), 260);
	playText.setFillColor(sf::Color::White);

	quitText.setString("Quit");
	quitText.setFont(font);
	quitText.setCharacterSize(51);
	quitText.setPosition((800 / 2) - ((30 * 4) / 2), 350);
	quitText.setFillColor(sf::Color::White);

	this->menuPosition = 0;

	for (int i = 0; i < 1; i++) {
	    Bat *bat = new Bat();
	    bat->setSpriteSheet("resources/bat.png");
	    this->bats.push_back(bat);
	}

    for (int i = 0; i < 1; i++) {
        Bird *bird = new Bird();
        bird->setSpriteSheet("resources/bird_right.png");
        this->birds.push_back(bird);
    }

    std::srand(std::time(0));
    for (int i = 0; i < 100; i++) {
        sf::RectangleShape rectangle;
        rectangle.setFillColor((sf::Color){42,52,62, 150});
        rectangle.setSize(sf::Vector2f((rand()%15)/10.f+1,(rand()%500)/10.f+3));
		rectangles.push_back(rectangle);
		rectangles[i].setPosition(sf::Vector2f(rand()%ScreenX,rand()%ScreenY));
		speed.push_back((rectangles[i].getSize().x)*rectangles[i].getSize().x);
	}

	std::cout << "MenuState Init" << std::endl;
}

void MenuState::pause()
{
	std::cout << "MenuState Pause" << std::endl;
}

void MenuState::resume()
{
	std::cout << "MenuState Resume" << std::endl;
}

void MenuState::update()
{
	sf::Event event;

	while( m_window.pollEvent( event ) )
	{
		switch( event.type )
		{
			case sf::Event::Closed:
				m_machine.quit();
				break;

			case sf::Event::KeyPressed:
				switch( event.key.code )
				{
					case sf::Keyboard::Escape:
						m_machine.quit();
						break;

					case sf::Keyboard::Up:
						if (this->menuPosition == 0)
						    this->menuPosition = 1;
						else if (this->menuPosition == 1)
                            this->menuPosition = 0;
						break;

					case sf::Keyboard::Down:
						if (this->menuPosition == 1)
						    this->menuPosition = 0;
						else if (this->menuPosition == 0)
                            this->menuPosition = 1;
						break;

					case sf::Keyboard::Enter:
						if (this->menuPosition == 1)
						    m_machine.quit();
						else if (this->menuPosition == 0)
                           m_next = StateMachine::build<GameState>( m_machine, m_window, false );
						break;

					default:
						break;
				}
				break;

			default:
				break;
		}
	}
}

void MenuState::draw()
{
	// Clear the previous drawing
	m_window.clear();
	m_window.draw( m_bg );

	for (int i = 0; i < rectangles.size(); i++) {
        if (rectangles[i].getPosition().y <= ScreenY)
            rectangles[i].setPosition(rectangles[i].getPosition().x, rectangles[i].getPosition().y + speed[i] + spd);
        else {
            rectangles[i].setPosition(rectangles[i].getPosition().x, -40);
        }
    }

    for (int i = 0; i < rectangles.size(); i++) {
        m_window.draw(rectangles[i]);
    }

	if (this->menuPosition == 0) {
	    quitText.setFillColor(sf::Color::White);
	    playText.setFillColor(sf::Color::Yellow);
	}
	else if (this->menuPosition == 1) {
	    playText.setFillColor(sf::Color::White);
        quitText.setFillColor(sf::Color::Yellow);
	}

	for (auto bat = bats.begin(); bat != bats.end(); bat++) {
        (*bat)->Update();
        (*bat)->Move(10, 10);
        m_window.draw((*bat)->getSprite());
	}

    for (auto bird = birds.begin(); bird != birds.end(); bird++) {
        (*bird)->Update();
        (*bird)->Move(10, 10);
        m_window.draw((*bird)->getSprite());
    }

	m_window.draw(this->gameName);
	m_window.draw(this->playText);
	m_window.draw(this->quitText);
	m_window.display();
}
