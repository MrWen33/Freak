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
	RAII<ConstVelocitySetter> velocity(new ConstVelocitySetter(0.01));
	RAII<Sprite> sprite(new Sprite("imgs/player.png"));
	RAII<BoxCollider> collider1(new BoxCollider(Bound2f(0, 0, 0.05, 0.05)));
	RAII<BoxCollider> collider2(new BoxCollider(Bound2f(0, 0, 0.05, 0.05)));
	GameObjectPool pool;
	pool.create("player",
		input.get(),
		velocity.get(),
		sprite.get(), 
		collider1.get());
	pool.create("ball",
		NULL,
		NULL,
		sprite.get(),
		collider2.get());
	velocity.get()->setBound(Bound2f(0, 0, 2, 2));
	while (!glfwWindowShouldClose(win)) {
		float deltaTime = glfwGetTime() - time;
		time = glfwGetTime();
		process_input(win);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		pool.update(deltaTime);
		pool.DoCollisionTest();
		pool.Draw();
		glfwPollEvents();
		glfwSwapBuffers(win);
	}
	return 0;
}