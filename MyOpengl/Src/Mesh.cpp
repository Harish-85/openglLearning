#include "Mesh.h"

#include "IndexBuffer.h"
#include "Shader.h"
#include "VertexArray.h"

Mesh::Mesh(const std::vector<vertex>& vertices, const std::vector<GLuint>& indices)
{
	Mesh::vertices = vertices;
	Mesh::indices = indices;

	std::cout<<"Size" <<Mesh::vertices.size();
	VertexBuffer vb(vertices);
	IndexBuffer ib(indices);

	VertexBufferLayout vbl;

	vbl.append(GL_FLOAT,false,3);//position
	vbl.append(GL_FLOAT,false,3);//color
	vbl.append(GL_FLOAT,false,3);//normal
	vbl.append(GL_FLOAT,false,2);//uv

	
	va.LinkVertexArray(vb,ib,vbl);

}

void Mesh::Draw(Shader& shader) const
{
	va.Bind();
	
	shader.bind();

	GLCall(glDrawElements(GL_TRIANGLES,indices.size(),GL_UNSIGNED_INT,nullptr));
}
