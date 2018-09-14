#include "classObj.h"
#include "vectorObj.h"

pieceMain::pieceMain()
{

}

void pieceMain::setPieceMap(int pColour, int pos)
{
	if (pColour == WHITE)
		pieceMap[pos] = WHITE;
	else
		pieceMap[pos] = BLACK;
}

int pieceMain::getPieceMap(int nextSquare, int pColour)
{
	if (pieceMap[nextSquare] == 9) {	// If square is empty
		return 9;
	}
	else {	// If square is not empty
		if (pieceMap[nextSquare] == WHITE)	// If piece occupying square is white
			return WHITE;	// return white
		else
			return BLACK;	// otherwise, return black
	}
}

void pieceMain::updatePieceMap(int pColour, int sq, int sqOld)
{
	pieceMap[sqOld] = 9;
	pieceMap[sq] = pColour;
}

void pieceMain::setPawnMap(int pColour, int pos)
{
	if (pColour == WHITE)
		wPawnMap.push_back(pos);
	else
		bPawnMap.push_back(pos);
}

void pieceMain::setKingPos(int sq, int pColour)
{
	if (pColour == WHITE) {
		wKingPos = sq;
	}
	else {
		bKingPos = sq;
	}
}

int pieceMain::getKingPos(int pColour)
{
	if (pColour == WHITE) {
		return wKingPos;
	}
	else {
		return bKingPos;
	}
}

void pieceMain::updatePawnMap(int pColour, int sqOld, int sq)
{
	if (pColour == WHITE) {
		for (unsigned int i = 0; i < wPawnMap.size(); ++i) {
			if (wPawnMap[i] == sqOld) {
				wPawnMap[i] = sq; break;
			}
		}
	}
	else {
		for (unsigned int i = 0; i < bPawnMap.size(); ++i) {
			if (bPawnMap[i] == sqOld) {
				bPawnMap[i] = sq; break;
			}
		}
	}
}

void pieceMain::pieceCapture(int pType, int pColour, int j, int pieceNum)
{
	pieceList[j].setPieceCaptured(1);
	switch(pType)
	{
	case 2:	{
		if (pColour == WHITE) {
			wKnightList[pieceNum].capture = true; break;
		}
		else {
			bKnightList[pieceNum].capture = true; break;
		}
			}		// Knight

	case 5:	{
		if (pColour == WHITE) {
			wBishopList[pieceNum].capture = true; break;
		}
		else {
			bBishopList[pieceNum].capture = true; break;
		}
			}		// Bishop

	case 6:	{
		if (pColour == WHITE) {
			wRookList[pieceNum].capture = true; break;
		}
		else {
			bRookList[pieceNum].capture = true; break;
		}
			}		// Rook

	case 7:	{
		if (pColour == WHITE) {
			wQueenList[pieceNum].capture = true; break;
		}
		else {
			bQueenList[pieceNum].capture = true; break;
			}		// Queen
			}
	}
}

void pieceMain::setPiece(int pType, int pColour, int pos, Vector2D &xyPos, sf::RenderWindow *win)
{
	//cX = xyPos.x;
	//cY = xyPos.y;

	// Passes the xy coordinates, the square position and the piece type and colour 
	// to the disp() function in piece.cpp.

	cPiece.disp(xyPos.x, xyPos.y, pos, pType, pColour, win);
	pieceList.push_back(cPiece);	// Store an instance of the cPiece class in the pieceList vector and push back (add a new entry)
}

void pieceMain::pcSearch(int sq, int *pType, int *pColour, int *pieceNumber)
{
	// This function runs when the user clicks a square. The square number is passed as an argument,
	// and the piece type, colour, and xy coordinates are passed by reference.
	// The for loop runs through the pieceList vector until it gets to the end. As it's looping,
	// the getPiecePos() function of the currect pieceList entry is called (each pieceList entry contains an instance of the cPiece object),
	// which returns the square of the current entry. If it matches the square passed to pcSearch() as an argument,
	// it saves the current square number in the sqOld integer, then calls the getPieceType(), getPieceColour() and 
	// getPieceNum() functions in the current cPiece object saved in pieceList.
	// It then saves the piece type and piece colour in the pointers, and stores the piece number
	// in pieceNum.
	// If the returned value of getPiecePos() is not equal to sq in any vector entry, then *pType and *pColour is set to NULL.

	pTResult = 0;
	for (unsigned int i = 0; i < pieceList.size(); ++i)
	{
			pTResult = pieceList[i].getPiecePos();
			if (pTResult == sq){
				if (board.getSideToMove() == pieceList[i].getPieceColour()) {
					sqOld = pTResult;
					(*pType) = pieceList[i].getPieceType();
					(*pColour) = pieceList[i].getPieceColour();
					(*pieceNumber) = pieceList[i].getPieceNum(pType, pColour);
					//(*pieceNumber) = i;
					pieceNum = *pieceNumber;
	
					break;
				}
				else {
					(*pType) = 8; break;
				}
			}
			else
			{
				(*pType) = NULL;
				(*pColour) = NULL;
			}
			pTResult = 0;
	}

}

