#include "EntityState.h"
#include "cocos2d/cocos/base/CCDirector.h"
#include "cocos2d/cocos/base/CCEventCustom.h"
#include "cocos2d/cocos/base/CCEventDispatcher.h"
#include "cocos2d/cocos/base/CCEventListenerCustom.h"
#include "Entity.h"
#include "Global/GameEventDef.h"

EntityState::EntityState() : m_owner(nullptr), m_dispatcher(nullptr)
{

}

EntityState::~EntityState()
{
	CC_SAFE_RELEASE_NULL(m_owner);
	CC_SAFE_RELEASE_NULL(m_dispatcher);
}

bool EntityState::init(Entity* owner)
{
	CCASSERT(owner != nullptr, "owner can not be null");
	m_owner = owner;
	m_dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
	m_owner->retain();
	m_dispatcher->retain();
	return true;
}

ReadyState* ReadyState::create(Entity* owner)
{
	ReadyState* ret = new ReadyState();
	if (ret && ret->init(owner))
	{
		ret->autorelease();
		return ret;
	}
	else
	{
		CC_SAFE_DELETE(ret);
		return nullptr;
	}
}

bool ReadyState::init(Entity* owner)
{
	if (!EntityState::init(owner))
		return false;

	return true;
}

void ReadyState::onEnter()
{
	m_moveListener = m_dispatcher->addCustomEventListener(ENTITY_MOVE_EVENT, [](cocos2d::EventCustom* event){
	});
	m_moveListener->retain();
}

void ReadyState::onExcute(float dt)
{

}

void ReadyState::onExit()
{
	m_dispatcher->removeEventListener(m_moveListener);
	m_moveListener->release();
}