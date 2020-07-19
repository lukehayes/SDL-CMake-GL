#version 330 core
layout (location = 0) in vec3 vtxPosition;
layout (location = 1) in vec3 vtxColor;
  
out vec4 vertexColor;

void main()
{
    gl_Position = vec4(vtxPosition, 1.0);
    vertexColor = vec4(vtxColor, 1.0); 
}
