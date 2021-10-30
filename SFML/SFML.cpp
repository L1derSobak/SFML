#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main()
{
    //Window
    sf::RenderWindow window(sf::VideoMode(640, 480), "My first SFML programm!", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;

    //Game loop
    while (window.isOpen())
    {
        //Event polling
        while (window.pollEvent(ev))
        {
            switch (ev.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape)
                    window.close();
                break;
            }
        }

        //Update


         //Render
        window.clear(sf::Color(0, 255, 141, 255));//CLear old frame

        //Draw your game

        window.display(); //Tell app that window is done drawing       
    }

    //End of application
    return 0;
}
