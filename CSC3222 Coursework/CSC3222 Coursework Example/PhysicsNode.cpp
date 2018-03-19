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
