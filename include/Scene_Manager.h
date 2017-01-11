#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H
#include "Shader_Manager.h"
#include "Models_Manager.h"
#include "IListener.h"

namespace BasicEngine
{
  namespace Managers
  {
    class Scene_Manager : public Core::IListener
    {
    public:
      Scene_Manager();
      ~Scene_Manager();

      virtual void NotifyKeyboardPressed(unsigned char key, int x, int y);
      virtual void NotifySpecialKeyboardPressed(int key, int x, int y);

      virtual void NotifyBeginFrame();
      virtual void NotifyDisplayFrame();
      virtual void NotifyEndFrame();
      virtual void NotifyReshape(int width, int height, int previous_width, int previous_height);

      void SetModelsManager(Managers::Models_Manager*& models_manager);

    private:
      Managers::Models_Manager* models_manager;

      int areaId;
      int directionId;
      bool printDetails;

      glm::mat4 projection_matrix;
      glm::mat4 view_matrix;
    };
  }
}

#endif
