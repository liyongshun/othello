#include "gtest/gtest.h"
#include "Othello.h"

TEST(OthelloTest, should_get_all_moves_given_a_square_position)
{
    Othello othello;
    othello.findMoves(e4);
    const Moves e4Moves = othello.getMoves(e4);
    ASSERT_EQ(e4Moves.size(), 2);
    ASSERT_TRUE(e4Moves.contains(c4));
    ASSERT_TRUE(e4Moves.contains(e6));

    othello.findMoves(d5);
    const Moves& d5Moves = othello.getMoves(d5);
    ASSERT_EQ(d5Moves.size(), 2);
    ASSERT_TRUE(d5Moves.contains(d3));
    ASSERT_TRUE(d5Moves.contains(f5));
}

TEST(OthelloTest, should_turn_given_position)
{
    Othello othello;
    othello.findMoves(e4);
    othello.findMoves(d5);

    othello.turn();
}