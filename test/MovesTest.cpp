#include "gtest/gtest.h"
#include "Moves.h"

TEST(MovesTest, should_init_moves_with_a_disc_list)
{
	Moves one = {a1, b2};
	Moves another{a1, b2};
}

TEST(MovesTest, should_return_ture_when_moves_is_empty)
{
	Moves moves;
	ASSERT_TRUE(moves.isEmpty());
}

TEST(MovesTest, should_equals_given_a_same_position_list_with_any_sequence)
{
	Moves one{a1, b2, c3};
	Moves another{b2, c3, a1};

	ASSERT_EQ(one, another);
}

TEST(MovesTest, should_not_equals_given_a_position_list_with_different_number_or_different_position)
{
	Moves one{a1, b2};
	Moves another{a1};
	Moves third{a1, b3};

	ASSERT_FALSE(one == another);
	ASSERT_FALSE(one == third);
}

TEST(MovesTest, should_push_some_position_to_moves)
{
    Moves moves = {c4, e6};
    ASSERT_FALSE(moves.isEmpty());
    Moves sameMoves{c4, e6};
    ASSERT_EQ(moves, sameMoves);
}

TEST(MovesTest, should_pop_the_front_position_given_a_not_empty_moves)
{
    Moves moves = { c4, e6 };
    ASSERT_EQ(moves.pop(), c4);
    ASSERT_EQ(moves.pop(), e6);
    ASSERT_TRUE(moves.isEmpty());
}

TEST(MovesTest, should_moves_is_empty_when_clear)
{
    Moves moves = {a1, b2, c3, d4};
    moves.clear();
    ASSERT_TRUE(moves.isEmpty());    
}

TEST(MovesTest, should_not_push_same_disc_to_moves)
{
	Moves moves{a1, a1};
	moves.push(a1);
	Moves another{a1};
	ASSERT_EQ(moves, another);
}

TEST(MovesTest, should_get_two_moves_union_given_two_moves)
{
	Moves one{a1, b2, c3, d4};
	Moves another{c3, d4, e5, f6};
	Moves unionMoves = one + another;
	Moves expect {a1, b2, c3, d4, e5, f6};
	ASSERT_EQ(unionMoves, expect);
}
