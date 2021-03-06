#include "Scene_Manager.h"
using namespace BasicEngine;
using namespace Managers;

#define PI 3.14159265

Scene_Manager::Scene_Manager()
{
  glEnable(GL_DEPTH_TEST);
  glEnable (GL_LIGHTING); //enable the lighting
  glEnable (GL_LIGHT0); //enable LIGHT0, our Diffuse Light
  glShadeModel (GL_SMOOTH); //set the shader to smooth shader

  view_matrix = glm::mat4(1.0f, 0.0f, 0.0f, 0.0f,
                          0.0f, 1.0f, 0.0f, 0.0f,
                          0.0f, 0.0f, -1.0f, 0.0f,
                          0.0f, 0.0f, 15.0f, 1.0f);

  areaId = NONE;
  directionId = NONE;
}

Scene_Manager::~Scene_Manager()
{

}

void Scene_Manager::NotifyMouseMovement(int x, int y)
{
  int diffx = x - lastMouseX;
  int diffy = y - lastMouseY;
  lastMouseX = x;
  lastMouseY = y;

}

void Scene_Manager::NotifyKeyboardPressed(unsigned char key, int x, int y)
{
  float xrotrad, yrotrad;
  switch (key)
  {
    case 27:
      exit(0);
    break;
    case 'q':
    case 'Q':
      areaId = UP_LEFT;
    break;
    case 'w':
    case 'W':
      areaId = UP_MIDDLE;
    break;
    case 'e':
    case 'E':
      areaId = UP_RIGHT;
    break;
    case 'a':
    case 'A':
      areaId = MIDDLE_LEFT;
    break;
    case 's':
    case 'S':
      areaId = MIDDLE_MIDDLE;
    break;
    case 'd':
    case 'D':
      areaId = MIDDLE_RIGHT;
    break;
    case 'z':
    case 'Z':
      areaId = DOWN_LEFT;
    break;
    case 'x':
    case 'X':
      areaId = DOWN_MIDDLE;
    break;
    case 'c':
    case 'C':
      areaId = DOWN_RIGHT;
    break;
    case 'p':
    case 'P':
      printDetails = true;
    break;
    case '+':
      if(view_matrix[3][2] > 9)
        view_matrix[3][2]-= 0.5;
    break;
    case '-':
      if(view_matrix[3][2] < 30)
        view_matrix[3][2]+= 0.5;
    break;
    default:
      areaId = NONE;
    break;
  }
}

void Scene_Manager::NotifySpecialKeyboardPressed(int key, int x, int y)
{
  switch (key)
  {
		case GLUT_KEY_LEFT :
      directionId = GLUT_KEY_LEFT;
			break;
		case GLUT_KEY_RIGHT :
      directionId = GLUT_KEY_RIGHT;
      break;
		case GLUT_KEY_UP :
      directionId = GLUT_KEY_UP;
      break;
		case GLUT_KEY_DOWN :
      directionId = GLUT_KEY_DOWN;
      break;
    default:
      directionId = NONE;
    break;
	}
}

void Scene_Manager::NotifyBeginFrame()
{
  models_manager->Move(areaId, directionId);
  models_manager->Update();
  if(printDetails)
  {
    models_manager->PrintDetails();
    printDetails = false;
  }
}

void Scene_Manager::NotifyDisplayFrame()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0, 0.0, 0.0, 1.0);

  //observator = glm::vec3(0.0, 0.0, 10.0);
  //referencePoint = glm::vec3(0.0, 0.0, 1.0);
  //vertPlane = glm::vec3(0.0, 1.0, 0.0);

  //view_matrix = glm::lookAt(observator, referencePoint, vertPlane);
  //projection_matrix = glm::perspective(1.0f, 0.0f, 1.0f, 2000.0f);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  models_manager->Draw();
  models_manager->Draw(projection_matrix, view_matrix);

}

void Scene_Manager::NotifyEndFrame()
{
  if(areaId != NONE && directionId != NONE)
  {
    areaId = NONE;
    directionId = NONE;
  }
  if(areaId == NONE && directionId != NONE)
    directionId = NONE;
}

void Scene_Manager::NotifyReshape(int width, int height, int previous_width, int previous_height)
{
  float ar = (float)glutGet(GLUT_WINDOW_WIDTH) / (float)glutGet(GLUT_WINDOW_HEIGHT);
  float angle = 45.0f, near1 = 1.0f, far1 = 2000.0f;

  projection_matrix[0][0] = 1.0f / (ar * tan(angle / 2.0f));
  projection_matrix[1][1] = 1.0f / tan(angle / 2.0f);
  projection_matrix[2][2] = (-near1 - far1) / (near1 - far1);
  projection_matrix[2][3] = 1.0f;
  projection_matrix[3][2] = 2.0f * near1 * far1 / (near1 - far1);
}

void Scene_Manager::SetModelsManager(Managers::Models_Manager*& models_m)
{
	models_manager = models_m;
}
