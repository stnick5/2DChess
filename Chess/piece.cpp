#include "classObj.h"
#include "vectorObj.h"
#include "objdef.h"

pieceClass::pieceClass()
{

}

void pieceClass::setPieceCaptured(bool captured)
{
	pCaptured = captured;
}

bool pieceClass::getPieceCaptured()
{
	return pCaptured;
}

int pieceClass::getPieceType()
{
	return pcType;
}

int pieceClass::getPiecePos()
{
	return pcPos;
}

int pieceClass::getPieceColour()
{
	return pcColour;
}

void pieceClass::setPiecePos(int sq)
{
	pcPos = sq;
}

void pieceClass::setPieceType(int pType)
{
	pcType = pType;
}

int pieceClass::getPieceNum(int *pType, int *pColour)
{
	// Function to return the piece number.
	switch(*pType)
	{
	case 1: {
		if (*pColour == WHITE)
			return wPawnNum;
		else
			return bPawnNum;
			} break;
	case 2: {
		if (*pColour == WHITE)
			return wKnightNum;
		else
			return bKnightNum;
			} break;
	case 3: {
		if (*pColour == WHITE)
			return wKingNum;
		else
			return bKingNum;
			} break;
	case 5: {
		if (*pColour == WHITE)
			return wBishopNum;
		else
			return bBishopNum;
			} break;
	case 6: {
		if (*pColour == WHITE)
			return wRookNum;
		else
			return bRookNum;
			} break;
	case 7: {
		if (*pColour == WHITE)
			return wQueenNum;
		else
			return bQueenNum;
			} break;
	default: {
		return 0;
				  }
	}
}

void pieceClass::setPawnInactive()
{
	pActive = false;
}

bool pieceClass::getPawnActive()
{
	return pActive;
}

void pieceClass::setSpritePos(int sq, int pType, int pieceNum, int pColour, int sprX, int sprY)
{
	// Function to set the sprite position of the currently selected piece.
	unsigned int i;
	for (i = 0; i < coords.size(); ++i)	// Loops through the coords vector until the selected square equals the square number in coords[].
	{
		if (sq == coords[i].boardSq)
			break;
	}

	sprX = coords[i].x;
	sprY = coords[i].y;

	// Sets the xy coordinates to the piece vector entry corresponding to the pieceNum integer.
	switch(pType)
	{
	case Pawn: {
				if (pColour == WHITE)
				{
					cWPawn[pieceNum].SetX(sprX);
					cWPawn[pieceNum].SetY(sprY); break;
				}
				else
				{
					cBPawn[pieceNum].SetX(sprX);
					cBPawn[pieceNum].SetY(sprY); break;
				}
			}
	case Knight: {
				if (pColour == WHITE)
				{
					cWKnight[pieceNum].SetX(sprX);
					cWKnight[pieceNum].SetY(sprY); break;
				}
				else
				{
					cBKnight[pieceNum].SetX(sprX);
					cBKnight[pieceNum].SetY(sprY); break;
				}
			}
	case King: {
				if (pColour == WHITE)
				{
					cWKing[pieceNum].SetX(sprX);
					cWKing[pieceNum].SetY(sprY); break;
				}
				else
				{
					cBKing[pieceNum].SetX(sprX);
					cBKing[pieceNum].SetY(sprY); break;
				}
			}
	case Bishop: {
				if (pColour == WHITE)
				{
					cWBishop[pieceNum].SetX(sprX);
					cWBishop[pieceNum].SetY(sprY); break;
				}
				else
				{
					cBBishop[pieceNum].SetX(sprX);
					cBBishop[pieceNum].SetY(sprY); break;
				}
			}
	case Rook: {
				if (pColour == WHITE)
				{
					cWRook[pieceNum].SetX(sprX);
					cWRook[pieceNum].SetY(sprY); break;
				}
				else
				{
					cBRook[pieceNum].SetX(sprX);
					cBRook[pieceNum].SetY(sprY); break;
				}
			}
	case Queen: {
				if (pColour == WHITE)
				{
					cWQueen[pieceNum].SetX(sprX);
					cWQueen[pieceNum].SetY(sprY); break;
				}
				else
				{
					cBQueen[pieceNum].SetX(sprX);
					cBQueen[pieceNum].SetY(sprY); break;
				}
			}
	}
}

