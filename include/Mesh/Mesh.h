#ifndef MESH_MESH
#define MESH_MESH

namespace Mesh
{
	/*
	* Base mesh class that all meshes should inherit from
	*/
	class Mesh
	{
	public:
		Mesh() {}
		~Mesh() {}

		virtual std::vector<float> GetVerticies() = 0;
		virtual std::vector<unsigned int> GetIndicies() = 0;

		std::vector<float> m_verticies;
		std::vector<unsigned int> m_indicies;
	};
}

#endif // !MESH_MESH