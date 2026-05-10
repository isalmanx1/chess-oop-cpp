#include "xyz.h"
#include <cmath>

//pawn moves forward 1 step, or 2 steps from starting row
//it only moves in one direction based on its color
//pawn move validation implemented by ayyan
bool pawn::isValidMove(position start, position end) {
    int direction = isWhite ? -1 : 1; //white goes up (row decreases), black goes down
    int rowDiff = end.row - start.row;
    int colDiff = end.col - start.col;

    //normal 1-step forward move (no column change)
    if (colDiff == 0 && rowDiff == direction)
        return true;

    //2-step move only allowed from starting row
    int startRow = isWhite ? 6 : 1;
    if(colDiff == 0 && rowDiff == 2 * direction && start.row == startRow)
        return true;

    //diagonal capture (1 step diagonally forward)
    if(abs(colDiff) == 1 && rowDiff == direction)
        return true;

    return false;
}

char pawn::getSymbol() {
    return isWhite ? 'P' : 'p';
}

//king moves 1 step in any direction
bool King::isValidMove(position start, position end) {
    int rowDiff = abs(end.row - start.row);
    int colDiff = abs(end.col - start.col);
    return rowDiff <= 1 && colDiff <= 1 && (rowDiff + colDiff > 0);
}

char King::getSymbol() {
    return isWhite ? 'K' : 'k';
}

//queen moves in straight lines or diagonals, any number of steps
bool Queen::isValidMove(position start, position end) {
    int rowDiff = abs(end.row - start.row);
    int colDiff = abs(end.col - start.col);

    //same row or same column = straight line
    if (start.row == end.row || start.col == end.col)
        return true;

    //equal row and col difference = diagonal
    if(rowDiff == colDiff)
        return true;

    return false;
}

char Queen::getSymbol() {
    return isWhite ? 'Q' : 'q';
}

//rook moves in straight lines only (same row or same column)
bool Rook::isValidMove(position start, position end) {
    return start.row == end.row || start.col == end.col;
}

char Rook::getSymbol() {
    return isWhite ? 'R' : 'r';
}

//bishop moves diagonally only
bool Bishop::isValidMove(position start, position end) {
    int rowDiff = abs(end.row - start.row);
    int colDiff = abs(end.col - start.col);
    return rowDiff == colDiff;
}

char Bishop::getSymbol() {
    return isWhite ? 'B' : 'b';
}

//knight moves in L-shape: 2 steps one way, 1 step the other
bool Knight::isValidMove(position start, position end) {
    int rowDiff = abs(end.row - start.row);
    int colDiff = abs(end.col - start.col);
    return (rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2);
}

char Knight::getSymbol() {
    return isWhite ? 'N' : 'n';
}

//board constructor - sets up all pieces in their starting positions
Board::Board() {
    // fill entire board with nulls first
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            grid[i][j] = nullptr;

    //place black pieces on row 0
    grid[0][0] = new Rook(false);
    grid[0][1] = new Knight(false);
    grid[0][2] = new Bishop(false);
    grid[0][3] = new Queen(false);
    grid[0][4] = new King(false);
    grid[0][5] = new Bishop(false);
    grid[0][6] = new Knight(false);
    grid[0][7] = new Rook(false);

    //black pawns on row 1
    for(int j = 0; j < 8; j++)
        grid[1][j] = new pawn(false);

    //white pawns on row 6
    for(int j = 0; j < 8; j++)
        grid[6][j] = new pawn(true);

    //place white pieces on row 7
    grid[7][0] = new Rook(true);
    grid[7][1] = new Knight(true);
    grid[7][2] = new Bishop(true);
    grid[7][3] = new Queen(true);
    grid[7][4] = new King(true);
    grid[7][5] = new Bishop(true);
    grid[7][6] = new Knight(true);
    grid[7][7] = new Rook(true);
}

//board destructor - free memory for all pieces
Board::~Board() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (grid[i][j] != nullptr)
                delete grid[i][j];
}

//display the board with row/column labels
void Board::display() {
    cout << "  0 1 2 3 4 5 6 7" << endl;
    for (int i = 0; i < 8; i++) {
        cout << i << " ";
        for (int j = 0; j < 8; j++) {
            if (grid[i][j] == nullptr)
                cout << ". ";
            else
                cout << grid[i][j]->getSymbol() << " ";
        }
        cout << endl;
    }
}

//checks if a move is legal and performs it if so
bool Board::movePiece(position start, position end, bool whiteTurn) {
    piece* p = grid[start.row][start.col];

    // no piece at start position
    if(p == nullptr) {
        cout << "No piece at that position." << endl;
        return false;
    }

    //make sure the player is moving their own piece
    char sym = p->getSymbol();
    bool pieceIsWhite = (sym >= 'A' && sym <= 'Z'); // uppercase = white
    if(pieceIsWhite != whiteTurn) {
        cout << "That is not your piece." << endl;
        return false;
    }

    //check if the destination is the same spot
    if (start.row == end.row && start.col == end.col) {
        cout << "You didn't move anywhere." << endl;
        return false;
    }

    //validate move according to piece rules
    if (!p->isValidMove(start, end)) {
        cout << "Invalid move for this piece." << endl;
        return false;
    }

    //can't capture your own piece
    if(grid[end.row][end.col] != nullptr) {
        char targetSym = grid[end.row][end.col]->getSymbol();
        bool targetIsWhite = (targetSym >= 'A' && targetSym <= 'Z');
        if(targetIsWhite == whiteTurn) {
            cout << "You can't capture your own piece." << endl;
            return false;
        }

        //check if king was captured - game over
        if(targetSym == 'K' || targetSym == 'k') {
            cout << (whiteTurn ? "White" : "Black") << " captured the King! Game over." << endl;
            delete grid[end.row][end.col];
            grid[end.row][end.col] = p;
            grid[start.row][start.col] = nullptr;
            return true;
        }

        delete grid[end.row][end.col]; // remove captured piece from memory
    }

    //perform the move
    grid[end.row][end.col] = p;
    grid[start.row][start.col] = nullptr;

    return true;
}
