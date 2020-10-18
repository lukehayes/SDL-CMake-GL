#include "Util/GL.h"
#include <iostream>
#include <vector>
#include "SDL.h"
#include "App/App.h"
#include "GL/Texture.h"
#include "GL/RawBuffer.h"
#include "Graphics/Basic-Renderer.h"
#include "Graphics/Camera.h"
#include "Mesh/RectangleMesh.h"

int main(int argc, char* argv[])
{

    App::App app(800, 600, "Window Title");


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


    Mesh::RectangleMesh mesh;
    
    //GL::Texture t1("doge.png");
    const GL::RawBuffer buffer(mesh.m_verticies, mesh.m_indicies);

	const std::string vshPath = ShaderResource("default-vsh.glsl");
	const std::string fshPath = ShaderResource("default-fsh.glsl");
	GL::Shader shader(vshPath.c_str(), fshPath.c_str());

    Model::Model model;

	Graphics::Camera camera;

    Graphics::BasicRenderer renderer(buffer, shader, camera);

    app.SetRenderer(&renderer);

    app.Run();

	return 0;
}
 
