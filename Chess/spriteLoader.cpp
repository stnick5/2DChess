#include "classObj.h"
#include "objdef.h"

sprLoader::sprLoader()
{

}

void sprLoader::loadSprites()
{
	if (!wpawn.LoadFromFile("wPawn.tga"))
		cout <<"Unable to load wPawn.tga";
	if (!bpawn.LoadFromFile("bPawn.tga"))
		cout << "Unable to load bPawn.tga";
	if (!wrook.LoadFromFile("wRook.tga"))
		cout << "Unable to load wRook.tga";
	if (!brook.LoadFromFile("bRook.tga"))
		cout << "Unable to load bRook.tga";
	if (!wknight.LoadFromFile("wKnight.tga"))
		cout << "Unable to load wKnight.tga";
	if (!bknight.LoadFromFile("bKnight.tga"))
		cout << "Unable to load bKnight.tga";
	if (!wbishop.LoadFromFile("wBishop.tga"))
		cout << "Unable to load wBishop.tga";
	if (!bbishop.LoadFromFile("bBishop.tga"))
		cout << "Unable to load bBishop.tga";
	if (!wqueen.LoadFromFile("wQueen.tga"))
		cout << "Unable to load wQueen.tga";
	if (!bqueen.LoadFromFile("bQueen.tga"))
		cout << "Unable to load bQueen.tga";
	if (!wking.LoadFromFile("wKing.tga"))
		cout << "Unable to load wKing.tga";
	if (!bking.LoadFromFile("bKing.tga"))
		cout << "Unable to load bKing.tga";
}