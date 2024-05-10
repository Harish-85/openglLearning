#include "IndexBuffer.h"

#include <gl/glew.h>

#include "DebugErrors.h"

IndexBuffer::IndexBuffer(const void* data, unsigned int size)
{
	GLCall(glCreateBuffers(1,&m_rendererID));
	
	GLCall(glNamedBufferData(m_rendererID,size,data,GL_STATIC_DRAW));
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