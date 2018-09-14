#ifndef VECTOROBJ_H
#define VECTOROBJ_H

#include <vector>
#include "classObj.h"
#include "Vector2D.h"

extern std::vector<pieceClass> pieceList;

extern string boardSquare[129];

extern string fileA;
extern string fileB;
extern string fileC;
extern string fileD;
extern string fileE;
extern string fileF;
extern string fileG;
extern string fileH;

extern string row1;
extern string row2;
extern string row3;
extern string row4;
extern string row5;
extern string row6;
extern string row7;
extern string row8;

extern std::vector<sf::Sprite> cWPawn;
extern std::vector<sf::Sprite> cBPawn;
extern std::vector<sf::Sprite> cWRook;
extern std::vector<sf::Sprite> cBRook;
extern std::vector<sf::Sprite> cWKnight;
extern std::vector<sf::Sprite> cBKnight;
extern std::vector<sf::Sprite> cWBishop;
extern std::vector<sf::Sprite> cBBishop;
extern std::vector<sf::Sprite> cWQueen;
extern std::vector<sf::Sprite> cBQueen;
extern std::vector<sf::Sprite> cWKing;
extern std::vector<sf::Sprite> cBKing;

extern Vector2D xycoords;

extern std::vector<Vector2D> coords;

extern std::vector<int> file1;
extern std::vector<int> file2;
extern std::vector<int> file3;
extern std::vector<int> file4;
extern std::vector<int> file5;
extern std::vector<int> file6;
extern std::vector<int> file7;
extern std::vector<int> file8;

extern std::vector<LMoves> legalMoves;

extern std::vector< vector<LMoves> > wPawnLegal;
extern std::vector< vector<LMoves> > wRookLegal;
extern std::vector< vector<LMoves> > wKnightLegal;
extern std::vector< vector<LMoves> > wBishopLegal;
extern std::vector< vector<LMoves> > wQueenLegal;
extern std::vector< vector<LMoves> > wKingLegal;
						   
extern std::vector< vector<LMoves> > bPawnLegal;
extern std::vector< vector<LMoves> > bRookLegal;
extern std::vector< vector<LMoves> > bKnightLegal;
extern std::vector< vector<LMoves> > bBishopLegal;
extern std::vector< vector<LMoves> > bQueenLegal;
extern std::vector< vector<LMoves> > bKingLegal;

extern LMoves LMovesBuffer;

extern int pieceMap[127];
extern int wKingPos;
extern int bKingPos;
extern std::vector<int> wPawnMap;
extern std::vector<int> bPawnMap;

extern wPawn wPawnStr;
extern bPawn bPawnStr;
extern wRook wRookStr;
extern bRook bRookStr;
extern wBishop wBishopStr;
extern bBishop bBishopStr;
extern wKnight wKnightStr;
extern bKnight bKnightStr;
extern wQueen wQueenStr;
extern bQueen bQueenStr;

extern std::vector<wPawn> wPawnList;
extern std::vector<bPawn> bPawnList;
extern std::vector<wRook> wRookList;
extern std::vector<bRook> bRookList;
extern std::vector<wKnight> wKnightList;
extern std::vector<bKnight> bKnightList;
extern std::vector<wBishop> wBishopList;
extern std::vector<bBishop> bBishopList;
extern std::vector<wQueen> wQueenList;
extern std::vector<bQueen> bQueenList;

extern moveList mvList;

extern castle kqCastle;

extern std::vector<moveList> moveVector;

#endif