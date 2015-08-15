#ifndef _OTHELLO_CPP_OTHELLO_H_
#define _OTHELLO_CPP_OTHELLO_H_

#include "Board.h"
#include "Moves.h"

typedef Position (*Action)(Position);

struct Othello
{
	Othello();
	void refreshBoard(const Board&);
    const Board& capture(Position original, Position move);
    const Board& retract(Position original, Position move);
    const Moves& getAvailableMoves(Position);
    const Moves& getAllAvailableMoves(Disc);
    const Board& getBoard() const;

private:
    bool hasNext(Position curr, Position moves) const;
    void doTurn(Position curr, Position moves);
    void find(Position, Action);
private:
    Board board;
};

#endif
