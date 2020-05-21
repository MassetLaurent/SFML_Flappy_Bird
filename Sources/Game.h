#ifndef DEF_GAME
#define DEF_GAME

#include <iostream>
#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

struct GameData
{
	StateMachine stateMachine;
	sf::RenderWindow window;
	AssetManager assetManager;
	InputManager inputManager;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
private:
	//attributes
	const float dt = 1.f / 60.f;
	sf::Clock clock;
	GameDataRef _data = std::make_shared<GameData>();

public:
	//constructors
	Game(float width, float height, std::string title);

	//methodes
	void run();
};

#endif //! DEF_GAME