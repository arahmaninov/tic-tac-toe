#include <gtest/gtest.h>
#include "Board.hpp"
#include "Game.hpp"

TEST(BoardTests, Number_1)
{
	Board board;
	bool flag = true;
	for(int i = 0; i < 9; i++)
	{
		if(board.cells[i] != 0)
		{
			flag = false;
			break;
		}
	}
	ASSERT_TRUE(flag == true);
}




int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
