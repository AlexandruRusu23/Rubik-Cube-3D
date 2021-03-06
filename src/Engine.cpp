#include "Engine.h"
using namespace BasicEngine;
using namespace Core;

Engine::Engine()
{

}

//You can set params for init
bool Engine::Init()
{
	WindowInfo window(std::string("Scene3D"), 100, 50, 1200, 800, true);
	ContextInfo context(3, 3, true);
	FrameBufferInfo frameBufferInfo(true, true, true, true);

	Init::Init_GLUT::Init(window, context, frameBufferInfo);

	m_scene_manager = new Managers::Scene_Manager();

	Init::Init_GLUT::SetListener(m_scene_manager);

	m_shader_manager = new Managers::Shader_Manager();
	m_shader_manager->CreateProgram("colorShader", "Vertex_Shader.glsl", "Fragment_Shader.glsl");

	if (m_scene_manager && m_shader_manager)
	{
		m_models_manager = new Managers::Models_Manager();
		m_scene_manager->SetModelsManager(m_models_manager);
	}
	else
	{
		return false;
	}

	return true;
}

//Create the loop
void Engine::Run()
{
	Init::Init_GLUT::Run();
}


Managers::Scene_Manager* Engine::GetScene_Manager() const
{
	return m_scene_manager;
}

Managers::Shader_Manager* Engine::GetShader_Manager() const
{
	return m_shader_manager;
}

Managers::Models_Manager* Engine::GetModels_Manager() const
{
	return m_models_manager;
}

Engine::~Engine()
{
	if (m_scene_manager)
		delete m_scene_manager;

	if (m_shader_manager)
		delete m_shader_manager;

	if (m_models_manager)
		delete m_models_manager;
}
