#include "Shader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <gl/glew.h>

#include "DebugErrors.h"

Shader::Shader(const std::string& path)
{
	ParseShader(path);

	CompileShader();
}

Shader::~Shader()
{
	glDeleteProgram(m_rendererId);
}

void Shader::printShader()
{
	
}

void Shader::bind() const
{
	GLCall(glUseProgram(m_rendererId));
}

void Shader::unbind()
{
	GLCall(glUseProgram(m_rendererId));
}

void Shader::setUniform4f(const std::string& name, float x, float y, float z, float w) const
{
	
	GLCall(glUniform4f(getUniformLocation(name),x,y,z,w));
}

void Shader::CompileShader()
{
	unsigned int vid = glCreateShader(GL_VERTEX_SHADER);
	const char* vert = vertShader.c_str();
	glShaderSource(vid,1,&vert,nullptr);
	glCompileShader(vid);
	ErrorCheck(vid);

	unsigned int fid = glCreateShader(GL_FRAGMENT_SHADER);
	const char* frag = fragShader.c_str();
	glShaderSource(fid,1,&frag,nullptr);
	glCompileShader(fid);
	ErrorCheck(fid);
	

	m_rendererId =glCreateProgram();
	GLCall(glAttachShader(m_rendererId,vid));
	GLCall(glAttachShader(m_rendererId,fid));
	GLCall(glLinkProgram(m_rendererId));
	GLCall(glValidateProgram(m_rendererId));
	
	
}

void Shader::ErrorCheck(unsigned int id)
{
	int param;
	glGetShaderiv(id,GL_COMPILE_STATUS,&param);
	if(param == GL_FALSE)
	{
		int len;
		glGetShaderiv(id,GL_INFO_LOG_LENGTH,&len);

		GLchar* msg =static_cast<char*>(alloca(sizeof(char) * len));
		glGetShaderInfoLog(id,len*sizeof(char),&len,msg);
		std::cout <<"SHADER COMPILE FAILED\n";
		std::cout<<msg;
	}
}

void Shader::ParseShader(const std::string& path)
{
	std::cout<<"PARSIING"<< std::endl;
	std::ifstream file(path);
	std::string s;
	std::stringstream fstream;
	std::stringstream vstream;


	enum ShaderType
	{
		NONE,
		VERTEX,
		FRAGMENT
	};
	ShaderType type = NONE;

	while(std::getline(file,s))
	{
		if(s.find("#shader fragment") != std::string::npos)
		{
			type=FRAGMENT;
		}
		else if (s.find("#shader vertex") != std::string::npos)
		{
			type = VERTEX;
		}
		else{
		if(type == VERTEX)
			vstream<<s << "\n";
		if(type == FRAGMENT)
			fstream<<s<< "\n";
		}
	}
	std::cout << "PRINTING";
	vertShader = vstream.str();
	fragShader = fstream.str();
	std::cout<<vertShader<< std::endl;
	std::cout<<fragShader<<std::endl;
}

int Shader::getUniformLocation(const std::string& name) const
{
	//TODO: make it cache the result so that we dont need to get location every time
		GLCall(int location = glGetUniformLocation(m_rendererId,name.c_str()));
		if(location == -1)
			std::cout << "Warning : uniform "<<name<<" doesn't exist \n";
		return location;
}
