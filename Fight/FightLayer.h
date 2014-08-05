#ifndef __FIGHT_LAYER_H__
#define __FIGHT_LAYER_H__

#include "cocos2d/cocos/2d/CCLayer.h"
#include <iostream>
class FightLayer : public cocos2d::Layer
{
public:
	FightLayer();

	~FightLayer();
	CREATE_FUNC(FightLayer);
	bool init() override;
};

#endif // __FIGHT_LAYER_H__