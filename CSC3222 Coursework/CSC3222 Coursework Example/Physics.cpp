#include "Physics.h"
#define _USE_MATH_DEFINES
#include <math.h>

Physics::Physics()
{
	numRaiders = 16;
	//dragon = new Dragon();

		l.physicsNode.setPosition(Vector3(-311 + 27 * 0, -80.0f, -199.9f));
		l.physicsNode.setOrientation(0*20.0f);
		l.physicsNode.setScale(Vector3(10.0f, 10.0f, 1.0f));

		raiders.push_back(l);

	for (int i = 1; i < numRaiders; i++)
	{
		f.physicsNode.setPosition(Vector3(-311 + 27 * i, -30.0f, -199.9f));
		f.physicsNode.setOrientation(i*20.0f);
		f.physicsNode.setScale(Vector3(10.0f, 10.0f, 1.0f));

		raiders.push_back(f);
	}

	map.setPosition(Vector3(0.0f, 100.0f, -200.0f));
	map.setOrientation(0.0f);
	map.setScale(Vector3(864.0f, 540.0f, 100.0f));

	dragon.physicsNode.setPosition(Vector3(-300.0f, 90.0f, -199.5f));
	dragon.physicsNode.setOrientation(0.0f);
	dragon.physicsNode.setScale(Vector3(50.0f, 50.0f, 1.0f));

	dragonState = 1;

	breath.setPosition(Vector3(0.0f, -50.0f, -0.3f));
	breath.setOrientation(270.0f);
	breath.setScale(Vector3(2.0f, 1.0f, 1.0f));

	breathState = 1;
}

Physics::~Physics()
{
	raiders.clear();
}

