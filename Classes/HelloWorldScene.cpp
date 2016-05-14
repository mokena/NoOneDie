#include "HelloWorldScene.h"
#include "GameOverScene.h"

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, -2000));
    
    // 'layer' is an autorelease object
	auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
    {
        return false;
    }
    
	_gcs.insert(0, GameController::create(this, 30));

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = [this](PhysicsContact &contact) {
		switch(contact.getShapeA()->getContactTestBitmask() | contact.getShapeB()->getContactTestBitmask()) {
		case Guy::CONTACT_MASK | Block::CONTACT_MASK:
			this->unscheduleUpdate();
			Director::getInstance()->replaceScene(GameOver::createScene());
			break;
		}
		return true;
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [this](Touch* t, Event* e) {
		for (auto it = _gcs.begin(); it != _gcs.end(); it++) {
			if ((*it)->isTouched(t->getLocation())) {
				(*it)->onTouched();
			}
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

	scheduleUpdate();
    
    return true;
}

void HelloWorld::update(float dt) {
	for (auto it = _gcs.begin(); it != _gcs.end(); it++) {
		(*it)->onUpdate();
	}
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
