#ifndef PIECEMAIN_H
#define PIECEMAIN_H
#include "Vector2D.h"

class pieceMain
{
private:

	int pType;
	int pos;
	int pTResult;
	int sqOld;
	int sqNew;
	int pColour;
	bool pCaptured;
	int castleSide;	// 3 for Queen-side, 2 for King-side
	bool enpassant;
	int pieceNum;

	int pTypeOld;
	int pPromoted;

	//bool bCheckStatus;
	//bool wCheckStatus;

public:
	pieceMain();
	virtual void setPiece(int pType, int pColour, int pos, Vector2D &xyPos, sf::RenderWindow *win);
	virtual void pcSearch(int sq, int *pType, int *pColour, int *pieceNumber);
	virtual void updatePiece(int sq, int pType, int pColour, int mvDir, int sprX, int sprY, sf::RenderWindow *win);

	//virtual void pCapture();
	virtual void enPassant(unsigned int *j, int sq);
	virtual void castling(int sq, int pColour, int sprX, int sprY);

	virtual void setPieceMap(int pColour, int pos);
	virtual int getPieceMap(int nextSquare, int pColour);
	virtual void updatePieceMap(int pColour, int sq, int sqOld);

	virtual void setPawnMap(int pColour, int pos);
	virtual void updatePawnMap(int pColour, int sqOld, int sq);

	virtual void pPromoteSel(int pType, int pColour, int sq, int i, sf::RenderWindow *win);
	virtual void pPromote(int i, int *j, int *pieceAvailable, int sq, int pType, int pColour, sf::RenderWindow *win);

	virtual void pieceCapture(int pType, int pColour, int j, int pieceNum);

	virtual void isCheck(int pType, int pColour, int pieceNum, int j, int sq);
	//virtual bool getCheckStatus();
	//virtual bool setCheckStatus();

	virtual void setKingPos(int sq, int pColour);
	virtual int getKingPos(int pColour);
};

#endif