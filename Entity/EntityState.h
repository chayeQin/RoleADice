#ifndef __ENTITY_STATE_H__
#define __ENTITY_STATE_H__

#include "cocos2d/cocos/base/CCRef.h"
#include "Entity.h"
/************************************************************************/
/* 控制实体状态动画表现                                                                     */
/************************************************************************/

class cocos2d::EventCustom;
class cocos2d::EventDispatcher;
class cocos2d::EventListener;
class Entity;
class EntityState : public cocos2d::Ref
{
public:
	EntityState();
	virtual ~EntityState();
	virtual bool init(Entity* owner);
	virtual void onEnter() = 0;
	virtual void onExcute(float dt) = 0;
	virtual void onExit() = 0;
	virtual bool canTransition(cocos2d::EventCustom* input) = 0;

protected:
	Entity* m_owner;
	cocos2d::EventDispatcher* m_dispatcher;
};


class ReadyState : public EntityState
{
public:
	ReadyState();
	~ReadyState();
	static ReadyState* create(Entity* owner);
	bool init(Entity* owner);
	void onEnter() override;
	void onExcute(float dt) override;
	void onExit() override;
	bool canTransition(cocos2d::EventCustom* input) override;

private:
	cocos2d::EventListener* m_moveListener;
};

#endif // __ENTITY_STATE_H__
