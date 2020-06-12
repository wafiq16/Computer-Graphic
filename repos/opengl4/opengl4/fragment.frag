#version 330 core
in vec3 ourColor;
out vec4 color;

void main(){
	color = vec4(ourColor, 1.0);
}

// #version 330 core
// //layout (location = 0) in vec3 position;
// in vec3 ourColor;
// in vec2 TexCoord;
// //layout (location = 2) in vec2 texCoord;
// out vec4 color;

// uniform sampler2D ourTexture; 
// //out vec2 TexCoord;
// void main()
// {
// 	//gl_position = vec4(position, 1.0f);
// 	color = texture(ourTexture, TexCoord);//* vec4(ourColor, 1.0f ); 
// 	//TexCoord = vec2(texCoord.x, 1.0 - texCoord.y);
// }

// #version 330 core
// in vec3 ourColor;
// in vec2 TexCoord;
// out vec4 color;
// // Texture samplers
// uniform sampler2D ourTexture1;
// uniform sampler2D ourTexture2;
// void main()
// {
//  // Linearly interpolate between both textures (second texture is only slightly combined)
//  color = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord),
// 0.5);
// }