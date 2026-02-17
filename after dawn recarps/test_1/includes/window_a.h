#pragma once

#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace blue{
    class WindowG{
private:
int width;
int height;
GLFWwindow* share;
GLFWmonitor* monitor;
const char* title;
int i;

public:

//_s sub window
int width_s;
int height_s;
GLFWwindow*  share_s;
GLFWmonitor* monitor_s;
const char*  title_s;

GLFWwindow* window_g;
WindowG(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);

void setUp();

~WindowG();
    };
}