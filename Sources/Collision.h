#ifndef DEF_COLLISION
#define DEF_COLLISION

#include <SFML/Graphics.hpp>

class Collision
{
private:

public:
	//constructor
	Collision();

	bool checkSpriteCollision(sf::Sprite _spriteA, sf::Sprite _spriteB);
	bool checkSpriteCollision(sf::Sprite _spriteA, float scaleA, sf::Sprite _spriteB, float scaleB);
};
#endif // !DEF_COLLISION