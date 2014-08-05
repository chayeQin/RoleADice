#include "StateMachine.h"
#include "cocos2d/cocos/base/ccMacros.h"

void StateMachine::runWithState(EntityState* state)
{
	CCASSERT(m_currentState == nullptr, "State machine had been running");
	CCASSERT(state != nullptr, "The state can not be null");
	m_nextState = state;
}

void StateMachine::switchState(EntityState* state)
{
	CCASSERT(m_currentState != nullptr, "Use runWithState instead to start the state machine");
	CCASSERT(state != nullptr, "New state can not be null");

	if (state == m_nextState)
		return;

	m_nextState = state;
}

void StateMachine::update(float dt)
{
	if (m_nextState)
	{
		setNextState();
	}

	if (m_currentState)
	{
		m_currentState->onExcute(dt);
	}
}

void StateMachine::setNextState()
{
	if (m_currentState)
	{
		m_currentState->onExit();
		m_currentState->release();
	}

	m_currentState = m_nextState;
	m_nextState->retain();
	m_nextState = nullptr;
	m_currentState->onEnter();
}