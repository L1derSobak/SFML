#include <iostream>
#include "Game.h"

int main()
{
    //Init sradn
    std::srand(static_cast<unsigned>(time(NULL)));
    //Init Game engine
    Game game;

    //Game loop
    while (game.getWindowIsOpen())
    {
        //Update
        game.Update();

        //Render
        game.Render();
    }

    //End of application
    return 0;
}
