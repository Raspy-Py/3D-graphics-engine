#version 330 core
layout (location = 0) in vec3 vPos;

uniform mat4 proj;
uniform mat4 model;
uniform mat4 view;

void main()
{
    gl_Position = proj * view * model * vec4(vPos, 1.0);
}
