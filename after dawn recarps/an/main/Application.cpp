#include "Application.h"


void Application::loop(GLFWwindow* window, blue::Shader* shader_obj, blue::FollowCamera* cam){
shader_obj->useShader();


glEnable(GL_DEPTH_TEST);
glEnable(GL_BLEND);
 while(!glfwWindowShouldClose(window)){
    glClearColor(0.20f, 0.20f, 0.30f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

{
glDisable(GL_DEPTH_TEST);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
 shader_obj->useProgram();
 shader_obj->setUniform("model",glm::translate(glm::rotate(glm::mat4(1.0f),glm::sin(static_cast<float>(glfwGetTime())) * glm::radians(180.0f),glm::vec3(0.0f,1.0f,1.0f)),glm::vec3(0.0f)));
shader_obj->setUniform("view", cam->setUpCamera());
shader_obj->setUniform("projection",glm::perspective(glm::radians(cam->fov),600.0f/600.0f,0.1f,100.0f));
 //for optimazation
 if(first){
 shader_obj->setUniform("texture_s",0);
 first = false;
 }
 shader_obj->draw();

glEnable(GL_DEPTH_TEST);
    glfwPollEvents();
    glfwSwapBuffers(window);
 
 }
 }   
}