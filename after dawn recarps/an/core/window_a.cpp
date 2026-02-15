 #include "window_a.h"


blue::WindowG::WindowG(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share){
this->width = width;
this->height = height;
this-> title = title;
this->monitor = monitor;
this->share = share;

if(!glfwInit()){
     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
     glfwWindowHint(GLFW_POSITION_X, 300);
     glfwWindowHint(GLFW_POSITION_Y, 200);
}
}
 


 void blue::WindowG::setUp(){
     
     GLFWwindow* window = glfwCreateWindow(width, height, title, monitor, share);
     if(!window){
      printf("failed to create the window...");
     }
     window_g = window;//allow main window to be accessed outside this func
     
    glfwMakeContextCurrent(window_g);

     if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
       printf("failed to initialize glad ...\n");
     }
     glViewport(0, 0, 600, 600);

      

    
 }
 

 blue::WindowG::~WindowG(){
      glfwDestroyWindow(window_g);
      glfwTerminate();
    printf("goodbye from the main frames of the window ...");
 }