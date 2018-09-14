#include "classObj.h"
#include "vectorObj.h"

pieceUpdate::pieceUpdate()
{

}

bool pieceUpdate::selected()
{
	if (pSelected == true)
		return true;
	else
		return false;
}

void pieceUpdate::setSelected(bool selPiece)
{
	pSelected = selPiece;	// sets pSelected to current value of selPiece.
}

void pieceUpdate::selectP(int sq)
{
	// Passes the square containing the square enum value, and passes piece type and colour, and the sprite xy coordinates
	// by reference to the pcSearch() function in pieceMain.cpp.

	// The switch statement is mostly so I can see that it recognises the piece that's been selected, or empty square.
	// It sets pSelected to true, and calls the pieceLMoves function, which calculates and stores the legal moves 
	// available for the currently selected piece.

	pMain.pcSearch(sq, &pType, &pColour, &pieceNumber);

	switch(pType)
	{
	case 1: {
				if (pColour == WHITE) {
					cout << "White Pawn\n"; pSelected=true;
				}
				else {
					cout << "Black Pawn\n"; pSelected=true; 
				}
				break;
			}
	case 2: {
				if (pColour == WHITE) {
					cout << "White Knight\n"; pSelected=true;
				}
				else {
					cout << "Black Knight\n"; pSelected=true;
				}
				break;
			}
	case 3: {
				if (pColour == WHITE) {
					cout << "White King\n"; pSelected=true;
				}
				else {
					cout << "Black King\n"; pSelected=true;
				}
				break;
			}
	case 5: {
				if (pColour == WHITE) {
					cout << "White Bishop\n"; pSelected=true;
				}
				else {
					cout << "Black Bishop\n"; pSelected=true;
				}
				break;
			}
	case 6: {
				if (pColour == WHITE) {
					cout << "White Rook\n"; pSelected=true; 
				}
				else {
					cout << "Black Rook\n"; pSelected=true;
				}
				break;
			}
	case 7: {
				if (pColour == WHITE) {
					cout << "White Queen\n"; pSelected=true;
				}
				else {
					cout << "Black Queen\n"; pSelected=true;
				}
				break;
			}
	case 8: {
				if (board.getSideToMove() == WHITE)
					cout << "White to move\n";
				else
					cout << "Black to move\n";
				break;
			}
	default: {
		cout << "Empty Square\n"; pSelected=false; break;
			 }
	}

}

void pieceUpdate::isOccupied(int *i, int sq, int pColour, int nextSquare, int currentSquare, int pType, int *mvDir, int pieceNumber)
{
	sqOccupied = pMain.getPieceMap(nextSquare, pColour);

	if (sqOccupied == 9) {							// If square is unoccupied
		if (pType == Pawn) {	// If selected piece is a pawn
			if (*mvDir == northeast || *mvDir == northwest || *mvDir == southeast || *mvDir == southwest) {
				(*i) = 0;
			}
			else {
			//legalMoves.push_back(nextSquare);
				LMovesBuffer.pieceNumber = pieceNumber;
				LMovesBuffer.sq = nextSquare;
				legalMoves.push_back(LMovesBuffer);
			}
		}	// End if pType == Pawn

		else {
			LMovesBuffer.pieceNumber = pieceNumber;
			LMovesBuffer.sq = nextSquare;
			legalMoves.push_back(LMovesBuffer);
		}
	}	// end if square is unoccupied

	else {											// If square is occupied
		if (pColour == WHITE) {						// If selected piece is white
			if (sqOccupied == WHITE) {
				(*i) = 1;							// Don't allow piece to move to that square
			}
			else {
				if (pType == Pawn) {
					if (*mvDir == northeast || *mvDir == northwest) {
						//legalMoves.push_back(nextSquare);
						LMovesBuffer.pieceNumber = pieceNumber;
						LMovesBuffer.sq = nextSquare;
						legalMoves.push_back(LMovesBuffer);
						(*i) = 1;							// Break from do while loop
					}
					else {
						(*i) = 1;
					}
				}	// End if pType == Pawn

				else {
					//legalMoves.push_back(nextSquare);	// Store square as a legal move
					LMovesBuffer.pieceNumber = pieceNumber;
					LMovesBuffer.sq = nextSquare;
					legalMoves.push_back(LMovesBuffer);
					(*i) = 1;							// Break from do while loop
				}
			}
		}	// end if selected piece is white


		else {										// If selected piece is black
			if (sqOccupied == WHITE) {
				if (pType == Pawn) {
					if (*mvDir == southeast || *mvDir == southwest) {
						//legalMoves.push_back(nextSquare);
						LMovesBuffer.pieceNumber = pieceNumber;
						LMovesBuffer.sq = nextSquare;
						legalMoves.push_back(LMovesBuffer);
						(*i) = 1;
					}
					else {
					(*i) = 1;
					}
				}
				else {
					//legalMoves.push_back(nextSquare);
					LMovesBuffer.pieceNumber = pieceNumber;
					LMovesBuffer.sq = nextSquare;
					legalMoves.push_back(LMovesBuffer);
					(*i) = 1;
					}
				}
			else {
				(*i) = 1;
			}
		}
	}	// end if occupied
}

