#ifndef DEF_PIPE
#define DEF_PIPE

#include <vector>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Definitions.h"

class Pipe
{
private:
	GameDataRef _data;
	std::vector<sf::Sprite> _pipesSprites;
	std::vector<sf::Sprite> _scoringPipes;
	int _landHeight;
	int _pipeSpawnYOffset;

public:
	//constructor
	Pipe( GameDataRef data);

	void spawnBottomPipe();
	void spawnTopPipe();
	void spawnInvisiblePipe();
	void spawnScoringPipe();
	void movePipes(float dt);
	void drawPipes();
	void randomisePipeOffset();
	const std::vector<sf::Sprite> &getPipes() const;
	 std::vector<sf::Sprite> &getScoringPipes() ;
};
#endif // !DEF_PIPE