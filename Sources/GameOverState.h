#ifndef DEF_GAME_OVER_STATE
#define DEF_GAME_OVER_STATE

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

class GameOverState : public State
{
private:
	//attributes
	GameDataRef _data;
	sf::Sprite _backgroundSprite;
	sf::Sprite _gameOverTitle;
	sf::Sprite _gameOverContainer;
	sf::Sprite _retryButton;
	sf::Sprite _medalSprite;
	sf::Text _scoreText;
	sf::Text _highScoreText;

	int _score;
	int _highScore;

public:
	//constructors
	GameOverState(GameDataRef data, int score);

	//methodes
	void init();
	void handleInput();

	void update(float dt);
	void render(float dt);
};

#endif // !DEF_GAME_OVER_STATE