#version 330

// TODO: get vertex attributes from each location
layout(location = 0) in vec3 v_position;
layout(location = 1) in vec3 v_normal;
layout(location = 2) in vec2 v_texture;
layout(location = 3) in vec3 v_color;

// Uniform properties
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform float time;

// TODO: output values to fragment shader
out vec3 frag_position;
out vec3 frag_normal;
out vec2 frag_texture;
out vec3 frag_color;


void main()
{
	// TODO: send output to fragment shader
	frag_position	= v_position;
	frag_normal		= v_normal + vec3(cos(time), sin(time), sin(time));   // change color
	frag_texture	= v_texture;
	frag_color		= v_color;


	// TODO: compute gl_Position
	 vec3 vec_new_position = v_position + v_normal * vec3(sin(time), sin(time), sin(time));
	// vec3 vec_new_position = v_position;
	gl_Position	= Projection * View * Model * vec4(vec_new_position, 1.f);
}
