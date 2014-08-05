#ifndef __DICE_H__
#define __DICE_H__

#include "cocos2d/cocos/2d/CCSprite.h"

enum DicePoint{
	kDicePointNone = 0,
	kDicePointOne,
	kDicePointTwo,
	kDicePointThree,
	kDicePointFour,
	kDicePointFive,
	kDicePointSix,
	kDicePointMax,
};

class Dice : public cocos2d::Sprite
{
public:
	static Dice* create();

	bool init() override;
	int rollADice();
};

#endif // __DICE_H__