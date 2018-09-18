#include "Graphics.h"
#include "../utils.h"

using std::unordered_map;
using std::string;
unordered_map<string, unsigned int> Sprite::Path2TexID = unordered_map<string, unsigned int>();

Sprite::Sprite(std::string path)
{
	TexID = get_id_or_load(path);
	xpos = 0;
	ypos = 0;
}

void Sprite::SetPos(float x, float y)
{
	xpos = x;
	ypos = y;
}

void Sprite::Draw()
{
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	Shader& shader = get_shader();
	shader.use();
	shader.setFloat("sprite_tex", 0);
	shader.setVec3("aPos", glm::vec3(xpos, ypos, 0));
	glBindVertexArray(VAO);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, TexID);
	glDrawArrays(GL_POINTS, 0, 1);
	glBindVertexArray(0);
	glDeleteVertexArrays(1, &VAO);
}

unsigned int Sprite::get_id_or_load(std::string path)
{
	if (Path2TexID.find(path) == Path2TexID.end()) {
		Path2TexID[path] = loadMaterial(path);
	}
	return Path2TexID[path];
}

Shader & Sprite::get_shader()
{
	static Shader pointShader("shaders/pointShader.vs", "shaders/pointShader.fs");
	return pointShader;
}
