#include <sstream>
#include <iostream>

#include "GameState.h"
#include "Definitions.h"
#include "GameOverState.h"

//constructors
GameState::GameState(GameDataRef data) : _data(data)
{

}


//methodes
void GameState::init()
{
	//font
	this->_data->assetManager.LoadFont("Flappy Font", FLAPPY_FONT_FAILEPATH);

	//Game background
	this->_data->assetManager.LoadTextures("Game Background", GAME_BACKGROUND_FILEPATH);
	this->_backgroundSprite.setTexture(this->_data->assetManager.GetTexture("Game Background"));

	//pipes
	this->_data->assetManager.LoadTextures("Pipe Up", PIPE_UP_FILEPATH);
	this->_data->assetManager.LoadTextures("Pipe Down", PIPE_DOWN_FILEPATH);
	this->_data->assetManager.LoadTextures("Land Sprite", LAND_FILEPATH);
	this->_data->assetManager.LoadTextures("Scoring Pipe", SCORING_PIPE_FILEPATH);

	//bird
	this->_data->assetManager.LoadTextures("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
	this->_data->assetManager.LoadTextures("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
	this->_data->assetManager.LoadTextures("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
	this->_data->assetManager.LoadTextures("Bird Frame 4", BIRD_FRAME_4_FILEPATH);

	pipe = new Pipe( _data );
	land = new Land( _data );
	bird = new Bird(_data);
	flash = new Flash(_data);
	gui = new Gui(_data);

	_score = 0;
	gui->updateScore(_score);
	_gameState = GameStates::eReady;

	_hitBuffer.loadFromFile("Ressources/audio/Hit.wav");
	_pointBuffer.loadFromFile("Ressources/audio/Point.wav");
	_wingBuffer.loadFromFile("Ressources/audio/Wing.wav");

	_hitSound.setBuffer(_hitBuffer);
	_pointSound.setBuffer(_pointBuffer);
	_wingSound.setBuffer(_wingBuffer);
}

void GameState::handleInput()
{
	sf::Event ev;
	while (this->_data->window.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
			_data->window.close();
	}

	if (this->_data->inputManager.isSpriteClicked(this->_backgroundSprite, sf::Mouse::Left, this->_data->window))
	{
		if (_gameState != GameStates::eGameOver)
		{
			_gameState = GameStates::ePlaying;
			bird->tap();
		}
	}
}

void GameState::update(float dt)
{
	//update land & animate bird while !GameOver
	if (_gameState != GameStates::eGameOver)
	{
		land->moveLand(dt);
		bird->animate(dt);
	}

	if (_gameState == GameStates::ePlaying)
	{
		pipe->movePipes(dt);

		_wingSound.setLoop(true);
		_wingSound.play();
		//scoring pipes
		std::vector<sf::Sprite> &scoringSprites = pipe->getScoringPipes();

		for (size_t i = 0; i < scoringSprites.size(); i++)
		{
			if (_collision.checkSpriteCollision(bird->getSprite(), 0.625f, scoringSprites[i], 1.f))
			{
				_score++;
				scoringSprites.erase(scoringSprites.begin() + i);
				gui->updateScore(_score);
				_pointSound.play();
			}
		}

		//spawning pipes
		if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
		{
			this->pipe->randomisePipeOffset();

			this->pipe->spawnInvisiblePipe();
			this->pipe->spawnScoringPipe();
			this->pipe->spawnBottomPipe();
			this->pipe->spawnTopPipe();

			_clock.restart();
		}
		
		bird->update(dt);

		//collision with land
		std::vector<sf::Sprite> landSprites = land->getSprites();

		for (size_t i = 0; i < landSprites.size(); i++)
		{
			if (_collision.checkSpriteCollision(bird->getSprite(), 0.7f, landSprites[i], 1.f))
			{
				_gameState = GameStates::eGameOver;
				_clock.restart();
				_wingSound.stop();
				_hitSound.play();
			}
		}

		//collision with pipes
		std::vector<sf::Sprite> pipesSprites = pipe->getPipes();

		for (size_t i = 0; i < pipesSprites.size(); i++)
		{
			if (_collision.checkSpriteCollision(bird->getSprite(), 0.625f, pipesSprites[i], 1.f))
			{
				_gameState = GameStates::eGameOver;
				_clock.restart();
				_wingSound.stop();
				_hitSound.play();
			}
		}	
	}
	
	//GameOver State
	if (_gameState == GameStates::eGameOver)
	{
		flash->Show(dt);
		
		if (_clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER)
		{
			_data->stateMachine.addState(StateRef(new GameOverState(_data, _score)), true);
		}
	}
}

void GameState::render(float dt)
{
	this->_data->window.clear();

	this->_data->window.draw(_backgroundSprite);
	this->pipe->drawPipes();
	this->land->drawLand();
	this->bird->draw();
	this->flash->draw();
	this->gui->draw();

	this->_data->window.display();
}
