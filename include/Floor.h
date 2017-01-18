#ifndef FLOOR_H
#define FLOOR_H

#include "Model.h"
#include <time.h>
#include <stdarg.h>

using namespace BasicEngine::Rendering::Models;

class Floor : public Model
{
public:
  Floor();
  ~Floor();

  void Create();
  virtual void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix) override final;
  virtual void Update() override final;
  virtual void Move(int areaId, int directionId) override final;

  virtual void PrintDetails() override final;

private:
  glm::vec3 rotation, rotation_speed;
  glm::vec3 rotation_sin;
  glm::vec3 translate, translate_speed;
  glm::mat4 translate_matrix;
};

#endif
