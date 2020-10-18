#ifndef MODEL_BASE_MESH_H
#define MODEL_BASE_MESH_H

#include "BaseMesh.h"
#include <vector>

namespace Model {

    /**
     * Base class represents all meshes and is meant to be inheritied from.
     */
    class RectMesh
    {
    public:
        RectMesh() {}
        virtual ~RectMesh(){}

        void SetVertices(const std::vector<float>& verticies)
        {
            this->m_verticies = verticies;
        }
        void SetIndicies(const std::vector<unsigned int>& indicies) 
        {
            this->m_indicies = indicies;
        }

    protected:
        std::vector<float> m_verticies;
        std::vector<unsigned int> m_indicies;

    };

} /* namespace Model */

#endif