void pieceUpdate::rookLMoves(int sq, int pColour, int pieceNumber)
{
	int i;
	int currentSquare;
	int nextSquare;
	pType = Rook;

	currentSquare = sq;
	LMovesBuffer.pieceNumber = pieceNumber;
	LMovesBuffer.sq = sq;
	legalMoves.push_back(LMovesBuffer);

	// Check all the squares upwards
	do {
		nextSquare = currentSquare + north;
		i = nextSquare & 0x88;
		if (i == 0) {
			isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			currentSquare+=north;
		}
	} while (i == 0);

	currentSquare = sq;

	// Check all the squares downwards.
	do {
		nextSquare = currentSquare + south;
		i = nextSquare & 0x88;
		if (i == 0) {
			isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			currentSquare+=south;
		}
	} while ( i == 0);

	currentSquare = sq;

	// Check the squares to the left.
	do {
		nextSquare = currentSquare + west;
		i = nextSquare & 0x88;
		if (i == 0) {
			isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			currentSquare+=west;;
		}
	} while (i == 0);

	currentSquare = sq;

	// Check the squares to the right.
	do {
		nextSquare = currentSquare + east;
		i = nextSquare & 0x88;
		if (i == 0) {
			isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			currentSquare+=east;
		}
	} while (i == 0);
}

void pieceUpdate::bishopLMoves(int sq, int pColour, int pieceNumber)
{
	int i;
	int currentSquare;
	int nextSquare;
	pType = Bishop;

	currentSquare = sq;
	LMovesBuffer.pieceNumber = pieceNumber;
	LMovesBuffer.sq = sq;
	legalMoves.push_back(LMovesBuffer);

	// Check the northeast diagonal
	do {
		nextSquare = currentSquare + northeast;
		i = nextSquare & 0x88;
		if (i == 0) {
			isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			currentSquare+=northeast;
		}
	} while (i == 0);

	currentSquare = sq;

	// Check the northwest diagonal
	do {
		nextSquare = currentSquare + northwest;
		i = nextSquare & 0x88;
		if (i == 0) {
			isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			currentSquare+=northwest;
		}
	} while (i == 0);

	currentSquare = sq;

	// Check the southeast diagonal
	do {
		nextSquare = currentSquare + southeast;
		i = nextSquare & 0x88;
		if (i == 0) {
			isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			currentSquare+=southeast;
		}
	} while (i == 0);

	currentSquare = sq;

	// Check the southwest diagonal
	do {
		nextSquare = currentSquare + southwest;
		i = nextSquare & 0x88;
		if (i == 0) {
			isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			currentSquare+=southwest;
		}
	} while (i == 0);
}

