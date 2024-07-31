#pragma once
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


class glInterface
{
private:
	GLFWwindow* window;
public:
	void SetupOpengl(int width,int height);

	const bool shouldCloseWindow(){return glfwWindowShouldClose(window); }


};
