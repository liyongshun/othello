/*
 * Direction.cpp
 *
 *  Created on: 2015年8月19日
 *      Author: liyongshun
 */

#include "Direction.h"

namespace
{
	enum { LEFT_FACTOR = -1, RIGHT_FACTOR = 1, UP_FACTOR = -8, DOWN_FACTOR = 8 };
}

Direction::Direction(int factor) : factor(factor)
{
}

namespace
{
	bool onARow(Position l, Position r)
	{
		return l/8 == r/8;
	}
}

Position Direction::move(Position p) const
{
	Position moved = static_cast<Position>(p + factor);

	if(factor == LEFT_FACTOR || factor == RIGHT_FACTOR)
	{
		moved = onARow(p, moved) ? moved : MAX_POSITION_NUM;
	}

	return moved;
}

Direction& Direction::getUp()
{
	static Direction up(UP_FACTOR);
	return up;
}

Direction& Direction::getDown()
{
	static Direction down(DOWN_FACTOR);
	return down;
}

Direction& Direction::getLeft()
{
	static Direction left(LEFT_FACTOR);
	return left;
}

Direction& Direction::getRight()
{
	static Direction right(RIGHT_FACTOR);
	return right;
}

JoinMovable::JoinMovable(const Removable& left, const Removable& right) : left(left), right(right)
{
}

Position JoinMovable::move(Position p) const
{
	Position r = right.move(left.move(p));
	return r;
}


