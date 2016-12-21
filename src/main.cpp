#include "Engine.h"
#include "CubeIndex.h"
#include "CubeTexture.h"
#include <SOIL/SOIL.h>

using namespace BasicEngine;

int main(int argc, char **argv)
{
	Engine* engine = new Engine();
	engine->Init();

	engine->GetShader_Manager()->CreateProgram("cubeShader", "Vertex_Shader.glsl", "Fragment_Shader.glsl");

	CubeIndex* cube = new CubeIndex();
	cube->SetProgram(engine->GetShader_Manager()->GetShader("cubeShader"));
	cube->Create();

	engine->GetModels_Manager()->SetModel("cubeIndex", cube);

	/*
	engine->GetShader_Manager()->CreateProgram("cubeShader", "Texture_Vertex_Shader.glsl", "Texture_Fragment_Shader.glsl");

	CubeTexture* cube = new CubeTexture();

	int program = engine->GetShader_Manager()->GetShader("cubeShader");
	if (program != 0) {
		cube->SetProgram(program);
		cube->Create();
	}
	else {
		std::cout << "invalid program...";
		std::cin.get();
	}

	//int textureID = SOIL_load_OGL_texture("textures/Crate.bmp", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
	int textureID = engine->GetTexture_Loader()->LoadTexture("textures/Crate.bmp", 256, 256);

	cube->SetTexture("Create", textureID);
	engine->GetModels_Manager()->SetModel("cube", cube);
	*/

	//glDisable(GL_CULL_FACE);

	engine->Run();

	delete engine;
	return 0;
}
