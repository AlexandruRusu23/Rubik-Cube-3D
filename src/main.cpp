#include "Engine.h"
#include "CubeIndex.h"
#include "CubeTexture.h"

using namespace BasicEngine;

int main(int argc, char **argv)
{
	Engine* engine = new Engine();
	engine->Init();

	/*
	engine->GetShader_Manager()->CreateProgram("cubeShader", "Vertex_Shader.glsl", "Fragment_Shader.glsl");

	CubeIndex* cube = new CubeIndex();
	cube->SetProgram(engine->GetShader_Manager()->GetShader("cubeShader"));
	cube->Create();

	engine->GetModels_Manager()->SetModel("cubeIndex", cube);
	*/

	engine->GetShader_Manager()->CreateProgram("cubeTextureShader", "Texture_Vertex_Shader.glsl", "Texture_Fragment_Shader.glsl");

	CubeTexture* cube = new CubeTexture();
	cube->SetProgram(engine->GetShader_Manager()->GetShader("cubeTextureShader"));
	cube->Create();

	int texture =  engine->GetTexture_Loader()->LoadTexture("textures/Crina.bmp", 256, 256);

	cube->SetTexture("Create", texture);

	engine->GetModels_Manager()->SetModel("cubeTextureIndex", cube);

	glDisable(GL_CULL_FACE);

	engine->Run();

	delete engine;
	return 0;
}
