/*
** EPITECH PROJECT, 2020
** JAM_escape_2019
** File description:
** GameState
*/

#include "GameState.hpp"

std::vector<std::string> Map = {
    "1S11111111111111111111111111111111111111111111111111111111111",
    "1 1     1   1     1       1 1       1       1     1         1",
    "1 1 111 1 1 1 1 1 1 11111 1 1 111 1 1 11111 11111 1 111 11111",
    "1 1   1   1 1 1 1   1     1     1 1   1   1       1 1 1     1",
    "1 1 1 1111111 1 11111 11111 11111 11111 1 1111111 1 1 11111 1",
    "1 1 1         1     1   1 1   1   1     1     1   1 1   1   1",
    "1 111 1111111111111 111 1 1 111 111 111111111 11111 111 1 1 1",
    "1   1 1     1       1   1   1   1   1   1   1       1   1 1 1",
    "111 1 1 111 1 1111111 1111111 1 1 111 111 1 111111111 111 1 1",
    "1 1 1 1 1 1 1     1 1 1   1   1 1 1       1       1     1 1 1",
    "1 1 1 1 1 1 111 1 1 1 1 1 1 111 1 1 1111111 11111 11111 1 1 1",
    "1 1 1 1 1 1   1 1 1 1   1 1 1   1 1 1   1   1   1       1 1 1",
    "1 1 111 1 111 111 1 11111 1 1 111 1 1 111 111 111111111 1 111",
    "1 1     1   1   1 1     1 1 1   1 1   1   1 1   1       1   1",
    "1 111111111 111 1 1 111 1 1 111 1 11111 111 1 1 1 111111111 1",
    "1     1       1   1   1 1 1 1   1       1     1 1     1     1",
    "1 111 1 1 111111111 1 1 1 1 1 11111111111 11111 111 111 111 1",
    "1 1   1 1         1 1 1 1 1 1 1         1     1   1 1   1 1 1",
    "111 111 11111 111 111 111 1 111 11111 1 1 11111 1 1 1 111 1 1",
    "1   1   1   1   1     1   1 1   1   1 1   1   1 1 1 1 1   1 1",
    "1 1 1 111 11111 11111 1 111 1 111 1 1 11111 1 1 1 1 1 111 1 1",
    "1 1 1 1   1   1 1   1 1 1 1   1 1 1 1 1   1 1   1 1 1 1   1 1",
    "1 111 1 1 1 1 1 1 1 1 1 1 1 111 1 1 1 111 1 1111111 1 1 111 1",
    "1       1 1 1 1 1 1 1 1 1       1 1 1     1 1       1 1     1",
    "1 111111111 1 1 1 1 111 11111 111 1 11111 1 1 1111111 11111 1",
    "1 1   1     1   1 1   1     1 1   1 1 1   1         1     1 1",
    "1 1 111 111111111 111 11111 111 111 1 1 11111111111111111 1 1",
    "1   1   1         1 1     1 1   1   1     1   1     1     1 1",
    "111 1 1 1 111111111 111 111 1 111 1111111 1 111 111 1 11111 1",
    "1   1 1 1 1     1   1   1   1 1 1       1 1   1 1 1   1 1   1",
    "11111 1 1 111 1 1 1 1 111 111 1 1111111 1 111 1 1 11111 1 111",
    "1     1 1 1   1 1 1 1     1   1       1 1     1 1         1 1",
    "1 11111 1 1 111 111 111111111 1 11111 1 1111111 1 111111111 1",
    "1   1   1   1 1     1   1     1     1       1   1 1         1",
    "111 111111111 11111 1 1 1 11111111111111111 1 111 1 1111111 1",
    "1   1             1 1 1   1       1   1     1 1     1     1 1",
    "1 111 11111 1111111 1 11111 11111 1 1 111 111 111111111 1 1 1",
    "1   1   1 1         1     1   1 1   1   1 1         1   1 1 1",
    "1 1 111 1 11111111111 111 111 1 1111111 1 111111111 1 11111 1",
    "1 1     1       1   1 1 1     1       1 1     1   1 1 1     1",
    "1 1111111111111 1 1 1 1 1111111 111 111 11111 1 1 1 1 1 11111",
    "1 1   1       1 1 1 1   1 1       1 1   1   1 1 1   1 1     1",
    "1 1 1 1 1 111 1 1 1 111 1 1 11111 1 1 111 1 1 1 11111 11111 1",
    "1 1 1 1 1 1     1 1   1 1   1   1 1 1 1   1 1   1       1 1 1",
    "1 111 1 1 1111111 111 1 11111 1 111 1 1 111 1111111 111 1 1 1",
    "1   1   1   1   1 1 1         1     1 1   1       1 1 1   1 1",
    "111 111 111 1 1 1 1 11111111111111111 1 1 1111111 1 1 1 111 1",
    "1 1   1 1 1 1 1       1 1             1 1 1         1   1   1",
    "1 111 1 1 1 1 1111111 1 1 111111111111111 111 11111111111 111",
    "1 1   1   1     1   1   1 1         1   1   1   1 1       1 1",
    "1 1 111 111111111 1 11111 11111 1 1 1 1 111 111 1 1 1111111 1",
    "1 1 1 1 1   1     1     1     1 1 1   1     1   1 1   1     1",
    "1 1 1 1 1 1 1 111111111 1 111 111 111 111111111 1 111 111 1 1",
    "1   1   1 1   1     1   1   1   1   1 1       1     1 1   1 1",
    "1 1111111 11111 111 1 11111 111 1 1 111 11111 111 111 1 111 1",
    "1 1       1     1   1 1       1 1 1 1   1   1   1 1   1   1 1",
    "1 1 1111111 111111111 1 1111111 1 1 1 11111 111 111 11111 1 1",
    "1 1   1 1     1       1   1   1 1 1 1     1   1     1     1 1",
    "1 111 1 1 111 1 11111111111 1 1 1 1 11111 111 111111111 111 1",
    "1     1     1               1   1 1                     1   1",
    "11111111111111111111111111111111111111111111111111111111111E1"
};