void pieceUpdate::pawnLMoves(int sq, int pColour, int pieceNumber)
{
	int i;
	int j;
	int currentSquare;
	int nextSquare;
	int LRSquare;
	pType = Pawn;

	currentSquare = sq;
	LMovesBuffer.pieceNumber = pieceNumber;
	LMovesBuffer.sq = sq;
	legalMoves.push_back(LMovesBuffer);

	j = 0;

	if (pColour == WHITE) {	// If the selected pawn is white
		if (pieceList[pieceNumber].getFirstMove() == true) {
			do {
				mvDir = north;
				nextSquare = currentSquare + north;
				i = nextSquare & 0x88;
				if (i == 0) {
					isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
					currentSquare+=north;
				}
				j++;
			} while (j <= 1 && i == 0);

			mvDir = northeast;
			nextSquare = currentSquare + northeast;
			i = nextSquare & 0x88;
			if (i == 0) {
				isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			}

			currentSquare = sq;

			mvDir = northwest;
			nextSquare = currentSquare + northwest;
			i = nextSquare & 0x88;
			if (i == 0) {
				isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			}
		}
		
		else {	// If getFirstMove() is not true
			mvDir = north;
			nextSquare = currentSquare + north;
			i = nextSquare & 0x88;
			if (i == 0) {
				isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			}

			currentSquare = sq;

			mvDir = northeast;
			nextSquare = currentSquare + northeast;
			i = nextSquare & 0x88;
			if (i == 0) {
				isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			}

			currentSquare = sq;

			mvDir = northwest;
			nextSquare = currentSquare + northwest;
			i = nextSquare & 0x88;
			if (i == 0) {
				isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			}
		}	// end getFirstMove() == true

		// Check for en Passant for white.
		if (currentSquare >= A5 && currentSquare <= H5) {
			int end = moveVector.size() - 1;
			if (moveVector[end].pType == Pawn) {	// Check if the previous move made by black was a pawn
				if (moveVector[end].mvFrom - moveVector[end].mvTo == 32) {	// If black piece moved two spaces onto its fifth row

					 if (moveVector[end].mvTo == currentSquare + 1) {	// If the black piece is on the east square next to the white piece
						nextSquare = currentSquare + northeast;
						LRSquare = currentSquare + 1;
						i = nextSquare & 0x88;
						if (i == 0) {
							enPassant(&i, sq, pColour, nextSquare, currentSquare, LRSquare, pType, &mvDir, pieceNumber);
						}
					}

					 if (moveVector[end].mvTo == currentSquare - 1) {	// If the black piece is on the west square next to the white piece
						 nextSquare = currentSquare + northwest;
						 LRSquare = currentSquare - 1;
						 i = nextSquare & 0x88;
						 if (i == 0) {
							 enPassant(&i, sq, pColour, nextSquare, currentSquare, LRSquare, pType, &mvDir, pieceNumber);
						 }
					 }
				}
			}
		}
	}	// end white



	else {	// If selected pawn is black
		if (pieceList[pieceNumber].getFirstMove() == true) {
			do {
				mvDir = south;
				nextSquare = currentSquare + south;
				i = nextSquare & 0x88;
				if (i == 0) {
					isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
					currentSquare+=south;
				}
				j++;
			} while (j <= 1 && i == 0);

			mvDir = southeast;
			nextSquare = currentSquare + southeast;
			i = nextSquare & 0x88;
			if (i == 0) {
				isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			}

			currentSquare = sq;

			mvDir = southwest;
			nextSquare = currentSquare + southwest;
			i = nextSquare & 0x88;
			if (i == 0) {
				isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			}
		}
		else {
			mvDir = south;
			nextSquare = currentSquare + south;
			i = nextSquare & 0x88;
			if (i == 0) {
				isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			}

			currentSquare = sq;

			mvDir = southeast;
			nextSquare = currentSquare + southeast;
			i = nextSquare & 0x88;
			if (i == 0) {
				isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			}

			currentSquare = sq;

			mvDir = southwest;
			nextSquare = currentSquare + southwest;
			i = nextSquare & 0x88;
			if (i == 0) {
				isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			}
		}

		// Check for en Passant for black.
		if (currentSquare >= A4 && currentSquare <= H4) {
			int end = moveVector.size() - 1;
			if (moveVector[end].pType == Pawn) {	// Check if the previous move made by black was a pawn
				if (moveVector[end].mvTo - moveVector[end].mvFrom == 32) {	// If black piece moved two spaces onto its fifth row

					 if (moveVector[end].mvTo == currentSquare + 1) {	// If the black piece is on the east square next to the white piece
						nextSquare = currentSquare + southwest;
						LRSquare = currentSquare + 1;
						i = nextSquare & 0x88;
						if (i == 0) {
							enPassant(&i, sq, pColour, nextSquare, currentSquare, LRSquare, pType, &mvDir, pieceNumber);
						}
					}

					 if (moveVector[end].mvTo == currentSquare - 1) {	// If the black piece is on the west square next to the white piece
						 nextSquare = currentSquare + southeast;
						 LRSquare = currentSquare - 1;
						 i = nextSquare & 0x88;
						 if (i == 0) {
							 enPassant(&i, sq, pColour, nextSquare, currentSquare, LRSquare, pType, &mvDir, pieceNumber);
						 }
					 }
				}
			}
		}
	}	// end black
}

