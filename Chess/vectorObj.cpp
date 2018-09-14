#include "vectorObj.h"

// Creates all the vectors used.

std::vector<pieceClass> pieceList;

string boardSquare[129];

string fileA = "A";
string fileB = "B";
string fileC = "C";
string fileD = "D";
string fileE = "E";
string fileF = "F";
string fileG = "G";
string fileH = "H";

string row1	= "1";
string row2	= "2";
string row3	= "3";
string row4	= "4";
string row5	= "5";
string row6	= "6";
string row7	= "7";
string row8	= "8";

std::vector<sf::Sprite> cWPawn;
std::vector<sf::Sprite> cBPawn;
std::vector<sf::Sprite> cWRook;
std::vector<sf::Sprite> cBRook;
std::vector<sf::Sprite> cWKnight;
std::vector<sf::Sprite> cBKnight;
std::vector<sf::Sprite> cWBishop;
std::vector<sf::Sprite> cBBishop;
std::vector<sf::Sprite> cWQueen;
std::vector<sf::Sprite> cBQueen;
std::vector<sf::Sprite> cWKing;
std::vector<sf::Sprite> cBKing;



Vector2D xycoords;

std::vector<Vector2D> coords;

std::vector<int> file1;
std::vector<int> file2;
std::vector<int> file3;
std::vector<int> file4;
std::vector<int> file5;
std::vector<int> file6;
std::vector<int> file7;
std::vector<int> file8;

std::vector<LMoves> legalMoves;

std::vector< vector<LMoves> > wPawnLegal;
std::vector< vector<LMoves> > wRookLegal;
std::vector< vector<LMoves> > wKnightLegal;
std::vector< vector<LMoves> > wBishopLegal;
std::vector< vector<LMoves> > wQueenLegal;
std::vector< vector<LMoves> > wKingLegal;
					
std::vector< vector<LMoves> > bPawnLegal;
std::vector< vector<LMoves> > bRookLegal;
std::vector< vector<LMoves> > bKnightLegal;
std::vector< vector<LMoves> > bBishopLegal;
std::vector< vector<LMoves> > bQueenLegal;
std::vector< vector<LMoves> > bKingLegal;

LMoves LMovesBuffer;


int pieceMap[127];
int wKingPos;
int bKingPos;
std::vector<int> wPawnMap;
std::vector<int> bPawnMap;

wPawn wPawnStr;
bPawn bPawnStr;
wRook wRookStr;
bRook bRookStr;
wBishop wBishopStr;
bBishop bBishopStr;
wKnight wKnightStr;
bKnight bKnightStr;
wQueen wQueenStr;
bQueen bQueenStr;

std::vector<wPawn> wPawnList;
std::vector<bPawn> bPawnList;
std::vector<wRook> wRookList;
std::vector<bRook> bRookList;
std::vector<wKnight> wKnightList;
std::vector<bKnight> bKnightList;
std::vector<wBishop> wBishopList;
std::vector<bBishop> bBishopList;
std::vector<wQueen> wQueenList;
std::vector<bQueen> bQueenList;

moveList mvList;

castle kqCastle;

std::vector<moveList> moveVector;