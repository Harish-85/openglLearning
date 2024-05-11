#include <execution>
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "DebugErrors.h"
#include "IndexBuffer.h"
#include "Renderer.h"
#include "Shader.h"
#include "Texture.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

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
		-100.f,-100.f,0.0f,0.0f,
		100.f,-100.f,1.0f,0.0f,
		100.f,100.f,1.0f,1.0f,
		-100.f,100.f,0.0f,1.0f

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
		2,3,0
	};
	VertexBuffer vb(positions,sizeof(float)*16);
	IndexBuffer ib(index,sizeof(unsigned int) * 6);

	std::cout<<"\nVersion " <<(glGetString(GL_VERSION))<<'\n';
	
	int max;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS,&max);
	std::cout<<"max" <<max;
	


	Shader s("res/Shaders/Base.shader");
	s.bind();
	
	Texture tex("res/Tex/showcase1.png");
	tex.Bind(0);
	s.setUniform1i("u_Texture",0);


	Renderer renderer;
	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(win,true);
	ImGui_ImplOpenGL3_Init("#version 440");
	ImGui::StyleColorsDark();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	
io.Fonts->AddFontDefault();
io.Fonts->Build();
	VertexBufferLayout vbl;
	vbl.append(GL_FLOAT,false,2);
	vbl.append(GL_FLOAT,false,2);
	VertexArray va;
	va.LinkVertexArray(vb,ib,vbl);

	glm::vec3 translation(200,200,0);
	float angle = 30.f;
	float angle2 = 30.f;
	float angle3 = 30.f;

    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	while(!glfwWindowShouldClose(win))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		
	glm::mat4 proj = glm::ortho(-.0f,500.f,-.0f,500.0f,-1.0f,1.0f);
	glm::mat4	rot = glm::rotate(glm::mat4(1.0),glm::radians(angle),glm::vec3(0,1,0));
		rot = glm::rotate(rot,glm::radians(angle2),glm::vec3(1,0,0));
		rot = glm::rotate(rot,glm::radians(angle3),glm::vec3(0,0,1));
	glm::mat4 model = glm::translate(glm::mat4(1.0f),translation) * rot;
	glm::mat4 mvp = proj * model;
		s.setUniformMat4("u_MVP",mvp);
		renderer.Draw(va,s);


		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		 static float f = 0.0f;
            static int counter = 0;

		   ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.


            ImGui::SliderFloat3("Transltaion", &translation.x, -200.f, 200.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
               ImGui::SliderFloat("Angle", &angle, 0, 360);            // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::SliderFloat("Angle2", &angle2, 0, 360);  
            ImGui::SliderFloat("Angle3", &angle3, 0, 360);  
            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
            ImGui::End();


		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


		glfwSwapBuffers(win);
		glfwPollEvents();
	}

	ImGui_ImplGlfw_Shutdown();
	ImGui_ImplOpenGL3_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
	std::cout<<"TEst";
}
