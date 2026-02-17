#pragma once

#include <iostream>
#include "shader.h"
#include "camera.h"


class Application{
public:
void loop(GLFWwindow* window, blue::Shader* shader_obj, blue::FollowCamera* cam);//cast between the pointers to facilitate any inherited obj to take place

private:
};