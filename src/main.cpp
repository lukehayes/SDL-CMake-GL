#if _WIN32
    #define GLEW_STATIC
    #include "eglew.h"
    #include "glew.h"

#elif __linux__
    #include "GL/glew.h"
#endif

#include <iostream>
#include <vector>
#include "SDL.h"
#include "app/app.h"
#include "GL/shader.h"


void Draw(const std::vector<float>& verticies, const std::vector<unsigned int>& indicies) {

    GLuint VAO;
    GLuint VBO;
    GLuint EBO;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verticies.size(), verticies.data(), GL_STATIC_DRAW );

    glEnableVertexAttribArray(0); // Turn attrib 0 on
    // 6 verticies in total. 3 are positions, 3 are colours.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)0);

    glEnableVertexAttribArray(1); // Turn attrib 1 on
    // Same as attrib 0 but we need to jump 12 bytes (3 * float) to get to
    // the colour attribs. Then every six verts is our next colour.
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)12);

    glGenBuffers(GL_ELEMENT_ARRAY_BUFFER, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indicies.size(), indicies.data(), GL_STATIC_DRAW );

}

int main(int argc, char* argr[])
{

    App::App app(800, 600, "Window Title");

    std::vector<float> v = {
        -0.5f, -0.5f, 0.0f, 1.0f, 0.f, 0.0f, // 3x vertex, 3x colour
         0.5f, -0.5f, 0.0f, 0.0f, 1.f, 0.0f,
         0.0f,  0.5f, 0.0f, 0.0f,0.0f,1.0f
    };

    std::vector<unsigned int> i = {
        0,1,3,
        1,2,3
    };

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
          /* Problem: glewInit failed, something is seriously wrong. */
          fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

    Draw(v, i);


    app.Run();

	return 0;
}

