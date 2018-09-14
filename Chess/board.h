#ifndef BOARD_H
#define BOARD_H
#include "vector2D.h"
#include <string>

class Board
{

private:
	int sideToMove;
	bool sqSelected;

public:
	Board();
	virtual void FENReader(sf::RenderWindow *win);
	virtual void initPlacement(Piece Piece, Colour Colour, int sq, int i, sf::RenderWindow *win);
	virtual void setCoords();
	virtual void getMCoords(sf::RenderWindow *win, float *mX, float *mY);
	virtual void redraw(sf::RenderWindow *win, float *mXSel, float *mYSel, sf::Shape *SelSquare);

	virtual void highlight(float *mX, float *mY, sf::Shape *DSquare, sf::RenderWindow *win);
	virtual void sqHighlight(sf::Shape *SelSquare, float *mXSel, float *mYSel, sf::RenderWindow *win);
	virtual void findSqPos(float *mX, float *mY);


	virtual void setSideToMove(int STM);
	virtual int getSideToMove();

	virtual void setSqSelected(bool select);
	virtual bool getSqSelected();

	virtual void moveLog(int pType, int pColour, int mvFrom, int mvTo, bool captured, int castleSide, bool enpassant, int pPromoted);

	virtual void prtPieceInfo(bool *print);
};

#endif