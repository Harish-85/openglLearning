#include "IndexBuffer.h"

#include <gl/glew.h>

#include "DebugErrors.h"

IndexBuffer::IndexBuffer(const void* data, unsigned int size)
{
	GLCall(glGenBuffers(1,&m_rendererID));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_rendererID));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER,size,data,GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
	GLCall(glDeleteBuffers(1,&m_rendererID));
}

void IndexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_rendererID));
}
