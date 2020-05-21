#ifndef DEF_FLASH
#define DEF_FLASH

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Definitions.h"

class Flash
{
private:
	GameDataRef _data;
	sf::RectangleShape _shape;

	bool _flashOn;

public:
	//constructor
	Flash(GameDataRef data);

	void Show(float dt);
	void draw();
};

#endif // !DEF_FLASH