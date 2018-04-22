#pragma once
#include "PhysicsNode.h"


using namespace std;

class Entity {
public:
	Entity();
	virtual ~Entity();

	void updateAggroRange(float x) { aggroRange = x; };
	void updateAggroRange(Vector3 v) { physicsNode.setPosition(v); };
	void updateAggroRange(float x, float y) { updateAggroRange(Vector3(x, y, physicsNode.getPosition().z)); };
	void updateAggroRange(int x) { entitiesInRange = x; };

	void updateAggroRange(int i, float x, Vector3 v) {
		entitiesInRange = i;
		aggroRange = x;
		physicsNode.setPosition(v);
	};

	int getEntitiesInRange() { return entitiesInRange; };
	float getAggroRange() { return aggroRange; };
	PhysicsNode getPhysicsNode() { return physicsNode; };
	bool inRange(Entity e);


	float mass;
	int entitiesInRange;
	PhysicsNode physicsNode;
	float aggroRange;

};