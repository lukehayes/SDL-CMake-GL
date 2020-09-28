﻿#include "Util/GL.h"
#include <iostream>
#include <vector>
#include "SDL.h"
#include "App/App.h"
#include "GL/Texture.h"
#include "GL/RawBuffer.h"
#include "Graphics/Basic-Renderer.h"
#include "Graphics/Camera.h"

int main(int argc, char* argv[])
{

    App::App app(800, 600, "Window Title");

    std::vector<float> v = {
   // positions          // colors           // texture coords
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
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

    if( argc > 1 ) {

        if(std::string(argv[1]) == "-wf") {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            std::cout << "Enabled: Wireframe Mode" << std::endl;
        }
    }
    
    // MUST BE ENABLED FOR TRANSPARENT PNG!
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    //GL::Texture t1("doge.png");
    const GL::RawBuffer buffer(v,i);

	const std::string vshPath = ShaderResource("default-vsh.glsl");
	const std::string fshPath = ShaderResource("default-fsh.glsl");
	GL::Shader shader(vshPath.c_str(), fshPath.c_str());

    Model::Model model(glm::vec3(0.2, 0.0, 0.0));

	Graphics::Camera camera;

    shader.SetMat4("projection", camera.GetCombinedProjection());
    shader.SetMat4("model", model.GetMatrix());

    Graphics::BasicRenderer renderer(buffer, shader, camera, model);

    app.SetRenderer(&renderer);

    app.Run();

	return 0;
}
 
