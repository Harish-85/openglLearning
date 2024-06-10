#include "Renderer.h"



void Renderer::Draw(const Mesh* m,Shader& shader) const 
{	
		m->Draw(shader);

}
