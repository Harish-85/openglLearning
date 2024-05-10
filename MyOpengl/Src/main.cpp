#include <execution>
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "DebugErrors.h"
#include "IndexBuffer.h"
#include "Renderer.h"
#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"

int main(){
	
	if(!glfwInit())
	{
		glfwTerminate();
		return -1;
	}
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	GLFWwindow* win = glfwCreateWindow(500,500,"Test",NULL,NULL);
	glfwMakeContextCurrent(win);
	

	if(glewInit() != GLEW_OK)
	{
		return -1;
	}

	float positions[] = {
		0.0f,.5f,
		-.5f,0.0f,
		0.50f,0.0f,
		0.0f,-.5f

	};
	float colors[]
	{
		1.0f,0.0f,0.0f,1.0f,
		0.0f,1.0f,0.0f,1.0f,
		0.0f,0.0f,1.0f,1.0f,
		1.0f,0.0f,0.0f,1.0f,
	};
	unsigned int index[]
	{
		0,1,2,
		1,2,3
	};
	

	std::cout<<"\nVersion " <<(glGetString(GL_VERSION))<<'\n';
	
	int max;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS,&max);
	std::cout<<"max" <<max;
	VertexBuffer vb(positions,sizeof(float)*8);
	IndexBuffer ib(index,sizeof(unsigned int) * 6);
	
	Shader s("res/Shaders/Base.shader");
	s.bind();

	Renderer renderer;

	VertexBufferLayout vbl;
	vbl.append(GL_FLOAT,false,2);
	VertexArray va;
	va.LinkVertexArray(vb,ib,vbl);

	while(!glfwWindowShouldClose(win))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		renderer.Draw(va,s);
		
		glfwSwapBuffers(win);
		glfwPollEvents();
	}

	std::cout<<"TEst";
}
