#pragma once
#pragma once
#include <vector>
#include <gl/glew.h>

struct VertexBufferElement
{
	unsigned int type;
	unsigned int count;
	bool isNormalized;
};

class VertexBufferLayout
{
private:
	std::vector<VertexBufferElement> vertexLayout;
	unsigned int stride;
public:
	VertexBufferLayout():stride(0){}
	void append(GLuint type,bool isNormalized,int count);
	std::vector<VertexBufferElement> getVertexLayout() const {return vertexLayout;}
	unsigned int getStride() const {return stride;}
};

inline void VertexBufferLayout::append(GLuint type, bool isNormalized, int count)
{
	VertexBufferElement vbe;
	vbe.count = count;
	vbe.type = type;
	vbe.isNormalized = isNormalized;

	vertexLayout.push_back(vbe);
	stride += count * sizeof(type);
}
