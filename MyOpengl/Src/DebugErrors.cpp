#pragma once
#include "DebugErrors.h"


void ClearErrors()
{
    while (glGetError() != GL_NO_ERROR);

}
bool GLLogCall(const char* func, const char* file, int line)
{
    while (GLenum g = glGetError()) {
        std::cout << "OPENGL ERROR :" << g << " : " << func << " " << file << " " << line << std::endl;
        return false;
    }
    return true;
}