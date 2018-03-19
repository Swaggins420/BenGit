#include "Entity.h"


Entity::Entity(){
	aggroRange = 250;
	physicsNode = PhysicsNode();
}

Entity::~Entity() {}


bool Entity::inRange(Entity e) {
	float distance = sqrt(pow(this->physicsNode.getPosition().x - e.physicsNode.getPosition().x, 2) + 
		pow(this->physicsNode.getPosition().y - e.physicsNode.getPosition().y, 2));

	if (distance <= this->aggroRange) {
		return true;
	}
	else return false;
}


	
