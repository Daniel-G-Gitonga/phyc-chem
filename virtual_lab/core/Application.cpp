#include "Application.h"


void Application::m_print(std::string message){
    std::cout<<" application :: "<<message<<std::endl;
}//setup test

Application::Application(AppSetup* app_specifications){
    if(app_specifications->width == int()){
app_specifications->width = 600;
    }
    if(app_specifications->height == int()){
app_specifications->height = 600;
    }
    if(app_specifications->title == std::string()){
app_specifications->title = "NULL";
    }

window  = createWindow(app_specifications->width,app_specifications->height,app_specifications->title);
glfwMakeContextCurrent(window);

if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
    std::cout<<"failure loading glad"<<std::endl;
    return;
}

}
Application::~Application(){
std::cout<<"App destroyed"<<std::endl;
stop();
}

void Application::run(){

float delta_time = float();
float time_1 = float();
float time_f  = float(0);

while (main_appRunning)
{
if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS || glfwWindowShouldClose(window)){
main_appRunning = false;//will change on events addition
}
time_1 = static_cast<float>(glfwGetTime());
delta_time =  time_1 - time_f;
time_f = time_1;



for (const auto& layer_a : layer)
{
 layer_a->onUpdate(delta_time);
}

for (const auto& layer_a : layer)
{
 layer_a->onRender();
}

glfwPollEvents();
glfwSwapBuffers(window);
}


}

void Application::stop(){

glfwDestroyWindow(window);
glfwTerminate();
}

GLFWwindow* Window::createWindow(int width, int height, std::string title){
glfwInit();
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
glfwWindowHint(GLFW_SAMPLES, 3);

GLFWwindow* win =  glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
return win;
}