#include <iostream>
#include <Gl/glew.h>

#define ASSERT(x) if (!(x)) __debugbreak()
#define GLCall(x) ClearErrors();\
    x;\
    ASSERT(GLLogCall(#x,__FILE__,__LINE__))


void ClearErrors();

bool GLLogCall(const char* func, const char* file, int line);
