#include "GameController.h"

GameController* GameController::create(Layer* layer, int positionY) {
	GameController* ins = new GameController();
	ins->init(layer, positionY);
	ins->autorelease();

	return ins;
}


bool GameController::init(Layer* layer, int positionY) {
	_layer = layer;
	_positionY = positionY;

	_visibleSize = Director::getInstance()->getVisibleSize();

	_edge = Edge::create();
	_layer->addChild(_edge);
	_edge->setPosition(0, positionY);

	auto ground = Sprite::create();
	ground->setColor(Color3B(0, 0, 0));
	ground->setTextureRect(Rect(0, 0, _visibleSize.width, 3));
	ground->setPosition(_visibleSize.width / 2, 1.5 + positionY);
	_layer->addChild(ground);

	_guy = Guy::create();
	_layer->addChild(_guy);
	_guy->setPosition( _guy->getContentSize().width/2, _guy->getContentSize().height / 2 + positionY);

	return true;
}

void GameController::addBlock() {
	auto block = Block::create();
	_layer->addChild(block);
	block->setPosition(_visibleSize.width, block->getContentSize().height / 2 + _positionY);
}

void GameController::resetFrame() {
	curFrame = 0;
	nextFrameCount = rand() % 120 + 100;
}

void GameController::onUpdate() {
	curFrame++;
	if (curFrame > nextFrameCount) {
		resetFrame();
		addBlock();
	}
}

bool GameController::isTouched(Vec2 point) {
	if (_edge->getBoundingBox().containsPoint(point)) {
		return true;
	}
	else {
		return false;
	}
}

void GameController::onTouched() {
	_guy->getPhysicsBody()->setVelocity(Vec2(0, 600));
}