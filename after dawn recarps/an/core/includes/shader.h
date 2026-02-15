#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <memory>



/*
load shader from loc,
store in a class accesible loc
verts loaded,
buffers, vbo vao, ibo,
send to shader
compile shader
attach compiled shader to a program
link & use program
draw using the linked program
*/

namespace blue{
    class Shader{
public:
std::vector<float> vertices; 
std::vector<unsigned int> indices;
std::string name_program = std::string();

std::string vertex_shader_path = std::string();
std::string fragment_shader_path = std::string();


Shader();
void useShader();
void useProgram();
void draw();
~Shader();


private:
void loadShader();
void renderEngine();
void check_err();

const char* vertex_shader;
const char* fragment_shader;

GLuint fragment_shader_obj;
GLuint vertex_shader_obj;
GLuint program;

GLuint VAO;
GLuint VBO;
GLuint IBO;

    };
}