/*
 * Direction.cpp
 *
 *  Created on: 2015年8月19日
 *      Author: liyongshun
 */

#include "Direction.h"

Direction::Direction(int factor) : factor(factor)
{
}

Position Direction::move(Position p) const
{
	return static_cast<Position>(p + factor);
}

Direction& Direction::getUp()
{
	static Direction up(-8);
	return up;
}

Direction& Direction::getDown()
{
	static Direction down(8);
	return down;
}

Direction& Direction::getLeft()
{
	static Direction left(-1);
	return left;
}

Direction& Direction::getRight()
{
	static Direction right(1);
	return right;
}

JoinMovable::JoinMovable(const Removable& left, const Removable& right) : left(left), right(right)
{
}

Position JoinMovable::move(Position p) const
{
	return right.move(left.move(p));
}


