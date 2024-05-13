#include "VertexBuffer.h"

#include <gl/glew.h>

#include "DebugErrors.h"

VertexBuffer::VertexBuffer(const std::vector<vertex>& data)
{

	GLCall(glCreateBuffers(1,&m_rendererID));
	
	GLCall(glNamedBufferData(m_rendererID,data.size() * sizeof(vertex),data.data(),GL_STATIC_DRAW));
	
}

VertexBuffer::~VertexBuffer()
{
	GLCall(glDeleteBuffers(1,&m_rendererID));
}

void VertexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER,m_rendererID));
}

unsigned int VertexBuffer::getVertexBuffer() const
{
	return m_rendererID;
}