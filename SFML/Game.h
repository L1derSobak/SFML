#pragma once

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
	void PollEvents();

	const bool getWindowIsOpen() const;

	// Destructors
	virtual ~Game();

private:
	//Private functions
	void InitializeVariables();
	void InitializeWindow();

	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;

};

