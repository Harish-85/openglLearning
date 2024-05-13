#pragma once
#include "VertexArray.h"
#include "Shader.h"
#include <GLFW/glfw3.h>

#include "Mesh.h"

class Renderer
{
public:
	void Draw(const Mesh& m,Shader& shader) const ;
};
