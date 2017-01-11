#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H
#include <vector>
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include <iostream>
#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "VertexFormat.h"
#include "Models_Format.h"

namespace BasicEngine
{
  namespace Rendering
  {
    class IGameObject
    {
    public:
      virtual ~IGameObject() = 0;

      virtual void Draw() = 0;
      virtual void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix) = 0;
      virtual void Update() = 0;
      virtual void Move(int areaId, int directionId) = 0;

      virtual void PrintDetails() = 0;

      virtual void SetProgram(GLuint shaderName) = 0;
      virtual void Destroy() = 0;

      virtual GLuint GetVao() const = 0;
      virtual const std::vector<GLuint>& GetVbos() const = 0;
    };

    inline IGameObject::~IGameObject()
    {

    }
  }
}

#endif
