#include <iostream>
#include "Pipe.h"

//constructor
Pipe::Pipe(GameDataRef data) : _data(data)
{
	_landHeight = _data->assetManager.GetTexture("Land Sprite").getSize().y;

	_pipeSpawnYOffset = 0;
}


//methodes
void Pipe::spawnBottomPipe()
{
	sf::Sprite bottomPipeSprite(_data->assetManager.GetTexture("Pipe Up"));
	
	bottomPipeSprite.setPosition(
		_data->window.getSize().x + 20,
		_data->window.getSize().y - bottomPipeSprite.getGlobalBounds().height - _pipeSpawnYOffset);

	_pipesSprites.push_back(bottomPipeSprite);
}

void Pipe::spawnTopPipe()
{
	sf::Sprite topPipeSprite(_data->assetManager.GetTexture("Pipe Down"));
	
	topPipeSprite.setPosition(
		_data->window.getSize().x + 20,
		- _pipeSpawnYOffset);

	_pipesSprites.push_back(topPipeSprite);
}

void Pipe::spawnInvisiblePipe()
{
	sf::Sprite invisiblePipeSprite(_data->assetManager.GetTexture("Pipe Up"));

	invisiblePipeSprite.setPosition(
		_data->window.getSize().x, 
		_data->window.getSize().y - invisiblePipeSprite.getGlobalBounds().height
		);

	invisiblePipeSprite.setColor(sf::Color(0, 0, 0, 0));

	_pipesSprites.push_back(invisiblePipeSprite);
}

void Pipe::spawnScoringPipe()
{
	sf::Sprite scoringSprite(_data->assetManager.GetTexture("Scoring Pipe"));

	scoringSprite.setPosition(
		_data->window.getSize().x + scoringSprite.getGlobalBounds().width * 2, 
		0
	);
	
	_scoringPipes.push_back(scoringSprite);
}

void Pipe::movePipes(float dt)
{
	for (size_t i = 0; i < _pipesSprites.size(); i++)
	{
		if ((_pipesSprites[i].getPosition().x + _pipesSprites[i].getGlobalBounds().width) < -10.f)
			_pipesSprites.erase(_pipesSprites.begin() + i);	
		
		float movementSpeed = PIPE_MOVEMENT_SPEED * dt;

		_pipesSprites[i].move(-movementSpeed, 0);
	}

	for (size_t i = 0; i < _scoringPipes.size(); i++)
	{
		if ((_scoringPipes[i].getPosition().x + _scoringPipes[i].getGlobalBounds().width) < -10.f)
			_scoringPipes.erase(_scoringPipes.begin() + i);

		float movementSpeed = PIPE_MOVEMENT_SPEED * dt;

		_scoringPipes[i].move(-movementSpeed, 0);
	}
}

void Pipe::drawPipes()
{
	for (size_t i = 0; i < _pipesSprites.size(); i++)
	{
		this->_data->window.draw(_pipesSprites[i]);
	}
}

void Pipe::randomisePipeOffset()
{
	_pipeSpawnYOffset = rand() % (_landHeight + 1);
}

const std::vector<sf::Sprite> &Pipe::getPipes() const
{
	return _pipesSprites;
}

std::vector<sf::Sprite> &Pipe::getScoringPipes()
{
	return _scoringPipes;
}

