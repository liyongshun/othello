#include "gtest/gtest.h"
#include "Othello.h"

namespace
{
	struct OthelloTest : testing::Test
	{
		void ASSERT_OTHELLO(Position original, const Moves& expectMoves)
		{
			Moves availableMoves = othello.getAvailableMoves(original);
			ASSERT_EQ(expectMoves, availableMoves);
		}

		void ASSERT_ALL_MOVES(Disc disc, const Moves& expectMoves)
		{
			Moves availableMoves = othello.thinkMoves(disc);
			ASSERT_EQ(expectMoves, availableMoves);
		}

	protected:
		Othello othello;
	};
}

TEST_F(OthelloTest, should_get_available_moves_given_a_position_of_othello_board)
{
	ASSERT_OTHELLO(e4, Moves{c4, e6});
	ASSERT_OTHELLO(d5, Moves{d3, f5});
}

TEST_F(OthelloTest, should_get_the_board_of_othello)
{
	const Board& board = othello.getBoard();
	ASSERT_EQ(board.at(d4), W);
	ASSERT_EQ(board.at(d5), B);
	ASSERT_EQ(board.at(e4), B);
	ASSERT_EQ(board.at(e5), W);
}

namespace
{
	const Disc GIVEN_BOARD[MAX_POSITION_NUM] =
	{
	    B, _, _, _, _, _, _, _,
		W, _, _, _, _, _, _, _,
		_, _, B, _, B, _, _, _,
		_, _, _, W, W, B, _, _,
		_, _, _, _, W, W, _, _,
		_, _, _, _, _, _, _, _,
		_, _, _, _, _, _, _, _,
		_, W, W, W, B, _, _, _,
	};
}

TEST_F(OthelloTest, should_refresh_the_board_given_another_board)
{
	Othello othello;
	ASSERT_EQ(othello.getBoard().at(a1), _);

	Board board(GIVEN_BOARD);
	othello.refreshBoard(board);
	ASSERT_EQ(othello.getBoard().at(a1), B);
}

TEST_F(OthelloTest, should_get_all_available_moves_of_black_disc)
{
	Board board(GIVEN_BOARD);
	othello.refreshBoard(board);
	ASSERT_ALL_MOVES(B, Moves{a3, f6, c5, e6, c4, d6, a8});
}

TEST_F(OthelloTest, should_print_all_black_disc_available_moves_board)
{
	Othello othello;
	othello.refreshBoard(Board(GIVEN_BOARD));
	Moves allMoves = othello.thinkMoves(B);

	while( ! allMoves.isEmpty())
	{
		Position movePosition = allMoves.pop();
		othello.capture(movePosition).print();
		othello.retract();
	}
}
