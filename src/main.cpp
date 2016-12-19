#include <iostream>
#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

#include "Init_GLUT.h"
#include "Scene_Manager.h"

using namespace Core;

int main(int argc, char **argv)
{
	WindowInfo window(std::string("Scene3D"), 300, 300, 800, 600, true);

	ContextInfo context(4, 5, true);
	FrameBufferInfo frameBufferInfo(true, true, true, true);
	Init::Init_GLUT::Init(window, context, frameBufferInfo);

	IListener* scene = new Managers::Scene_Manager();
	Init::Init_GLUT::SetListener(scene);

	Init::Init_GLUT::Run();

	delete scene;
	return 0;
}
