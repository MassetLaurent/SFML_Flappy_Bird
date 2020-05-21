#include <sstream>
#include <iostream>
#include <fstream>

#include "GameOverState.h"
#include "Definitions.h"
#include "GameState.h"

//constructors
GameOverState::GameOverState(GameDataRef data, int score) : _data(data), _score(score)
{

}


//methodes
void GameOverState::init()
{
	std::fstream file;
	file.open(HIGHSCORE_FILEPATH);

	if (file.is_open())
	{
		while (!file.eof())
		{
			file >> _highScore;
		}
	}
	file.close();

	std::ofstream writeFile(HIGHSCORE_FILEPATH);

	if (writeFile.is_open())
	{
		if (_score > _highScore)
			_highScore = _score;
		
		writeFile << _highScore;
	}

	writeFile.close();

	//background
	this->_data->assetManager.LoadTextures("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
	this->_backgroundSprite.setTexture(this->_data->assetManager.GetTexture("Game Over Background"));
	   
	//Game Over Background
	this->_data->assetManager.LoadTextures("Game Over Body", GAME_OVER_BODY_FILEPATH);
	this->_gameOverContainer.setTexture(this->_data->assetManager.GetTexture("Game Over Body"));

	_gameOverContainer.setPosition(
		(_data->window.getSize().x /2.f) - _gameOverContainer.getGlobalBounds().width / 2.f,
		(_data->window.getSize().y / 2.f) - _gameOverContainer.getGlobalBounds().height/ 2.f
		);

	//Game Over Title
	this->_data->assetManager.LoadTextures("Game Over Title", GAME_OVER_TITLE_FILEPATH);
	this->_gameOverTitle.setTexture(this->_data->assetManager.GetTexture("Game Over Title"));

	_gameOverTitle.setPosition(
		(_data->window.getSize().x / 2.f) - _gameOverTitle.getGlobalBounds().width / 2.f,
		(_gameOverContainer.getPosition().y) - _gameOverTitle.getGlobalBounds().height * 1.2f
		);

	//Play button for retry
	this->_retryButton.setTexture(this->_data->assetManager.GetTexture("Play Button"));

	_retryButton.setPosition(
		(_data->window.getSize().x / 2.f) - _retryButton.getGlobalBounds().width / 2.f,
		(_gameOverContainer.getPosition().y) + _gameOverContainer.getGlobalBounds().height + _retryButton.getGlobalBounds().height / 5.f
		);

	//score position on the container
	_scoreText.setFont(_data->assetManager.GetFont("Flappy Font"));
	_scoreText.setString(std::to_string(_score));
	_scoreText.setCharacterSize(56);
	_scoreText.setFillColor(sf::Color::White);
	_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
	_scoreText.setPosition(
		_gameOverContainer.getPosition().x + _gameOverContainer.getGlobalBounds().width - 105.f,
		_gameOverContainer.getPosition().y + 105.f
		);

	//HIGH score position on the container
	_highScoreText.setFont(_data->assetManager.GetFont("Flappy Font"));
	_highScoreText.setString(std::to_string(_highScore));
	_highScoreText.setCharacterSize(56);
	_highScoreText.setFillColor(sf::Color::White);
	_highScoreText.setOrigin(_highScoreText.getGlobalBounds().width / 2, _highScoreText.getGlobalBounds().height / 2);
	_highScoreText.setPosition(
		_gameOverContainer.getPosition().x + _gameOverContainer.getGlobalBounds().width - 105.f,
		_gameOverContainer.getPosition().y + 205.f
	);

	//medals
	this->_data->assetManager.LoadTextures("Bronze Medal", BRONZE_MEDAL_FILEPATH);
	this->_data->assetManager.LoadTextures("Silver Medal", SILVER_MEDAL_FILEPATH);
	this->_data->assetManager.LoadTextures("Gold Medal", GOLD_MEDAL_FILEPATH);
	this->_data->assetManager.LoadTextures("Platinum Medal", PLATINUM_MEDAL_FILEPATH);

	if(_score >= PLATINUM_MEDAL_SCORE)
		_medalSprite.setTexture(_data->assetManager.GetTexture("Platinum Medal"));

	else if(_score >= GOLD_MEDAL_SCORE)
		_medalSprite.setTexture(_data->assetManager.GetTexture("Gold Medal"));

	else if(_score >= SILVER_MEDAL_SCORE)
		_medalSprite.setTexture(_data->assetManager.GetTexture("Silver Medal"));

	else if (_score >= BRONZE_MEDAL_SCORE)
		_medalSprite.setTexture(_data->assetManager.GetTexture("Bronze Medal"));

	_medalSprite.setPosition(
		_gameOverContainer.getPosition().x + 60,
		_gameOverContainer.getPosition().y + 100
	);

}


void GameOverState::handleInput()
{
	sf::Event ev;
	while (this->_data->window.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
			_data->window.close();
	}

	if (_data->inputManager.isSpriteClicked(_retryButton, sf::Mouse::Left, _data->window))
		_data->stateMachine.addState(StateRef(new GameState(_data)), true);
}

void GameOverState::update(float dt)
{
}

void GameOverState::render(float dt)
{
	this->_data->window.clear();

	this->_data->window.draw(_backgroundSprite);
	this->_data->window.draw(_gameOverContainer);
	this->_data->window.draw(_gameOverTitle);
	this->_data->window.draw(_retryButton);

	this->_data->window.draw(_scoreText);
	this->_data->window.draw(_highScoreText);
	this->_data->window.draw(_medalSprite);

	this->_data->window.display();
}
