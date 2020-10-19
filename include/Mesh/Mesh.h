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
		std::vector<float> m_verticies;
		std::vector<unsigned int> m_indicies;
	};
}

#endif // !MESH_MESH