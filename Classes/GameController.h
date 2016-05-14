#pragma once
#include "cocos2d.h"
#include "Edge.h"
#include "Guy.h";
#include "Block.h"

USING_NS_CC;

class GameController : public Ref {
private:
	Guy* _guy;
	Edge* _edge;
	Layer* _layer;
	int _positionY;
	Size _visibleSize;

	int curFrame;
	int nextFrameCount;

public:

	static GameController* create(Layer* layer, int positionY);
	virtual bool init(Layer* layer, int positionY);

	void resetFrame();
	void onUpdate();
	void addBlock();
	bool isTouched(Vec2 point);
	void onTouched();
};



