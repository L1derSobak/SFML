#pragma once

#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
	Game engine class	
*/

class Game
{
public:
	//Constructors
	Game();

	//Functions
	void Update();
	void Render();

	void UpdateEnemies();
	void RenderEnemies();

	void PollEvents();
	void updateMousePositions();
	void spawnEnemy();

	//Accessors
	const bool getWindowIsOpen() const;

	// Destructors
	virtual ~Game();

private:
	//Private functions
	void InitializeVariables();
	void InitializeWindow();
	void InitializeEnemies();

	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;

	//Mouse positions
	sf::Vector2i mousePosWindow;

	//Game logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;

	//game objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;
};

