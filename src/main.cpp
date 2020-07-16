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


void draw(const std::vector<float>& verticies) {

    GLuint VAO;
    GLuint VBO;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verticies.size(), verticies.data(), GL_STATIC_DRAW );

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    

}

int main(int argc, char* argr[])
{

    App::App app(800, 600, "Window Title");

    std::vector<float> v = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
          /* Problem: glewInit failed, something is seriously wrong. */
          fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

    draw(v);

    GL::Shader shader("../v.vsh", "../f.vsh");

    app.run();

	return 0;
}

