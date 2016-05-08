#pragma once

#include "cocos2d.h"

USING_NS_CC;

class Guy : public Sprite {
public:
	static const int CONTACT_MASK = 0x0001;

	virtual bool init();

	CREATE_FUNC(Guy);
};
