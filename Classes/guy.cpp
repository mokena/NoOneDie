#include "Guy.h"


bool Guy::init() {
	Sprite::init();

	auto animation = Animation::create();
	for (int i = 1; i <= 5; i++)
	{
		char szName[20] = { 0 };
		sprintf(szName, "guy0%d.png", i);
		animation->addSpriteFrameWithFile(szName);
	}

	animation->setDelayPerUnit(0.5f / 5.0f);
	animation->setRestoreOriginalFrame(true);
	auto action = Animate::create(animation);
	runAction(RepeatForever::create(action));

	Size size = Size(44, 52);
	setContentSize(size);
	setPhysicsBody(PhysicsBody::createBox(size));

	getPhysicsBody()->setRotationEnable(false);

	return true;
}