void pieceMain::enPassant(unsigned int *j, int sq)
{
	if (pieceList[*j].getPieceColour() == BLACK) {
		if (pieceList[*j].getPiecePos() == sq - 16) {
			if (moveVector.size() > 0) {
				int end = moveVector.size() - 1;

				if (moveVector[end].pType == Pawn) {
					if (sq - 16 == moveVector[end].mvTo) {
						pieceCapture(pType, pColour, *j, pieceNum);
						pCaptured = pieceList[*j].getPieceCaptured();
						pieceList[*j].setPiecePos(200);
						updatePieceMap(pColour, sq, sqOld);
						enpassant = true;
						(*j) = pieceList.size();
					}
				}
			}
		}
	}

	if (pieceList[*j].getPieceColour() == WHITE) {
		if (pieceList[*j].getPiecePos() == sq + 16) {
			if (moveVector.size() > 0) {
				int end = moveVector.size() - 1;

				if (moveVector[end].pType == Pawn) {
					if (sq + 16 == moveVector[end].mvTo) {
						pieceCapture(pType, pColour, *j, pieceNum);
						pCaptured = pieceList[*j].getPieceCaptured();
						pieceList[*j].setPiecePos(200);
						updatePieceMap(pColour, sq, sqOld);
						enpassant = true;
						(*j) = pieceList.size();
					}
				}
			}
		}
	} // End en-Passant.
}

void pieceMain::castling(int sq, int pColour, int sprX, int sprY)
{
	unsigned int j;
	if (kqCastle.kCastle == true) {
		if (sq - sqOld == 2) {
			int pTypeCastle;
			int pieceNumCastle;
			pTypeCastle = Rook;
			for (j = 0; j < pieceList.size(); ++j) {
				if (pColour == WHITE) {
					if (pieceList[j].getPiecePos() == H1) {
						pieceList[j].setPiecePos(F1);
						updatePieceMap(pColour, F1, H1);
						pieceNumCastle = pieceList[j].getPieceNum(&pTypeCastle, &pColour);
						pieceList[j].setSpritePos(F1, Rook, pieceNumCastle, pColour, sprX, sprY);
						castleSide = 2;	// King-side
						break;
					}
				}
				else {
					if (pieceList[j].getPiecePos() == H8) {
						pieceList[j].setPiecePos(F8);
						updatePieceMap(pColour, F8, H8);
						pieceNumCastle = pieceList[j].getPieceNum(&pTypeCastle, &pColour);
						pieceList[j].setSpritePos(F8, Rook, pieceNumCastle, pColour, sprX, sprY);
						castleSide = 2;	// King-side
						break;
					}
				}
			}
		}
	}

	if (kqCastle.qCastle == true) {
		if (sqOld - sq == 2) {
			int pTypeCastle;
			int pieceNumCastle;
			pTypeCastle = Rook;
			for (j = 0; j < pieceList.size(); ++j) {
				if (pColour == WHITE) {
					if (pieceList[j].getPiecePos() == A1) {
						pieceList[j].setPiecePos(D1);
						updatePieceMap(pColour, A1, D1);
						pieceNumCastle = pieceList[j].getPieceNum(&pTypeCastle, &pColour);
						pieceList[j].setSpritePos(D1, Rook, pieceNumCastle, pColour, sprX, sprY);
						castleSide = 3;	// Queen-side
						break;
					}
				}
				else {
					if (pieceList[j].getPiecePos() == A8) {
						pieceList[j].setPiecePos(D8);
						updatePieceMap(pColour, A8, D8);
						pieceNumCastle = pieceList[j].getPieceNum(&pTypeCastle, &pColour);
						pieceList[j].setSpritePos(D8, Rook, pieceNumCastle, pColour, sprX, sprY);
						castleSide = 3; // Queen-side
						break;
					}
				}
			}
		}
	}	
}	// End castling

