#type fragment
#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

in vec2 v_TextCoord;

void main()
{
	color = texture(u_Texture, v_TextCoord) * u_Color;
}

#type vertex
#version 330 core
uniform mat4 uVPCamera;
uniform mat4 u_Transform;

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec2 a_TextCoord;

out vec2 v_TextCoord;

void main()
{
	v_TextCoord = a_TextCoord;
	gl_Position = uVPCamera * u_Transform * vec4(a_Position, 1.0);			
}
