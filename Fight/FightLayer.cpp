#include "FightLayer.h"
#include "cocos2d/cocos/2d/CCSpriteFrameCache.h"
#include "cocos2d/cocos/2d/CCSprite.h"
#include "cocos2d/cocos/math/Vec2.h"
#include "cocos2d/cocos/2d/CCMenu.h"
#include "cocos2d/cocos/2d/CCMenuItem.h"
#include "Entity/Dice.h"

using namespace cocos2d;

FightLayer::FightLayer()
{
}

FightLayer::~FightLayer()
{
}

bool FightLayer::init()
{
	if (!Layer::init())
		return false;
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("a.plist");

	Dice* d = Dice::create();
	Sprite* sp1 = Sprite::createWithSpriteFrameName("path.png");
	Sprite* sp2 = Sprite::createWithSpriteFrameName("path.png");
	auto item = MenuItemSprite::create(sp1, sp2,[d](Ref*){
		CCLOG("HelloWorld %d", d->rollADice());
		
	});


	auto menu =  Menu::create(item, nullptr);
	menu->setPosition(Vec2(100, 100));
	this->addChild(menu);
	return true;
}