/*
** EPITECH PROJECT, 2020
** JAM_escape_2019
** File description:
** game
*/

#include "Application.hpp"

void Application::run()
{
	// Create render window
	m_window.create( sf::VideoMode{800, 600}, "Game Escape", sf::Style::Titlebar | sf::Style::Close );
	m_window.setFramerateLimit( 30 );

	m_machine.is_win = true;

	m_machine.run( StateMachine::build<MenuState>( m_machine, m_window, true ) );

	m_machine.music.openFromFile("resources/music.ogg");
	m_machine.music.setVolume(20);
    m_machine.music.play();

	// Main loop
	while( m_machine.running() )
	{
		m_machine.nextState();
		m_machine.update();
		m_machine.draw();
	}

	// Leaving the scope of 'Application' will cleanup the engine
}
