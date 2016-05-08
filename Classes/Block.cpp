#include "Block.h"

bool Block::init() {
	Sprite::init();

	auto size = Size((rand() % 20) + 5, (rand() % 30) + 10);
	setContentSize(size);
	setTextureRect(Rect(0, 0, size.width, size.height));
	setColor(Color3B(0, 0, 0));
	setPhysicsBody(PhysicsBody::createBox(size));

	auto visibleSize = Director::getInstance()->getVisibleSize();
	setPositionX(visibleSize.width);

	getPhysicsBody()->setDynamic(false);
	getPhysicsBody()->setContactTestBitmask(Block::CONTACT_MASK);

	scheduleUpdate();

	return true;
}

void Block::update(float dt) {
	setPositionX(getPositionX() - 2);

	if (getPositionX() < 0) {
		unscheduleUpdate();
		removeFromParent();
	}
}