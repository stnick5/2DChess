#ifndef PIECEUPDATE_H
#define PIECE_H

class pieceUpdate
{
private:
	float mX;
	float mY;
	int pType;
	int pColour;
	int pieceNumber;

	int squarePos;

	int sprX;
	int sprY;

	bool pSelected;

	int legalMove;
	int sqOccupied;

	int mvDir;

public:
	pieceUpdate();
	virtual void selectSq(float mX, float mY);
	virtual void selectP(int sq);
	virtual void findSqPos(float *mX, float *mY, int *squarePos);

	virtual bool selected();
	virtual void updateSq(float mX, float mY, sf::RenderWindow *win);

	virtual void setSelected(bool selPiece);

	virtual void pawnLMoves(int sq, int pColour, int pieceNumber);
	virtual void rookLMoves(int sq, int pColour, int pieceNumber);
	virtual void knightLMoves(int sq, int pColour, int pieceNumber);
	virtual void bishopLMoves(int sq, int pColour, int pieceNumber);
	virtual void queenLMoves(int sq, int pColour, int pieceNumber);
	virtual void kingLMoves(int sq, int pColour, int pieceNumber);

	virtual bool checkLegal(int sq);

	virtual void findLegalMoves();

	virtual void isOccupied(int *i, int sq, int pColour, int nextSquare, int currentSquare, int pType, int *mvDir, int pieceNumber);
	virtual void enPassant(int *i, int sq, int pColour, int nextSquare, int currentSquare, int LRSquare, int pType, int *mvDir, int pieceNumber);
	virtual bool canCastle(int pColour, int pieceNumber, int *mvDir);
};

#endif