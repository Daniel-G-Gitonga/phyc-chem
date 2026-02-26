#pragma once
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "chemical_lab.h"

#include <vector>
#include <memory>

#include <type_traits>

class Window {
private:


protected:
GLFWwindow* createWindow(int width, int height, std::string title);

};

class AppSetup{
public:
int width = int();
int height = int();
std::string title =std::string();

};

class Application : public Window {
public:
void m_print(std::string message);

Application(AppSetup* app_specifications);
~Application();

void run();

template<typename T>
void pushLayer(){
std::cout<<"here"<<std::endl;
std::cout<<"here_2"<<std::endl;
layer.emplace_back(std::make_unique<T>());
std::cout<<"here_3"<<std::endl;
}

void transitionLayers();
void suspendLayers();


GLFWwindow* window = nullptr;
private:
void stop();
bool main_appRunning = true;

std::vector<std::unique_ptr<Lab>> layer;

};


