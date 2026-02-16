#include "window_a.h"
#include "Application.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


blue::Shader* triangle(){
    blue::Shader* triangle = new blue::Shader();
    std::cout<<"debug :: 0 ;: "<<triangle<<std::endl;
    triangle->vertices = { 
                                  -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                                   0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
                                   0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                                   0.0f, -0.5f,0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f
                                   
    };

    triangle->indices = {
        0, 1, 3,
        1, 2, 3

    };
    triangle->name_program = "rectangle test \"\'\' ::";
    triangle->fragment_shader_path = "C:\\Users\\USER\\Desktop\\an\\main\\triangle_fs.glsl";//note 2 me ;; convert to relative path
    triangle->vertex_shader_path = "C:\\Users\\USER\\Desktop\\an\\main\\triangle_vs.glsl";
std::cout<<"debug :: 1 ;: "<<triangle<<std::endl;
    
    return triangle;
}


int main(){
    blue::WindowG* main_window_frames = new blue::WindowG(
        600, 600, "main_window-frame", NULL, NULL
    );
    Application* main_layer = new Application();

    main_window_frames->setUp();  
    blue::Shader* cust_obj =  triangle();
    main_layer->loop(main_window_frames->window_g, cust_obj);//note 2 me:: arg 1 convert to a vector to allow asset management...
    
    delete cust_obj;
    delete main_layer;
    delete main_window_frames; 
}