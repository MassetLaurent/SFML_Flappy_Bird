#ifndef DEF_STATEMACHINE
#define DEF_STATEMACHINE

#include <memory>
#include <stack>

#include "State.h"


typedef std::unique_ptr<State> StateRef;


class StateMachine
{
private:
	//attributes
	std::stack<StateRef> statesStack;
	StateRef newState;
	bool isRemoving;
	bool isAdding;
	bool isReplacing;

public:
	//constructors
	StateMachine() {}
	virtual ~StateMachine() {}

	//methodes
	void addState(StateRef _newState, bool _isReplacing = true);
	void removeState();
	void processStateChanges();
	StateRef &getActiveState();



};

#endif // !DEF_STATEMACHINE
