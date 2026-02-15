#include "window_a.h"
#include "shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



 void loop(GLFWwindow* window){
   
    std::unique_ptr<blue::Shader> triangle = std::make_unique<blue::Shader>();

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
    triangle->useShader();


    while(!glfwWindowShouldClose(window)){
    {//main window managemment
      glClearColor(1.0f, 1.0f, 0.4f,1.0f);
      glClear(GL_COLOR_BUFFER_BIT);
      
    triangle->useProgram();
    triangle->draw(); 

      glfwSwapBuffers(window);
    }
     glfwPollEvents();
     }
 }

int main(){
    blue::WindowG* main_window_frames = new blue::WindowG(
        600, 600, "main_window-frame", NULL, NULL
    );
    

    main_window_frames->setUp();
    loop(main_window_frames->window_g);    

    delete main_window_frames; 
}