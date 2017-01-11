#include "CubeIndex.h"
using namespace BasicEngine;
using namespace Rendering;

#define PI 3.14159265

CubeIndex::CubeIndex()
{
  isMoving = false;
  cube_position = NONE;
  rotation_direction = 1;
  translate_direction = 1;

  rotation_speed = glm::vec3(0.0, 0.0, 0.0);
  rotation = glm::vec3(0.0, 0.0, 0.0);

  translate_speed = glm::vec3(0.0, 0.0, 0.0);
  translate = glm::vec3(0.0, 0.0, 0.0);

  next_rotation = rotation;
}

CubeIndex::CubeIndex(int positionId)
{
  isMoving = false;
  cube_position = positionId;

  rotation_direction = 1;
  translate_direction = 1;

  rotation_speed = glm::vec3(0.0, 0.0, 0.0);
  rotation = glm::vec3(0.0, 0.0, 0.0);

  translate_speed = glm::vec3(0.0, 0.0, 0.0);

  next_rotation = rotation;

  switch (positionId)
  {
      // front layer
      case UP_LEFT_FRONT:
          translate = glm::vec3(-2.0, 2.0, 2.0);
      break;
      case UP_MIDDLE_FRONT:
          translate = glm::vec3(0.0, 2.0, 2.0);
      break;
      case UP_RIGHT_FRONT:
          translate = glm::vec3(2.0, 2.0, 2.0);
      break;
      case MIDDLE_LEFT_FRONT:
          translate = glm::vec3(-2.0, 0.0, 2.0);
      break;
      case MIDDLE_MIDDLE_FRONT:
          translate = glm::vec3(0.0, 0.0, 2.0);
      break;
      case MIDDLE_RIGHT_FRONT:
          translate = glm::vec3(2.0, 0.0, 2.0);
      break;
      case DOWN_LEFT_FRONT:
          translate = glm::vec3(-2.0, -2.0, 2.0);
      break;
      case DOWN_MIDDLE_FRONT:
          translate = glm::vec3(0.0, -2.0, 2.0);
      break;
      case DOWN_RIGHT_FRONT:
          translate = glm::vec3(2.0, -2.0, 2.0);
      break;

      // middle layer
      case UP_LEFT_MIDDLE:
          translate = glm::vec3(-2.0, 2.0, 0.0);
      break;
      case UP_MIDDLE_MIDDLE:
          translate = glm::vec3(0.0, 2.0, 0.0);
      break;
      case UP_RIGHT_MIDDLE:
          translate = glm::vec3(2.0, 2.0, 0.0);
      break;
      case MIDDLE_LEFT_MIDDLE:
          translate = glm::vec3(-2.0, 0.0, 0.0);
      break;
      case MIDDLE_MIDDLE_MIDDLE:
          translate = glm::vec3(0.0, 0.0, 0.0);
      break;
      case MIDDLE_RIGHT_MIDDLE:
          translate = glm::vec3(2.0, 0.0, 0.0);
      break;
      case DOWN_LEFT_MIDDLE:
          translate = glm::vec3(-2.0, -2.0, 0.0);
      break;
      case DOWN_MIDDLE_MIDDLE:
          translate = glm::vec3(0.0, -2.0, 0.0);
      break;
      case DOWN_RIGHT_MIDDLE:
          translate = glm::vec3(2.0, -2.0, 0.0);
      break;

      // rear layer
      case UP_LEFT_REAR:
          translate = glm::vec3(-2.0, 2.0, -2.0);
      break;
      case UP_MIDDLE_REAR:
          translate = glm::vec3(0.0, 2.0, -2.0);
      break;
      case UP_RIGHT_REAR:
          translate = glm::vec3(2.0, 2.0, -2.0);
      break;
      case MIDDLE_LEFT_REAR:
          translate = glm::vec3(-2.0, 0.0, -2.0);
      break;
      case MIDDLE_MIDDLE_REAR:
          translate = glm::vec3(0.0, 0.0, -2.0);
      break;
      case MIDDLE_RIGHT_REAR:
          translate = glm::vec3(2.0, 0.0, -2.0);
      break;
      case DOWN_LEFT_REAR:
          translate = glm::vec3(-2.0, -2.0, -2.0);
      break;
      case DOWN_MIDDLE_REAR:
          translate = glm::vec3(0.0, -2.0, -2.0);
      break;
      case DOWN_RIGHT_REAR:
          translate = glm::vec3(2.0, -2.0, -2.0);
      break;
  }
}

