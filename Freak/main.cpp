#include "Game.h"

using std::string;

int main() {
	Game game;
	game.InitPlayer("imgs/player.png");
	game.Start();
	//GLFWwindow* win= openglInit("test", 800, 600, framebuffer_size_callback);
	//float time = glfwGetTime();
	//
	//std::shared_ptr<ConstVelocitySetter> velocity(new ConstVelocitySetter(0.01));
	//std::shared_ptr<Sprite> sprite(new Sprite("imgs/player.png"));
	//std::unique_ptr<BoxCollider> collider1(new BoxCollider(Bound2f(0, 0, 0.05, 0.05)));
	//GameObjectFactory fac;
 //   Player obj(0, 0, sprite);
	//velocity.get()->setBound(Bound2f(0, 0, 2, 2));
	//while (!glfwWindowShouldClose(win)) {
	//	float deltaTime = glfwGetTime() - time;
	//	time = glfwGetTime();
	//	process_input(win);
	//	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	//	glClear(GL_COLOR_BUFFER_BIT);
	//	obj.Update(deltaTime);
	//	obj.Draw();
	//	glfwPollEvents();
	//	glfwSwapBuffers(win);
	//	display_FPS(deltaTime);
	//}
	return 0;
}