void pieceUpdate::enPassant(int *i, int sq, int pColour, int nextSquare, int currentSquare, int LRSquare, int pType, int *mvDir, int pieceNumber)
{
	sqOccupied = pMain.getPieceMap(LRSquare, pColour);

	if (sqOccupied == WHITE) {
		for (unsigned int i = 0; i < wPawnMap.size(); ++i) {
			if (wPawnMap[i] == LRSquare) {
				//legalMoves.push_back(nextSquare);
				LMovesBuffer.pieceNumber = pieceNumber;
				LMovesBuffer.sq = nextSquare;
				legalMoves.push_back(LMovesBuffer);
			}
		}
	}
	else {
		for (unsigned int i = 0; i < bPawnMap.size(); ++i) {
			if (bPawnMap[i] == LRSquare) {
				//legalMoves.push_back(nextSquare);
				LMovesBuffer.pieceNumber = pieceNumber;
				LMovesBuffer.sq = nextSquare;
				legalMoves.push_back(LMovesBuffer);
			}
		}
	}
}

void pieceUpdate::kingLMoves(int sq, int pColour, int pieceNumber)
{
	int i;
	int j;
	int currentSquare;
	int nextSquare;
	pType = King;

	currentSquare = sq;
	LMovesBuffer.pieceNumber = pieceNumber;
	LMovesBuffer.sq = sq;
	legalMoves.push_back(LMovesBuffer);

	// Move north once
	nextSquare = currentSquare + north;
	i = nextSquare & 0x88;
	if (i == 0) {
		isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
	}

	currentSquare = sq;

	// Move northeast diagonal
	nextSquare = currentSquare + northeast;
	i = nextSquare & 0x88;
	if (i == 0) {
		isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
	}

	currentSquare = sq;
	
	// Check if king can castle east
	nextSquare = currentSquare + east;
	mvDir = east;
	i = nextSquare & 0x88;
	j = 0;

	if (canCastle(pColour, pieceNumber, &mvDir) == true) {
		do {
			if (i == 0) {
				isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
				currentSquare+=east;
				j++;
			}
			nextSquare = currentSquare + east;
			i = nextSquare & 0x88;
		} while (j <= 1 && i == 0);
	}

	// Move east once
	if (i == 0) {
		isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
	}

	currentSquare = sq;

	// Move southeast once
	nextSquare = currentSquare + southeast;
	i = nextSquare & 0x88;
	if (i == 0) {
		isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
	}

	currentSquare = sq;

	// Move south once
	nextSquare = currentSquare + south;
	i = nextSquare & 0x88;
	if (i == 0) {
		isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
	}

	currentSquare = sq;

	// Move southwest once
	nextSquare = currentSquare + southwest;
	i = nextSquare & 0x88;
	if (i == 0) {
		isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
	}

	currentSquare = sq;

	// Check if king can castle west
	nextSquare = currentSquare + west;
	mvDir = west;
	i = nextSquare & 0x88;
	j = 0;

	if (canCastle(pColour, pieceNumber, &mvDir) == true) {
		do {
			if (i == 0) {
				isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
				currentSquare+=west;
				j++;
			}
			nextSquare = currentSquare + west;
			i = nextSquare & 0x88;
		} while (j <= 1 && i == 0);
	}

	// Move west once
	nextSquare = currentSquare + west;
	i = nextSquare & 0x88;
	if (i == 0) {
		isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
	}

	currentSquare = sq;

	// Move northwest once
	nextSquare = currentSquare + northwest;
	i = nextSquare & 0x88;
	if (i == 0) {
		isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
	}
}

