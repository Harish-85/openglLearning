#include "Renderer.h"



void Renderer::Draw(const VertexArray& va, const Shader& s) const
{
		
		va.Bind();
		s.bind();
		//s.setUniform4f("u_col",(sin(glfwGetTime()) +1.0)/2.0,1,0,1);
		GLCall(glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,nullptr));
}
