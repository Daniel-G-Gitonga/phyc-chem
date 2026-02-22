#version 330 core

out vec4 fragColor;

in vec3 cubeMaps_vector;

uniform samplerCube skybox;

void main(){
    fragColor = vec4(1.0f) * texture(skybox, cubeMaps_vector);
}