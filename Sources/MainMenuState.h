#ifndef DEF_MAIN_MENU_STATE
#define DEF_MAIN_MENU_STATE

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

class MainMenuState : public State
{
private:
	//attributes
	GameDataRef _data;

	sf::Sprite _backgroundSprite;
	sf::Sprite _title;
	sf::Sprite _playButton;

public:
	//constructors
	MainMenuState(GameDataRef data);

	//methodes
	void init();
	void handleInput();

	void update(float dt);
	void render(float dt);
};

#endif // !DEF_MAIN_MENU_STATE