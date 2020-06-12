#version 330 core
in vec3 ourColor;
out vec4 color;

//texture
//uniform sampler2D ourTexture1;
//uniform sampler2D ourTexture2;

void main(){
	color = vec4(ourColor, 1.0f);
}