#ifndef GL_BUFFER_TARGET
#define GL_BUFFER_TARGET

namespace GL {

    /* #defines for GL_ARRAY_BUFFER etc are found in gl/glext.h */
    enum BufferTarget {
        ARRAY_BUFFER = GL_ARRAY_BUFFER,
        ELEMENT_BUFFER = GL_ELEMENT_ARRAY_BUFFER
    };
}

#endif
