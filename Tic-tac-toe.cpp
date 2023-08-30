#include <iostream>
#include <vector>

enum {
    EMPTY,
    PLAYER,
    BOT
};

class Board{
public:
    int cells[9] = {EMPTY, EMPTY, EMPTY,
                    EMPTY, EMPTY, EMPTY,
                    EMPTY, EMPTY, EMPTY};
};

class Game{
public:
    Board board;
    void printBoard()
    {
        for(int i = 0; i < 9; i++)
        {
            if(i % 3 == 0)
                std::cout << '\n';

            if(board.cells[i] == PLAYER)
                std::cout << 'X' << ' ';
            else if(board.cells[i] == BOT)
                std::cout << 'O' << ' ';
            else
                std::cout << '-' << ' ';

        }
        std::cout << std::endl;
    }

};

int main()
{
    Game game;
    game.printBoard();

    return 0;
}
