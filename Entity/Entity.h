#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "cocos2d/cocos/2d/CCSprite.h"

class Entity : public cocos2d::Sprite
{
public:
	CREATE_FUNC(Entity);
	bool init();
};

#endif // __ENTITY_H__
