#pragma once
#include <vector>
#include <gl/glew.h>

#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"


class Mesh
{
private:
	std::vector<vertex> vertices;
	std::vector<GLuint> indices;
	VertexArray va;
public:
	Mesh(const std::vector <vertex>& vertices, const std::vector <GLuint>& indices);
	void Draw(Shader& shader) const;
};