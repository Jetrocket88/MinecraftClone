#version 330 core

out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main() {
		
	vec4 texColor = texture(texture1, TexCoord);
	vec4 tintColor = vec4(0.3, 0.0, 1.0, 1.0);
	FragColor = mix(texColor, tintColor, 0.2);
}




