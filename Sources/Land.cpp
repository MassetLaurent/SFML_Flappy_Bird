#include "Land.h"
#include "Definitions.h"

//constructor
Land::Land(GameDataRef data) : _data(data)
{
	sf::Sprite landSprite(_data->assetManager.GetTexture("Land Sprite"));
	sf::Sprite landSprite2(_data->assetManager.GetTexture("Land Sprite"));

	landSprite.setPosition(0.f, this->_data->window.getSize().x);
	landSprite2.setPosition(landSprite.getGlobalBounds().width , this->_data->window.getSize().x);

	this->_landSprites.push_back(landSprite);
	this->_landSprites.push_back(landSprite2);
}

//methodes
const std::vector<sf::Sprite>& Land::getSprites() const
{
	return _landSprites;
}

void Land::moveLand(float dt)
{
	for (size_t i = 0; i < _landSprites.size(); i++)
	{
		float movementSpeed = dt * PIPE_MOVEMENT_SPEED;
		_landSprites[i].move(-movementSpeed, 0.f);

		if (_landSprites[i].getPosition().x + _landSprites[i].getGlobalBounds().width < 0.f)			
			_landSprites[i].setPosition(_data->window.getSize().x, _landSprites[i].getPosition().y);
	}
}

void Land::drawLand()
{
	for (size_t i = 0; i < _landSprites.size(); i++)
	{
		_data->window.draw(_landSprites[i]);
	}
}
