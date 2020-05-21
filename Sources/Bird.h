#ifndef DEF_BIRD
#define DEF_BIRD

#include <vector>
#include <SFML/Graphics.hpp>

#include "Definitions.h"
#include "Game.h"

class Bird
{
private:
	//attributes
	GameDataRef _data;
	std::vector<sf::Texture> _animationFrames;
	sf::Sprite _birdSprite;
	sf::Clock _clock;
	sf::Clock _movementClock;
	unsigned int _animationIterator;
	int _birdState;
	float _rotation;

public:
	//methodes
	Bird(GameDataRef data);

	const sf::Sprite &getSprite() const;
	
	void animate(float dt);
	void update(float dt);
	void tap();
	void draw();
};

#endif // !DEF_BIRD