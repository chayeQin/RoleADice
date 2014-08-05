#include "Dice.h"
#include <cstdlib>
#include "cocos2d/cocos/base/CCPlatformMacros.h"


Dice* Dice::create()
{
	Dice* ret = new Dice();
	if (ret && ret->init())
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

bool Dice::init()
{
	return true;
}

int Dice::rollADice()
{
	return rand()%(kDicePointMax - kDicePointOne) + kDicePointOne;
}