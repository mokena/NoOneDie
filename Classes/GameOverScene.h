#pragma once
#include "cocos2d.h"

USING_NS_CC;

class GameOver : public LayerColor {
public:
	virtual bool init();
	static Scene* createScene();

	CREATE_FUNC(GameOver);
};
