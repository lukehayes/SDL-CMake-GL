#version 330 core
layout (location = 0) in vec3 vtxPosition;
layout (location = 1) in vec3 vtxColor;
layout (location = 2) in vec2 vtxTexCoord;
  
out vec4 vertexColor;
out vec2 TexCoord;

void main()
{
    gl_Position = vec4(vtxPosition, 1.0);
    vertexColor = vec4(vtxColor, 1.0); 
    TexCoord = vtxTexCoord;
}