bool pieceUpdate::canCastle(int pColour, int pieceNumber, int *mvDir)
{
	unsigned int i;
	if (pColour == WHITE) {	// If white king is selected
		if (pieceList[pieceNumber].getFirstMove() == true) {
			if (*mvDir == east) {
				for (i = 0; i < pieceList.size(); ++i) {
					if (pieceList[i].getPiecePos() == H1) {
						if (pieceList[i].getFirstMove() == true) {
							kqCastle.kCastle = true;
							return true;
						}
						else {
							kqCastle.kCastle = false;
							return false;
						}
					}
				}
			}
			if (*mvDir == west) {
				for (i = 0; i < pieceList.size(); ++i) {
					if (pieceList[i].getPiecePos() == A1) {
						if (pieceList[i].getFirstMove() == true) {
							kqCastle.qCastle = true;
							return true;
						}
						else {
							kqCastle.qCastle = false;
							return false;
						}
					}
				}
			}
		}
	}

	else {	// If black king is selected
		if (pieceList[pieceNumber].getFirstMove() == true) {
			if (*mvDir == east) {
				for (i = 0; i < pieceList.size(); ++i) {
					if (pieceList[i].getPiecePos() == H8) {
						if (pieceList[i].getFirstMove() == true) {
							kqCastle.kCastle = true;
							return true;
						}
						else {
							kqCastle.kCastle = false;
							return false;
						}
					}
				}
			}
			if (*mvDir == west) {
				for (i = 0; i < pieceList.size(); ++i) {
					if (pieceList[i].getPiecePos() == A8) {
						if (pieceList[i].getFirstMove() == true) {
							kqCastle.qCastle = true;
							return true;
						}
						else {
							kqCastle.qCastle = false;
							return false;
						}
					}
				}
			}
		}
	}
}

void pieceUpdate::queenLMoves(int sq, int pColour, int pieceNumber)
{
	int i;
	int currentSquare;
	int nextSquare;
	pType = Queen;

	currentSquare = sq;
	LMovesBuffer.pieceNumber = pieceNumber;
	LMovesBuffer.sq = sq;
	legalMoves.push_back(LMovesBuffer);

	// Move north
	do {
		nextSquare = currentSquare + north;
		i = nextSquare & 0x88;
		if (i == 0) {
			isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			currentSquare+=north;
		}
	} while (i == 0);

	currentSquare = sq;

	// Move northeast diagonal
	do {
		nextSquare = currentSquare + northeast;
		i = nextSquare & 0x88;
		if (i == 0) {
			isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			currentSquare+=northeast;
		}
	} while (i == 0);

	currentSquare = sq;
	
	// Move east
	do {
		nextSquare = currentSquare + east;
		i = nextSquare & 0x88;
		if (i == 0) {
			isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			currentSquare+=east;
		}
	} while (i == 0);

	currentSquare = sq;

	// Move southeast
	do {
		nextSquare = currentSquare + southeast;
		i = nextSquare & 0x88;
		if (i == 0) {
			isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			currentSquare+=southeast;
		}
	} while (i == 0);

	currentSquare = sq;

	// Move south
	do {
		nextSquare = currentSquare + south;
		i = nextSquare & 0x88;
		if (i == 0) {
			isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			currentSquare+=south;
		}
	} while (i == 0);

	currentSquare = sq;

	// Move southwest
	do {
		nextSquare = currentSquare + southwest;
		i = nextSquare & 0x88;
		if (i == 0) {
			isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			currentSquare+=southwest;
		}
	} while (i == 0);

	currentSquare = sq;

	// Move west
	do {
		nextSquare = currentSquare + west;
		i = nextSquare & 0x88;
		if (i == 0) {
			isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			currentSquare+=west;
		}
	} while (i == 0);

	currentSquare = sq;

	// Move northwest
	do {
		nextSquare = currentSquare + northwest;
		i = nextSquare & 0x88;
		if (i == 0) {
			isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
			currentSquare+=northwest;
		}
	} while (i == 0);
}

void pieceUpdate::knightLMoves(int sq, int pColour, int pieceNumber)
{
	int i;
	int nextSquare;
	int currentSquare;
	pType = Knight;

	currentSquare = sq;
	LMovesBuffer.pieceNumber = pieceNumber;
	LMovesBuffer.sq = sq;
	legalMoves.push_back(LMovesBuffer);

	nextSquare = currentSquare + kNorthRight;
	i = nextSquare & 0x88;
	if (i == 0) {
		isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
	}

	currentSquare = sq;

	nextSquare = currentSquare + kEastUp;
	i = nextSquare & 0x88;
	if (i == 0) {
		isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
	}

	currentSquare = sq;

	nextSquare = currentSquare + kEastDown;
	i = nextSquare & 0x88;
	if (i == 0) {
		isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
	}

	currentSquare = sq;

	nextSquare = currentSquare + kSouthRight;
	i = nextSquare & 0x88;
	if (i == 0) {
		isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
	}

	currentSquare = sq;

	nextSquare = currentSquare + kSouthLeft;
	i = nextSquare & 0x88;
	if (i == 0) {
		isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
	}

	currentSquare = sq;

	nextSquare = currentSquare + kWestDown;
	i = nextSquare & 0x88;
	if (i == 0) {
		isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
	}

	currentSquare = sq;

	nextSquare = currentSquare + kWestUp;
	i = nextSquare & 0x88;
	if (i == 0) {
		isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
	}

	currentSquare = sq;

	nextSquare = currentSquare + kNorthLeft;
	i = nextSquare & 0x88;
	if (i == 0) {
		isOccupied(&i, sq, pColour, nextSquare, currentSquare, pType, &mvDir, pieceNumber);
	}
}

