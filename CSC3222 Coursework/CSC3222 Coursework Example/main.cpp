
#include "Renderer.h"
#include "Physics.h"
#include "Raider.h"
#include "Dragon.h"

#pragma comment(lib, "nclgl.lib")
using namespace std;
//void keyboard() {
//	if (Keyboard::KeyDown(KEY_UP)) {							//move ship object up,down,left,right
//		//raiders.at(i)->modelMatrix = shipObject->modelMatrix *
//		//	Matrix4::Translation(Vector3(0, 0.01f, 0));
//	}
//}
Physics p;




int main() {
	Window w("CSC3222 Coursework", p.SCREEN_PIXEL_WIDTH, p.SCREEN_PIXEL_HEIGHT, false);
	if (!w.HasInitialised()) {
		return -1;
	}

	Physics physics;
	Renderer renderer(w, &physics);
	float shift;
	if (!renderer.HasInitialised()) {
		return -1;
	}
	//Raider r = Raider();
	//Dragon d = Dragon();

	//cout << "dragon = " + d.getAggroRange();
	w.LockMouseToWindow(true);
	w.ShowOSPointer(false);		
	//one map sq = 5 feet
	//1 sq = 35 pixels x 35 pixels
	
	while (w.UpdateWindow() && !Window::GetKeyboard()->KeyDown(KEYBOARD_ESCAPE)) {
		float msec = w.GetTimer()->GetTimedMS();
		physics.UpdatePhysics(msec);
		renderer.UpdateScene(msec);
		renderer.RenderScene();

		

		shift = 0.3f*msec;
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_RIGHT)) {							
			physics.raiders.at(0).physicsNode.orientation -= shift;
		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_LEFT)) {							
			physics.raiders.at(0).physicsNode.orientation += shift;
		}



	}

	return 0;
}