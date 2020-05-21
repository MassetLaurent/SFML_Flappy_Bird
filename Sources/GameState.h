#ifndef DEF_GAME_STATE
#define DEF_GAME_STATE

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "State.h"
#include "Game.h"
#include "Pipe.h"
#include "Land.h"
#include "Bird.h"
#include "Collision.h"
#include "Flash.h"
#include "Gui.h"

class GameState : public State
{
private:
	//attributes
	GameDataRef _data;
	sf::Sprite _backgroundSprite;
	sf::Clock _clock;
	sf::SoundBuffer _hitBuffer;
	sf::SoundBuffer _pointBuffer;
	sf::SoundBuffer _wingBuffer;
	sf::Sound _hitSound;
	sf::Sound _pointSound;
	sf::Sound _wingSound;


	Collision _collision;
	Pipe *pipe;
	Land *land;
	Bird *bird;
	Flash *flash;
	Gui *gui;
	
	int _gameState;
	int _score;

public:
	//constructors
	GameState(GameDataRef data);

	//methodes
	void init();
	void handleInput();

	void update(float dt);
	void render(float dt);
};

#endif // !DEF_GAME_STATE