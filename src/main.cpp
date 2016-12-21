#include "Engine.h"
#include "CubeIndex.h"

using namespace BasicEngine;

int main(int argc, char **argv)
{
	Engine* engine = new Engine();
	engine->Init();

	engine->GetShader_Manager()->CreateProgram("cubeShader", "Vertex_Shader.glsl", "Fragment_Shader.glsl");

	CubeIndex* cubeIndex = new CubeIndex();
	cubeIndex->SetProgram(engine->GetShader_Manager()->GetShader("cubeShader"));
	cubeIndex->Create();

	engine->GetModels_Manager()->SetModel("cubeIndex", cubeIndex);

	engine->Run();

	delete engine;
	return 0;
}
