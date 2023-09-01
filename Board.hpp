#pragma once


enum {
    EMPTY,
    PLAYER,
    BOT
};

/**
 * Game board made of array
 */
class Board{
public:
    int cells[9] = {EMPTY, EMPTY, EMPTY,
                    EMPTY, EMPTY, EMPTY,
                    EMPTY, EMPTY, EMPTY};

	/**
	 * Fill the board with empty values after restarting the game
	 */
    void clearBoard()
    {
        for(int i = 0; i < 9; i++)
            cells[i] = EMPTY;
    }
};
