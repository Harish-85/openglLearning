#include "IndexBuffer.h"

#include <vector>
#include <gl/glew.h>
#include "VertexBuffer.h"
#include "DebugErrors.h"

IndexBuffer::IndexBuffer(const std::vector<unsigned int>& data)
{
	GLCall(glCreateBuffers(1,&m_rendererID));
	
	GLCall(glNamedBufferData(m_rendererID,data.size() * sizeof(unsigned int),data.data(),GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
	GLCall(glDeleteBuffers(1,&m_rendererID));
}

void IndexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_rendererID));
}

uint32_t IndexBuffer::getIndexBuffer() const
{
	return m_rendererID;
}