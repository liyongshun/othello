#include "gtest/gtest.h"
#include "Board.h"

namespace
{
/*
        a  b  c  d  e  f  g  h
      1 V, V, V, V, V, V, V, V,
      2 V, V, V, V, V, V, V, V
      3 V, V, V, V, V, V, V, V
      4 V, V, V, W, B, V, V, V
      5 V, V, V, B, W, V, V, V
      6 V, V, V, V, V, V, V, V
      7 V, V, V, V, V, V, V, V
      8 V, V, V, V, V, V, V, V
*/
    const int ROWS = 8;
    const int COLUMNS = 8;
    const Grid GIVEN_BOARD[ROWS * COLUMNS] = 
    {
        V, V, V, V, V, V, V, V,
        V, V, V, V, V, V, V, V,
        V, V, V, V, V, V, V, V,
        V, V, V, B, W, V, V, V,
        V, V, V, W, B, V, V, V,
        V, V, V, V, V, V, V, V,
        V, V, V, V, V, V, V, V,
        V, V, V, V, V, V, V, V,
    }; 
}

TEST(BoardTest, should_init_board)
{
    Board board;
    ASSERT_EQ(board.at(a1), V);
    ASSERT_EQ(board.at(h8), V);

    ASSERT_EQ(board.at(e4), B);
    ASSERT_EQ(board.at(d5), B);
    ASSERT_EQ(board.at(d4), W);
    ASSERT_EQ(board.at(e5), W);
}

TEST(BoardTest, should_print_board)
{
    Board b;
    b.print();
}

TEST(BoardTest, should_turn_over_grid)
{
    Board b;
    b.turn(e4);
    ASSERT_EQ(b.at(e4), W);
}


