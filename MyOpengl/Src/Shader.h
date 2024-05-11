#pragma once
#include <string>

#include "DebugErrors.h"
#include "glm/glm.hpp"

class Shader
{
	
public:
	Shader(const std::string& path);
	~Shader();
	void printShader();
	void bind() const ;
	void unbind();
	void setUniform4f(const std::string& name,float x,float y ,float z,float w) const;
	void setUniform1i(const std::string& name,int val) const;
	void setUniformMat4(const ::std::string& name, glm::mat4& matrix) const;

private:
	std::string fragShader;
	std::string vertShader;
	unsigned int m_rendererId;
	
	void CompileShader();
	void ErrorCheck(unsigned int id);
	
	void ParseShader(const std::string& path);
	int getUniformLocation(const std::string& name) const;
	
};