GameState::GameState(StateMachine &machine, sf::RenderWindow& _window, bool replace)
: State{machine, _window, replace}
{
    std::cout << "GameState : ctor" << std::endl;
    if (!_wall.loadFromFile("img/wall.png")) {
        std::cerr << "Load texture failed" << std::endl;
        exit(84);
    }
    if (!_font.loadFromFile("img/segoeui.ttf")) {
        std::cerr << "Load font failed" << std::endl;
        exit(84);
    }
    _player.loadFromFile("img/player.png");
    s_player.setTexture(_player);

    s_player.setOrigin(32, 32);
    //s_player.setPosition(55, 45);
    //setRect(0, 0, 0, 0);

    sf::View player_view(sf::FloatRect(0, 0, m_window.getSize().x, m_window.getSize().y));
    this->_level = 1;
    this->_maxtime = 90 / this->_level;
}

GameState::~GameState()
{
    std::cout << "GameState : dtor" << std::endl;
}

void GameState::pause()
{
    std::cout << "GameState Pause" << std::endl;
}

void GameState::resume()
{
    std::cout << "GameState Resume" << std::endl;
}

void GameState::DisplayMap()
{
	for (int i = 0; i < 61; i++) {
		for (int j = 0; j < 61; j++) {
            if (Map[i][j] == '1' && Map[i][j] != 'S' && Map[i][j] != 'E') {
                check_player_collision();
                s_wall.setTexture(_wall);
                s_wall.setPosition(((13 / 2) - (13 / 2) + j) * 32, ((16.5 / 2)  - (15.5 / 2) + i) * 32);
                m_window.draw(s_wall);
            }
		}
	}
}

//void GameState::setRect(int x, int y, int index_x_pos, int index_y_pos)
//{
//    _rect.left = x + (index_x_pos * 48);
//    _rect.top = y + (index_y_pos * 48);
//    _rect.height = 48;
//    _rect.width = 48;
//    s_player.setTextureRect(_rect);
//}

