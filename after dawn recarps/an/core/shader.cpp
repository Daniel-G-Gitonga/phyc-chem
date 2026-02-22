#include "shader.h"
#define STB_IMAGE_IMPLEMENTATION
   #include "stb_image.h"
/*
public:

void useProgram();
void draw();

private:
void loadShader();
void render_engine();
void check_err();
*/
blue::Shader::Shader(){}

void blue::Shader::useShader(){
    
    //log for dbug

    std::cout<<"vertex path  "<<vertex_shader_path<<std::endl;
    std::cout<<"fragment path "<<fragment_shader_path<<std::endl;

    //
    loadShader();
    renderEngine();
    loadTexture();
 
}


void blue::Shader::loadShader(){

    std::string vertex_code = std::string();
    std::string fragment_code = std::string();

    std::fstream vertex_file;
    std::fstream fragment_file;

    vertex_file.exceptions(std::ios::badbit | std::ios::failbit);
    fragment_file.exceptions(std::ios::badbit | std::ios::failbit);
   
    try
    {
     vertex_file.open(vertex_shader_path);
     fragment_file.open(fragment_shader_path);

     std::stringstream vertex_buff;
      vertex_buff << vertex_file.rdbuf();
     std::stringstream fragment_buff;
      fragment_buff << fragment_file.rdbuf();

     vertex_code = vertex_buff.str();
     fragment_code = fragment_buff.str();

        vertex_file.close();
        fragment_file.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() <<" :: vertex code "<<vertex_code<<" fragment code :: "<<fragment_code<< '\n';
    }
    

    vertex_shader = vertex_code.c_str();
    fragment_shader = fragment_code.c_str();

    std::cout<<" load shader func executed ..."<<std::endl;

    
}

void blue::Shader::renderEngine(){
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);


    vertex_shader_obj = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader_obj,1, &vertex_shader, NULL);
    glCompileShader(vertex_shader_obj);

    fragment_shader_obj = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader_obj, 1, &fragment_shader, NULL);
    glCompileShader(fragment_shader_obj);

    program = glCreateProgram();
    glAttachShader(program, vertex_shader_obj);
    glAttachShader(program, fragment_shader_obj);
    glLinkProgram(program);
    check_err();


     //formaat assumed for all passed data,
    //pos 3 float, normal 3 float, texture-coords 2 floats
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(0));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));

    
}

void blue::Shader::check_err(){
    int success ;
    char infoLog[512];
    {
       glGetShaderiv(vertex_shader_obj, GL_COMPILE_STATUS, &success);
       if(!success){
        glGetShaderInfoLog(vertex_shader_obj, 512, NULL, infoLog);
        std::cout<<name_program<<" error compiling vertex shader :: :: "<<infoLog<<std::endl;
       }
    }
    {
        glGetShaderiv(fragment_shader_obj, GL_COMPILE_STATUS, &success);
       if(!success){
        glGetShaderInfoLog(fragment_shader_obj, 512, NULL, infoLog);
        std::cout<<name_program<<" error compiling fragment shader :: :: "<<infoLog<<std::endl;
       }

    }
    {  
        glGetProgramiv(program, GL_LINK_STATUS, &success);
       if(!success){
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout<<name_program<<" error linking the program :: :: "<<infoLog<<std::endl;
       }

    }
}

void blue::Shader::useProgram(){
    glBindVertexArray(VAO);
    glUseProgram(program);
}

void blue::Shader::draw(){
     
    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()) , GL_UNSIGNED_INT, 0);
}

blue::Shader::~Shader(){
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &IBO);
  glDeleteVertexArrays(1, &VAO);
  
  glDeleteTextures(1,&texture);
  glDeleteShader(vertex_shader_obj);
  glDeleteShader(fragment_shader_obj);
  glDeleteProgram(program);
}



//shader uniforms...

void blue::Shader::setUniform(std::string name, int M){
glUniform1i(glGetUniformLocation(program , name.c_str()), M);
}
void blue::Shader::setUniform(std::string name, glm::mat4 N){
glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()),1, GL_FALSE, glm::value_ptr(N));
}
void blue::Shader::setUniform(std::string name, glm::vec4 O){
glUniform4fv(glGetUniformLocation(program, name.c_str()), 1, glm::value_ptr(O));
}
void blue::Shader::setUniform(std::string name, glm::vec3 P){
glUniform3fv(glGetUniformLocation(program, name.c_str()), 1, glm::value_ptr(P));
}

void blue::Shader::loadTexture(){
    stbi_set_flip_vertically_on_load(true);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    glActiveTexture(GL_TEXTURE0);
    
    int width, height, nrChannels;
       
     unsigned char *data = stbi_load(texture_path.c_str(), &width, &height, &nrChannels, 0);
     if(data){
     int format = nrChannels = 4 ? GL_RGBA : GL_RGB;
     //later 2 me: add support for 2 and 1 color format
     glTexImage2D(GL_TEXTURE_2D, 0, format, width,height, 0, format, GL_UNSIGNED_BYTE, data);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
     }else{
        std::cout<<"failure loading the data"<<std::endl;
     }
      
     stbi_image_free(data);
}