#include "Game.h"
#include "WindowFunc.h"
#include "Player.h"

Game::Game()
{
	m_window = openglInit("test", 800, 600, framebuffer_size_callback);
	m_state = GAME_MENU;
	m_player = nullptr;
	m_enemies = nullptr;
	m_bullets = nullptr;
}

void Game::Start()
{
	if (m_player == nullptr) {
		std::cout << "Error: Player is NULL!" << std::endl;
		return;
	}
	static double time = glfwGetTime();
	while (!glfwWindowShouldClose(m_window)) {
		double cur_time = glfwGetTime();
		Update(cur_time - time);
		time = cur_time;
		Draw();
	}
}

void Game::InitPlayer(std::string path)
{
	m_player = new Player(0, 0, path);
}

void Game::Update(float deltaTime)
{
	m_player->Update(deltaTime);
}

void Game::Draw()
{
	process_input(m_window);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	m_player->Draw();
	glfwPollEvents();
	glfwSwapBuffers(m_window);
}

Game::~Game()
{
	if (m_player) {
		delete m_player;
	}
	if (m_enemies) {
		delete m_enemies;
	}
	if (m_bullets) {
		delete m_bullets;
	}
}
