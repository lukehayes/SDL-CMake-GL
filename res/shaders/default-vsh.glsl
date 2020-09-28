#version 330 core
layout (location = 0) in vec3 vtxPosition;
layout (location = 1) in vec3 vtxColor;
layout (location = 2) in vec2 vtxTexCoord;
  
out vec4 vertexColor;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
    gl_Position = projection * view * model * vec4(vtxPosition, 1.0);
    vertexColor = vec4(vtxColor, 1.0); 
}
