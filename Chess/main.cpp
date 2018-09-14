#include "classObj.h"
#include "vectorObj.h"

int main()
{

	// Create the main rendering window
	sf::RenderWindow App(sf::VideoMode(800, 800, 32), "SFML Graphics");

	// Load chessboard image from file
	sf::Image chessboard;
	if (!chessboard.LoadFromFile("board.tga"))
		return EXIT_FAILURE;

	// Create the sprite for the chessboard
	sf::Sprite chess(chessboard);
	chess.SetImage(chessboard);

	// Display chessboard sprite
	App.Draw(chess);

	// Calls the loadSprites() function in spriteLoader.cpp, and loads the sprites into memory
	spLoader.loadSprites();

	//Calls the setCoords() function, initializes the coordinates vector and stores the xy coordinates of all the squares in the vector.
	board.setCoords();

	// Calls the FENReader function in board.cpp. This function loads the initial position on the board.
	board.FENReader(&App);

	pUpdate.findLegalMoves();

	board.setSideToMove(WHITE);

	// Display window contents on screen
	App.Display();
	
	// The selPiece variable is used to test whether a piece has been selected or not. If selPiece is set to false, then a piece hasn't been selected. If it's true, then a piece has been selected.
	bool selPiece = false;
	pUpdate.setSelected(selPiece);

	bool print = true;

	// Start game loop
	while (App.IsOpened())
	{


		// Process events
		sf::Event Event;
		while (App.GetEvent(Event))
		{
			// Integers for mouse coordinates.
			float mX;
			float mY;

			float mXSel;
			float mYSel;


			// Create the square highlight
			sf::Shape DSquare;
			DSquare.AddPoint(0, 0);
			DSquare.AddPoint(100, 0);
			DSquare.AddPoint(100, 100);
			DSquare.AddPoint(0, 100);

			// The highlight for the selected square (piece)
			sf::Shape SelSquare;
			SelSquare.AddPoint(0, 0);
			SelSquare.AddPoint(100, 0);
			SelSquare.AddPoint(100, 100);
			SelSquare.AddPoint(0, 100);

			// Close window : exit
			if (Event.Type == sf::Event::Closed)
				App.Close();

			// Escape key : exit
			if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
				App.Close();
			
			// If mouse button is clicked
			if ((Event.Type == sf::Event::MouseButtonPressed)) {

				App.Clear();	// Clears the screen

				if (pUpdate.selected() == false) {	// If no piece has been selected

					// Calls the getMCoords() function in board.cpp and passes the mX and mY integers by reference. The getMCoords() function then sets the current xy coordinates of the mouse to the mX and mY integers.
					board.getMCoords(&App, &mX, &mY);

					pUpdate.selectSq(mX, mY);	// Passes the current mouse coordinates to the selectSq() function in pieceUpdate.cpp.
					mXSel = mX;
					mYSel = mY;

					board.sqHighlight(&DSquare, &mXSel, &mYSel, &App);
					
				}

				else {
					board.getMCoords(&App, &mX, &mY);

					pUpdate.updateSq(mX, mY, &App);	// Passes the current mouse coordinates to the updateSq() function in pieceUpdate.cpp.
					pUpdate.setSelected(selPiece);	// passes selPiece to the setSelected() function in pieceUpdate.cpp.
					board.setSqSelected(false);

					print = true;
				}
				
				App.Draw(chess);	// Draws the chessboard sprite.
				board.redraw(&App, &mXSel, &mYSel, &SelSquare);	// Calls the redraw() function in board.cpp, which redraws all the pieces at their current positions.
				App.Display();
				
			}
			if ((Event.Type == sf::Event::MouseMoved)) {	// When the mouse is moved.
				App.Clear();
				
				App.Draw(chess);
				board.getMCoords(&App, &mX, &mY);

				board.highlight(&mX, &mY, &DSquare, &App);	// Call the highlight() function in board.cpp, which draws the square over the current mouse position.

				board.redraw(&App, &mXSel, &mYSel, &SelSquare);
				App.Display();
			}
			if (print == true) {
				board.prtPieceInfo(&print);
			}
		}
	}
	return EXIT_SUCCESS;
}