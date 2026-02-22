#include "Application.h"

   #include "stb_image.h"



void Application::loop(GLFWwindow* window, blue::Shader* shader_obj, blue::FollowCamera* cam){
shader_obj->useShader();

GLuint over_program = GLuint();
GLuint cube_program = GLuint();

GLuint program_cube_map, program_main_cube;

shader_obj->useShader();
program_main_cube = shader_obj->program;

shader_obj->name_program = "cube_map ";
shader_obj->vertex_shader_path = "..\\..\\main\\cubemap_vs.glsl";
shader_obj->fragment_shader_path = "..\\..\\main\\cubemap_fs.glsl";
shader_obj->useShader();
program_cube_map = shader_obj->program;

/*
framebuffer recall...
*/
////////////////////////////////
//_

GLuint fbo, rbo;
glGenFramebuffers(1, &fbo);
glBindFramebuffer(GL_FRAMEBUFFER, fbo);

GLuint texture;
glGenTextures(1, &texture);
glBindTexture(GL_TEXTURE_2D, texture);

glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,600,600,0,GL_RGB,GL_UNSIGNED_BYTE, NULL);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glBindTexture(GL_TEXTURE_2D, 0);


glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,GL_TEXTURE_2D,texture,0);



glGenRenderbuffers(1, &rbo);
glBindRenderbuffer(GL_RENDERBUFFER, rbo);
glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8,600,600);
glBindRenderbuffer(GL_RENDERBUFFER, 0);


glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER,rbo);

//rbo store the depth and stencil for the fbo.
//texture store the depth obj for the fbo.

if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE){
    std::cout<<"failure creating the frame buffer ... \n";
}

glBindFramebuffer(GL_FRAMEBUFFER, 0);



bool first_s = true;
//glEnable(GL_CULL_FACE);
glEnable(GL_DEPTH_TEST);
glEnable(GL_BLEND);
glEnable(GL_STENCIL_TEST);
glEnable(GL_MULTISAMPLE);


//cubemap test
GLuint texture_cube;
glGenTextures(1, &texture_cube);
glBindTexture(GL_TEXTURE_CUBE_MAP, texture_cube);

std::vector<std::string> faces = {
    "../../texture/+x.png",//+x
    "../../texture/-x.png",//-x
    "../../texture/+y.png",//+y
    "../../texture/-y.png",//-y
    "../../texture/+z.png",//+z
    "../../texture/-z.png" //-z
};
int width, height, nr_channels;
for(int i = 0; i < faces.size(); i++){
   unsigned char* data = stbi_load(faces[i].c_str(),&width,&height,&nr_channels,0);
   if(data){
   glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
   stbi_image_free(data);
}else{
    std::cout<<"no data was loaded ..."<<std::endl;
}
}
glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);



