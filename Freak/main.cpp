#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<iostream>
#include<string>
#include"utils.h"
#include"WindowFunc.h"
#include"GameObject.h"
#include"Player.h"
#include"RAII.h"

using std::string;

int main() {
	GLFWwindow* win= openglInit("test", 800, 600, framebuffer_size_callback);
	float time = glfwGetTime();
	RAII<InputMovement> input(new InputMovement());
	RAII<VelocitySetter> velocity(new ConstVelocitySetter(0.01));
	RAII<Sprite> sprite(new Sprite("imgs/player.png"));
	GameObjectPool pool;
	pool.create("player",
		input.get(),
		velocity.get(),
		sprite.get());
	while (!glfwWindowShouldClose(win)) {
		float deltaTime = glfwGetTime() - time;
		time = glfwGetTime();
		process_input(win);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		pool.update(deltaTime);
		glfwPollEvents();
		glfwSwapBuffers(win);
	}
	return 0;
}