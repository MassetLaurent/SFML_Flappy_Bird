#ifndef DEF_STATE
#define DEF_STATE

class State
{
private:
	//attributes

public:
	//methodes
	virtual void init() = 0;
	virtual void handleInput() = 0;

	virtual void update(float dt) = 0;
	virtual void render(float dt) = 0;

	virtual void pause() {}
	virtual void resume() {}
};

#endif // ! DEF_STATE
