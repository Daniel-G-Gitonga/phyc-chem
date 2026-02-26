#include "Shader.h"


Shader::Shader(){
}
Shader::~Shader(){

}

void Shader::setUp(){
   
     std::cout<<"shader -==> here_5_1a"<<std::endl;
    glGenVertexArrays(1, &VAO);
      std::cout<<"shader -==> here_5_1a_a"<<std::endl;
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER,vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(0)); 
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
      
     std::cout<<"shader -==> here_5_1b"<<std::endl;
    
    std::cout<<"shader -==> here_5"<<std::endl;

    loadShader();

    const char* vertexShaderSource = vertexShaderCode.c_str();
    const char* fragmentShaderSource = fragmentShaderCode.c_str();
    
   // std::cout<<vertexShaderSource<<std::endl;
   // std::cout<<fragmentShaderSource<<std::endl;

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    {
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if(!success){
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout<<"vertexShader error :: "<<infoLog<<std::endl;
        }
    }
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    {
        int success;
        char infoLog[512];
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if(!success){
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout<<"fragmentShader error :: "<<infoLog<<std::endl;
        }
    }
    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    {
        int success;
        char infoLog[512];
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if(!success){
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout<<"program error :: "<<infoLog<<std::endl;
        }
    }
    
  //  loadTexture();
}
void Shader::loadTexture(){
    
}
void Shader::loadShader(){
   std::fstream v_file;
   std::fstream f_file;

   v_file.exceptions(std::ios::badbit | std::ios::failbit);
   f_file.exceptions(std::ios::badbit | std::ios::failbit);

    try
    {
        v_file.open(p_vertexShader.c_str());
        f_file.open(p_fragmentShader.c_str());

      std::stringstream v_buffer;
      std::stringstream f_buffer;

      v_buffer << v_file.rdbuf();
      f_buffer << f_file.rdbuf();

      vertexShaderCode = v_buffer.str();
      fragmentShaderCode = f_buffer.str();
 
        v_file.close();
        f_file.close();

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "vPath :: "<<p_vertexShader<< " fPath:: "<<p_fragmentShader << '\n';
    }
    
}


void Shader::uniform(std::string name, int i){
glUniform1i(glGetUniformLocation(program, name.c_str()),i);
}
void Shader::uniform(std::string name, glm::mat4 i){
glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()),1, GL_FALSE, glm::value_ptr(i));
}
void Shader::uniform(std::string name, glm::vec4 i){
glUniform4fv(glGetUniformLocation(program, name.c_str()), 1, glm::value_ptr(i));
}
void Shader::uniform(std::string name, glm::vec3 i){
glUniform3fv(glGetUniformLocation(program, name.c_str()), 1, glm::value_ptr(i));
}