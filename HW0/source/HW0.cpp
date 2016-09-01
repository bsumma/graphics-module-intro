#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "common/Angel.h"
#include "shader.h"

#include <stdlib.h>
#include <stdio.h>


static void error_callback(int error, const char* description)
{
  fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(void)
{
  GLFWwindow* window;
  GLuint vertex_shader, fragment_shader, program;
  GLint vpos_location;
  
  glfwSetErrorCallback(error_callback);
  
  if (!glfwInit())
    exit(EXIT_FAILURE);
  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
  window = glfwCreateWindow(512, 512, "Simple example", NULL, NULL);
  if (!window)
    {
    glfwTerminate();
    exit(EXIT_FAILURE);
    }
  
  glfwSetKeyCallback(window, key_callback);
  
  glfwMakeContextCurrent(window);
  gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
  glfwSwapInterval(1);
  
  Angel::vec2 shape[6]     = { Angel::vec2( -0.5, -0.5),
                               Angel::vec2( -0.5, 0.5 ),
                               Angel::vec2( 0.5, 0.5 ),
                               Angel::vec2( -0.5, -0.5),
                               Angel::vec2( 0.5, 0.5 ),
                               Angel::vec2( 0.5, -0.5 )};

  GLuint vao, buffer;

  // Create a vertex array object
  glGenVertexArrays( 1, &vao );
  //Set GL state to use vertex array object
  glBindVertexArray( vao );
  
  //Generate buffer to hold our vertex data
  glGenBuffers( 1, &buffer );
  //Set GL state to use this buffer
  glBindBuffer( GL_ARRAY_BUFFER, buffer );

  //Send vertex data to GPU
  glBufferData( GL_ARRAY_BUFFER, sizeof(shape), shape, GL_STATIC_DRAW );

  std::string vshader = shader_path + "vshader.glsl";
  std::string fshader = shader_path + "fshader.glsl";
  
  GLchar* vertex_shader_source = readShaderSource(vshader.c_str());
  GLchar* fragment_shader_source = readShaderSource(fshader.c_str());

  vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex_shader, 1, (const GLchar**) &vertex_shader_source, NULL);
  glCompileShader(vertex_shader);
  check_shader_compilation(vshader, vertex_shader);
  
  fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment_shader, 1, (const GLchar**) &fragment_shader_source, NULL);
  glCompileShader(fragment_shader);
  check_shader_compilation(fshader, fragment_shader);
  
  program = glCreateProgram();
  glAttachShader(program, vertex_shader);
  glAttachShader(program, fragment_shader);

  glLinkProgram(program);
  check_program_link(program);
  
  glBindFragDataLocation(program, 0, "fragColor");

  vpos_location   = glGetAttribLocation(program, "vPos");
  
  glEnableVertexAttribArray(vpos_location);
  glVertexAttribPointer( vpos_location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );

  glClearColor(1.0, 1.0, 1.0, 1.0);
  
  //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
  
  while (!glfwWindowShouldClose(window))
    {
    int width, height;
    
    glfwGetFramebufferSize(window, &width, &height);
    
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glUseProgram(program);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    
    glfwSwapBuffers(window);
    glfwPollEvents();
    }
  
  glfwDestroyWindow(window);
  
  glfwTerminate();
  exit(EXIT_SUCCESS);
}

