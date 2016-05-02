#include "Guy.h"

bool Guy::init() {
	Sprite::init();

	//initWithFile("guy02.png");

	auto animation = Animation::create();
	for (int i = 1; i<=5; i++)
	{
		char szName[20] = { 0 };
		sprintf(szName, "guy0%d.png", i);
		animation->addSpriteFrameWithFile(szName);
	}

	animation->setDelayPerUnit(100.0f / 5.0f);
	animation->setRestoreOriginalFrame(true);
	auto action = Animate::create(animation);
	//this->runAction();
	runAction(RepeatForever::create(action));

	Size size = Size(44, 52);
	setPhysicsBody(PhysicsBody::createBox(size));
	setContentSize(size);

	return true;
}