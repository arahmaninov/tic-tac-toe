#include <iostream>
#include <string>

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

    void clearBoard()
    {
        for(int i = 0; i < 9; i++)
            cells[i] = EMPTY;
    }
};

class Game{
public:
    Board board;
    bool hasPlayerWon = false;
    bool hasBotWon = false;
    bool isGameRunning = true;

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

    void takePlayerInput()
    {
        std::string playerChoice;
        bool isChoiceLegit = false;
        do{
            std::cout << "\nChoose a free cell (type a number from 1 to 9): ";
            std::cin >> playerChoice;

            if(!isInputValid(playerChoice))
                std::cout << "Invalid input. Type a number from 1 to 9.\n\n";
            else if( stoi(playerChoice) < 1 || stoi(playerChoice) > 9)
                std::cout << "Invalid input. Type a number from 1 to 9.\n\n";
            else if(board.cells[stoi(playerChoice) - 1] != EMPTY)
                std::cout << "This cell is already taken. Choose another cell.\n\n";
            else if(board.cells[stoi(playerChoice) - 1] == EMPTY)
            {
                board.cells[stoi(playerChoice) - 1] = PLAYER;
                isChoiceLegit = true;
            }

        }while(!isChoiceLegit);
    }

    void checkWinCondition()
    {
        if((board.cells[0] == PLAYER && board.cells[1] == PLAYER && board.cells[2] == PLAYER) || // 1st row
           (board.cells[3] == PLAYER && board.cells[4] == PLAYER && board.cells[5] == PLAYER) || // 2nd row
           (board.cells[6] == PLAYER && board.cells[7] == PLAYER && board.cells[8] == PLAYER) || // 3d row
           (board.cells[0] == PLAYER && board.cells[3] == PLAYER && board.cells[6] == PLAYER) || // 1st column
           (board.cells[1] == PLAYER && board.cells[4] == PLAYER && board.cells[7] == PLAYER) || // 2nd column
           (board.cells[2] == PLAYER && board.cells[5] == PLAYER && board.cells[8] == PLAYER) || // 3d column
           (board.cells[0] == PLAYER && board.cells[4] == PLAYER && board.cells[8] == PLAYER) || // 1st diagonal
           (board.cells[2] == PLAYER && board.cells[4] == PLAYER && board.cells[6] == PLAYER)    // 2nd diagonal
           )
            hasPlayerWon = true, isGameRunning = false;
        else if((board.cells[0] == BOT && board.cells[1] == BOT && board.cells[2] == BOT) || // 1st row
           (board.cells[3] == BOT && board.cells[4] == BOT && board.cells[5] == BOT) || // 2nd row
           (board.cells[6] == BOT && board.cells[7] == BOT && board.cells[8] == BOT) || // 3d row
           (board.cells[0] == BOT && board.cells[3] == BOT && board.cells[6] == BOT) || // 1st column
           (board.cells[1] == BOT && board.cells[4] == BOT && board.cells[7] == BOT) || // 2nd column
           (board.cells[2] == BOT && board.cells[5] == BOT && board.cells[8] == BOT) || // 3d column
           (board.cells[0] == BOT && board.cells[4] == BOT && board.cells[8] == BOT) || // 1st diagonal
           (board.cells[2] == BOT && board.cells[4] == BOT && board.cells[6] == BOT)    // 2nd diagonal
           )
            hasBotWon = true, isGameRunning = false;
    }

    void play()
    {
        while(isGameRunning)
        {
            printBoard();
            takePlayerInput();
            checkWinCondition();
        }
        printResult();
    }

    void printResult()
    {
        if(hasPlayerWon)
        {
            std::cout << "\nCongratulations! You won!\nWant to play again? ";
            std::string choice;
            std::cin >> choice;
            if(choice == "y" || choice == "Y")
            {
                board.clearBoard();
                hasPlayerWon = false;
                isGameRunning = true;
                play();
            }
            else
                return;
        }
        else if(hasBotWon)
        {
            std::cout << "\nUnfortunately you lost :\(\nWant to play again? ";
            std::string choice;
            std::cin >> choice;
            if(choice == "y" || choice == "Y")
            {
                board.clearBoard();
                hasBotWon = false;
                isGameRunning = true;
                play();
            }
            else
                return;
        }

    }

    bool isInputValid(std::string input)
    {
        for(const auto& c : input)
        {
            if(!std::isdigit(c))
                return false;
        }

        return true;
    }
};



int main()
{
    Game game;
    game.play();


    return 0;
}