void pieceClass::setFirstMove()
{
	firstMove = false;
}

bool pieceClass::getFirstMove()
{
	return firstMove;
}

void pieceClass::disp(int cX, int cY, int pos, int pType, int pColour, sf::RenderWindow *win)
{
	// Store the xy coordinates, the square, piece type and colour in variables.
	x = cX;
	y = cY;
	pcPos = pos;
	pcType = pType;
	pcColour = pColour;

	// Creates the i and white/black piece integers.
	int i = 0;
	wPawnNum = 0;
	bPawnNum = 0;
	wRookNum = 0;
	bRookNum = 0;
	wKnightNum = 0;
	bKnightNum = 0;
	wBishopNum = 0;
	bBishopNum = 0;
	wKingNum = 0;
	bKingNum = 0;
	wQueenNum = 0;
	bQueenNum = 0;

	firstMove = true;

	pActive = true;

	// Switch statement takes the current piece type as an argument. Finds the current piece, then checks the piece colour.
	// Then it sets i to the size of the vector of the current piece, then sets the corresponding piece integer
	// to i. Then it creates a new entry in the piece vector. Sets the xy coordinates for the current piece, assigns it the appropriate sprite, then draws it.
	// This method means each piece on the board can be easily distinguished from another (for example, two white rooks).

	switch(pType)
	{
	case Pawn: {
				if (pColour == WHITE) {
					i = cWPawn.size(); wPawnNum = i; cWPawn.push_back(pBack); 
					cWPawn[i].SetImage(wpawn); cWPawn[i].SetX(x); cWPawn[i].SetY(y); win->Draw(cWPawn[i]);

					wPawnStr.sq = pos;
					wPawnStr.pNum = i;
					wPawnStr.capture = false;
					wPawnList.push_back(wPawnStr);
				}
				else {
					i = cBPawn.size(); bPawnNum = i; cBPawn.push_back(pBack); 
					cBPawn[i].SetImage(bpawn); cBPawn[i].SetX(x); cBPawn[i].SetY(y); win->Draw(cBPawn[i]);
					bPawnStr.sq = pos;
					bPawnStr.pNum = i;
					bPawnStr.capture = false;
					bPawnList.push_back(bPawnStr);
				}
				pMain.setPieceMap(pColour, pos); 
				pMain.setPawnMap(pColour, pos); break;
			}

	case Knight: {
				if (pColour == WHITE) {
					i = cWKnight.size(); wKnightNum = i; cWKnight.push_back(pBack); 
					cWKnight[i].SetImage(wknight); cWKnight[i].SetX(x); cWKnight[i].SetY(y); cWKnight[i].SetScale(0.75f, 0.76f); win->Draw(cWKnight[i]);
					
					wKnightStr.sq = pos;
					wKnightStr.pNum = i;
					wKnightStr.capture = false;
					wKnightList.push_back(wKnightStr);
				}
				else {
					i = cBKnight.size(); bKnightNum = i; cBKnight.push_back(pBack); 
					cBKnight[i].SetImage(bknight); cBKnight[i].SetX(x); cBKnight[i].SetY(y); cBKnight[i].SetScale(0.75f, 0.76f); win->Draw(cBKnight[i]);
					bKnightStr.sq = pos;
					bKnightStr.pNum = i;
					bKnightStr.capture = false;
					bKnightList.push_back(bKnightStr);
				}

				pMain.setPieceMap(pColour, pos); break;
			}

	case King: {
				if (pColour == WHITE) {
					i = cWKing.size(); wKingNum = i; cWKing.push_back(pBack); 
					cWKing[i].SetImage(wking); cWKing[i].SetX(x); cWKing[i].SetY(y); cWKing[i].SetScale(0.7f, 0.52f); win->Draw(cWKing[i]);
				}
				else {
					i = cBKing.size(); bKingNum = i; cBKing.push_back(pBack); 
					cBKing[i].SetImage(bking); cBKing[i].SetX(x); cBKing[i].SetY(y); cBKing[i].SetScale(0.7f, 0.52f); win->Draw(cBKing[i]);
				}
				pMain.setKingPos(pos, pColour);
				pMain.setPieceMap(pColour, pos); break;
			}

	case Bishop: {
				if (pColour == WHITE) {
					i = cWBishop.size(); wBishopNum = i; cWBishop.push_back(pBack); 
					cWBishop[i].SetImage(wbishop); cWBishop[i].SetX(x); cWBishop[i].SetY(y); cWBishop[i].SetScale(0.80f, 0.67f); win->Draw(cWBishop[i]);

					wBishopStr.sq = pos;
					wBishopStr.pNum = i;
					wBishopStr.capture = false;
					wBishopList.push_back(wBishopStr);
				}
				else {
					i = cBBishop.size(); bBishopNum = i; cBBishop.push_back(pBack); 
					cBBishop[i].SetImage(bbishop); cBBishop[i].SetX(x); cBBishop[i].SetY(y); cBBishop[i].SetScale(0.80f, 0.67f); win->Draw(cBBishop[i]);

					bBishopStr.sq = pos;
					bBishopStr.pNum = i;
					bBishopStr.capture = false;
					bBishopList.push_back(bBishopStr);
				}
				pMain.setPieceMap(pColour, pos); break;
			}

	case Rook: {
				if (pColour == WHITE) {
					i = cWRook.size(); wRookNum = i; cWRook.push_back(pBack); 
					cWRook[i].SetImage(wrook); cWRook[i].SetX(x); cWRook[i].SetY(y); cWRook[i].SetScale(0.95f, 0.85f); win->Draw(cWRook[i]);

					wRookStr.sq = pos;
					wRookStr.pNum = i;
					wRookStr.capture = false;
					wRookList.push_back(wRookStr);
				}
				else {
					i = cBRook.size(); bRookNum = i; cBRook.push_back(pBack); 
					cBRook[i].SetImage(brook); cBRook[i].SetX(x); cBRook[i].SetY(y); cBRook[i].SetScale(0.95f, 0.85f); win->Draw(cBRook[i]);

					bRookStr.sq = pos;
					bRookStr.pNum = i;
					bRookStr.capture = false;
					bRookList.push_back(bRookStr);
				}
				pMain.setPieceMap(pColour, pos); break;
			}

	case Queen: {
				if (pColour == WHITE) {
					i = cWQueen.size(); wQueenNum = i; cWQueen.push_back(pBack); 
					cWQueen[i].SetImage(wqueen); cWQueen[i].SetX(x); cWQueen[i].SetY(y); cWQueen[i].SetScale(0.75f, 0.58f); win->Draw(cWQueen[i]);

					wQueenStr.sq = pos;
					wQueenStr.pNum = i;
					wQueenStr.capture = false;
					wQueenList.push_back(wQueenStr);
				}
				else {
					i = cBQueen.size(); bQueenNum = i; cBQueen.push_back(pBack); 
					cBQueen[i].SetImage(bqueen); cBQueen[i].SetX(x); cBQueen[i].SetY(y); cBQueen[i].SetScale(0.75f, 0.58f); win->Draw(cBQueen[i]);

					bQueenStr.sq = pos;
					bQueenStr.pNum = i;
					bQueenStr.capture = false;
					bQueenList.push_back(bQueenStr);
				}
				pMain.setPieceMap(pColour, pos); break;
			} 
	}
}