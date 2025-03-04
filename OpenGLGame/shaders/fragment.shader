#version 330 core

out vec4 FragColor;

in vec2 TexCoord;
in vec4 ColorVal;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform vec4 color1;

void main() {
		
	vec4 texColor = texture(texture1, TexCoord);
	vec4 mixColor = mix(ColorVal, color1, 0.8);
	FragColor = mix(texColor, mixColor, 0.5);
}




