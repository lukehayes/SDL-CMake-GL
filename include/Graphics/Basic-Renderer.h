#ifndef GRAPHICS_BASIC_RENDERER_H
#define GRAPHICS_BASIC_RENDERER_H

#include "GL/RawBuffer.h"
#include "GL/Shader.h"
#include "Util/GL.h"
#include "Model/Model.h"
#include "App/EngineBase.h"

namespace Graphics {

	class BasicRenderer {
	public:
		BasicRenderer() {}

		BasicRenderer(const GL::Shader& shader) 
			: m_shader(shader){}

		BasicRenderer(const Model::Model& model) : m_model(model){}
		BasicRenderer(const GL::RawBuffer& buffer, const Model::Model model, const GL::Shader& shader)
			: m_rawBuffer(buffer), m_model(model), m_shader(shader) {}
		~BasicRenderer() {}

		void SetShader()
		{
            const std::string vshPath = ShaderResource("default-vsh.glsl");
            const std::string fshPath = ShaderResource("default-fsh.glsl");
            GL::Shader shader(vshPath.c_str(), fshPath.c_str());
			m_shader = shader;
		}

		void Render()
		{
			m_shader.Use();
			glDrawElements(GL_TRIANGLES, m_model.m_vertexCount, GL_UNSIGNED_INT, 0);
		}

	private:
		GL::RawBuffer m_rawBuffer;
		Model::Model m_model;
		GL::Shader m_shader;
	};
}

#endif // !GRAPHICS_RENDERER_H