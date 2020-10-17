#ifndef MODEL_BASE_MESH_H
#define MODEL_BASE_MESH_H

#include <vector>

namespace Model {

    /**
     * Base class represents all meshes and is meant to be inheritied from.
     */
    class BaseMesh
    {
    public:
        BaseMesh() {}
        virtual ~BaseMesh(){}

        virtual void SetVertices() = 0;
        virtual void SetIndicies() = 0;

    protected:
        std::vector<float> m_verticies;
        std::vector<unsigned int> m_indcies;

    };

} /* namespace Model */

#endif
