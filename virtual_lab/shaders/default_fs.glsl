#version 330 core

out vec4 fragColor;

uniform vec3 f_color;
void main(){
    fragColor = vec4(f_color,1.0f);
}