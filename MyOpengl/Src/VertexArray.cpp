#include "VertexArray.h"

#include <gl/glew.h>

#include "DebugErrors.h"




VertexArray::VertexArray()
{
	GLCall(glGenVertexArrays(1,&m_rendererId));
	
}

VertexArray::~VertexArray()
{
	GLCall(glDeleteVertexArrays(1,&m_rendererId));
}

void VertexArray::Bind() const
{
	GLCall(glBindVertexArray(m_rendererId));
}

void VertexArray::LinkVertexArray(const VertexBuffer& vb, const IndexBuffer& ib,  const VertexBufferLayout& vbo) const
{
	
	Bind();
	
	vb.Bind();
	ib.Bind();

	unsigned int offset = 0;
	std::vector<VertexBufferElement> elements= vbo.getVertexLayout();

	for(int i =0 ;i < elements.size();i++)
	{
		const VertexBufferElement& el =elements[i];

		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i,el.count,el.type,el.isNormalized,vbo.getStride(),(const void*)offset));
		offset += el.count * sizeof(el.type);
	}
}




