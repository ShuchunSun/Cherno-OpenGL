#shader vertex
#version 330 core

layout(location = 0) in vec3 a_position;
layout(location = 1) in vec4 a_color;
layout(location = 2) in vec2 a_textCoord;
layout(location = 3) in float a_textIndex;

out vec4 v_color;
out vec2 v_textCoord;
out float v_textIndex;

uniform mat4 u_proj;

void main()
{
	gl_Position = u_proj * vec4(a_position.x, a_position.y, a_position.z, 1.0);
	v_color = a_color;
	v_textCoord = a_textCoord;
	v_textIndex = a_textIndex;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;
in vec4 v_color;
in vec2 v_textCoord;
in float v_textIndex;

uniform sampler2D u_texture[2];

void main()
{
	int index = int(v_textIndex);
	vec4 texColor = texture(u_texture[index], v_textCoord);
	color = texColor;
}