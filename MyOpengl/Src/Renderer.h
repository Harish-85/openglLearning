#pragma once
#include "VertexArray.h"
#include "Shader.h"
#include <GLFW/glfw3.h>

class Renderer
{
public:
	void Draw(const VertexArray& va,const Shader& shader) const ;
};
