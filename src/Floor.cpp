#include "Floor.h"

using namespace BasicEngine;
using namespace Rendering;

#define PI 3.14159265

Floor::Floor()
{

}

Floor::~Floor()
{

}

void Floor::Create()
{
  GLuint vao;
  GLuint vbo;
  GLuint ibo;

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
  vertices.push_back(VertexFormat(glm::vec3(-8.0, 0.0, 8.0), glm::vec4((float)62/255, (float)107/255, 1.0, 1)));
  vertices.push_back(VertexFormat(glm::vec3( 8.0, 0.0, 8.0), glm::vec4((float)62/255, (float)107/255, 1.0, 1)));
  vertices.push_back(VertexFormat(glm::vec3( 7.0, 0.5, 7.0), glm::vec4((float)62/255, (float)107/255, 1.0, 1)));
  vertices.push_back(VertexFormat(glm::vec3(-7.0, 0.5, 7.0), glm::vec4((float)62/255, (float)107/255, 1.0, 1)));

  //right -- white
  vertices.push_back(VertexFormat(glm::vec3(7.0, 0.5, 7.0), glm::vec4((float)62/255, (float)107/255, 1.0, 1)));
  vertices.push_back(VertexFormat(glm::vec3(7.0, 0.5, -7.0), glm::vec4((float)62/255, (float)107/255, 1.0, 1)));
  vertices.push_back(VertexFormat(glm::vec3(8.0, 0.0, -8.0), glm::vec4((float)62/255, (float)107/255, 1.0, 1)));
  vertices.push_back(VertexFormat(glm::vec3(8.0, 0.0, 8.0), glm::vec4((float)62/255, (float)107/255, 1.0, 1)));

  //back -- orange
  vertices.push_back(VertexFormat(glm::vec3(-8.0, 0.0, -8.0), glm::vec4((float)62/255, (float)107/255, 1.0, 1)));
  vertices.push_back(VertexFormat(glm::vec3( 8.0, 0.0, -8.0), glm::vec4((float)62/255, (float)107/255, 1.0, 1)));
  vertices.push_back(VertexFormat(glm::vec3( 7.0, 0.5, -7.0), glm::vec4((float)62/255, (float)107/255, 1.0, 1)));
  vertices.push_back(VertexFormat(glm::vec3(-7.0, 0.5, -7.0), glm::vec4((float)62/255, (float)107/255, 1.0, 1)));

  //left -- yellow
  vertices.push_back(VertexFormat(glm::vec3(-8.0, 0.0, -8.0), glm::vec4((float)62/255, (float)107/255, 1.0, 1)));
  vertices.push_back(VertexFormat(glm::vec3(-8.0, 0.0, 8.0), glm::vec4((float)62/255, (float)107/255, 1.0, 1)));
  vertices.push_back(VertexFormat(glm::vec3(-7.0, 0.5, 7.0), glm::vec4((float)62/255, (float)107/255, 1.0, 1)));
  vertices.push_back(VertexFormat(glm::vec3(-7.0, 0.5, -7.0), glm::vec4((float)62/255, (float)107/255, 1.0, 1)));

  //upper -- green
  vertices.push_back(VertexFormat(glm::vec3( 7.0, 0.5, 7.0), glm::vec4((float)102/255, (float)177/255, 1.0, 1)));
  vertices.push_back(VertexFormat(glm::vec3(-7.0, 0.5, 7.0), glm::vec4((float)102/255, (float)177/255, 1.0, 1)));
  vertices.push_back(VertexFormat(glm::vec3(-7.0, 0.5, -7.0), glm::vec4((float)102/255, (float)177/255, 1.0, 1)));
  vertices.push_back(VertexFormat(glm::vec3( 7.0, 0.5, -7.0), glm::vec4((float)102/255, (float)177/255, 1.0, 1)));

  //bottom -- blue
  vertices.push_back(VertexFormat(glm::vec3(-8.0, 0.0, -8.0), glm::vec4(0, 0, 1, 1))); // 59/255, 177/255, 183/255
  vertices.push_back(VertexFormat(glm::vec3( 8.0, 0.0, -8.0), glm::vec4(0, 0, 1, 1)));
  vertices.push_back(VertexFormat(glm::vec3( 8.0, 0.0, 8.0), glm::vec4(0, 0, 1, 1)));
  vertices.push_back(VertexFormat(glm::vec3(-8.0, 0.0, 8.0), glm::vec4(0, 0, 1, 1)));

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

  rotation_speed = glm::vec3(0.0, -5.0, 0.0);
  rotation = glm::vec3(0.0, 0.0, 0.0);
  translate = glm::vec3(0.0, -3.5, 0.0);
  translate_matrix = glm::translate(glm::mat4(1.0f), translate);
}

void Floor::Update()
{

}

void Floor::Move(int areaId, int directionId)
{

}

void Floor::Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix)
{
    glUniform1i(0, 1);

    rotation = 0.01f * rotation_speed + rotation;

    glm::vec3 rotation_sin = glm::vec3(rotation.x * PI / 180, rotation.y * PI / 180, rotation.z * PI / 180);

    glUseProgram(program);
    glUniform3f(glGetUniformLocation(program, "rotation"), rotation_sin.x, rotation_sin.y, rotation_sin.z);
    glUniformMatrix4fv(glGetUniformLocation(program, "translate_matrix"), 1, GL_FALSE, &translate_matrix[0][0]);

    glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"), 1, GL_FALSE, &view_matrix[0][0]);
    glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"), 1, GL_FALSE, &projection_matrix[0][0]);
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void Floor::PrintDetails()
{

}
