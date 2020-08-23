#ifndef RAW_BUFFER_H
#define RAW_BUFFER_H

#include <vector>
#include "GL/BufferTarget.h"

namespace GL {
    
    /**
     * Represents a VAO, VBO etc all in a single location
     */
    class RawBuffer
    {
        public:
            RawBuffer(const std::vector<float>& verticies, const std::vector<unsigned int>& indicies) {
                this->Load(verticies, indicies);
            }
            ~RawBuffer(){}
            
            /**
             * Generate and bind the classes VAO
             */
            void GenVertexArray() {
                glGenVertexArrays(1, &m_VAO_ID);
                glBindVertexArray(m_VAO_ID);
            }

            void Load(const std::vector<float>& verticies, const std::vector<unsigned int>& indicies){

                GenVertexArray();

                glGenBuffers(1, &m_VBO_ID);
                glBindBuffer(GL::BufferTarget::ARRAY_BUFFER, m_VBO_ID);

                glBufferData(GL::BufferTarget::ARRAY_BUFFER, sizeof(float) * verticies.size(), verticies.data(), GL_STATIC_DRAW );

                // Vertex Coordinates
                glEnableVertexAttribArray(0); // Turn attrib 0 on
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)0);

                // Colour Coordinates
                glEnableVertexAttribArray(1); // Turn attrib 1 on
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(3 * sizeof(float)));

                // Texture Coordinates
                glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
                glEnableVertexAttribArray(2);  

                // Index Buffer
                glGenBuffers(1, &m_EBO_ID);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO_ID);
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indicies.size(), indicies.data(), GL_STATIC_DRAW );

            }

        private:
            GLuint m_VAO_ID;
            GLuint m_VBO_ID;
            unsigned int m_EBO_ID;
    };

}
#endif
