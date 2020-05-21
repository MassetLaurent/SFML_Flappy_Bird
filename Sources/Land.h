#ifndef DEF_LAND
#define DEF_LAND

#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.h"
#include "Definitions.h"

class Land
{
private:
	GameDataRef _data;
	std::vector<sf::Sprite> _landSprites;

public:
	//constructor
	Land(GameDataRef data);

	const std::vector<sf::Sprite> &getSprites() const;

	void moveLand(float dt);
	void drawLand();
};


#endif // !DEF_LAND