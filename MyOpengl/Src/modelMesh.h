#pragma once
#include "Mesh.h"
#include "wavefront/tiny_obj_loader.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class modelMesh
{
private:
	

public:

	std::vector<Mesh*> meshes;
	Mesh* processMesh(aiMesh* mesh, const aiScene* scene);
	
	void processNode(aiNode* node, const aiScene* scene);
	modelMesh(const std::string& path);
	void Draw(Shader& s);
};