void Physics::UpdatePhysics(float msec)
{	
	/*
	//int count = 0;
	//for (int i = 0; i < raiders.size(); ++i)
	//{
		//float distance = (raiders.at(i).getPosition() - dragon.getPosition()).Length();

	
		shift into raider class passing raiders.at(i) and dragon as params for 2 points
		then do calculation of raider distance there
		
		//Vector3& r = raiders.at(i).getPhysicsNode().getPosition();	
		//Vector3& d = dragon.getPhysicsNode().getPosition();
		//float distance = sqrt(pow(r.x - d.x, 2) + pow(r.y - d.y, 2));
		//if ( distance <= 25 ) {
		//	count += 1;
		//}
		*/
		//float angle = atan2(raiders.at(0).physicsNode.getPosition().y - dragon.physicsNode.getPosition().y, raiders.at(0).physicsNode.getPosition().x - dragon.physicsNode.getPosition().x);
		//raiders.at(0).physicsNode.setOrientation(angle * 180 / M_PI);

		//Raider r;
		//noInRange = r.countRaidersInRange(raiders, dragon);

		//for (int i = 1; i < numRaiders; i++)
		//{
		//	if (dragon.inRange(raiders.at(i)) == true) {
		//		float angle = atan2(raiders.at(i).physicsNode.getPosition().y - dragon.physicsNode.getPosition().y, raiders.at(i).physicsNode.getPosition().x - dragon.physicsNode.getPosition().x);
		//		raiders.at(i).physicsNode.setOrientation(angle * 180 / M_PI);
		//	}
		//	else {
		//		float angle = atan2(raiders.at(i).physicsNode.getPosition().y - raiders.at(0).physicsNode.getPosition().y, raiders.at(i).physicsNode.getPosition().x - raiders.at(0).physicsNode.getPosition().x);
		//		raiders.at(i).physicsNode.setOrientation(angle * 180 / M_PI);
		//	}
		//}
		/*// add set raider orientation here - find angle between 2 points and call set orientation with it
		
		It's just float angle = atan2(p1.y - p2.y, p1.x - p2.x).

		Of course the return type is in radians, if you need it in degrees just do angle * 180 / PI
		*/
	Raider r;
	noInRange = r.countRaidersInRange(raiders, dragon);

	//r.orientRaiders(raiders, dragon, numRaiders );


	//make leader face dragon
	float angle = atan2(raiders.at(0).physicsNode.getPosition().y - dragon.physicsNode.getPosition().y, raiders.at(0).physicsNode.getPosition().x - dragon.physicsNode.getPosition().x);
	raiders.at(0).physicsNode.setOrientation(angle * 180 / M_PI);


	for (int i = 1; i < numRaiders; i++)
	{
		//make followers face leader
		angle = atan2(raiders.at(i).physicsNode.getPosition().y - raiders.at(0).physicsNode.getPosition().y, raiders.at(i).physicsNode.getPosition().x - raiders.at(0).physicsNode.getPosition().x);
		raiders.at(i).physicsNode.setOrientation(angle * 180 / M_PI);


		if (dragon.inRange(raiders.at(i)) == true) {	//if follower in range of dragon
			r.raidersInRange.push_back(raiders.at(i));	//add follower to list of followers in range of dragon
														//make followers in aggro range face dragon
			angle = atan2(raiders.at(i).physicsNode.getPosition().y - dragon.physicsNode.getPosition().y, raiders.at(i).physicsNode.getPosition().x - dragon.physicsNode.getPosition().x);
			raiders.at(i).physicsNode.setOrientation(angle * 180 / M_PI);
		}

	}
	//}
	//noInRange = count;


	/* Placeholder functionality to show things moving on screen
	Note that our physics update is parcelled away from our renderer. So
	long as our SceneNode has a pointer to its associated PhysicsData it
	should update reliably. Note that as these pointers are set at the
	beginning of execution, we should take care when messing around with
	the contents of our raiders <vector> */
	
	float shift;

	shift = 0.3f*msec;

	/* Here, we simply rotate each raider counter-clockwise by a value
	relative to framerate. */

	//for (int i = 0; i < numRaiders; i++)
	//{
	//	raiders.at(i).rotation += shift;
	//}

	/* This segment demonstrates a simple finite state machine. State 1 is
	analogous to 'move right'. Once the dragon has moved right beyond a
	specific threshold (in this example, 100 units from origin), it flips
	to State 0, 'move left', and continues until it is -320 units from
	origin. Repeat ad nauseum. You should compartmentalise this decision
	making away from your physics system - it is included here for
	illustrative purposes only.	*/

	shift = 0.1*msec;

	if (dragon.physicsNode.getPosition().x > 100.0f)
	{
		dragonState = 0;
	}
	else if(dragon.physicsNode.getPosition().x < -320.0f)
	{
		dragonState = 1;
	}

	if (dragonState == 1)
	{
		dragon.physicsNode.setPosition(Vector3(dragon.physicsNode.getPosition().x + shift, dragon.physicsNode.getPosition().y, dragon.physicsNode.getPosition().z));
		//raiders.at(0).physicsNode.setPosition(Vector3(raiders.at(0).physicsNode.getPosition().x, raiders.at(0).physicsNode.getPosition().y + shift, raiders.at(0).physicsNode.getPosition().z));
		//dragon.getPosition.x += shift;
		
	}
	else
	{
		dragon.physicsNode.setPosition(Vector3(dragon.physicsNode.getPosition().x - shift, dragon.physicsNode.getPosition().y, dragon.physicsNode.getPosition().z));
		//raiders.at(0).physicsNode.setPosition(Vector3(raiders.at(0).physicsNode.getPosition().x, raiders.at(0).physicsNode.getPosition().y - shift, raiders.at(0).physicsNode.getPosition().z));

		//dragon.position.x -= shift;
	}

	/* Note also, as highlighted in the comments in Renderer.cpp, that
	we do not explicitly change the position of the fiery breath - but
	the breath moves in any case. This is because it inherits its base
	coordinates from its parent (the dragon) in our scene structure. It
	also inherits its orientation from the dragon - to see this in
	action, uncomment the line of code below: */
	//raiders.at(0).physicsNode.orientation -= shift;
	//dragon.physicsNode.orientation -= shift;

	/* Lastly, there may be times when we want to control the scale of
	an object. If that object collides, it makes sense for its physics
	data to be aware of, or govern, this change in scale. Our SceneNode
	is adapted to read in an object's scale each frame from its associated
	PhysicsData just in case it has changed - here is an example of that
	applied to the dragon's breath weapon. */

	if (breath.getScale().x > 100.0f)
	{
		breathState = 0;
		breath.setScale(Vector3(100, 50, breath.getScale().z));
	}
	else if (breath.getScale().x < 2.0f)
	{
		breathState = 1;
		breath.setScale(Vector3(2.0f, 1.0f, breath.getScale().z));
	}

	if (breathState == 1)
	{
		breath.setScale(Vector3(breath.getScale().x + 1.5*shift, breath.getScale().y + 0.75*shift, breath.getScale().z));
	}
	else
	{
		breath.setScale(Vector3(breath.getScale().x - 2*shift, breath.getScale().y - shift, breath.getScale().z));
	}

}