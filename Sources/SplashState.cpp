#include <sstream>
#include <iostream>

#include "SplashState.h"
#include "MainMenuState.h"
#include "Definitions.h"

//constructors
SplashState::SplashState(GameDataRef data) : _data(data)
{

}


//methodes
void SplashState::init()
{
	this->_data->assetManager.LoadTextures("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
	this->_backgroundSprite.setTexture(this->_data->assetManager.GetTexture("Splash State Background"));
}

void SplashState::handleInput()
{
	sf::Event ev;
	while (this->_data->window.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
			_data->window.close();
	}
}

void SplashState::update(float dt)
{
	if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		this->_data->stateMachine.addState(StateRef(new MainMenuState(this->_data)), true);
}

void SplashState::render(float dt)
{
	this->_data->window.clear();
	this->_data->window.draw(_backgroundSprite);
	this->_data->window.display();
}
