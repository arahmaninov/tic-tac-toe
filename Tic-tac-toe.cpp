#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Board.hpp"
#include "Game.hpp"


/**
 * @mainpage Tic-tac-toe documentation
 *
 * This is a test documentation for a simple tic-tac-toe game.
 * Documentation was made with Doxygen.
 */



/**
 * Print title of the game
 */
void printTitle();

int main()
{
    printTitle();
    Game game;
    game.play();

    return 0;
}

void printTitle()
{
    std::cout << "\t===========================\n";
    std::cout << "\t=\tTIC-TAC-TOE\t  =\n";
    std::cout << "\t===========================\n\n\n";
}
