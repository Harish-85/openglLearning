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
	
	~Mesh();
	Mesh(const Mesh&& m) noexcept
	{
		vertices = m.vertices;
		indices = m.indices;
		va =m.va;
		va.Bind();
	}

	void operator =(const Mesh& m)
	{
		vertices = m.vertices;
		indices = m.indices;
		va=m.va;
	}

	void Draw(Shader& shader) const;
	
};