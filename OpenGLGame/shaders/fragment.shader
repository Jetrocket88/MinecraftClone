#version 330 core

out vec4 FragColor;

in vec2 TexCoord;
in vec4 ColorVal;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform vec4 color1;

void main() {
		
	vec4 texColor = texture(texture1, TexCoord);
	FragColor = texColor * ColorVal; 
}




