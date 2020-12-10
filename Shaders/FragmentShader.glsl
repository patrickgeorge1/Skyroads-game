#version 330

// TODO: get values from fragment shader
in vec3 frag_position;
in vec3 frag_normal;
in vec2 frag_texture;
in vec3 frag_color;
in float frag_time;


layout(location = 0) out vec4 out_color;


void main()
{
	// TODO: write pixel out color
	if (frag_time != 0) {
		out_color	= vec4(abs(frag_normal), 1.f);
	} else {
		out_color	= vec4(frag_color, 1.f);
	}
}