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

		BasicRenderer(const Model::Model& model) : m_model(model){}

		BasicRenderer(const GL::RawBuffer& buffer, const GL::Shader& shader, const Graphics::Camera& cam, const Model::Model& model)
			: m_rawBuffer(buffer), 
			m_shader(ShaderResource("default-vsh.glsl").c_str(),
			ShaderResource("default-fsh.glsl").c_str()), 
			m_camera(cam),
			m_model(model) {}


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

		void Render()
		{
			m_shader.Use();

			glClearColor(1.0,0.2,0.5,1);
			glClear(GL_COLOR_BUFFER_BIT);

			glDrawElements(GL_TRIANGLES, m_model.m_vertexCount, GL_UNSIGNED_INT, 0);
		}

		GL::RawBuffer m_rawBuffer;
		GL::Shader m_shader;
		Graphics::Camera m_camera;
		Model::Model m_model;
	};
}

#endif // !GRAPHICS_RENDERER_H