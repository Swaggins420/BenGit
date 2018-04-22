#include "Raider.h"

Raider::Raider() {

	//physicsNode = PhysicsNode();
	physicsNode.maxVelocity = 10;
	physicsNode.maxAcceleration = 10;
}


Raider::~Raider() {}


int Raider::countRaidersInRange(vector<Raider> raiders, Dragon dragon) {

	int count = 0;
	for (int i = 0; i < raiders.size(); ++i)
	{
		if (dragon.inRange(raiders.at(i)) ) {
			count += 1;
		}
	}
	return count;

}


//void Raider::orientRaiders(vector<Raider> raiders, Dragon dragon, int numRaiders) {
//	//make leader face dragon
//	float angle = atan2(raiders.at(0).physicsNode.getPosition().y - dragon.physicsNode.getPosition().y, raiders.at(0).physicsNode.getPosition().x - dragon.physicsNode.getPosition().x);
//	angle = abs(angle * 180 / M_PI);
//	raiders.at(0).physicsNode.setOrientation(angle);
//
//
//	for (int i = 1; i < numRaiders; i++)
//	{
//		//make followers face leader
//		angle = atan2(raiders.at(i).physicsNode.getPosition().y - raiders.at(0).physicsNode.getPosition().y, raiders.at(i).physicsNode.getPosition().x - raiders.at(0).physicsNode.getPosition().x);
//		angle = abs(angle * 180 / M_PI);
//		raiders.at(i).physicsNode.setOrientation(angle);
//
//
//		if (dragon.inRange(raiders.at(i)) == true) {	//if follower in range of dragon
//			raidersInRange.push_back(raiders.at(i));	//add follower to list of followers in range of dragon
//			//make followers in aggro range face dragon
//			angle = atan2(raiders.at(i).physicsNode.getPosition().y - dragon.physicsNode.getPosition().y, raiders.at(i).physicsNode.getPosition().x - dragon.physicsNode.getPosition().x);
//			angle = abs(angle * 180 / M_PI);
//			raiders.at(i).physicsNode.setOrientation(angle);
//		}
//
//	}
//}