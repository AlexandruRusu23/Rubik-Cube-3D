#include "Engine.h"
#include "CubeIndex.h"
#include <SOIL/SOIL.h>

using namespace BasicEngine;

int main(int argc, char **argv)
{
	Engine* engine = new Engine();
	engine->Init();
	engine->GetShader_Manager()->CreateProgram("cubeShader", "Vertex_Shader.glsl", "Fragment_Shader.glsl");

	std::vector<CubeIndex*> cubes;
	CubeIndex* cube = new CubeIndex();
	cubes.push_back(cube);

	for(std::vector<CubeIndex*>::iterator it = cubes.begin(); it != cubes.end(); it++)
	{
		(*it)->SetProgram(engine->GetShader_Manager()->GetShader("cubeShader"));
		(*it)->Create();
		// (*it)->Create(int pozitionId); // TO IMPLEMENT
		engine->GetModels_Manager()->SetModel("cubeIndex", (*it));
	}
	engine->Run();

	delete engine;
	return 0;
}
