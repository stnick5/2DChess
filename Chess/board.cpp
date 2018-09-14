#include "classObj.h"
#include "vectorObj.h"

Board::Board()
{

}

void Board::FENReader(sf::RenderWindow *win)
{

	int i = 0;

	//char fenInit[] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR|";
	char fenInit[] = "2r3k1/p4p1p/2r3p1/p1bp4/b4BN1/P1R1P3/5PPP/1R2K3|";
	//char fenInit[] = "8/4pp2/3p4/8/8/3P4/1P6/8|";

	for (i = 0; i < 127; ++i) {
		pieceMap[i] = 9;
	}

	// This is the FEN Reader. It scans through the FEN String stored in fenInit[]
	// and passes the appropriate information to the initPlacement() function.
	// For example, 'r', results in Rook and BLACK, both enum values, passing to initPlacement().
	// It also passes row * 16 + col, which calculates the current square, and coordPos, which
	// refers to the coords entry. Each loop adds one to the column integer and coordPos integer,
	// and the i integer. When the next character is a number, it adds that number to the column
	// integer, and when the character is a / it sets col to 0, and reduces the value of row by one.
	// When the character is a |, it stops scanning the string. It places pieces from the top left,
	// going across to the right and down, like a book.

	int col = 0;
	int row = 7;
	i = 0;
	int coordPos = 0;
		do {
			
			switch(fenInit[i])
			{
			case 'r': initPlacement(Rook, BLACK, row * 16 + col, coordPos, win); col++; coordPos++; break;
			case 'n': initPlacement(Knight, BLACK, row * 16 + col, coordPos, win); col++; coordPos++; break;
			case 'b': initPlacement(Bishop, BLACK, row * 16 + col, coordPos, win); col++; coordPos++; break;
			case 'q': initPlacement(Queen, BLACK, row * 16 + col, coordPos, win); col++; coordPos++; break;
			case 'k': initPlacement(King, BLACK, row * 16 + col, coordPos, win); col++; coordPos++; break;
			case 'p': initPlacement(Pawn, BLACK, row * 16 + col, coordPos, win); col++; coordPos++; break;
			case '/': row--; col=0; break;
			case '1': col+=1; coordPos+=1; break;
			case '2': col+=2; coordPos+=2; break;
			case '3': col+=3; coordPos+=3; break;
			case '4': col+=4; coordPos+=4; break;
			case '5': col+=5; coordPos+=5; break;
			case '6': col+=6; coordPos+=6; break;
			case '7': col+=7; coordPos+=7; break;
			case '8': col+=8; coordPos+=8; break;
			case 'P': initPlacement(Pawn, WHITE, row * 16 + col, coordPos, win); col++; coordPos++; break;
			case 'R': initPlacement(Rook, WHITE, row * 16 + col, coordPos, win); col++; coordPos++; break;
			case 'N': initPlacement(Knight, WHITE, row * 16 + col, coordPos, win); col++; coordPos++; break;
			case 'B': initPlacement(Bishop, WHITE, row * 16 + col, coordPos, win); col++; coordPos++; break;
			case 'Q': initPlacement(Queen, WHITE, row * 16 + col, coordPos, win); col++; coordPos++; break;
			case 'K': initPlacement(King, WHITE, row * 16 + col, coordPos, win); col++; coordPos++; break;
			}
			i++;
		} while (fenInit[i] != '|');
}

void Board::initPlacement(Piece Piece, Colour Colour, int sq, int coordPos, sf::RenderWindow *win)
{
	// Passes the Piece, Colour, square and coordinate entry to the setPiece() function in pieceMain.cpp.
	pMain.setPiece(Piece, Colour, sq, coords[coordPos], win);
}

