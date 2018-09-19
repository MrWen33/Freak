#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<iostream>
#include<string>
#include"utils.h"
#include"WindowFunc.h"
#include"GameObject.h"
#include"Player.h"

using std::string;

int main() {
	GLFWwindow* win= openglInit("test", 800, 600, framebuffer_size_callback);
	float time = glfwGetTime();
	Player player("player", "imgs/player.png");
	while (!glfwWindowShouldClose(win)) {
		float deltaTime = glfwGetTime() - time;
		time = glfwGetTime();
		process_input(win);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		for (auto& object : GameObject::objects) {
			object->Update(deltaTime);
			object->Draw();
		}

		glfwPollEvents();
		glfwSwapBuffers(win);
		GameObject::fresh_obj_sheet();
	}
	return 0;
}