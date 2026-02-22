#version 330 core

out vec4 fragColor;

in vec2 text_coords;

uniform sampler2D texture_s;

void main(){
    fragColor = texture(texture_s, text_coords);
}