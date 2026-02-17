#include "Application.h"

void Application::loop(GLFWwindow* window, blue::Shader* shader_obj, blue::FollowCamera* cam){
shader_obj->useShader();

glEnable(GL_DEPTH_TEST);
 while(!glfwWindowShouldClose(window)){
    glClearColor(0.20f, 0.20f, 0.30f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

 shader_obj->useProgram();
 shader_obj->setUniform("model",glm::rotate(glm::mat4(1.0f),glm::sin(static_cast<float>(glfwGetTime())) * glm::radians(180.0f),glm::vec3(0.0f,1.0f,1.0f)));
 //cam->updateFollowCamera(window);
 //shader_obj->setUniform("view", cam->setUpCamera(window));
 //shader_obj->setUniform("projection",glm::ortho(0.0f,600.0f,0.0f,600.0f, 0.01f, 100.0f));
 shader_obj->draw();

    glfwPollEvents();
    glfwSwapBuffers(window);
 }   
}