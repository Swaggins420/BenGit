#pragma once
#include "../../nclgl/Vector3.h"
struct  BoundingBox {
	Vector3  topLeft;
	Vector3  topRight;
	Vector3  bottomRight;
	Vector3  bottomLeft;
};


class PhysicsNode {
public:
	PhysicsNode();
	PhysicsNode(Vector3 pos, float o, Vector3 s);
	~PhysicsNode();



	Vector3 getPosition() { return position; };
	float getOrientation() { return orientation; };
	Vector3 getScale() { return scale; };

	void setPosition(Vector3 pos) { position = pos; };
	void setPosition(BoundingBox box);
	void setOrientation(float f) { orientation = f; };
	void setScale(Vector3 s) { scale = s; };




	Vector3 position;
	float orientation;
	Vector3 scale;


	float currentVelocity;
	float maxVelocity;
	float currentAcceleration;
	float maxAcceleration;
	float displacement;

};