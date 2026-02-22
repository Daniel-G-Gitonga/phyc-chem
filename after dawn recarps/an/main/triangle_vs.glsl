#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 norm;
layout (location = 2) in vec2 texture_coords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 text_coords;

void main(){
    text_coords = texture_coords;
    gl_Position = projection * view * model * vec4(aPos, 1.0f);
}