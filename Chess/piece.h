#ifndef PIECE_H
#define PIECE_H



class pieceClass
{
private:
	int x;
	int y;
	int pcPos;
	int pcType;
	int pcColour;
	
	int wPawnNum;
	int bPawnNum;
	int wRookNum;
	int bRookNum;
	int wKnightNum;
	int bKnightNum;
	int wBishopNum;
	int bBishopNum;
	int wKingNum;
	int bKingNum;
	int wQueenNum;
	int bQueenNum;


	bool firstMove;

	bool pCaptured;
	bool pActive;
	
	sf::Sprite pBack;

public:
	pieceClass();
	virtual void disp(int cX, int cY, int pcPos, int pType, int pColour, sf::RenderWindow *win);

	virtual void setPieceType(int pType);
	virtual void setPiecePos(int sq);

	virtual int getPieceType();
	virtual int getPiecePos();
	virtual int getPieceColour();

	virtual int getPieceNum(int *pType, int *pColour);

	virtual void setFirstMove();
	virtual bool getFirstMove();

	virtual void setSpritePos(int sq, int pType, int piecenum, int pColour, int sprX, int sprY);

	virtual void setPieceCaptured(bool captured);
	virtual bool getPieceCaptured();

	virtual void setPawnInactive();
	virtual bool getPawnActive();
};

#endif