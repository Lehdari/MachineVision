#ifndef GLFFT_HPP
#define GLFFT_HPP


#include "Shader.hpp"

#include <GL/glew.h>
#include <string>


class GLFFT {
public:
    //  power-of-two dimensions only
    GLFFT(unsigned width, unsigned height,
          const std::string& vsFileName, const std::string& fsFileName);
    ~GLFFT(void);

    GLFFT(const GLFFT&)             = delete;
    GLFFT(GLFFT&&)                  = delete;
    GLFFT& operator=(const GLFFT&)  = delete;
    GLFFT& operator=(GLFFT&&)       = delete;

    //  returns id to texture containing the DFT
    GLuint transform(GLuint textureId, GLuint xoffset = 0u, GLuint yoffset = 0u);

private:
    GLuint vertexArrayId_;
    GLuint arrayBufferId_;
    GLuint framebufferId_;
    GLuint textureIds_[4];
    unsigned width_, height_;
    unsigned xDepth_, yDepth_;
    int active_;
    Shader shader_;

    static const GLfloat quad__[18];
    static const GLenum drawBuffers__[2];
};


#endif  //  GLFFT_HPP