#pragma once
#include <inttypes.h>

class IndexBuffer
{
	unsigned int m_rendererID;
public:
	
	IndexBuffer(const void* data, unsigned int size);
	~IndexBuffer();

	void Bind() const;
	uint32_t getIndexBuffer() const;
};
