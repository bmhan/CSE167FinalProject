#version 330 core
// This is a sample fragment shader.

in vec3 Normal;
in vec2 texel;

// You can output many things. The first vec4 type output determines the color of the fragment
out vec4 FragColor;

uniform vec3 color;
uniform int normalColor;
uniform sampler2D terrainTexture;

void main()
{    
	if(normalColor == 1)
		FragColor = vec4(Normal, 1.0);
	else
		FragColor = texture(terrainTexture, texel);
}