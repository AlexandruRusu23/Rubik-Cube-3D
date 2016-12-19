#ifndef QUAD_H
#define QUAD_H

#include "Model.h"

namespace Rendering
{
  namespace Models
  {
    class Quad: public Model
    {
    public:
      Quad();
      ~Quad();

      void Create();
      virtual void Update() override final;
      virtual void Draw() override final;
    };
  }
}

#endif
