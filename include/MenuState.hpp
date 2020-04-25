#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "State.hpp"
#include "Bat.hpp"

#include <SFML/Graphics.hpp>

class StateMachine;

namespace sf
{
	class RenderWindow;
}

class MenuState : public State
{
public:
	MenuState( StateMachine& machine, sf::RenderWindow& window, bool replace = true );

	void pause();
	void resume();

	void update();
	void draw();

private:
	sf::Texture m_bgTex;
	sf::Sprite m_bg;

	sf::Font font;
	sf::Text gameName;
	sf::Text playText;
	sf::Text quitText;

	int menuPosition;

	std::vector<Entity*> bats;
};

#endif // MENUSTATE_HPP
