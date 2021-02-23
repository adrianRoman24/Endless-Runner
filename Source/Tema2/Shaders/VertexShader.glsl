#version 330

// TODO: get vertex attributes from each location
layout(location = 0) in vec3 v_position;
layout(location = 3) in vec3 v_color;
layout(location = 1) in vec3 v_normal;
layout(location = 2) in vec2 tex_coord;

// Uniform properties
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform float Time;
uniform int Deformation;

// TODO: output values to fragment shader
out vec3 frag_color;
out vec3 frag_pos;
out vec3 frag_normal;

// texture
out vec2 texcoord;

void main()
{
	// TODO : pass v_texture_coord as output to Fragment Shader
	texcoord = tex_coord;

	// TODO: send output to fragment shader
	frag_color =  v_color;
	frag_pos = (Model * vec4(v_position,1)).xyz;
	frag_normal = normalize(mat3(Model) * v_normal);

	// TODO: compute gl_Position
	if(Deformation == 0) {
		gl_Position = Projection * View * (Model * vec4(v_position, 1.0) + vec4(vec3(0, 0,0),0));
	} else {
		gl_Position = Projection * View * (Model * vec4(1.2f * vec3(v_position.x, -v_position.y * v_normal.y * 0.8f, v_position.z), 1.0) + vec4(vec3(0, 0,0),0));
	}
}
