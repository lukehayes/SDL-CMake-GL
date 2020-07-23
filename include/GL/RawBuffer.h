#ifndef RAW_BUFFER_H
#define RAW_BUFFER_H

#include <vector>

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

            void Load(const std::vector<float>& verticies, const std::vector<unsigned int>& indicies){

                GLuint VAO;
                GLuint VBO;
                unsigned int EBO;

                glGenVertexArrays(1, &VAO);
                glBindVertexArray(VAO);

                glGenBuffers(1, &VBO);
                glBindBuffer(GL_ARRAY_BUFFER, VBO);

                glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verticies.size(), verticies.data(), GL_STATIC_DRAW );

                glEnableVertexAttribArray(0); // Turn attrib 0 on
                // 6 verticies in total. 3 are positions, 3 are colours.
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)0);

                glEnableVertexAttribArray(1); // Turn attrib 1 on
                // Same as attrib 0 but we need to jump 12 bytes (3 * float) to get to
                // the colour attribs. Then every six verts is our next colour.
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(3 * sizeof(float)));

                glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
                glEnableVertexAttribArray(2);  

                glGenBuffers(1, &EBO);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indicies.size(), indicies.data(), GL_STATIC_DRAW );

            }
    };

}
#endif