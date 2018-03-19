#include "../../nclgl/window.h"
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





int main() {
	Window w("CSC3222 Coursework", 1920,1080, false);
	if (!w.HasInitialised()) {
		return -1;
	}

	Physics physics;
	Renderer renderer(w, &physics);
	
	if (!renderer.HasInitialised()) {
		return -1;
	}
	//Raider r = Raider();
	//Dragon d = Dragon();

	//cout << "dragon = " + d.getAggroRange();
	w.LockMouseToWindow(true);
	w.ShowOSPointer(false);		

	
	while (w.UpdateWindow() && !Window::GetKeyboard()->KeyDown(KEYBOARD_ESCAPE)) {
		float msec = w.GetTimer()->GetTimedMS();
		physics.UpdatePhysics(msec);
		renderer.UpdateScene(msec);
		renderer.RenderScene();


	}

	return 0;
}