void pieceMain::isCheck(int pType, int pColour, int pieceNum, int j, int sq)
{
	//int i;
	//
	//if (pColour == WHITE) {
	//	for (i = 0; i < bKingPosCheck.size(); ++i) {
	//		if (bKingPosCheck[i].sq == sq) {
	//			cout << "Check\n";
	//		}
	//	}
	//} // End if pColour == WHITE
	//
	//else {
	//	for (i = 0; i < wKingPosCheck.size(); ++i) {
	//		if (wKingPosCheck[i].sq == sq) {
	//			cout << "Check\n";
	//		}
	//	}
	//} // End if pColour == BLACK
}

void pieceMain::updatePiece(int sq, int pType, int pColour, int mvDir, int sprX, int sprY, sf::RenderWindow *win)
{
	// Function to update the piece position.
	unsigned int j;
	for (unsigned int i = 0; i < pieceList.size(); ++i)	// Loops until i is not smaller than pieceList.
	{
		if (sq == sqOld)	// If the selected square is the same as the previous square
		{
			cout << "Square deselected.\n\n";	// Do nothing and break from the loop.
			board.setSqSelected(false);
			break;
		}
		else
		{
			if (pieceList[i].getPieceType() == pType)	// If the current pieceList entry equals piece type
			{
				if (pieceList[i].getPieceNum(&pType, &pColour) == pieceNum)	// if the piece number is equal to the number of the selected piece
				{
					if (pieceList[i].getPieceColour() == pColour)	// if the piece colour equals the piece colour of the selected piece.
					{
						for (j=0; j<pieceList.size(); ++j) {
							// If an enemy piece is already occupying the target square, capture.
							if (pieceList[j].getPiecePos() == sq) {	
								pieceCapture(pType, pColour, j, pieceNum);
								pCaptured = pieceList[j].getPieceCaptured();
								pieceList[j].setPiecePos(200);
								updatePieceMap(pColour, sq, sqOld);
								break;
							}

							// Check for en Passant.
							enPassant(&j, sq);

							// Check for castling
							if (pType == King)
								castling(sq, pColour, sprX, sprY);
									
						}

						pieceList[i].setPiecePos(sq);	// Sets the piece position to the selected square.
						pieceList[i].setFirstMove();



						// If pawn reaches opposite side of the board, promote.
						if (pType == Pawn) {
							if (pieceList[i].getPiecePos() >= 112 && pieceList[i].getPiecePos() <= 119 || pieceList[i].getPiecePos() >= 0 && pieceList[i].getPiecePos() <= 7) {
								pTypeOld = pType;
								pPromoteSel(pType, pColour, sq, i, win);
							}
						}

						// Passes the square, piece type and colour, and xy coordinates of the sprite to the setSpritePos() function.
						// the setSpritePos() function moves the sprite to the new position on the board.
						pieceList[i].setSpritePos(sq, pType, pieceNum, pColour, sprX, sprY);

						updatePieceMap(pColour, sq, sqOld);
						if (pType == Pawn) {
							updatePawnMap(pColour, sqOld, sq);
						}

						if (pType == King) {
							setKingPos(sq, pColour);
						}

						// Check for check/checkmate
						isCheck(pType, pColour, pieceNum, j, sq);
						
						// Update the piece movement log
						board.moveLog(pType, pColour, sqOld, sq, pCaptured, castleSide, enpassant, pPromoted);

						// Switch side to move.
						if (board.getSideToMove() == WHITE) {
							board.setSideToMove(BLACK);
							cout << "Black to move\n";
						}
						else {
							board.setSideToMove(WHITE);
							cout << "White to move\n";
						}

						// Finds new legal moves
						pUpdate.findLegalMoves();

						break;
					}
				}
			}
		}
	}
}

