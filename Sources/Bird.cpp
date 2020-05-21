#include "Bird.h"

Bird::Bird(GameDataRef data) : _data(data)
{
	//animation
	_animationIterator = 0;
	_animationFrames.push_back(_data->assetManager.GetTexture("Bird Frame 1"));
	_animationFrames.push_back(_data->assetManager.GetTexture("Bird Frame 2"));
	_animationFrames.push_back(_data->assetManager.GetTexture("Bird Frame 3"));
	_animationFrames.push_back(_data->assetManager.GetTexture("Bird Frame 4"));
	_birdSprite.setTexture(_animationFrames[_animationIterator]);

	//start position
	_birdSprite.setPosition(
		(_data->window.getSize().x / 4) - _birdSprite.getGlobalBounds().width / 2, 
		(_data->window.getSize().y / 2) - _birdSprite.getGlobalBounds().height / 2
		);

	//start State
	_birdState = BIRD_STATE_STILL;

	//set origin in center of bird
	sf::Vector2f origin = sf::Vector2f(
		_birdSprite.getGlobalBounds().width / 2,
		_birdSprite.getGlobalBounds().height / 2
	);

	_birdSprite.setOrigin(origin);

	_rotation = 0.f;
}

const sf::Sprite &Bird::getSprite() const
{
	return _birdSprite;
}

void Bird::animate(float dt)
{
	if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size())
	{
		if (_animationIterator < _animationFrames.size() - 1)
			_animationIterator++;
		else
			_animationIterator = 0;
		
		_birdSprite.setTexture(_animationFrames[_animationIterator]);

		_clock.restart();
	}
}

void Bird::update(float dt)
{
	if (_birdState == BIRD_STATE_FALLING)
	{
		_birdSprite.move(0, GRAVITY * dt);
		_rotation += BIRD_ROTATION_SPEED * dt;

		if (_rotation > 25.f)
			_rotation = 25.f;

		_birdSprite.setRotation(_rotation);
	}
	else if (_birdState == BIRD_STATE_FLYING)
	{
		_birdSprite.move(0, -FLYING_SPEED * dt);
		_rotation -= BIRD_ROTATION_SPEED * dt;

		if (_rotation < -25.f)
			_rotation = -25.f;

		_birdSprite.setRotation(_rotation);
	}

	if (_movementClock.getElapsedTime().asSeconds() > FLYING_DURATION)
	{
		_birdState = BIRD_STATE_FALLING;
		_movementClock.restart();
	}
}

void Bird::tap()
{
	_birdState = BIRD_STATE_FLYING;
	_movementClock.restart();
}

void Bird::draw()
{
	_data->window.draw(_birdSprite);
}
