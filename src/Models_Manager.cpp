#include "Models_Manager.h"
using namespace BasicEngine;
using namespace Managers;
using namespace Rendering;

Models_Manager::Models_Manager()
{

}

Models_Manager::~Models_Manager()
{
  for(auto model: gameModelList)
  {
    delete model.second;
  }
  gameModelList.clear();
}

void Models_Manager::DeleteModel(const std::string& gameModelName)
{
  IGameObject* model = gameModelList[gameModelName];
  model->Destroy();
  gameModelList.erase(gameModelName);
}

const IGameObject& Models_Manager::GetModel(const std::string& gameModelName) const
{
  return (*gameModelList.at(gameModelName));
}

void Models_Manager::Update()
{
  for(auto model: gameModelList)
  {
    model.second->Update();
  }
}

void Models_Manager::Draw()
{
  for(auto model: gameModelList)
  {
    model.second->Draw();
  }
}

void Models_Manager::Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix)
{
	for (auto model : gameModelList)
	{
		model.second->Draw(projection_matrix, view_matrix);
	}
}

void Models_Manager::Move(int areaId, int directionId)
{
  for(auto model : gameModelList)
  {
    model.second->Move(areaId, directionId);
  }
}

void Models_Manager::PrintDetails()
{
  for(auto model : gameModelList)
  {
    model.second->PrintDetails();
  }
}

void Models_Manager::SetModel(const std::string& gameObjectName, IGameObject* gameObject)
{
	gameModelList[gameObjectName.c_str()] = gameObject;
}