void pieceMain::pPromote(int i, int *j, int *pieceAvailable, int sq, int pType, int pColour, sf::RenderWindow *win)
{
	int sprX = 0;
	int sprY = 0;
	unsigned int k;
	
	pieceList[i].setPawnInactive();
	pieceList[i].setPiecePos(200);
	updatePieceMap(pColour, 200, sqOld);
	updatePawnMap(pColour, sqOld, 200);
	
	for (k = 0; k < pieceList.size(); ++k) {
		if (pieceList[k].getPieceCaptured() == true) {
			if (pieceList[k].getPieceType() == pType) {
				pieceNum = pieceList[k].getPieceNum(&pType, &pColour);
				pieceList[k].setPieceCaptured(false);
				pieceList[k].setPiecePos(sq);
				pieceList[k].setSpritePos(sq, pType, pieceNum, pColour, sprX, sprY);

				(*pieceAvailable) = 1; break;
				}
			}
		}
	if (*pieceAvailable == 0) {
		for (k = 0; k < coords.size(); ++k) {
			if (coords[k].boardSq == sq) {
				setPiece(pType, pColour, sq, coords[k], win);
				break;
			}
		}
	}
}

void pieceMain::pPromoteSel(int pType, int pColour, int sq, int i, sf::RenderWindow *win)
{
	char newPiece;
	int pieceAvailable = 0;
	int sprX = 0;
	int sprY = 0;

	for (int j = 0; j < 1;) {

		cout << "Select piece to promote pawn to (R = Rook, N = Knight, B = Bishop, Q = Queen): ";
		cin >> newPiece;

		switch(newPiece) {
		case 'r': {
					cout << "Promoted to Rook.\n"; j = 1;
					pPromote(i, &j, &pieceAvailable, sq, Rook, pColour, win);
					if (pieceAvailable == 1) {
						if (pColour == WHITE)
							wRookList[pieceNum].capture = false; 
						else
							bRookList[pieceNum].capture = false; 
					}
					pPromoted = Rook;
				  } break;

		case 'n': {
					cout << "Promoted to Knight\n"; j = 1;
					pPromote(i, &j, &pieceAvailable, sq, Knight, pColour, win);
					if (pieceAvailable == 1) {
						if (pColour == WHITE)
							wKnightList[pieceNum].capture = false;
						else
							bKnightList[pieceNum].capture = false;
					}
					pPromoted = Knight;
				  } break;

		case 'b': {
					cout << "Promoted to Bishop\n"; j = 1;
					pPromote(i, &j, &pieceAvailable, sq, Bishop, pColour, win);
					if (pieceAvailable == 1) {
						if (pColour == WHITE)
							wBishopList[pieceNum].capture = false;
						else
							bBishopList[pieceNum].capture = false;
					}
					pPromoted = Bishop;
				  } break;

		case 'q': {
					cout << "Promoted to Queen\n"; j = 1;
					pPromote(i, &j, &pieceAvailable, sq, Queen, pColour, win);
					if (pieceAvailable == 1) {
						if (pColour == WHITE)
							wQueenList[pieceNum].capture = false;
						else
							bQueenList[pieceNum].capture = false;
					}
					pPromoted = Queen;
				  } break;


		case 'R': {
					cout << "Promoted to Rook\n"; j = 1;
					pPromote(i, &j, &pieceAvailable, sq, Rook, pColour, win);
					if (pieceAvailable == 1) {
						if (pColour == WHITE)
							wRookList[pieceNum].capture = false;
						else
							bRookList[pieceNum].capture = false;
					}
					pPromoted = Rook;
				  } break;


		case 'N': {
					cout << "Promoted to Knight\n"; j = 1;
					pPromote(i, &j, &pieceAvailable, sq, Knight, pColour, win);
					if (pieceAvailable == 1) {
						if (pColour == WHITE)
							wKnightList[pieceNum].capture = false;
						else
							bKnightList[pieceNum].capture = false;
					}
					pPromoted = Knight;
				  } break;


		case 'B': {
					cout << "Promoted to Bishop\n"; j = 1;
					pPromote(i, &j, &pieceAvailable, sq, Bishop, pColour, win);
					if (pieceAvailable == 1) {
						if (pColour == WHITE)
							wBishopList[pieceNum].capture = false;
						else
							bBishopList[pieceNum].capture = false;
					}
					pPromoted = Bishop;
				  } break;


		case 'Q': {
					cout << "Promoted to Queen\n"; j = 1;
					pPromote(i, &j, &pieceAvailable, sq, Queen, pColour, win);
					if (pieceAvailable == 1) {
						if (pColour == WHITE)
							wQueenList[pieceNum].capture = false;
						else
							bQueenList[pieceNum].capture = false;
					}
					pPromoted = Queen;
				  } break;


		default: cout << "Invalid character.\n"; break;
		}
	}
}