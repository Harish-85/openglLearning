#pragma once
#include "Mesh.h"
#include "gltf/tiny_gltf.h"

class modelMesh
{
private:
	Mesh mesh;

public:
	modelMesh(const std::string& path);
};


