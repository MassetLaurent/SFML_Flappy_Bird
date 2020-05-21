#include "InputManager.h"

bool InputManager::isSpriteClicked(sf::Sprite _sprite, sf::Mouse::Button _mouseButton, sf::RenderWindow & _windowRef)
{
	if (sf::Mouse::isButtonPressed(_mouseButton))
	{
		sf::IntRect _spriteRect(
			_sprite.getPosition().x, _sprite.getPosition().y,
			_sprite.getGlobalBounds().width, _sprite.getGlobalBounds().height
		);

		if (_spriteRect.contains(sf::Mouse::getPosition(_windowRef)))
			return true;
	}

	return false;
}

sf::Vector2i InputManager::getMousePosition(sf::RenderWindow & _windowRef)
{
	return sf::Mouse::getPosition(_windowRef);
}