CubeIndex::~CubeIndex()
{

}

void CubeIndex::Create()
{
    GLuint vao;
    GLuint vbo;
    GLuint ibo;

    time(&timer);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    std::vector<VertexFormat> vertices;
    std::vector<unsigned int> indices =
    { 0, 1, 2, 0, 2, 3, //front
      4, 5, 6, 4, 6, 7, //right
      8, 9, 10, 8, 10, 11, //back
      12, 13, 14, 12, 14, 15, //left
      16, 17, 18, 16, 18, 19, //upper
      20, 21, 22, 20, 22, 23
    }; //bottom

    //front -- red
    vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, 1.0), glm::vec4(1, 0, 0, 1)));
    vertices.push_back(VertexFormat(glm::vec3( 1.0, -1.0, 1.0), glm::vec4(1, 0, 0, 1)));
    vertices.push_back(VertexFormat(glm::vec3( 1.0, 1.0, 1.0), glm::vec4(1, 0, 0, 1)));
    vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, 1.0), glm::vec4(1, 0, 0, 1)));

    //right -- white
    vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, 1.0), glm::vec4(1, 1, 1, 1)));
    vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, -1.0), glm::vec4(1, 1, 1, 1)));
    vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, -1.0), glm::vec4(1, 1, 1, 1)));
    vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, 1.0), glm::vec4(1, 1, 1, 1)));

    //back -- orange
    vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, -1.0), glm::vec4(1, 0.5, 0, 1)));
    vertices.push_back(VertexFormat(glm::vec3( 1.0, -1.0, -1.0), glm::vec4(1, 0.5, 0, 1)));
    vertices.push_back(VertexFormat(glm::vec3( 1.0, 1.0, -1.0), glm::vec4(1, 0.5, 0, 1)));
    vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, -1.0), glm::vec4(1, 0.5, 0, 1)));

    //left -- yellow
    vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, -1.0), glm::vec4(1, 1, 0, 1)));
    vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, 1.0), glm::vec4(1, 1, 0, 1)));
    vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, 1.0), glm::vec4(1, 1, 0, 1)));
    vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, -1.0), glm::vec4(1, 1, 0, 1)));

    //upper -- green
    vertices.push_back(VertexFormat(glm::vec3( 1.0, 1.0, 1.0), glm::vec4(0.0, 0.5, 0, 1)));
    vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, 1.0), glm::vec4(0.0, 0.5, 0, 1)));
    vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, -1.0), glm::vec4(0.0, 0.5, 0, 1)));
    vertices.push_back(VertexFormat(glm::vec3( 1.0, 1.0, -1.0), glm::vec4(0.0, 0.5, 0, 1)));

    //bottom -- blue
    vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, -1.0), glm::vec4(0, 0, 1, 1)));
    vertices.push_back(VertexFormat(glm::vec3( 1.0, -1.0, -1.0), glm::vec4(0, 0, 1, 1)));
    vertices.push_back(VertexFormat(glm::vec3( 1.0, -1.0, 1.0), glm::vec4(0, 0, 1, 1)));
    vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, 1.0), glm::vec4(0, 0, 1, 1)));

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VertexFormat), &vertices[0], GL_STATIC_DRAW);

    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::color)));
    glBindVertexArray(0);

    this->vao = vao;
    this->vbos.push_back(vbo);
    this->vbos.push_back(ibo);
}

void CubeIndex::Update()
{
    rotation = rotation_direction * 0.1f * rotation_speed + rotation;
    rotation_sin = glm::vec3(rotation.x * PI / 180, rotation.y * PI / 180, rotation.z * PI / 180);

    translate = translate_direction * 0.01f * translate_speed + translate;
    translate_matrix = glm::translate(glm::mat4(1.0f), translate);

    if(abs(rotation.x - next_rotation.x) > 0 && abs(rotation.x - next_rotation.x) <= 5)
    {
      rotation_speed.x = 0;
      rotation = next_rotation;
      isMoving = false;
    }

    if(abs(rotation.y - next_rotation.y) > 0 && abs(rotation.y - next_rotation.y) <= 5)
    {
      rotation_speed.y = 0;
      rotation = next_rotation;
      isMoving = false;
    }

    if(rotation == next_rotation)
      isMoving = false;

    ChangePositionIdIfNeeded();
}

