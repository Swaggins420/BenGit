#pragma once


#include "../../nclgl/Vector3.h"
#include "../../nclgl/GameTimer.h"
#include "../../nclgl/window.h"
//#include "PhysicsNode.h"
//#include "Entity.h"
#include "Dragon.h"
//#include "Raider.h"
#include "Follower.h"
#include "Leader.h"


using std::vector;

/* An elementary Physics Data structure, containing the bare minimum of information necessary to
say where an object should appear, and which way it should point. As we increase the complexity
of our physics system, we will add elements to this structure, but the elements which can affect
the graphical representation of entities are present below (and integrated with the graphics
framework already, to make your life easier). Ultimately, you may decide to replace this data
structure entirely (for example with a class to allow inclusion of embedded functions) but be
aware that doing so might require some slight doctoring of Renderer::Renderer() and
SceneNode::Update() */

//struct PhysicsData {
//	Vector3 position;
//	float rotation;
//	Vector3 scale;
//};

/* Our placeholder physics system includes an update function, and physics data for each entity
in our environment. We also include a single integer to inform the dragon's behaviour and breath
weapon scaling.*/

class Physics {
public:
	Physics();
	~Physics();

	void UpdatePhysics(float msec);

	float mapX = 864.0f;
	float mapY = 540.0f;
	float mapZ = 100.0f;

	vector<vector<BoundingBox> > grid; 

	//void display(const vector<vector<int> >& vy)
	//{
	//	for (int i = 0; i < vy.size(); i++)       // loops through each row of vy
	//	{
	//		for (int j = 0; j < vy[i].size(); j++) // loops through each element of each row 
	//			cout << " " << vy[i][j];           // prints the jth element of the ith row
	//		cout << endl;
	//	}
	//}

	const int SCREEN_PIXEL_HEIGHT = 1080;
	const int SCREEN_PIXEL_WIDTH = 1920;
	int maxX = 1675 / 27;
	int maxY = 1000 / 28;
	float wInc = 2.0f / (float)SCREEN_PIXEL_WIDTH;
	float hInc = 2.0f / (float)SCREEN_PIXEL_HEIGHT;


	void coords(vector<vector<BoundingBox> >& box);

	PhysicsNode map;
	Dragon dragon;
	PhysicsNode breath;
	vector<Raider> raiders;
	Leader leader;
	Follower follower;
	int raiderCount = 1;
	int getNoInRange() { return noInRange; };
	
	GameTimer gT;

	void explicitEueler();
	void implicitEueler();
	void semiImplicitEueler();
	void verletIntegration();

	int noInRange;
	int numRaiders;
	int	dragonState;
	int breathState;
};