#version 330 core
in vec3 position;
in vec3 color;

out vec3 newColor;
out vec4 FragPos;

uniform GLint angle;

void main(){
    gl_Position = angle * vec4(position, 1.0);
    // gl_Position = vec4(position, 1.0); ORIGINAL
    newColor = color;
    
    FragPos = vec4(gl_Position);
}