#ifndef GRAPHICS_BASIC_RENDERER_H
#define GRAPHICS_BASIC_RENDERER_H

#include "GL/RawBuffer.h"
#include "GL/Shader.h"
#include "Util/GL.h"
#include "Model/Model.h"
#include "App/EngineBase.h"
#include "Graphics/Camera.h"

namespace Graphics {

	class BasicRenderer {
	public:
		BasicRenderer() {}

		BasicRenderer(const GL::Shader& shader) 
			: m_shader(shader){}

		BasicRenderer(const Model::Model& model) {}

		BasicRenderer(const GL::RawBuffer buffer, const GL::Shader& shader, const Graphics::Camera& cam)
			: m_rawBuffer(buffer), m_shader(ShaderResource("default-vsh.glsl").c_str(), ShaderResource("default-fsh.glsl").c_str()), m_camera(cam) {}

		~BasicRenderer() {}

		void SetShader()
		{
            const std::string vshPath = ShaderResource("default-vsh.glsl");
            const std::string fshPath = ShaderResource("default-fsh.glsl");
            GL::Shader shader(vshPath.c_str(), fshPath.c_str());
			m_shader = shader;
		}

		inline void SetCamera(const Graphics::Camera& camera)
		{
			m_camera = camera;
		}


        void Render(std::vector<Model::Model> &models)
        {
			m_shader.Use();

			glClearColor(0.9,0.5,0.8,1);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            for(auto &model : models)
            {
                m_shader.SetMat4("model", model.GetMatrix());
                glDrawElements(GL_TRIANGLES, model.m_vertexCount, GL_UNSIGNED_INT, 0);
            }
        }

		void Render()
		{
			m_shader.Use();

			glClearColor(0.3,0.5,0.8,1);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		}

		GL::RawBuffer m_rawBuffer;
		GL::Shader m_shader;
		Graphics::Camera m_camera;
	};
}

#endif // !GRAPHICS_RENDERER_H
