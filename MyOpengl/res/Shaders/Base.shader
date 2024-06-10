#shader vertex
#version 330 core
layout(location =0)in vec4 position;
layout(location = 1) in vec3 color;
layout(location = 2) in vec3 normal;
layout(location = 3) in vec2 texCoord;

uniform mat4 u_MVP;
out vec2 v_TexCoord;
out vec3 vCol;
out vec3 v_normal;

void main(){
	vCol = color;
	v_normal = normal;
	v_TexCoord = texCoord;
	gl_Position = u_MVP * position;
}

#shader fragment
#version 330 core

in vec2 v_TexCoord;
in vec3 vCol;
in vec3 v_normal;
out vec4 color;
uniform sampler2D u_Texture;

uniform vec4 u_col;
void main(){

	//vec4 texCol = texture(u_Texture,v_TexCoord);
	//color = texCol;
	vec3 lightDir = normalize(vec3(-.3f,-.5f,1));
	float d = max(0,dot(lightDir,v_normal)) + .1;
	
	color = vec4(vCol.xyz,1)*d;
}

