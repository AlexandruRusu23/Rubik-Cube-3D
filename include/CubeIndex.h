#ifndef CUBEINDEX_H
#define CUBEINDEX_H

#include "Model.h"
#include <time.h>
#include <stdarg.h>

using namespace BasicEngine::Rendering::Models;

class CubeIndex : public Model
{
public:
  CubeIndex();
  CubeIndex(int positionId);
  ~CubeIndex();

  void Create();
  virtual void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix) override final;
  virtual void Update() override final;
  virtual void Move(int areaId, int directionId) override final;

private:
  bool PartOfTheLayer(int areaId, int directionId);

private:
  glm::vec3 rotation, rotation_speed;
  glm::vec3 rotation_sin;
  glm::vec3 translate, translate_speed;
  glm::mat4 translate_matrix;
  glm::vec3 next_rotation;
  int cube_position;
  int rotation_direction;
  int translate_direction;
  time_t timer;
};

#endif
