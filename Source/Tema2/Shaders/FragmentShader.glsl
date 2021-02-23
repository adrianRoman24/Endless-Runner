#version 330

// TODO: get values from fragment shader
in vec3 frag_normal;
in vec3 frag_color;
in vec3 frag_pos;
in vec2 texcoord;

layout(location = 0) out vec4 out_color;

uniform sampler2D texture;
uniform int applyTexture;
uniform int applyColorMix;

// Uniforms for light properties
uniform vec3 light_direction;
//uniform vec3 light_position;
uniform vec3 eye_position;
uniform vec3 light_positions[10];

uniform float material_kd;
uniform float material_ks;
uniform int material_shininess;
uniform int spotlight;
uniform int lightPosNumber;

void main()
{	
	vec4 initial_texture = texture2D(texture, texcoord);
	vec3 my_texture = vec3(initial_texture.x, initial_texture.y, initial_texture.z);

	float intensity_sum = 0;
	for(int i = 0; i < lightPosNumber; i++) {/////////////
	vec3 light_position = light_positions[i];
	// light
	vec3 L = normalize(light_position - frag_pos);
	vec3 V = normalize(eye_position - frag_pos);
	vec3 H = normalize(L + V);
	vec3 R = reflect (-L, frag_normal);

	// TODO: define ambient light component
	float ambient_light = 0.25;

	// TODO: compute diffuse light component
	float diffuse_light = material_kd * max (dot(frag_normal, L), 0); // difuza

	// TODO: compute specular light component
	float primeste_lumina;
	if(dot(L, frag_normal) > 0) {
		primeste_lumina = 1;
	} else {
		primeste_lumina = 0;
	}
	
	float specular_light = 0;
	if (diffuse_light > 0)
	{
		float p = pow(max(dot(frag_normal, H), 0), material_shininess);
		specular_light = material_ks * primeste_lumina * p;
	}

	// TODO: compute light
	float d = length(L);
	float factor_atenuare = 1 / (d * d) + 1;
	float intensity = ambient_light + factor_atenuare * (diffuse_light + specular_light);
	if(light_position.x == 0) {
		// TODO: write pixel out color
		float cut_off = radians(30);
		float spot_light = dot(-L, light_direction);

		// OUTPUT COLOR
		if (spot_light > cos(cut_off))
		{
			float spot_light_limit = cos(cut_off);
 
			// Quadratic attenuation
			float linear_att = (spot_light - spot_light_limit) / (1 - spot_light_limit);
			float light_att_factor = pow(linear_att, 2);
			float factor_final = factor_atenuare * (diffuse_light + specular_light) * light_att_factor;
			//out_color = vec4(frag_color * (factor_final + ambient_light), 1);
			intensity_sum += factor_final + ambient_light;
		} else {
			//out_color = vec4(ambient_light * frag_color, 1);
			intensity_sum += ambient_light;
		}
	} else {
		intensity_sum += intensity;
	}
	}/////////////
	if(frag_color == vec3(0, 0, 0)) {
			out_color = vec4(intensity_sum * 0.8f * vec3(1, 1, 1), 1);
		} else {
			out_color = vec4(intensity_sum * 0.8f * frag_color, 1);
		}
	if(applyTexture == 1) {
		if(applyColorMix == 1) {
			out_color = texture2D(texture, texcoord) * out_color;
		} else {
			out_color = texture2D(texture, texcoord);
		}
		if(out_color.a < 0.5f) {
			discard;
		}
	}
}
