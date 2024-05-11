#include "VertexArray.h"

#include <gl/glew.h>

#include "DebugErrors.h"




VertexArray::VertexArray()
{
	GLCall(glCreateVertexArrays(1,&m_rendererId));
	
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
	unsigned int offset = 0;
	std::vector<VertexBufferElement> elements= vbo.getVertexLayout();

	for(int i =0 ;i < elements.size();i++)
	{
		const VertexBufferElement& el =elements[i];

		GLCall(glEnableVertexArrayAttrib(m_rendererId,i));
		GLCall(glVertexArrayAttribBinding(m_rendererId,i,0));
		GLCall(glVertexArrayAttribFormat(m_rendererId,i,el.count,el.type,el.isNormalized,offset));

		
		offset += el.count * sizeof(el.type);
	}
	glVertexArrayVertexBuffer(m_rendererId,0,vb.getVertexBuffer(),0,vbo.getStride());
	glVertexArrayElementBuffer(m_rendererId,ib.getIndexBuffer());

}




