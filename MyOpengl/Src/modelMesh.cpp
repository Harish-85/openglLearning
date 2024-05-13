#pragma once
#include "modelMesh.h"


modelMesh::modelMesh(const std::string& path)
{
	tinygltf::Model model;
	tinygltf::TinyGLTF loader;
	std::string err;
	std::string warn;

	bool ret = loader.LoadASCIIFromFile(&model,&err,&warn,path);
	
	for(unsigned int i =0; i<model.nodes.size(); i++)
	{
		const tinygltf::Node &node = model.nodes[i];
		node.mesh
	}
	for(unsigned int i =0; i<model.meshes.size(); i++)
	{
		model.meshes[i].primitivesa
	}
}	
