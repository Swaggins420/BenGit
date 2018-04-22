#include "PhysicsNode.h"

PhysicsNode::PhysicsNode()
{
	position = Vector3(0, 0, 0);
	orientation = 0;
	scale = Vector3(0, 0, 0);
}

PhysicsNode::~PhysicsNode() {}

PhysicsNode::PhysicsNode(Vector3 pos, float o, Vector3 s)
{
	position = pos;
	orientation = o;
	scale = s;
}

void PhysicsNode::setPosition(BoundingBox box) {
	float x = box.bottomLeft.x - 10;
	float y = box.bottomLeft.y - 4;

	position = Vector3(x, y, box.topRight.z);
}
