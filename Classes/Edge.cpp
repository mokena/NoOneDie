#include "Edge.h"

bool Edge::init() {
	Node::init();

	auto size = Director::getInstance()->getVisibleSize();
	setPhysicsBody(PhysicsBody::createEdgeBox(size));
	setContentSize(size);

	return true;
}
