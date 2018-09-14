#ifndef CLASSOBJ_H
#define CLASSOBJ_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "board.h"
#include "piece.h"
#include "pieceUpdate.h"
#include "spriteLoader.h"
#include "pieceMain.h"

using namespace std;

// Create the Board class object and the pieceUpdate class object
extern Board board;
extern pieceClass cPiece;
extern pieceUpdate pUpdate;
extern sprLoader spLoader;
extern pieceMain pMain;

#endif