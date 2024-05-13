#pragma once
#include <inttypes.h>

#include "VertexBuffer.h"

class IndexBuffer
{
	unsigned int m_rendererID;
public:
	
	
	IndexBuffer(const std::vector<unsigned int>& data);
	~IndexBuffer();

	void Bind() const;
	uint32_t getIndexBuffer() const;
};
