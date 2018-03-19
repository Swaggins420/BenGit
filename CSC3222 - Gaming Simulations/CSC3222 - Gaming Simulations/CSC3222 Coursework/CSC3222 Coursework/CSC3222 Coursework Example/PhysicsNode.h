#pragma once
#include "../../nclgl/Vector3.h"


class PhysicsNode {
public:
	PhysicsNode();
	PhysicsNode(Vector3 pos, float o, Vector3 s);
	~PhysicsNode();

	Vector3 getPosition() { return position; };
	float getOrientation() { return orientation; };
	Vector3 getScale() { return scale; };

	void setPosition(Vector3 pos) { position = pos; };
	void setOrientation(float f) { orientation = f; };
	void setScale(Vector3 s) { scale = s; };




	Vector3 position;
	float orientation;
	Vector3 scale;
};