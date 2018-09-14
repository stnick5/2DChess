#ifndef VECTOR2D_H
#define VECTOR2D_H

	struct Vector2D 
	{
		int x;
		int y;
		int boardSq;
	};

	// This struct stores a move the players make. An instance of this struct will be stored in a vector, which will store every move the player makes in the game.
	struct moveList
	{
		int pType;			// Which piece type was moved
		int pColour;		// Which piece colour was moved
		int mvFrom;			// Where was the piece moved from
		int mvTo;			// Where was the piece moved to
		bool capture;		// Was a piece captured?
		bool kCastle;		// Did the player castle on the king side?
		bool qCastle;		// Did the player castle on the queen side?
		int pProm;			// Was a pawn promoted? What was it promoted to?
		bool enpassant;		// Did the player use en passant?
		//bool check;			// Is the opponent in check?
		//bool checkmate;		// Is the opponent in checkmate?
	};

	struct castle
	{
		bool kCastle;
		bool qCastle;
	};

	struct wPawn {
		int sq;
		bool capture;
		int pNum;
	};

	struct bPawn {
		int sq;
		bool capture;
		int pNum;
	};

	struct wRook {
		int sq;
		bool capture;
		int pNum;
	};

	struct bRook {
		int sq;
		bool capture;
		int pNum;
	};

	struct wBishop {
		int sq;
		bool capture;
		int pNum;
	};

	struct bBishop {
		int sq;
		bool capture;
		int pNum;
	};

	struct wKnight {
		int sq;
		bool capture;
		int pNum;
	};

	struct bKnight {
		int sq;
		bool capture;
		int pNum;
	};

	struct wQueen {
		int sq;
		bool capture;
		int pNum;
	};

	struct bQueen {
		int sq;
		bool capture;
		int pNum;
	};

	struct LMoves {
		int sq;
		int pieceNumber;
	};



	// Piece List
	enum Piece
	{
		Pawn = 1,
		Knight = 2,
		King = 3,
		Bishop = 5,
		Rook = 6,
		Queen = 7
	};

	enum Colour
	{
		WHITE = 1,
		BLACK = 0
	};

	// Squares
	enum Square
	{
		A1 = 0, B1, C1, D1, E1, F1, G1, H1,
		A2 = 16, B2, C2, D2, E2, F2, G2, H2,
		A3 = 32, B3, C3, D3, E3, F3, G3, H3,
		A4 = 48, B4, C4, D4, E4, F4, G4, H4,
		A5 = 64, B5, C5, D5, E5, F5, G5, H5,
		A6 = 80, B6, C6, D6, E6, F6, G6, H6,
		A7 = 96, B7, C7, D7, E7, F7, G7, H7,
		A8 = 112, B8, C8, D8, E8, F8, G8, H8
	};

	enum movement
	{
	north = 16,
	south = -16,
	east = 1,
	west = -1,
	northeast = 17,
	southeast = -17,
	southwest = -15,
	northwest = 15,

	kNorthLeft = 31,
	kNorthRight = 33,
	kEastUp = 18,
	kEastDown = -18,
	kSouthLeft = -31,
	kSouthRight = -33,
	kWestUp = 14,
	kWestDown = -14
	};

#endif