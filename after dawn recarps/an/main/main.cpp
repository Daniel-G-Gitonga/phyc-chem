#include "window_a.h"
#include "Application.h"


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

    blue::FollowCamera* cam_1= new blue::FollowCamera();


    void scrollCallback(GLFWwindow* window,double xOffset, double yOffset){
        cam_1->fov -= static_cast<float>(yOffset) * 2.0f;
        if(cam_1->fov < 1){
         cam_1->fov = 1.0f;
        }
        if(cam_1->fov > 174){
         cam_1->fov = 173.0f;
        }
        std::cout<<"fov : "<<cam_1->fov<<std::endl;
    }
    void cursorCallBack(GLFWwindow* window, double x_pos, double y_pos){
cam_1->x_pos_c = x_pos;
cam_1->y_pos_c = y_pos;
cam_1->updateFollowCamera();
std::cout<<cam_1->logCamPos();
    }
blue::Shader* triangle(){
    blue::Shader* triangle = new blue::Shader();
    std::cout<<"debug :: 0 ;: "<<triangle<<std::endl;
    triangle->vertices = {
    // Front face (normal: 0,0,1)
    -0.5f,-0.5f, 0.5f,   0.0f,0.0f,1.0f,   0.0f,0.0f,
     0.5f,-0.5f, 0.5f,   0.0f,0.0f,1.0f,   1.0f,0.0f,
     0.5f, 0.5f, 0.5f,   0.0f,0.0f,1.0f,   1.0f,1.0f,
    -0.5f, 0.5f, 0.5f,   0.0f,0.0f,1.0f,   0.0f,1.0f,

    // Back face (normal: 0,0,-1)
    -0.5f,-0.5f,-0.5f,   0.0f,0.0f,-1.0f,  1.0f,0.0f,
     0.5f,-0.5f,-0.5f,   0.0f,0.0f,-1.0f,  0.0f,0.0f,
     0.5f, 0.5f,-0.5f,   0.0f,0.0f,-1.0f,  0.0f,1.0f,
    -0.5f, 0.5f,-0.5f,   0.0f,0.0f,-1.0f,  1.0f,1.0f,

    // Left face (normal: -1,0,0)
    -0.5f,-0.5f,-0.5f,  -1.0f,0.0f,0.0f,   0.0f,0.0f,
    -0.5f,-0.5f, 0.5f,  -1.0f,0.0f,0.0f,   1.0f,0.0f,
    -0.5f, 0.5f, 0.5f,  -1.0f,0.0f,0.0f,   1.0f,1.0f,
    -0.5f, 0.5f,-0.5f,  -1.0f,0.0f,0.0f,   0.0f,1.0f,

    // Right face (normal: 1,0,0)
     0.5f,-0.5f,-0.5f,   1.0f,0.0f,0.0f,   1.0f,0.0f,
     0.5f,-0.5f, 0.5f,   1.0f,0.0f,0.0f,   0.0f,0.0f,
     0.5f, 0.5f, 0.5f,   1.0f,0.0f,0.0f,   0.0f,1.0f,
     0.5f, 0.5f,-0.5f,   1.0f,0.0f,0.0f,   1.0f,1.0f,

    // Top face (normal: 0,1,0)
    -0.5f, 0.5f, 0.5f,   0.0f,1.0f,0.0f,   0.0f,0.0f,
     0.5f, 0.5f, 0.5f,   0.0f,1.0f,0.0f,   1.0f,0.0f,
     0.5f, 0.5f,-0.5f,   0.0f,1.0f,0.0f,   1.0f,1.0f,
    -0.5f, 0.5f,-0.5f,   0.0f,1.0f,0.0f,   0.0f,1.0f,

    // Bottom face (normal: 0,-1,0)
    -0.5f,-0.5f, 0.5f,   0.0f,-1.0f,0.0f,  1.0f,0.0f,
     0.5f,-0.5f, 0.5f,   0.0f,-1.0f,0.0f,  0.0f,0.0f,
     0.5f,-0.5f,-0.5f,   0.0f,-1.0f,0.0f,  0.0f,1.0f,
    -0.5f,-0.5f,-0.5f,   0.0f,-1.0f,0.0f,  1.0f,1.0f
};
//ai generated vertices....

    triangle->indices = {
     0, 1, 2,
    2, 3, 0,

    // Right
    1, 5, 6,
    6, 2, 1,

    // Back
    5, 4, 7,
    7, 6, 5,

    // Left
    4, 0, 3,
    3, 7, 4,

    // Top
    3, 2, 6,
    6, 7, 3,

    // Bottom
    4, 5, 1,
    1, 0, 4

    };//ai generated indices

    triangle->name_program = "rectangle test \"\'\' ::";
    triangle->fragment_shader_path = "..\\..\\main\\triangle_fs.glsl";//note 2 me ;; convert to relative path
    triangle->vertex_shader_path = "..\\..\\main\\triangle_vs.glsl";
    triangle->texture_path = "..\\..\\texture\\abc.png";
std::cout<<"debug :: 1 ;: "<<triangle<<std::endl;
    
    return triangle;
}

int width_c = int();
int height_c = int();
bool first_c = true;

    void framebufferSizecallback(GLFWwindow* window, int width, int height){
if(first_c){
   width_c = width;
   height_c = height;
   glViewport(0,0,width,height); 
first_c = false;
}
    }
int main(){
    blue::WindowG* main_window_frames = new blue::WindowG(
        600, 600, "main_window-frame", NULL, NULL
    );
    Application* main_layer = new Application();
    
    main_window_frames->setUp();  
    blue::Shader* cust_obj =  triangle();
    
    glfwSetScrollCallback(main_window_frames->window_g,scrollCallback);
    glfwSetInputMode(main_window_frames->window_g, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(main_window_frames->window_g, cursorCallBack);
    glfwSetFramebufferSizeCallback(main_window_frames->window_g, framebufferSizecallback);

    main_layer->loop(main_window_frames->window_g, cust_obj, cam_1);//note 2 me:: arg 1 convert to a vector to allow asset management...
    
    delete cam_1;
    delete cust_obj;
    delete main_layer;
    delete main_window_frames; 
}