#pragma once
#include <string>

class Texture
{
	unsigned int m_RendererId;
	std::string path;
	unsigned char* localBuffer;

	int width,height,bytesPerPixel;
public:
	Texture(const std::string& path);
	~Texture();

	void Bind(unsigned int slot) const;

	inline int getWidth()const {return width;}
	inline int getHeight()const {return height;}
};
