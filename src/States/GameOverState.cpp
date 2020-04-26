/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** file
*/

#include "GameOverState.hpp"

#define HEIGHT 40 * 20
#define WIDTH 60 * 20

GameOverState::GameOverState(StateMachine &machine, sf::RenderWindow& window, bool replace)
        : State{ machine, window, replace }
{
    m_bgTex.loadFromFile("resources/background_gameover.png");
    m_bg.setTexture( m_bgTex, true );
    m_font.loadFromFile("resources/pixel.ttf");

    m_text.setFont(m_font);
    m_text.setFillColor(sf::Color::White);
    m_text.setString("Game Over !!");
    m_text.setPosition((800 / 2) - ((17 * 14)/2), 250.f);
    m_text.setCharacterSize(30);

    r_text.setFont(m_font);
    r_text.setFillColor(sf::Color::White);
    r_text.setString("Press space to reload the game!");
    r_text.setPosition((800 / 2) - ((17 * 31)/2), 500.f);
    r_text.setCharacterSize(30);

    // Start off opaque
    m_alpha = sf::Color{ 0, 0, 0, 255 };

    // Fill the fader surface with black
    m_fader.setFillColor( m_alpha );
    m_fader.setSize( static_cast<sf::Vector2f>( m_bgTex.getSize() ) );

    std::cout << "GameOverState Init" << std::endl;
}

GameOverState::~GameOverState()
{
    std::cout << "GameOverState : dtor" << std::endl;
}

void GameOverState::pause()
{
    std::cout << "GameOverState Pause" << std::endl;
}

void GameOverState::update()
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
            {
                switch( event.key.code )
                {
                    case sf::Keyboard::Space:
                        m_next = StateMachine::build<GameState>( m_machine, m_window, true );
                        break;

                    case sf::Keyboard::Escape:
                        m_machine.quit();
                        break;

                    default:
                        break;
                }
                break;
            }

            default:
                break;
        }
    }
    if( m_alpha.a != 0 )
        m_alpha.a--;

    m_fader.setFillColor( m_alpha );
}

void GameOverState::resume()
{
    std::cout << "ScoreState Resume" << std::endl;
}

void GameOverState::defaultWindow()
{
    sf::View view = m_window.getDefaultView();
    view.zoom(0.5f);
    m_window.setView(view);
}

void GameOverState::draw()
{
    m_window.clear();
    m_window.draw(m_bg);
    m_window.draw(m_text);
    m_window.draw(r_text);
    defaultWindow();

    if( m_alpha.a != 0 ) {
        m_window.draw(m_fader);
    }
    m_window.display();
}
    /*std::stringstream displayscore;
    displayscore << "Score: " << this->m_machine._score;
    this->_lib_graphic->displayText(displayscore.str(), "resources/pixel.ttf",
                                    {(WIDTH / 2) - ((28 * displayscore.str().length()) / 2),((HEIGHT / 2) -
 }*/