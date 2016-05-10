#include "GameOverScene.h"

bool GameOver::init() {
	LayerColor::init();
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	
	initWithColor(Color4B::WHITE);
	auto overLabel = Label::create();
	overLabel->setString("Game Over!");
	overLabel->setSystemFontSize(45);
	overLabel->setColor(Color3B::BLACK);
	overLabel->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(overLabel);

	return true;
}

Scene* GameOver::createScene() {
	Scene* scene = Scene::create();
	GameOver* l = GameOver::create();
	scene->addChild(l);

	return scene;
}