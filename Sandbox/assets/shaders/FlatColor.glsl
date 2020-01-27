#type fragment
#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 u_Color;

void main()
{
	color = u_Color;
}

#type vertex
#version 330 core
uniform mat4 uVPCamera;
uniform mat4 u_Transform;

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec2 a_TextCoord;

void main()
{
	gl_Position = uVPCamera * u_Transform * vec4(a_Position, 1.0);			
}
