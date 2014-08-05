#ifndef __STATE_MACHINE_H__
#define __STATE_MACHINE_H__

#include "cocos2d/cocos/base/CCRef.h"
#include "cocos2d/cocos/base/CCVector.h"
#include "EntityState.h"

class StateMachine : public cocos2d::Ref
{
public:
	static StateMachine* create();
	bool init();
	void runWithState(EntityState* state);
	void switchState(EntityState* state);
	void update(float dt);

	StateMachine();
	~StateMachine();

private:
	void setNextState();

private:
	EntityState* m_currentState;
	EntityState* m_nextState;
};

#endif // __STATE_MACHINE_H__
