#ifndef _OTHELLO_CPP_OTHELLO_H_
#define _OTHELLO_CPP_OTHELLO_H_

#include "Board.h"
#include "Moves.h"

struct Removable;

struct Othello
{
	Othello();
	void refreshBoard(const Board&);
    const Board& capture(Position move);
    const Board& retract();
    const Moves& getAvailableMoves(Position);
    const Moves& thinkMoves(Disc);
    const Board& getBoard() const;

private:
    bool hasNext(Position curr, Position moves) const;
    void find(Position, const Removable&);
    void turn(Position original, Position moves);
    void doTurn(Position from, Position to, const Removable&);
private:
    Board board;
    Board lastBoard;
};

#endif
