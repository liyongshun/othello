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
			while( ! availableMoves.isEmpty())
			{
				Position move = availableMoves.pop();
				othello.capture(original, move).print();
				othello.retract(original, move);
			}
		}

	protected:
		Othello othello;
	};
}

TEST_F(OthelloTest, should_get_available_moves_given_a_position_of_othello_board)
{
	Moves expectMoves{c4, e6};
	ASSERT_EQ(othello.getAvailableMoves(e4), expectMoves);
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

TEST_F(OthelloTest, should_capture_the_discs_given_the_original_and_move_position)
{
	Othello othello;
	othello.refreshBoard(Board(GIVEN_BOARD));
	ASSERT_EQ(othello.getBoard().at(a2), W);
	ASSERT_EQ(othello.getBoard().at(a3), _);

	const Board& board = othello.capture(a1, a3);
	ASSERT_EQ(board.at(a2), B);
	ASSERT_EQ(board.at(a3), B);
}

TEST_F(OthelloTest, should_retract_the_discs_given_the_original_and_move_position)
{
	Othello othello;
	othello.refreshBoard(Board(GIVEN_BOARD));
	othello.capture(a1, a3);
	othello.retract(a1, a3);
	ASSERT_EQ(othello.getBoard().at(a2), W);
	ASSERT_EQ(othello.getBoard().at(a3), _);
}

TEST_F(OthelloTest, should_get_all_moves_given_a_square_position)
{
    ASSERT_OTHELLO(e4, Moves{c4, e6});
    ASSERT_OTHELLO(d5, Moves{d3, f5});
}

TEST_F(OthelloTest, should_print_all_black_disc_moves_given_a_board)
{
	Board board(GIVEN_BOARD);
	othello.refreshBoard(board);

    ASSERT_OTHELLO(a1, Moves{a3});
    ASSERT_OTHELLO(c3, Moves{f6});
    ASSERT_OTHELLO(e3, Moves{c5, e6});
    ASSERT_OTHELLO(f4, Moves{c4, d6, f6});
    ASSERT_OTHELLO(e8, Moves{a8});
}
