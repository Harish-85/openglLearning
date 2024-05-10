#pragma once

class VertexBuffer
{
	unsigned int m_rendererID;
public:
	
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind() const;
	unsigned int getVertexBuffer() const;
};