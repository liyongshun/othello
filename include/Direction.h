/*
 * Direction.h
 *
 *  Created on: 2015年8月19日
 *      Author: liyongshun
 */

#ifndef INCLUDE_DIRECTION_H_
#define INCLUDE_DIRECTION_H_

#include "Position.h"

struct Removable
{
	virtual ~Removable() {}
	virtual Position move(Position) const = 0;
};

struct Direction : Removable
{
	virtual Position move(Position) const;

	static Direction& getUp();
	static Direction& getDown();
	static Direction& getLeft();
	static Direction& getRight();

private:
	Direction(int factor);
private:
	int factor;
};

struct JoinMovable : Removable
{
	JoinMovable(const Removable&, const Removable&);
	virtual Position move(Position) const;

private:
	const Removable& left;
	const Removable& right;
};

#define _up Direction::getUp()
#define _down Direction::getDown()
#define _left Direction::getLeft()
#define _right Direction::getRight()
#define _left_up JoinMovable(_left, _up)
#define _left_down JoinMovable(_left, _down)
#define _right_up JoinMovable(_right, _up)
#define _right_down JoinMovable(_right, _down)

#endif /* INCLUDE_DIRECTION_H_ */
