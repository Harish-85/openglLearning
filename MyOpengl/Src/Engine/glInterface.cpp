#include  "glInterface.h"

void glInterface::SetupOpengl(int width, int height)
{
	if(!glfwInit())
	{
		glfwTerminate();
		throw std::exception("glfw init failed");
	}
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	window = glfwCreateWindow(width,height,"Test",NULL,NULL);
	glfwMakeContextCurrent(window);
	

	if(glewInit() != GLEW_OK)
	{
		throw std::exception("glew init failed");
	}
	
}
