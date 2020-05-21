#include "Collision.h"

Collision::Collision()
{
}

bool Collision::checkSpriteCollision(sf::Sprite _spriteA, sf::Sprite _spriteB)
{
	return _spriteA.getGlobalBounds().intersects(_spriteB.getGlobalBounds());
}

bool Collision::checkSpriteCollision(sf::Sprite _spriteA, float scaleA, sf::Sprite _spriteB, float scaleB)
{
	_spriteA.setScale(scaleA, scaleA);
	_spriteB.setScale(scaleB, scaleB);

	return _spriteA.getGlobalBounds().intersects(_spriteB.getGlobalBounds());
}
