#version 330 core

uniform sampler2D sprite_tex;
out vec4 FragColor;

void main(){
	FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	FragColor = texture(sprite_tex, gl_PointCoord);
}