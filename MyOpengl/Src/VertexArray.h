#pragma once
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
private:
	unsigned int m_rendererId;
public:
	VertexArray();
	
	~VertexArray();
	void Bind() const;

	
	void LinkVertexArray(const  VertexBuffer &vb,const  IndexBuffer &ib,const VertexBufferLayout& vbo) const;


};
