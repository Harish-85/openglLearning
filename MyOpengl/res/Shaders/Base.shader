#shader fragment
#version 330 core
layout (location =0)out vec4 color;

uniform vec4 u_col;
void main(){
	color = u_col;
	
}

#shader vertex
#version 330 core
layout(location =0)in vec4 position;

void main(){
	gl_Position = position;
	
}