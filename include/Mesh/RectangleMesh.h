#ifndef MESH_RECTANGLE_MESH
#define MESH_RECTANGLE_MESH

#include "Mesh.h"

namespace Mesh
{
	class RectangleMesh : public Mesh
	{
	public:
		RectangleMesh()
		{
			this->m_verticies = {
				// positions          // colors           // texture coords
				  0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
				  0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
				 -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
				 -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
			};

			this->m_indicies = {
				0,1,3,
				1,2,3
			};
		}
		~RectangleMesh() {}

		std::vector<float> GetVerticies() { return this->m_verticies; }
		std::vector<unsigned int> GetIndicies() { return this->m_indicies; }

		std::vector<float> m_verticies;
		std::vector<unsigned int> m_indicies;
	};
}

#endif
