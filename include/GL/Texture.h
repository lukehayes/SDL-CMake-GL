#ifndef TEXTURE_H
#define TEXTURE_H

#include "Platform/Resource.h"

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#include "stb_image.h"

namespace GL {
    
    /**
     * Represents a VAO, VBO etc all in a single location
     */
    class Texture
    {
        public:
            Texture(const std::string& texturePath){
                this->Load(texturePath);
            }
            ~Texture(){}

            void Load(const std::string& texturePath) {

                glGenTextures(1, &m_textureID); 

                int width, height, nrChannels;
                unsigned char *data = stbi_load(ImageResource(texturePath).c_str(), &width, &height, &nrChannels, STBI_rgb_alpha);

                glBindTexture(GL_TEXTURE_2D, m_textureID); 
                
                // Texture filtering, mipmaps etc.
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                
                // Must use RGBA for png!
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
                glGenerateMipmap(GL_TEXTURE_2D);

                stbi_image_free(data);
            }

            inline GLuint getTextureID() const {
                return m_textureID;
            }

        private:
            GLuint m_textureID;
    };

}
#endif