bool pieceUpdate::checkLegal(int sq)
{
	unsigned int i;

	switch(pType) 
	{
	case Pawn: {
		if (pColour == WHITE) {
			for (i = 0; i < wPawnLegal[pieceNumber].size(); ++i) {
				if (wPawnLegal[pieceNumber][i].sq == sq) {
					return true;
				}
			}
		}
		else {
			for (i = 0; i < bPawnLegal[pieceNumber].size(); ++i) {
				if (bPawnLegal[pieceNumber][i].sq == sq) {
					return true;
					break;
				}
			}
		}
		return false;
			   }

	case Rook: {
		if (pColour == WHITE) {
			for (i = 0; i < wRookLegal[pieceNumber].size(); ++i) {
				if (wRookLegal[pieceNumber][i].sq == sq) {
					return true;
					break;
				}
			}
		}
		else {
			for (i = 0; i < bRookLegal[pieceNumber].size(); ++i) {
				if (bRookLegal[pieceNumber][i].sq == sq) {
					return true;
					break;
				}
			}
		}
		return false;
			   }

	case Knight: {
		if (pColour == WHITE) {
			for (i = 0; i < wKnightLegal[pieceNumber].size(); ++i) {
				if (wKnightLegal[pieceNumber][i].sq == sq) {
					return true;
					break;
				}
			}
		}
		else {
			for (i = 0; i < bKnightLegal[pieceNumber].size(); ++i) {
				if (bKnightLegal[pieceNumber][i].sq == sq) {
					return true;
					break;
				}
			}
		}
		return false;
				 }

	case Bishop: {
		if (pColour == WHITE) {
			for (i = 0; i < wBishopLegal[pieceNumber].size(); ++i) {
				if (wBishopLegal[pieceNumber][i].sq == sq) {
					return true;
					break;
				}
			}
		}
		else {
			for (i = 0; i < bBishopLegal[pieceNumber].size(); ++i) {
				if (bBishopLegal[pieceNumber][i].sq == sq) {
					return true;
					break;
				}
			}
		}
		return false;
				 }

	case Queen: {
		if (pColour == WHITE) {
			for (i = 0; i < wQueenLegal[pieceNumber].size(); ++i) {
				if (wQueenLegal[pieceNumber][i].sq == sq) {
					return true;
					break;
				}
			}
		}
		else {
			for (i = 0; i < bQueenLegal[pieceNumber].size(); ++i) {
				if (bQueenLegal[pieceNumber][i].sq == sq) {
					return true;
					break;
				}
			}
		}
		return false;
				}

	case King: {
		if (pColour == WHITE) {
			for (i = 0; i < wKingLegal[pieceNumber].size(); ++i) {
				if (wKingLegal[pieceNumber][i].sq == sq) {
					return true;
					break;
				}
			}
		}
		else {
			for (i = 0; i < bKingLegal[pieceNumber].size(); ++i) {
				if (bKingLegal[pieceNumber][i].sq == sq) {
					return true;
					break;
				}
			}
		}
		return false;
			   }
	default: {
		return false;
			 }
	}
}

