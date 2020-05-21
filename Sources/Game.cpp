#include <stdlib.h>
#include <time.h>

#include "Game.h"
#include "SplashState.h"


Game::Game(float width, float height, std::string title)
{
	srand(time(NULL));
	
	this->_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	
	//adding the splashstate in the stack of stateMachine (the first state of the game)
	this->_data->stateMachine.addState(StateRef(new SplashState(this->_data)));
	this->run();
}

void Game::run()
{
	float newTime, frameTime, interpolation;
	float currentTime = this->clock.getElapsedTime().asSeconds();
	float accumulator = 0.f;

	while (_data->window.isOpen())
	{
		this->_data->stateMachine.processStateChanges();

		newTime = this->clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f)
			frameTime = 0.25f;

		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= dt)
		{
			this->_data->stateMachine.getActiveState()->handleInput();
			this->_data->stateMachine.getActiveState()->update(dt);

			accumulator -= dt;
		}

		interpolation = accumulator / dt;
		this->_data->stateMachine.getActiveState()->render(interpolation);
	}
}