void GameState::check_player_collision()
{
    sf::FloatRect p_bounds = s_player.getGlobalBounds();
    sf::FloatRect w_bounds = s_wall.getGlobalBounds();

    if (check_collision(s_player, s_wall)) {
        //bottom
        if (p_bounds.top < w_bounds.top
            && p_bounds.top + p_bounds.height < w_bounds.top + w_bounds.height
            && p_bounds.left < w_bounds.left + w_bounds.width
            && p_bounds.left + p_bounds.width > w_bounds.left) {
            s_player.move(0, -player_speed * frametime);
        }
        //top
        else if (p_bounds.top > w_bounds.top
            && p_bounds.top + p_bounds.height > w_bounds.top + w_bounds.height
            && p_bounds.left < w_bounds.left + w_bounds.width
            && p_bounds.left + p_bounds.width > w_bounds.left) {
            s_player.move(0, player_speed * frametime);
        }
        //right
        if (p_bounds.left < w_bounds.left
            && p_bounds.left + p_bounds.width < w_bounds.left + w_bounds.width
            && p_bounds.top < w_bounds.top + w_bounds.height
            && p_bounds.top + p_bounds.height > w_bounds.top) {
            s_player.move(-player_speed * frametime, 0);
        }
        //left
        else if (p_bounds.left > w_bounds.left
            && p_bounds.left + p_bounds.width > w_bounds.left + w_bounds.width
            && p_bounds.top < w_bounds.top + w_bounds.height
            && p_bounds.top + p_bounds.height > w_bounds.top) {
            s_player.move(player_speed * frametime, 0);
        }
    }
}

void GameState::MovePlayer()
{
    int index_pos = 0;
    velocity.x = 0.f;
    velocity.y = 0.f;

    frametime = player_clock.restart().asSeconds();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        //setRect(96, 0, 0, index_pos);
        //index_pos++;
        s_player.move(0, -player_speed * frametime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        //setRect(0, 0, 0, index_pos);
        //index_pos++;
        s_player.move(0, player_speed * frametime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        //setRect(48, 0, 0, index_pos);
        //index_pos++;
        s_player.move(-player_speed * frametime, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        //setRect(144, 0, 0, index_pos);
        //index_pos++;
        s_player.move(player_speed *frametime, 0);
    }
    //s_player.move(velocity);
    //if (index_pos > 3) {
    //    index_pos = 0;
    //}
}

void GameState::DisplayPlayer()
{
    player_view.setCenter(s_player.getPosition());
    m_window.setView(player_view);
    m_window.draw(s_player);
}

void GameState::DisplayTime()
{
    int timer = 0;
    int time_player = 0;
    int actual_score = 0;
    std::string messageTime;
    std::string messageScore;
    _text.setFont(_font);
    _text.setString("Timer");
    _text.setCharacterSize(20);
    _text.setFillColor(sf::Color::White);

    timer = timer_clock.getElapsedTime().asSeconds();
    time_player = this->_maxtime - timer;
    if (time_player == 0) {
        std::cout << "You have lost! " << std::endl;
        exit(0);
    }
    messageTime = "You have " + std::to_string(time_player) + " seconds left !";
    _text.setPosition(20*20, 20*20);
    _text.setString(messageTime);
    m_window.draw(_text);
}

void GameState::update()
{
    sf::Event event;

	while(m_window.pollEvent(event)) {
		switch(event.type){
            case sf::Event::Closed:
                m_machine.quit();
                break;
            case sf::Event::KeyPressed :{
                switch( event.key.code) {
                    case sf::Keyboard::Escape :
                        m_machine.quit();
                    case sf::Keyboard::M :
						m_next = StateMachine::build<MenuState>(m_machine, m_window, false);
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
}

void GameState::draw()
{
	m_window.clear();

	DisplayMap();
    DisplayTime();
    DisplayPlayer();
    MovePlayer();

	m_window.display();
}