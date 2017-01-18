#include "Engine.h"
#include "CubeIndex.h"
#include "Cone.h"
#include "Floor.h"
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

	Cone* cone = new Cone();
	cone->SetProgram(engine->GetShader_Manager()->GetShader("cubeShader"));
	cone->Create();
	engine->GetModels_Manager()->SetModel("cube", cone);

	Floor* flor = new Floor();
	flor->SetProgram(engine->GetShader_Manager()->GetShader("cubeShader"));
	flor->Create();
	engine->GetModels_Manager()->SetModel("flor", flor);

	engine->Run();

	delete engine;
	return 0;
}
