#pragma once
#include <vector>

#include "glm/vec2.hpp"
#include "glm/vec3.hpp"

struct vertex
{
	glm::vec3 position;
	glm::vec3 color;
	glm::vec3 normal;
	glm::vec2 uv;

};

class VertexBuffer
{
	unsigned int m_rendererID;
public:
	
	VertexBuffer(const std::vector<vertex>& data);
	~VertexBuffer();

	void Bind() const;
	unsigned int getVertexBuffer() const;
};