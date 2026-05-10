#include "xyz.h"

int main() {
    Board board;
    bool whiteTurn = true; //whitee always goes first
    bool gameOver = false;

    cout << "Chess Game" << endl;
    cout << "Uppercase letters = White, lowercase = Black" << endl;
    cout << "Enter moves as: row col row col (start then end)" << endl;

    while(!gameOver) {
        board.display();

        cout << (whiteTurn ? "White" : "Black") << "'s turn." << endl;
        cout << "Enter move: ";

        position start, end;
        cin >> start.row >> start.col >> end.row >> end.col;

        //basic boundary check
        if(start.row < 0 || start.row > 7 || start.col < 0 || start.col > 7 ||
            end.row < 0 || end.row > 7 || end.col < 0 || end.col > 7) {
            cout << "Position out of bounds. Try again." << endl;
            continue;
        }

        bool moved = board.movePiece(start, end, whiteTurn);

        if(moved) {
            //check if game ended (king captured message printed inside movePiece)
            //we just switch turns if move was valid
            whiteTurn = !whiteTurn;
        }

        //simple way to check if game is over - ask the user
        //(proper checkmate detection would need more logic)
        cout << "Type 0 to continue or 1 to quit: ";
        int choice;
        cin >> choice;
        if(choice == 1)
            gameOver = true;
    }

    cout << "Game ended." << endl;
    return 0;
}
