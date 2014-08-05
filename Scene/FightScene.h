#ifndef __FIGHT_SCENE_H__
#define __FIGHT_SCENE_H__

#include "cocos2d/cocos/2d/CCScene.h"


class FightScene : public cocos2d::Scene
{
public:
	FightScene();
	virtual ~FightScene();
	CREATE_FUNC(FightScene);
	bool init() override;
	
};
#endif // __FIGHT_SCENE_H__
