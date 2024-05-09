#pragma once
#include <string>

#include "DebugErrors.h"

class Shader
{
	
public:
	Shader(const std::string& path);
	~Shader();
	void printShader();
	void bind();
	void unbind();
	void setUniform4f(const std::string& name,float x,float y ,float z,float w) const;
private:
	std::string fragShader;
	std::string vertShader;
	unsigned int m_rendererId;
	
	void CompileShader();
	void ErrorCheck(unsigned int id);
	
	void ParseShader(const std::string& path);
	int getUniformLocation(const std::string& name) const;
	
};
