#include "gtest/gtest.h"
#include "Board.h"

namespace
{
/*
	a b c d e f g h
	_ _ _ _ _ _ _ _  1
	_ _ _ _ _ _ _ _  2
	_ _ _ _ _ _ _ _  3
	_ _ _ W B _ _ _  4
	_ _ _ B W _ _ _  5
	_ _ _ _ _ _ _ _  6
	_ _ _ _ _ _ _ _  7
	_ _ _ _ _ _ _ _  8
*/
}

TEST(BoardTest, should_init_othello_board_with_W_B_B_W_in_d4_d5_e4_e5_position)
{
    Board board;
    ASSERT_EQ(board.at(e4), B);
    ASSERT_EQ(board.at(d5), B);
    ASSERT_EQ(board.at(d4), W);
    ASSERT_EQ(board.at(e5), W);
}

namespace
{
	const Disc GIVEN_BOARD[MAX_POSITION_NUM] =
	{
		_, _, _, _, _, _, _, _,
		_, _, _, _, _, _, _, _,
		_, _, _, _, _, _, _, _,
		_, _, _, W, B, _, _, _,
		_, _, _, B, W, _, _, _,
		_, _, _, _, _, _, _, _,
		_, _, _, _, _, _, _, _,
		_, _, _, _, _, _, _, _,
	};
}

TEST(BoardTest, should_init_board_given_disc_array)
{
    Board board(GIVEN_BOARD);
	ASSERT_EQ(board.at(d4), W);
	ASSERT_EQ(board.at(d5), B);
    ASSERT_EQ(board.at(e4), B);
	ASSERT_EQ(board.at(e5), W);
}

TEST(BoardTest, should_equals_given_same_disc_array_set)
{
	Board one;
    Board another(GIVEN_BOARD);
    ASSERT_EQ(one, another);
}

TEST(BoardTest, should_place_a_disc_on_a_position_given_a_init_othello_board)
{
	Board board;
	ASSERT_EQ(board.at(a1), _);

	board.place(a1, B);
	ASSERT_EQ(board.at(a1), B);

	board.place(a1, W);
	ASSERT_EQ(board.at(a1), W);
}

TEST(BoardTest, should_assign_given_another_othello_board)
{
	Board board;
	ASSERT_EQ(board.at(d4), W);

	board.place(d4, B);
	Board another = board;
	ASSERT_EQ(another.at(d4), B);
}

TEST(BoardTest, should_turn_over_a_disc_given_a_board_position_placed_white_or_black)
{
    Board board;
    ASSERT_EQ(board.at(d4), W);

    board.trueOver(d4);
    ASSERT_EQ(board.at(d4), B);
    board.trueOver(d4);
    ASSERT_EQ(board.at(d4), W);
}

TEST(BoardTest, should_return_true_given_a_position_placed_white_or_black)
{
	Board board;
	ASSERT_EQ(board.at(a1), _);
	ASSERT_FALSE(board.isOccupied(a1));

	board.place(a1, B);
	ASSERT_TRUE(board.isOccupied(a1));
	board.place(a1, W);
	ASSERT_TRUE(board.isOccupied(a1));
}

TEST(BoardTest, should_not_turn_over_a_disc_given_a_not_occupied_position)
{
    Board board;
    ASSERT_EQ(board.at(a1), _);

    board.trueOver(a1);
    ASSERT_EQ(board.at(a1), _);
}

TEST(BoardTest, should_print_board)
{
	Board board;
	board.print();
}