void pieceUpdate::findLegalMoves()
{
	unsigned int i;
	int lPType;
	int lPColour;
	int lPNum;
	int lPPos;

	wPawnLegal.clear();
	bPawnLegal.clear();
	wRookLegal.clear();
	bRookLegal.clear();
	wKnightLegal.clear();
	bKnightLegal.clear();
	wBishopLegal.clear();
	bBishopLegal.clear();
	wQueenLegal.clear();
	bQueenLegal.clear();
	wKingLegal.clear();
	bKingLegal.clear();

	for (i = 0; i < pieceList.size(); ++i) {
		lPType = pieceList[i].getPieceType();
		lPColour = pieceList[i].getPieceColour();
		lPPos = pieceList[i].getPiecePos();
		lPNum = pieceList[i].getPieceNum(&lPType, &lPColour);


		switch(lPType) {
		case Pawn: {
					pawnLMoves(lPPos, lPColour, lPNum);
					if (lPColour == WHITE)
						wPawnLegal.push_back(legalMoves);
					else
						bPawnLegal.push_back(legalMoves);
				} break;

		case Rook: {
					rookLMoves(lPPos, lPColour, lPNum);
					if (lPColour == WHITE)
						wRookLegal.push_back(legalMoves);
					else
						bRookLegal.push_back(legalMoves);
				   } break;

		case Knight: {
						knightLMoves(lPPos, lPColour, lPNum);
						if (lPColour == WHITE)
							wKnightLegal.push_back(legalMoves);
						else
							bKnightLegal.push_back(legalMoves);
					 } break;

		case Bishop: {
						bishopLMoves(lPPos, lPColour, lPNum);
						if (lPColour == WHITE)
							wBishopLegal.push_back(legalMoves);
						else
							bBishopLegal.push_back(legalMoves);
					 } break;

		case Queen: {
						queenLMoves(lPPos, lPColour, lPNum);
						if (lPColour == WHITE)
							wQueenLegal.push_back(legalMoves);
						else
							bQueenLegal.push_back(legalMoves);
					} break;

		case King: {
					kingLMoves(lPPos, lPColour, lPNum);
					if (lPColour == WHITE)
						wKingLegal.push_back(legalMoves);
					else
						bKingLegal.push_back(legalMoves);
				   } break;
		}	// End switch statement
		legalMoves.clear();
		LMovesBuffer.pieceNumber = 0;
		LMovesBuffer.sq = 0;
	}	// End for loop
}

void pieceUpdate::updateSq(float mX, float mY, sf::RenderWindow *win)
{
	// Takes the current mouse xy coordinates as arguments. Finds which square these coordinates
	// fall into, then passes the appropriate square enum value (A8, B5 etc) to the updatePiece() function in pieceMain.cpp,
	// along with the currently selected piece type and colour, and the xy coordinates of the sprite.

	findSqPos(&mX, &mY, &squarePos);
	cout << "Square " << boardSquare[squarePos] << "\n";
	if (checkLegal(squarePos) == true) {
		pMain.updatePiece(squarePos, pType, pColour, mvDir, sprX, sprY, win);
	}
	else {
		cout << "Illegal Move\n";
	}
	legalMoves.clear();
}


void pieceUpdate::selectSq(float mX, float mY)
{

	// Takes the current mouse xy coordinates as arguments. Finds which square these coordinates
	// fall into, then passes the appropriate square enum value (A8, B5 etc) to the selectP() function.

	findSqPos(&mX, &mY, &squarePos);
	cout << "Square " << boardSquare[squarePos] << "\n";
	selectP(squarePos);
	cout << "\n";
}

