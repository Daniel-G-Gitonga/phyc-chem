#pragma once
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


namespace blue{
    class Camera{
public:
glm::mat4 setUpCamera(GLFWwindow* window);


protected:
glm::vec3 camera_pos = glm::vec3(0.0f,0.0f,-1.0f);
glm::vec3 camera_front = glm::vec3(0.0f,0.0f,-1.0f);
glm::vec3 world_up = glm::vec3(0.0f, 1.0f, 0.0f);

 glm::mat4 camera = glm::mat4(1.0f);
double x_pos_c = double();
double y_pos_c = double();//c = cursor 

double x_pos_n = double();
double y_pos_n =  double();//n = new_position


float x_offset = float();
float y_offset = float();

float yaw = 90.0f;
float pitch = 90.0f;

bool first_c = true;;
    };

    class FollowCamera : public Camera{
public:

void updateFollowCamera(GLFWwindow* window);
private:
    };
}