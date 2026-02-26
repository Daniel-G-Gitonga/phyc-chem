#include "chemical_lab.h"

Lab::~Lab(){}

AppLayer::AppLayer(){
obj_shader->p_vertexShader = "../../shaders/default_vs.glsl";
obj_shader->p_fragmentShader = "../../shaders/default_fs.glsl";

obj_shader->vertices = {
-1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
-1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 
 1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
1.0f,  -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f
};
obj_shader->indices  = {
0,1,2,
0,2,3
};
obj_shader->name = "chem_ing_lab";
obj_shader->setUp();

std::cout<<"AppLayer--=> here_4"<<std::endl;
}
AppLayer::~AppLayer(){

}

void AppLayer::onUpdate(float  ts){

glClearColor(1.0f,1.0f,1.0f,1.0f);
glClear(GL_COLOR_BUFFER_BIT);

//uniforms
glUseProgram(obj_shader->program);
obj_shader->uniform("model",glm::scale(glm::rotate(glm::mat4(1.0f), glm::sin(static_cast<float>(glfwGetTime())) * glm::radians(180.0f),glm::vec3(0.0f,0.0f,1.0f)), glm::vec3(0.4f)));
obj_shader->uniform("f_color",glm::vec3(0.4f,0.8f,0.3f));
//std::cout<<"on update func"<<std::endl;
//chemical logic updates here
//std::cout<<ts<<std::endl;


}
void AppLayer::onRender(){
glClearColor(1.0f,1.0f,1.0f,1.0f);
glClear(GL_COLOR_BUFFER_BIT);

//std::cout<<"on render func"<<std::endl;
glUseProgram(obj_shader->program);
glBindVertexArray(obj_shader->VAO);
glDrawElements(GL_TRIANGLES, obj_shader->indices.size(), GL_UNSIGNED_INT, 0);

}
void AppLayer::onEvents(){
    //future project::

}

OverLayLayer::OverLayLayer(){
   obj_shader->p_vertexShader = "../../shaders/default_vs.glsl";
   obj_shader->p_fragmentShader = "../../shaders/default_fs.glsl";

    obj_shader->vertices = {
    -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    -1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 
    1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    1.0f,  -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f
        };
    obj_shader->indices  = {
    0,1,2,
    0,2,3
    };
    obj_shader->name = "chem_ing_lab";
    obj_shader->setUp();

    std::cout<<"AppLayer--=> here_4"<<std::endl;

}
OverLayLayer::~OverLayLayer(){
    
}
void OverLayLayer::onUpdate(float ts){
glClearColor(0.0f,0.0f,0.0f,1.0f);
glClear(GL_COLOR_BUFFER_BIT);    
//uniforms
glUseProgram(obj_shader->program);
obj_shader->uniform("model",glm::scale(glm::translate(glm::mat4(1.0f),glm::vec3(-0.5f,-0.5f,0.0f)),glm::vec3(0.2f,0.1f,0.0f)));
obj_shader->uniform("f_color",glm::vec3(1.0f,0.4f,0.2f));
}
void OverLayLayer::onRender(){

    //std::cout<<"on render func"<<std::endl;
    glUseProgram(obj_shader->program);
    glBindVertexArray(obj_shader->VAO);
    glDrawElements(GL_TRIANGLES, obj_shader->indices.size(), GL_UNSIGNED_INT, 0);
}
void OverLayLayer::onEvents(){}