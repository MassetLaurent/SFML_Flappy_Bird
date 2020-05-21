#ifndef DEF_GUI
#define DEF_GUI

#include <SFML/Graphics.hpp>

#include "Definitions.h"
#include "Game.h"

class Gui
{
private:
	GameDataRef data;
	sf::Text scoreTxt;

public:
	Gui(GameDataRef _data);

	void updateScore(int _score);
	void draw();
};
#endif // !DEF_GUI
