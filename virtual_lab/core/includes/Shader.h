#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
#include <sstream>

#include <vector>
#include <memory>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Shader{
public:
Shader();
~Shader();

void setUp();
void loadTexture();
void loadShader();

void uniform(std::string name, int i);
void uniform(std::string name, glm::mat4 i);
void uniform(std::string name, glm::vec4 i);
void uniform(std::string name, glm::vec3 i);


std::string p_vertexShader = std::string();
std::string p_fragmentShader = std::string();

std::string vertexShaderCode = std::string();
std::string fragmentShaderCode = std::string();

GLuint program = GLuint();
GLuint VAO = GLuint();

GLuint vertexShader = GLuint();
GLuint fragmentShader = GLuint();
GLuint VBO = GLuint();
GLuint IBO = GLuint();
std::string name = std::string();//for debug
std::vector<float> vertices = {};
std::vector<unsigned int> indices = {};
};