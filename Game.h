#ifndef DEF_GAME
#define DEF_GAME

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
private:
	//attributes
	sf::RenderWindow* window;
	void initWindow();


public:
	//constructors
	Game();
	virtual ~Game();

	//methodes
	void run();
	void updatePollEvent();


	void update();
	void render();
};
#endif //! DEF_GAME