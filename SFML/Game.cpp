#include "Game.h"


//Constructor
Game::Game()
{
	this->InitializeVariables();
	this->InitializeWindow();
	this->InitializeEnemies();
}

//Update
void Game::Update()
{
	this->PollEvents();

	this->updateMousePositions();	

	this->UpdateEnemies();
}

void Game::Render()
{
	this->window->clear();

	//Draw game object

	this->RenderEnemies();

	this->window->display();
}

void Game::UpdateEnemies()
{
	/*
		@return void

		Updates the enemy spawn timer and spawn enemies
		whet the total...
	*/

	//Updating the timer for enemy spawning
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer <= this->enemySpawnTimerMax)
		{
			//Spawn the enemy and reset the timer
			this->spawnEnemy();
			this->enemySpawnTimer = 0.0f;
		}
		else
			this->enemySpawnTimer += 1.0f;
	}

	//Move the enemies

	for (auto& e : this->enemies)
	{
		e.move(0.0f, 1.0f);
	}
}

void Game::RenderEnemies()
{
	//Rendering all the enemies
	for (auto& e : this->enemies)
	{
		this->window->draw(e);
	}
}

void Game::PollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::updateMousePositions()
{
	/*
	@return void
	
	update the mouse position:
		- Mouse position relative to window(Vctor2i)
	*/

	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Game::spawnEnemy()
{
	/*
		@return void

		Spawns enemies and sets their color and positions
		-Sets the random positions.
		-Sets a random color.
		-Adds enemy to the vector.
	*/

	this->enemy.setPosition(
		static_cast<float>(rand()%static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		0.0f//static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
	);
	this->enemy.setFillColor(sf::Color::Green);

	//Spawn the enemy
	this->enemies.push_back(this->enemy);
}

const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}

void Game::InitializeVariables()
{
	this->window = nullptr;

	//Game logic
	this->points = 0;
	this->enemySpawnTimer = 0.0f;
	this->enemySpawnTimerMax = 1000.0f;
	this->maxEnemies = 1;
}

void Game::InitializeWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "Game!", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::InitializeEnemies()
{
	this->enemy.setPosition(sf::Vector2f(10.0f, 10.0f));
	this->enemy.setSize(sf::Vector2f(100.0f, 100.0f));
	this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
	this->enemy.setFillColor(sf::Color::Cyan);
	this->enemy.setOutlineColor(sf::Color::Red);
	this->enemy.setOutlineThickness(1.0f);
}

Game::~Game()
{
	delete this->window;
}
