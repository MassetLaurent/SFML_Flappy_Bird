#include "Game.h"

#define SCREEN_HEIGHT 1024
#define SCREEN_WIDTH 1024

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Flappy Bird");
}

Game::Game()
{
	this->initWindow();
}

Game::~Game()
{

}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updatePollEvent();

		this->update();

		this->render();
	}
}

void Game::update()
{

}

void Game::updatePollEvent()
{
	sf::Event ev;

	while (this->window->pollEvent(ev))
	{
		if (ev.Event::type == sf::Event::Closed)
			this->window->close();

		if (ev.Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

void Game::render()
{
	this->window->clear();



	this->window->display();
}

