#include <sstream>
#include <iostream>
#include <SFML/Audio.hpp>

#include "MainMenuState.h"
#include "GameState.h"
#include "Definitions.h"

//constructors
MainMenuState::MainMenuState(GameDataRef data) : _data(data)
{

}

sf::Music Sound;

//methodes
void MainMenuState::init()
{
	//sound 	
	Sound.openFromFile("Ressources/audio/Menu.wav");
	Sound.setLoop(true);
	Sound.play();

	//Background
	this->_data->assetManager.LoadTextures("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
	this->_backgroundSprite.setTexture(this->_data->assetManager.GetTexture("Main Menu Background"));

	//title
	this->_data->assetManager.LoadTextures("Game Title", GAME_TITLE_FILEPATH);
	this->_title.setTexture(this->_data->assetManager.GetTexture("Game Title"));
	this->_title.setPosition(sf::Vector2f(
		(SCREEN_WIDTH / 2) - (this->_title.getGlobalBounds().width / 2)
		, 200.f));

	//play button
	this->_data->assetManager.LoadTextures("Play Button", PLAY_BUTTON_FILEPATH);
	this->_playButton.setTexture(this->_data->assetManager.GetTexture("Play Button"));
	this->_playButton.setPosition(sf::Vector2f(
		(SCREEN_WIDTH / 2) - (this->_playButton.getGlobalBounds().width / 2)
		, SCREEN_HEIGHT / 2));
}

void MainMenuState::handleInput()
{
	sf::Event ev;
	while (this->_data->window.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
			this->_data->window.close();

		if (this->_data->inputManager.isSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
		{
			this->_data->stateMachine.addState(StateRef(new GameState(this->_data)), true);
		}
	}
}

void MainMenuState::update(float dt)
{
	
}

void MainMenuState::render(float dt)
{
	this->_data->window.clear();
	
	this->_data->window.draw(_backgroundSprite);
	this->_data->window.draw(_title);
	this->_data->window.draw(_playButton);
	
	this->_data->window.display();
}
