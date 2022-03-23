#version 330 core
layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vNormal;
layout (location = 2) in vec2 vTexCoords;


out vec3 fNormal;
out vec2 fTexCoords;
out vec3 FragPos;

uniform mat4 proj;
uniform mat4 model;
uniform mat4 view;

void main()
{
    gl_Position = proj * view * model * vec4(vPos, 1.0);
    FragPos = vec3(model * vec4(vPos, 1.0));
    fNormal = mat3(transpose(inverse(model))) * vNormal;
    fTexCoords = vTexCoords;
}
