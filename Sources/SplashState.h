#ifndef DEF_SPLASHSTATE
#define DEF_SPLASHSTATE

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "State.h"

class SplashState : public State
{
private:
	//attributes
	GameDataRef _data;
	sf::Clock _clock;
	sf::Sprite _backgroundSprite;

public:
	//constructors
	SplashState(GameDataRef data);

	//methodes
	void init();
	void handleInput();

	void update(float dt);
	void render(float dt);
};
#endif // ! DEF_SPLASHSTATE