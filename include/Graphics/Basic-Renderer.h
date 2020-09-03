#ifndef GRAPHICS_BASIC_RENDERER_H
#define GRAPHICS_BASIC_RENDERER_H

#include "GL/RawBuffer.h"
#include "GL/Shader.h"
#include "Util/GL.h"
#include "Model/Model.h"

namespace Graphics {

	class BasicRenderer {
	public:
		BasicRenderer() {}
		BasicRenderer(const RawBuffer& buffer, const Model::Model model)
			: m_rawBuffer(buffer), m_model(model) {}
		~BasicRenderer() {}

		void Render(const GL::Shader& shader)
		{
			shader.Use();
			glDrawElements(GL_TRIANGLES, m_model.m_vertexCount, GL_UNSIGNED_INT, 0);
		}

	private:
		GL::RawBuffer m_rawBuffer;
		Model::Model m_model;
	};
}

#endif // !GRAPHICS_RENDERER_H