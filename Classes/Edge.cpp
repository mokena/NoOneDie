#include "Edge.h"

bool Edge::init() {
	Node::init();

	auto size = Director::getInstance()->getVisibleSize();
	setContentSize(size);
	setPhysicsBody(PhysicsBody::createEdgeBox(size));
	
	return true;
}
