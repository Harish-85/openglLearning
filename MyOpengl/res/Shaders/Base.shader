#shader vertex
#version 330 core
layout(location =0)in vec4 position;
layout(location = 1) in vec2 texCoord;

uniform mat4 u_MVP;
out vec2 v_TexCoord;

void main(){
	v_TexCoord = texCoord;
	gl_Position = u_MVP * position;
}

#shader fragment
#version 330 core

in vec2 v_TexCoord;
layout (location =0)out vec4 color;
uniform sampler2D u_Texture;

uniform vec4 u_col;
void main(){

	vec4 texCol = texture(u_Texture,v_TexCoord);
	color = texCol;
	color = vec4(v_TexCoord.xy,0,0);
}

