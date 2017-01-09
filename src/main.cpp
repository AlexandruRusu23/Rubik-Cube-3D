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
	for(int i = 1; i<= 27; i++)
	{
		CubeIndex* cube = new CubeIndex(i);
		cubes.push_back(cube);
	}

	int contor = 1;
	for(std::vector<CubeIndex*>::iterator it = cubes.begin(); it != cubes.end(); it++)
	{
		(*it)->SetProgram(engine->GetShader_Manager()->GetShader("cubeShader"));
		(*it)->Create();
		engine->GetModels_Manager()->SetModel("cubeIndex" + std::to_string(contor), (*it));
		contor++;
	}

	engine->Run();

	delete engine;
	return 0;
}
