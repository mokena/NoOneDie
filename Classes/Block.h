#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Block : public Sprite {
public:
	static const int CONTACT_MASK = 0x0010;

	virtual bool init();
	virtual void update(float dt);

	CREATE_FUNC(Block);
};
