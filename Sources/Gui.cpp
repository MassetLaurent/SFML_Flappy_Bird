#include <string>

#include "Gui.h"

//constructor
Gui::Gui(GameDataRef _data) : data(_data)
{
	scoreTxt.setFont(_data->assetManager.GetFont("Flappy Font"));
	scoreTxt.setString("0");
	scoreTxt.setCharacterSize(128);
	scoreTxt.setFillColor(sf::Color::White);
	scoreTxt.setOrigin(scoreTxt.getGlobalBounds().width / 2, scoreTxt.getGlobalBounds().height / 2);
	scoreTxt.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 5);
}

//methodes
void Gui::updateScore(int _score)
{
	scoreTxt.setString(std::to_string(_score));
}

void Gui::draw()
{
	data->window.draw(scoreTxt);
}
