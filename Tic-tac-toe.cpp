#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

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
    int turn = 1;
    bool hasPlayerWon = false;
    bool hasBotWon = false;
    bool isDraw = false;
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

    void botTurn()
    {
        if(turn == 1 && isGameRunning)
        {
            if(board.cells[4] == EMPTY)
            {
                board.cells[4] = BOT;
            }
            else if(board.cells[0] == EMPTY)
            {
                board.cells[0] = BOT;
            }
        }
        else if(turn == 2 && isGameRunning)
        {
            if(board.cells[4] == BOT)
            {
                if(board.cells[0] == PLAYER && board.cells[1] == PLAYER)
                    board.cells[2] = BOT;
                else if(board.cells[1] == PLAYER && board.cells[2] == PLAYER)
                    board.cells[0] = BOT;
                else if(board.cells[0] == PLAYER && board.cells[2] == PLAYER)
                    board.cells[1] = BOT;
                else if(board.cells[0] == PLAYER && board.cells[3] == PLAYER)
                    board.cells[6] = BOT;
                else if(board.cells[3] == PLAYER && board.cells[6] == PLAYER)
                    board.cells[0] = BOT;
                else if(board.cells[2] == PLAYER && board.cells[5] == PLAYER)
                    board.cells[8] = BOT;
                else if(board.cells[5] == PLAYER && board.cells[8] == PLAYER)
                    board.cells[2] = BOT;
                else if(board.cells[6] == PLAYER && board.cells[7] == PLAYER)
                    board.cells[8] = BOT;
                else if(board.cells[7] == PLAYER && board.cells[8] == PLAYER)
                    board.cells[6] = BOT;
                else
                    botRandomTurn();
            }
            if(board.cells[0] == BOT)
            {
                if(board.cells[1] == PLAYER && board.cells[4] == PLAYER)
                    board.cells[7] = BOT;
                else if(board.cells[2] == PLAYER && board.cells[4] == PLAYER)
                    board.cells[6] = BOT;
                else if(board.cells[3] == PLAYER && board.cells[4] == PLAYER)
                    board.cells[5] = BOT;
                else if(board.cells[5] == PLAYER && board.cells[4] == PLAYER)
                    board.cells[3] = BOT;
                else if(board.cells[6] == PLAYER && board.cells[4] == PLAYER)
                    board.cells[2] = BOT;
                else if(board.cells[7] == PLAYER && board.cells[4] == PLAYER)
                    board.cells[1] = BOT;
                else
                    botRandomTurn();
            }
        }
        else if(turn > 2 && isGameRunning)
            botRandomTurn();

        if(isGameRunning)
        {
            std::cout << "\nComputer turn:\n";
            printBoard();
            turn++;
        }
    }

    void botRandomTurn()
    {
        int free_cells[9];
        int counter = 0;
        for(int i = 0; i < 9; i++)
        {
            if(board.cells[i] == EMPTY)
            {
                free_cells[counter] = i;
                counter++;
            }
        }

        int random = rand() % counter;
        int result = free_cells[random];

        board.cells[result] = BOT;
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
        else if(checkForDraw())
            isDraw = true, isGameRunning = false;
    }

    bool checkForDraw()
    {
        for(int i = 0; i < 9; i++)
            if(board.cells[i] == EMPTY)
                return false;

        return true;
    }

    void play()
    {
        srand((unsigned)time(NULL));

        printBoard();
        while(isGameRunning)
        {
            takePlayerInput();
            printBoard();
            checkWinCondition();
            botTurn();
            checkWinCondition();
        }
        printResult();
    }

    void printResult()
    {
        if(hasPlayerWon)
        {
            std::cout << "\nCongratulations! You won!\n\nWant to play again? (y/n) ";
            std::string choice;
            std::cin >> choice;
            if(choice == "y" || choice == "Y")
            {
                restartGame();
            }
            else
                return;
        }
        else if(hasBotWon)
        {
            std::cout << "\nUnfortunately you lost :\(\n\nWant to play again? (y/n) ";
            std::string choice;
            std::cin >> choice;
            if(choice == "y" || choice == "Y")
            {
                restartGame();
            }
            else
                return;
        }
        else if(isDraw)
        {
            std::cout << "\nIt's a draw.\n\nWant to play again? (y/n) ";
            std::string choice;
            std::cin >> choice;
            if(choice == "y" || choice == "Y")
            {
                restartGame();
            }
            else
                return;
        }

    }

    void restartGame()
    {
        board.clearBoard();
        hasPlayerWon = false;
        hasBotWon = false;
        isDraw = false;
        turn = 1;
        isGameRunning = true;
        play();
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
