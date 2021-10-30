#include "Game.h"


//Constructor
Game::Game()
{
	this->InitializeVariables();
	this->InitializeWindow();
}

//Update
void Game::Update()
{
	this->PollEvents();
}

void Game::Render()
{
	this->window->clear(sf::Color(0, 255, 165, 255));

	//Draw game object

	this->window->display();
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

const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}

void Game::InitializeVariables()
{
	this->window = nullptr;
}

void Game::InitializeWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "Game!", sf::Style::Titlebar | sf::Style::Close);
}

//Accessors


Game::~Game()
{
	delete this->window;
}
