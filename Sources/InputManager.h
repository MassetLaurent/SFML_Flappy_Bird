#ifndef DEF_INPUTMANAGER
#define DEF_INPUTMANAGER

#include <SFML/Graphics.hpp>

class InputManager
{
private:
	//attributes

public:
	//constructor
	InputManager() { }
	virtual ~InputManager() { }

	//methodes
	bool isSpriteClicked(sf::Sprite _sprite, sf::Mouse::Button _mouseButton, sf::RenderWindow &_windowRef);
	sf::Vector2i getMousePosition(sf::RenderWindow &_windowRef);
};
#endif // !DEF_INPUTMANAGER