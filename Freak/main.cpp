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
	
	std::shared_ptr<InputMovement> input(new InputMovement());
	std::shared_ptr<ConstVelocitySetter> velocity(new ConstVelocitySetter(0.01));
	std::shared_ptr<Sprite> sprite(new Sprite("imgs/player.png"));
	BoxCollider* collider1(new BoxCollider(Bound2f(0, 0, 0.05, 0.05)));
	BoxCollider* collider2(new BoxCollider(Bound2f(0, 0, 0.05, 0.05)));
	GameObjectPool pool;
	pool.create("ball",
		NULL,
		NULL,
		sprite,
		collider2);
	for (int i = 0; i < 1000; ++i) {
		pool.create("test",
			(float)rand() / (float)RAND_MAX * 2 - 1,
			(float)rand() / (float)RAND_MAX * 2 - 1,
			NULL,
			NULL,
			sprite,
			new BoxCollider(Bound2f(0, 0, 0.05, 0.05)));
	}
	pool.create("player",
		input,
		velocity,
		sprite,
		collider1);
	velocity.get()->setBound(Bound2f(0, 0, 2, 2));
	while (!glfwWindowShouldClose(win)) {
		float deltaTime = glfwGetTime() - time;
		time = glfwGetTime();
		process_input(win);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		pool.update(deltaTime);
		//pool.DoCollisionTest();
		pool.Draw();
		glfwPollEvents();
		glfwSwapBuffers(win);
		display_FPS(deltaTime);
	}
	return 0;
}