glm::vec3 pos = glm::vec3(0.0f);
cam->camera_pos = glm::vec3(0.0f);

 while(!glfwWindowShouldClose(window)){

//glBindFramebuffer(GL_FRAMEBUFFER, fbo);

    glClearColor(0.20f, 0.20f, 0.30f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
 


//sky box

glEnable(GL_DEPTH_TEST);

glUseProgram(program_cube_map);
 shader_obj->setUniform("model",glm::translate(glm::scale(glm::mat4(1.0f),glm::vec3(50.0f)), glm::vec3(0.0f)));
 shader_obj->setUniform("view", cam->setUpCamera());
 shader_obj->setUniform("projection",glm::perspective(glm::radians(cam->fov),600.0f/600.0f,0.1f,100.0f));
 //for optimazation
 if(first){
 shader_obj->setUniform("skybox",0);
 first = false;
 }
glBindTexture(GL_TEXTURE_CUBE_MAP, texture_cube);
shader_obj->draw();
glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
shader_obj->draw();
glDisable(GL_DEPTH_TEST);
    




{ 
glDisable(GL_DEPTH_TEST);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
 //shader_obj->useProgram();
 glUseProgram(program_main_cube);
 shader_obj->setUniform("model",glm::translate(glm::rotate(glm::mat4(1.0f),glm::sin(static_cast<float>(glfwGetTime())) * glm::radians(180.0f),glm::vec3(0.0f,0.0f,1.0f)),glm::vec3(0.0f,0.0f,2.0f)));
 shader_obj->setUniform("view", cam->setUpCamera());
 shader_obj->setUniform("projection",glm::perspective(glm::radians(cam->fov),600.0f/600.0f,0.1f,100.0f));
 //for optimazation
 if(first){
 shader_obj->setUniform("texture_s",0);
 first = false;
 }
 glBindTexture(GL_TEXTURE_2D, shader_obj->texture);
 shader_obj->draw();
 glBindTexture(GL_TEXTURE_2D, 0);

//http://www.fiverr.com/s/2KE011X

/*
glBindFramebuffer(GL_FRAMEBUFFER, 0);

 shader_obj->useProgram();
 shader_obj->setUniform("model",glm::mat4(1.0f));
 shader_obj->setUniform("view", glm::lookAt(glm::vec3(0.1f,0.1f,2.0f),glm::vec3(0.0f),glm::vec3(0.0f,1.0f,0.0f)));
 shader_obj->setUniform("projection",glm::perspective(glm::radians(cam->fov),600.0f/600.0f,0.1f,100.0f));
 //for optimazation
 if(first){
 shader_obj->setUniform("texture_s",0);
 first = false;
 }
 glBindTexture(GL_TEXTURE_2D, texture);
 shader_obj->draw();
 glBindTexture(GL_TEXTURE_2D, 0);
//glEnable(GL_DEPTH_TEST);

*/  

//will be functioned later...on addition of events :: plus gui
if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
cam->camera_pos += cam->camera_front * 0.50f;
if(cam->camera_pos.x > 24.5){
cam->camera_pos.x = 24.5;
}

if(cam->camera_pos.y > 24.5){
cam->camera_pos.y = 24.5;
}

if(cam->camera_pos.z > 24.5){
cam->camera_pos.z = 24.5;
}
if(cam->camera_pos.x < -24.5){
cam->camera_pos.x = -24.5;
}

if(cam->camera_pos.y < -24.5){
cam->camera_pos.y = -24.5;
}

if(cam->camera_pos.z < -24.5){
cam->camera_pos.z = -24.5;
}
}

if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
cam->camera_pos -= cam->camera_front * 0.5f;

if(cam->camera_pos.x < -24.5){
cam->camera_pos.x = -24.5;
}

if(cam->camera_pos.y < -24.5){
cam->camera_pos.y = -24.5;
}

if(cam->camera_pos.z < -24.5){
cam->camera_pos.z = -24.5;
}
if(cam->camera_pos.x > 24.5){
cam->camera_pos.x = 24.5;
}

if(cam->camera_pos.y > 24.5){
cam->camera_pos.y = 24.5;
}

if(cam->camera_pos.z > 24.5){
cam->camera_pos.z = 24.5;
}
}

if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
cam->camera_pos += glm::cross(cam->camera_front , glm::vec3(0.0f,1.0f,0.0f)) * 0.5f;
if(cam->camera_pos.x < -24.5){
cam->camera_pos.x = -24.5;
}

if(cam->camera_pos.y < -24.5){
cam->camera_pos.y = -24.5;
}

if(cam->camera_pos.z < -24.5){
cam->camera_pos.z = -24.5;
}
if(cam->camera_pos.x > 24.5){
cam->camera_pos.x = 24.5;
}

if(cam->camera_pos.y > 24.5){
cam->camera_pos.y = 24.5;
}

if(cam->camera_pos.z > 24.5){
cam->camera_pos.z = 24.5;
}
}
if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
cam->camera_pos -= glm::cross(cam->camera_front,glm::vec3(0.0f,1.0f,0.0f)) * 0.5f;
if(cam->camera_pos.x < -24.5){
cam->camera_pos.x = -24.5;
}

if(cam->camera_pos.y < -24.5){
cam->camera_pos.y = -24.5;
}

if(cam->camera_pos.z < -24.5){
cam->camera_pos.z = -24.5;
}
if(cam->camera_pos.x > 24.5){
cam->camera_pos.x = 24.5;
}

if(cam->camera_pos.y > 24.5){
cam->camera_pos.y = 24.5;
}

if(cam->camera_pos.z > 24.5){
cam->camera_pos.z = 24.5;
}
}
// shader_obj->useProgram();


    glfwPollEvents();
    glfwSwapBuffers(window);
 
 }
 }   
}