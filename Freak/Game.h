#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>

class Player;
class EnemyPool;
class BulletSystem;
enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

class Game {
private:
	GLFWwindow* m_window;
	GameState m_state;
	Player* m_player;
	EnemyPool* m_enemies;
	BulletSystem* m_bullets;
	int m_height;
	int m_width;
public:
	Game();
	void Start();
	void InitPlayer(std::string path);
	void Update(float deltaTime);
	void Draw();
	~Game();
};