#include <iostream>
#include "window_a.h"
#include "shader.h"

bool first = true;
void frameBuffersizecallback(GLFWwindow* window, int width, int height){
if(width != height){
width = height;
} 
glViewport( 5, 5, width, height);
first = false;
}


int main(){

blue::WindowG* main_win = new blue::WindowG(
    600, 600, "main_window", NULL, NULL
);
main_win->setUp();

blue::Shader* obj_1 = new blue::Shader();
obj_1->fragment_shader_path = "../main/fs.glsl";
obj_1->vertex_shader_path = "../main/vs.glsl";
obj_1->vertices = {
                                  -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                                   0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
                                   0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                                   0.0f, -0.5f,0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f

};
obj_1->indices = {
        0, 1, 3,
        1, 2, 3
};

obj_1->useShader();

glViewport(0,0,600,600);
glfwSetFramebufferSizeCallback(main_win->window_g, frameBuffersizecallback);


while(!glfwWindowShouldClose(main_win->window_g)){
glClearColor(0.0f,0.0f,0.0f,1.0f);
glClear(GL_COLOR_BUFFER_BIT);


obj_1->useProgram();
obj_1->setUniform("model",glm::rotate(glm::mat4(1.0f),glm::sin(static_cast<float>(glfwGetTime())) * glm::radians(90.0f), glm::vec3(0.0f,0.0f,1.0f)));
obj_1->draw();

glfwPollEvents();
glfwSwapBuffers(main_win->window_g);





}

delete obj_1;
delete main_win;
    return 0;
}