void CubeIndex::Move(int areaId, int directionId)
{
    if (areaId == NONE || directionId == NONE)
        return;

    if (isMoving)
        return;

    if(!PartOfTheLayer(areaId, directionId))
    {
        areaId = NONE;
        directionId = NONE;
    }
    else
    {
        switch (directionId) {
          case GLUT_KEY_UP:
              rotation_speed = glm::vec3(5.0, 0.0, 0.0);
              rotation_direction = -1;
              next_rotation.x -= 90;
              
              areaId = NONE;
              directionId = NONE;
          break;
          case GLUT_KEY_DOWN:
              rotation_speed = glm::vec3(5.0, 0.0, 0.0);
              rotation_direction = 1;
              next_rotation.x += 90;
              areaId = NONE;
              directionId = NONE;
          break;
          case GLUT_KEY_LEFT:
              rotation_speed = glm::vec3(0.0, 5.0, 0.0);
              rotation_direction = -1;
              next_rotation.y -= 90;
              areaId = NONE;
              directionId = NONE;
          break;
          case GLUT_KEY_RIGHT:
              rotation_speed = glm::vec3(0.0, 5.0, 0.0);
              rotation_direction = 1;
              next_rotation.y += 90;
              areaId = NONE;
              directionId = NONE;
          break;
          default:
              rotation_speed = glm::vec3(0.0, 0.0, 0.0);
              rotation_direction = 1;
              areaId = NONE;
              directionId = NONE;
          break;
        }
    }

    isMoving = true;
}

void CubeIndex::Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix)
{
    glUseProgram(program);
    glBindVertexArray(vao);

    glUniform3f(glGetUniformLocation(program, "rotation"), rotation_sin.x, rotation_sin.y, rotation_sin.z);
    glUniformMatrix4fv(glGetUniformLocation(program, "translate_matrix"), 1, GL_FALSE, &translate_matrix[0][0]);

    glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"), 1, GL_FALSE, &view_matrix[0][0]);
    glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"), 1, GL_FALSE, &projection_matrix[0][0]);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

bool CubeIndex::PartOfTheLayer(int areaId, int directionId)
{
    areaId = areaId % 50;
    if (directionId == GLUT_KEY_UP || directionId == GLUT_KEY_DOWN)
    {
        int aux = areaId;
        while (aux <= 27)
        {
            if(aux == cube_position)
              return true;
            aux += 3;
        }
        aux = areaId;
        while (aux > 0)
        {
            if(aux == cube_position)
              return true;
            aux -= 3;
        }
    }

    if (directionId == GLUT_KEY_LEFT || directionId == GLUT_KEY_RIGHT)
    {
        if(areaId > 0 && areaId < 4)
        {
            if(cube_position == 1 || cube_position == 2 || cube_position == 3 )
              return true;
            if(cube_position == 10 || cube_position == 11 || cube_position == 12 )
              return true;
            if(cube_position == 19 || cube_position == 20 || cube_position == 21 )
              return true;
        }
        if(areaId >= 4 && areaId < 7)
        {
            if(cube_position == 4 || cube_position == 5 || cube_position == 6 )
              return true;
            if(cube_position == 13 || cube_position == 14 || cube_position == 15 )
              return true;
            if(cube_position == 22 || cube_position == 23 || cube_position == 24 )
              return true;
        }
        if(areaId >= 7 && areaId <10)
        {
            if(cube_position == 7 || cube_position == 8 || cube_position == 9 )
              return true;
            if(cube_position == 16 || cube_position == 17 || cube_position == 18 )
              return true;
            if(cube_position == 25 || cube_position == 26 || cube_position == 27 )
              return true;
        }
    }

    return false;
}

void CubeIndex::ChangePositionIdIfNeeded()
{

}

void CubeIndex::PrintDetails()
{
  printf("POZITIE: %d\n", cube_position);
  printf("DIRECTIE ROTATIE: %d\n", rotation_direction);
  printf("UNGHI X ROTATIE: %f\n", rotation.x);
  printf("UNGHI Y ROTATIE: %f\n", rotation.y);
  printf("MOVING: %d\n", isMoving);
  printf("TRANSLATE X: %f\nTRANSLATE Y: %f\nTRANSLATE Z: %f\n\n\n", translate.x, translate.y, translate.z);
}
