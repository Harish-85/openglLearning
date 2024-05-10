#include "VertexBuffer.h"

#include <gl/glew.h>

#include "DebugErrors.h"

VertexBuffer::VertexBuffer(const void* data,unsigned int size)
{

	GLCall(glCreateBuffers(1,&m_rendererID));
	
	GLCall(glNamedBufferData(m_rendererID,size,data,GL_STATIC_DRAW));
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