void Board::setCoords()
{
	
	int i = 0;
	int k = 0;

	int x = 13;
	int y = 0;
	int j;

	int Square = 112;
	//Vector2D xycoords;	// Creates xycoords object

/* Loops through and stores coordinates in xycoords
   The i integer sets the number of coordinates to store (64 for 64 squares on the board)
   The second for loop uses the j integer to count along the x axis and store the coordinates for each
   column square in the current row.
   When j reaches the 8th column, it breaks out of the loop and goes up one row, and moves back to the
   left-hand square.
*/

	for (i = 0; i<64; i++)
	{
		for (j = 0; j < 8; j++)	
		{
			xycoords.x = x;
			xycoords.y = y;
			xycoords.boardSq = Square;

			coords.push_back(xycoords);

			Square++;
			x=x+100;
			i++;
		}

		Square = Square - 24;
		y = y + 100;
		x = 13;
		j = 0;
	}

	string row;
	string result;

	int l = 0;
	for (k = 0; k < 8; k++) {
		switch(k) {
			case 0: row = row1; break;
			case 1: row = row2; break;
			case 2: row = row3; break;
			case 3: row = row4; break;
			case 4: row = row5; break;
			case 5: row = row6; break;
			case 6: row = row7; break;
			case 7: row = row8; break;
				}
		for (l = 0; l < 8; l++) {
			switch(l) {
			case 0: {
				result = fileA; result.append(row);
				boardSquare[k*16+l] = result; break;
					}
			case 1: {
				result = fileB; result.append(row); 
				boardSquare[k*16+l] = result; break;
					}
			case 2: {
				result = fileC; result.append(row); 
				boardSquare[k*16+l] = result; break;
					}
			case 3: {
				result = fileD; result.append(row); 
				boardSquare[k*16+l] = result; break;
					}
			case 4: {
				result = fileE; result.append(row); 
				boardSquare[k*16+l] = result; break;
					}
			case 5: {
				result = fileF; result.append(row); 
				boardSquare[k*16+l] = result; break;
					}
			case 6: {
				result = fileG; result.append(row); 
				boardSquare[k*16+l] = result; break;
					}
			case 7: {
				result = fileH; result.append(row); 
				boardSquare[k*16+l] = result; break;
					}
			}
		}
	}

	int fileSq = 0;
	for (i = 0; i < 8; i++) {
		file1.push_back(fileSq);
		fileSq+=16;
	}

	fileSq = 1;
	for (i = 0; i < 8; i++) {
		file2.push_back(fileSq);
		fileSq+=16;
	}

	fileSq = 2;
	for (i = 0; i < 8; i++) {
		file3.push_back(fileSq);
		fileSq+=16;
	}

	fileSq = 3;
	for (i = 0; i < 8; i++) {
		file4.push_back(fileSq);
		fileSq+=16;
	}

	fileSq = 4;
	for (i = 0; i < 8; i++) {
		file5.push_back(fileSq);
		fileSq+=16;
	}

	fileSq = 5;
	for (i = 0; i < 8; i++) {
		file6.push_back(fileSq);
		fileSq+=16;
	}

	fileSq = 6;
	for (i = 0; i < 8; i++) {
		file7.push_back(fileSq);
		fileSq+=16;
	}

	fileSq = 7;
	for (i = 0; i < 8; i++) {
		file8.push_back(fileSq);
		fileSq+=16;
	}
}

void Board::getMCoords(sf::RenderWindow *win, float *mX, float *mY)
{
	// Gets the current xy coordinates of the mouse and assigns them to the mX and mY pointers.
	const sf::Input& Input = win->GetInput();
	
	(*mX) = Input.GetMouseX();
	(*mY) = Input.GetMouseY();

}

void Board::setSideToMove(int STM)
{
	sideToMove = STM;
}

int Board::getSideToMove()
{
	return sideToMove;
}

void Board::moveLog(int pType, int pColour, int mvFrom, int mvTo, bool captured, int castleSide, bool enpassant, int pPromoted)
{
	mvList.pType = pType;
	mvList.pColour = pColour;
	mvList.mvFrom = mvFrom;
	mvList.mvTo = mvTo;
	mvList.capture = captured;

	if (castleSide == 2)
		mvList.kCastle = true;
	if (castleSide == 3)
		mvList.qCastle = true;

	if (enpassant == true)
		mvList.enpassant = true;

	mvList.pProm = pPromoted;

	moveVector.push_back(mvList);
}

void Board::highlight(float *mX, float *mY, sf::Shape *DSquare, sf::RenderWindow *win)
{
	// Tests which range the passed mouse coordinates falls into, and moves the highlight square to the appropriate position.
	
	findSqPos(mX, mY);
	DSquare->Move(*mX, *mY);
	DSquare->SetColor(sf::Color(51,51,255,100));
	win->Draw(*DSquare);
}