void pieceUpdate::findSqPos(float *mX, float *mY, int *squarePos)
{
	if (*mX>0 && *mX<=100) {
		if (*mY>=0 && *mY<=100) {
			*squarePos = A8;
		}
		if (*mY>=100 && *mY<=200) {
			*squarePos = A7;
		}
		if (*mY>=200 && *mY<=300) {
			*squarePos = A6;
		}
		if (*mY>=300 && *mY<=400) {
			*squarePos = A5;
		}
		if (*mY>=400 && *mY<=500) {
			*squarePos = A4;
		}
		if (*mY>=500 && *mY<=600) {
			*squarePos = A3;
		}
		if (*mY>=600 && *mY<=700) {
			*squarePos = A2;
		}
		if (*mY>=700 && *mY<=800) {
			*squarePos = A1;
		}
	}
	if (*mX>=100 && *mX<=200) {
		if (*mY>=0 && *mY<=100) {
			*squarePos = B8;
		}
		if (*mY>=100 && *mY<=200) {
			*squarePos = B7;
		}
		if (*mY>=200 && *mY<=300) {
			*squarePos = B6;
		}
		if (*mY>=300 && *mY<=400) {
			*squarePos = B5;
		}
		if (*mY>=400 && *mY<=500) {
			*squarePos = B4;
		}
		if (*mY>=500 && *mY<=600) {
			*squarePos = B3;
		}
		if (*mY>=600 && *mY<=700) {
			*squarePos = B2;
		}
		if (*mY>=700 && *mY<=800) {
			*squarePos = B1;
		}
	}
	if (*mX>=200 && *mX<=300) {
		if (*mY>=0 && *mY<=100) {
			*squarePos = C8;
		}
		if (*mY>=100 && *mY<=200) {
			*squarePos = C7;
		}
		if (*mY>=200 && *mY<=300) {
			*squarePos = C6;
		}
		if (*mY>=300 && *mY<=400) {
			*squarePos = C5;
		}
		if (*mY>=400 && *mY<=500) {
			*squarePos = C4;
		}
		if (*mY>=500 && *mY<=600) {
			*squarePos = C3;
		}
		if (*mY>=600 && *mY<=700) {
			*squarePos = C2;
		}
		if (*mY>=700 && *mY<=800) {
			*squarePos = C1;
		}
	}
	if (*mX>=300 && *mX<=400) {
		if (*mY>=0 && *mY<=100) {
			*squarePos = D8;
		}
		if (*mY>=100 && *mY<=200) {
			*squarePos = D7;
		}
		if (*mY>=200 && *mY<=300) {
			*squarePos = D6;
		}
		if (*mY>=300 && *mY<=400) {
			*squarePos = D5;
		}
		if (*mY>=400 && *mY<=500) {
			*squarePos = D4;
		}
		if (*mY>=500 && *mY<=600) {
			*squarePos = D3;
		}
		if (*mY>=600 && *mY<=700) {
			*squarePos = D2;
		}
		if (*mY>=700 && *mY<=800) {
			*squarePos = D1;
		}
	}
	if (*mX>=400 && *mX<=500) {
		if (*mY>=0 && *mY<=100) {
			*squarePos = E8;
		}
		if (*mY>=100 && *mY<=200) {
			*squarePos = E7;
		}
		if (*mY>=200 && *mY<=300) {
			*squarePos = E6;
		}
		if (*mY>=300 && *mY<=400) {
			*squarePos = E5;
		}
		if (*mY>=400 && *mY<=500) {
			*squarePos = E4;
		}
		if (*mY>=500 && *mY<=600) {
			*squarePos = E3;
		}
		if (*mY>=600 && *mY<=700) {
			*squarePos = E2;
		}
		if (*mY>=700 && *mY<=800) {
			*squarePos = E1;
		}
	}
	if (*mX>=500 && *mX<=600) {
		if (*mY>=0 && *mY<=100) {
			*squarePos = F8;
		}
		if (*mY>=100 && *mY<=200) {
			*squarePos = F7;
		}
		if (*mY>=200 && *mY<=300) {
			*squarePos = F6;
		}
		if (*mY>=300 && *mY<=400) {
			*squarePos = F5;
		}
		if (*mY>=400 && *mY<=500) {
			*squarePos = F4;
		}
		if (*mY>=500 && *mY<=600) {
			*squarePos = F3;
		}
		if (*mY>=600 && *mY<=700) {
			*squarePos = F2;
		}
		if (*mY>=700 && *mY<=800) {
			*squarePos = F1;
		}
	}
	if (*mX>=600 && *mX<=700) {
		if (*mY>=0 && *mY<=100) {
			*squarePos = G8;
		}
		if (*mY>=100 && *mY<=200) {
			*squarePos = G7;
		}
		if (*mY>=200 && *mY<=300) {
			*squarePos = G6;
		}
		if (*mY>=300 && *mY<=400) {
			*squarePos = G5;
		}
		if (*mY>=400 && *mY<=500) {
			*squarePos = G4;
		}
		if (*mY>=500 && *mY<=600) {
			*squarePos = G3;
		}
		if (*mY>=600 && *mY<=700) {
			*squarePos = G2;
		}
		if (*mY>=700 && *mY<=800) {
			*squarePos = G1;
		}
	}
	if (*mX>=700 && *mX<=800) {
		if (*mY>=0 && *mY<=100) {
			*squarePos = H8;
		}
		if (*mY>=100 && *mY<=200) {
			*squarePos = H7;
		}
		if (*mY>=200 && *mY<=300) {
			*squarePos = H6;
		}
		if (*mY>=300 && *mY<=400) {
			*squarePos = H5;
		}
		if (*mY>=400 && *mY<=500) {
			*squarePos = H4;
		}
		if (*mY>=500 && *mY<=600) {
			*squarePos = H3;
		}
		if (*mY>=600 && *mY<=700) {
			*squarePos = H2;
		}
		if (*mY>=700 && *mY<=800) {
			*squarePos = H1;
		}
	}
}