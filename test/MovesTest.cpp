#include "gtest/gtest.h"
#include "Moves.h"

TEST(MovesTest, should_put_positons_into_moves)
{
    Moves moves;
    moves.push(c4);
    moves.push(e6);

    ASSERT_EQ(moves.size(), 2);
    ASSERT_FALSE(moves.isEmpty());
}

TEST(MovesTest, should_moves_is_empty_when_clear)
{
    Moves moves;
    moves.push(c4);
    moves.clear();
    ASSERT_TRUE(moves.isEmpty());    
}

TEST(MovesTest, should_pop_the_front_position_given_a_not_empty_moves)
{
    Moves moves;
    moves.push(c4);
    moves.push(e6);

    ASSERT_EQ(moves.pop(), c4);
    ASSERT_EQ(moves.pop(), e6);
    ASSERT_TRUE(moves.isEmpty());
    ASSERT_EQ(moves.pop(), MAX_POSITION_NUM);
}

TEST(MovesTest, should_return_true_when_moves_contains_the_position)
{
    Moves moves;
    moves.push(a1);
    ASSERT_TRUE(moves.contains(a1));
}