void Board::sqHighlight(sf::Shape *SelSquare, float *mXSel, float *mYSel, sf::RenderWindow *win)
{

	findSqPos(mXSel, mYSel);
	SelSquare->Move(*mXSel, *mYSel);
	SelSquare->SetColor(sf::Color(51,51,255,100));
	win->Draw(*SelSquare);
	setSqSelected(true);
}

void Board::findSqPos(float *mX, float *mY)
{
	if (*mX>0 && *mX<=100) {
		*mX = 0;
		if (*mY>=0 && *mY<=100) {
			*mY = 0;
		}
		if (*mY>=100 && *mY<=200) {
			*mY = 100;
		}
		if (*mY>=200 && *mY<=300) {
			*mY = 200;
		}
		if (*mY>=300 && *mY<=400) {
			*mY = 300;
		}
		if (*mY>=400 && *mY<=500) {
			*mY = 400;
		}
		if (*mY>=500 && *mY<=600) {
			*mY = 500;
		}
		if (*mY>=600 && *mY<=700) {
			*mY = 600;
		}
		if (*mY>=700 && *mY<=800) {
			*mY = 700;
		}
	}
	if (*mX>=100 && *mX<=200) {
		*mX = 100;
		if (*mY>=0 && *mY<=100) {
			*mY = 0;
		}
		if (*mY>=100 && *mY<=200) {
			*mY = 100;
		}
		if (*mY>=200 && *mY<=300) {
			*mY = 200;
		}
		if (*mY>=300 && *mY<=400) {
			*mY = 300;
		}
		if (*mY>=400 && *mY<=500) {
			*mY = 400;
		}
		if (*mY>=500 && *mY<=600) {
			*mY = 500;
		}
		if (*mY>=600 && *mY<=700) {
			*mY = 600;
		}
		if (*mY>=700 && *mY<=800) {
			*mY = 700;
		}
	}
	if (*mX>=200 && *mX<=300) {
		*mX = 200;
		if (*mY>=0 && *mY<=100) {
			*mY = 0;
		}
		if (*mY>=100 && *mY<=200) {
			*mY = 100;
		}
		if (*mY>=200 && *mY<=300) {
			*mY = 200;
		}
		if (*mY>=300 && *mY<=400) {
			*mY = 300;
		}
		if (*mY>=400 && *mY<=500) {
			*mY = 400;
		}
		if (*mY>=500 && *mY<=600) {
			*mY = 500;
		}
		if (*mY>=600 && *mY<=700) {
			*mY = 600;
		}
		if (*mY>=700 && *mY<=800) {
			*mY = 700;
		}
	}
	if (*mX>=300 && *mX<=400) {
		*mX = 300;
		if (*mY>=0 && *mY<=100) {
			*mY = 0;
		}
		if (*mY>=100 && *mY<=200) {
			*mY = 100;
		}
		if (*mY>=200 && *mY<=300) {
			*mY = 200;
		}
		if (*mY>=300 && *mY<=400) {
			*mY = 300;
		}
		if (*mY>=400 && *mY<=500) {
			*mY = 400;
		}
		if (*mY>=500 && *mY<=600) {
			*mY = 500;
		}
		if (*mY>=600 && *mY<=700) {
			*mY = 600;
		}
		if (*mY>=700 && *mY<=800) {
			*mY = 700;
		}
	}
	if (*mX>=400 && *mX<=500) {
		*mX = 400;
		if (*mY>=0 && *mY<=100) {
			*mY = 0;
		}
		if (*mY>=100 && *mY<=200) {
			*mY = 100;
		}
		if (*mY>=200 && *mY<=300) {
			*mY = 200;
		}
		if (*mY>=300 && *mY<=400) {
			*mY = 300;
		}
		if (*mY>=400 && *mY<=500) {
			*mY = 400;
		}
		if (*mY>=500 && *mY<=600) {
			*mY = 500;
		}
		if (*mY>=600 && *mY<=700) {
			*mY = 600;
		}
		if (*mY>=700 && *mY<=800) {
			*mY = 700;
		}
	}
	if (*mX>=500 && *mX<=600) {
		*mX = 500;
		if (*mY>=0 && *mY<=100) {
			*mY = 0;
		}
		if (*mY>=100 && *mY<=200) {
			*mY = 100;
		}
		if (*mY>=200 && *mY<=300) {
			*mY = 200;
		}
		if (*mY>=300 && *mY<=400) {
			*mY = 300;
		}
		if (*mY>=400 && *mY<=500) {
			*mY = 400;
		}
		if (*mY>=500 && *mY<=600) {
			*mY = 500;
		}
		if (*mY>=600 && *mY<=700) {
			*mY = 600;
		}
		if (*mY>=700 && *mY<=800) {
			*mY = 700;
		}
	}
	if (*mX>=600 && *mX<=700) {
		*mX = 600;
		if (*mY>=0 && *mY<=100) {
			*mY = 0;
		}
		if (*mY>=100 && *mY<=200) {
			*mY = 100;
		}
		if (*mY>=200 && *mY<=300) {
			*mY = 200;
		}
		if (*mY>=300 && *mY<=400) {
			*mY = 300;
		}
		if (*mY>=400 && *mY<=500) {
			*mY = 400;
		}
		if (*mY>=500 && *mY<=600) {
			*mY = 500;
		}
		if (*mY>=600 && *mY<=700) {
			*mY = 600;
		}
		if (*mY>=700 && *mY<=800) {
			*mY = 700;
		}
	}
	if (*mX>=700 && *mX<=800) {
		*mX = 700;
		if (*mY>=0 && *mY<=100) {
			*mY = 0;
		}
		if (*mY>=100 && *mY<=200) {
			*mY = 100;
		}
		if (*mY>=200 && *mY<=300) {
			*mY = 200;
		}
		if (*mY>=300 && *mY<=400) {
			*mY = 300;
		}
		if (*mY>=400 && *mY<=500) {
			*mY = 400;
		}
		if (*mY>=500 && *mY<=600) {
			*mY = 500;
		}
		if (*mY>=600 && *mY<=700) {
			*mY = 600;
		}
		if (*mY>=700 && *mY<=800) {
			*mY = 700;
		}
	}
}

