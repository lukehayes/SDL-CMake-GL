#ifndef MODEL_BASE_MESH_H
#define MODEL_BASE_MESH_H

#include <vector>
#include "Util/glm.h"

namespace Model {

    /**
     * Base class represents all meshes and is meant to be inheritied from.
     */
    class BaseMesh
    {
    public:
        BaseMesh() {}
        BaseMesh(const std::vector<float> vertices, const std::vector<unsigned int> indicies)
        : m_verticies(vertices), m_indcies(indicies) {}
        virtual ~BaseMesh(){}
    protected:

        std::vector<float> m_verticies;
        std::vector<unsigned int> m_indcies;

    };

    
} /* namespace Model */



#endif
