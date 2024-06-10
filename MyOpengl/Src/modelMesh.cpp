#pragma once
#include "modelMesh.h"


Mesh* modelMesh::processMesh(aiMesh* mesh, const aiScene* scene)
{
	std::vector<vertex> vertices;
	std::vector<unsigned int> indices;
    

	for(unsigned int i =0;i<mesh->mNumVertices;i++)
	{
		vertex v;
		float scale = 100;
		v.position = glm::vec3(mesh->mVertices[i].x * scale,mesh->mVertices[i].y * scale,mesh->mVertices[i].z *scale);
		v.normal = glm::vec3(mesh->mNormals[i].x,mesh->mNormals[i].y,mesh->mNormals[i].z);
		
		v.color = glm::vec3(1,0,0);


		if(mesh->mTextureCoords[0]) // does the mesh contain texture coordinates?
		{
		   glm::vec2 vec;
		    vec.x = mesh->mTextureCoords[0][i].x; 
			  vec.y = mesh->mTextureCoords[0][i].y;
			  v.uv = vec;
			
		}
		vertices.push_back(v);
	}

	for(unsigned int i = 0;i<mesh->mNumFaces;i++)
	{
		aiFace f = mesh->mFaces[i];
		for(unsigned int j =0; j<f.mNumIndices;j++)
		{
			indices.push_back(f.mIndices[j]);
		}
	}
	//print all vertices
	//	std::cout<<"printing vertics " << vertices.size()<< std::endl;

	//for(int i =0;i<vertices.size();i++)
	//{
	//	std::cout << vertices[i].position.x <<" "<<vertices[i].position.x <<" "<<vertices[i].position.x <<" " <<'\n';
	//}
	//std::cout<<"printing indices " << indices.size()<< std::endl;

	//for(int i =0;i<vertices.size();i++)
	//{
	//	std::cout << indices[i] <<'\n';
	//}

	Mesh* m = new Mesh(vertices,indices);
	return m;
}


void modelMesh::processNode(aiNode* node, const aiScene* scene)
{
	//meshes.resize(node->mNumMeshes);
	for(unsigned int i =0;i<node->mNumMeshes;i++)
	{
		aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
		Mesh* temp = processMesh(mesh,scene);

		meshes.push_back(temp);
		
	}
}

modelMesh::modelMesh(const std::string& path)
{

	Assimp::Importer importer;
	const aiScene *scene  = importer.ReadFile(path,aiProcess_Triangulate | aiProcess_FlipUVs);

	if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene ->mRootNode)
	{
		std::cout << "Error importing model";
		return;
	}

	processNode(scene->mRootNode,scene);

	
	
}