void Board::setSqSelected(bool select)
{
	sqSelected = select;
}

bool Board::getSqSelected()
{
	return sqSelected;
}

void Board::redraw(sf::RenderWindow *win, float *mXSel, float *mYSel, sf::Shape *SelSquare)
{
	// Loops through all of the piece vectors, and redraws them onto the screen.

	unsigned int j;
	int pType;
	int pColour;
	int pNum;

	if (getSqSelected() == true) {
		SelSquare->SetColor(sf::Color(51,51,255,100));
		SelSquare->Move(*mXSel, *mYSel);
		win->Draw(*SelSquare);
	}

	for (j=0; j<pieceList.size(); ++j) {
		pType = pieceList[j].getPieceType();
		pColour = pieceList[j].getPieceColour();
		pNum = pieceList[j].getPieceNum(&pType, &pColour);

		switch(pType) {

		case 1: 
			//if (pieceList[j].getPieceCaptured() == 1 && pieceList[j].getPawnActive() == true)
			if (pieceList[j].getPieceCaptured() == 1) {
				break;
			}
			if (pieceList[j].getPawnActive() == true) {
				if (pColour == WHITE) {
					win->Draw(cWPawn[pNum]);
				}
				else {
					win->Draw(cBPawn[pNum]);
				}
			}
			break;
		case 2:
			if (pieceList[j].getPieceCaptured() == 1)
				break;
				if (pColour == WHITE)
					win->Draw(cWKnight[pNum]);
				else
					win->Draw(cBKnight[pNum]);
			break;
		case 3:
			if (pieceList[j].getPieceCaptured() == 1)
				break;
				if (pColour == WHITE)
					win->Draw(cWKing[pNum]);
				else
					win->Draw(cBKing[pNum]);
			break;
		case 5:
			if (pieceList[j].getPieceCaptured() == 1)
				break;
				if (pColour == WHITE)
					win->Draw(cWBishop[pNum]);
				else
					win->Draw(cBBishop[pNum]);
			break;
		case 6:
			if (pieceList[j].getPieceCaptured() == 1)
				break;
				if (pColour == WHITE)
					win->Draw(cWRook[pNum]);
				else
					win->Draw(cBRook[pNum]);
			break;
		case 7:
			if (pieceList[j].getPieceCaptured() == 1)
				break;
				if (pColour == WHITE)
					win->Draw(cWQueen[pNum]);
				else
					win->Draw(cBQueen[pNum]);
			break;
		}
	}
}

void Board::prtPieceInfo(bool *print)
{
	cout << "Print this once\n\n";
	(*print) = false;
}