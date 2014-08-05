#include "FightScene.h"
#include "Fight/FightLayer.h"

using namespace cocos2d;

FightScene::FightScene()
{
}

FightScene::~FightScene()
{
}

bool FightScene::init()
{
	if (!Scene::init())
		return false;
	
	Layer* fightLayer = FightLayer::create();

	this->addChild(fightLayer);
	return true;
}