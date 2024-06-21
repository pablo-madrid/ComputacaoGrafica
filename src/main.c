#include "glad/glad.h"
#include <GLFW/glfw3.h>

//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>

#include <GL/glut.h>

#include "world/window.h"
#include "world/shader.h"

int main() {
  createWindow();

  struct Shader shader = createShader("res/shaders/vertex.vs", "res/shaders/fragment.fs");
  
  float vertices[] = {
    // positions         // normals
     0.5f, -0.5f, 0.0f,    // bottom right
    -0.5f, -0.5f, 0.0f,    // bottom left
     0.0f,  0.5f, 0.0f     // top
  };

  //talvez fazer rotation a mão
  // int time = glutGet(GLUT_ELAPSED_TIME) / 2000; //gerar um numero aleatório pro angulo
  // float rotation[4][4] = {
  //   {cos(time), 0.0, -sin(time), 0.0},
  //   {0.0, 1.0, 0.0, 0.0},
  //   {sin(time), 0.0, cos(time), 0.0},
  //   {0.0, 0.0, -3.0, 1.0}
  // };

  // GLint rotation_loc[4][4] = glGetUniformLocation(shader.ID, "trans"); //Matriz de transformação
  // glUniformMatrix4fv(rotation_loc, 1, GL_FALSE, *rotation);

  // Rotations outro jeito possivel talvez
  //glm::mat4 trans = glm::mat4(1.0f); //matriz de transformação
  //trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0)); //aplicando a rotação na matriz (no eixo z)

  
  unsigned int VBO, VAO;
  glGenVertexArrays(1, &VAO);
  glEnableVertexAttribArray(1);
  glGenBuffers(1, &VBO);
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  GLint angle_location = glGetUniformLocation(shader.ID, "angle");
  
  // Position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  
  useShader(shader);
  float angle = 45.0f;
  
  while (!glfwWindowShouldClose(window.self)) {
    updateWindow();
    angle += 0.1f;
    glUniform1f(angle_location ,angle);
    
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glfwSwapBuffers(window.self);
    glfwPollEvents();
  }

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  terminateWindow();
   
  return 0;
}