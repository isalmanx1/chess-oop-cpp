#ifndef CHESS_H
#define CHESS_H
#include <iostream>
using namespace std;

struct position {
    int row, col;
};

//base class for all pieces
class piece {
protected:
    bool isWhite;
public:
    piece(bool color) : isWhite(color) {}
    virtual ~piece() {}
    virtual bool isValidMove(position start, position end) = 0;
    virtual char getSymbol() = 0;
};

class pawn : public piece {
public:
    pawn(bool color) : piece(color) {}
    bool isValidMove(position start, position end) override;
    char getSymbol() override;
};

class King : public piece {
public:
    King(bool color) : piece(color) {}
    bool isValidMove(position start, position end) override;
    char getSymbol() override;
};

class Queen : public piece {
public:
    Queen(bool color) : piece(color) {}
    bool isValidMove(position start, position end) override;
    char getSymbol() override;
};

class Rook : public piece {
public:
    Rook(bool color) : piece(color) {}
    bool isValidMove(position start, position end) override;
    char getSymbol() override;
};

class Bishop : public piece {
public:
    Bishop(bool color) : piece(color) {}
    bool isValidMove(position start, position end) override;
    char getSymbol() override;
};

class Knight : public piece {
public:
    Knight(bool color) : piece(color) {}
    bool isValidMove(position start, position end) override;
    char getSymbol() override;
};

//board holds all the pieces and manages game state
class Board {
private:
    piece* grid[8][8]; //8x8 grid of piece pointers
public:
    Board();
    ~Board();
    void display();
    bool movePiece(position start, position end, bool whiteTurn);
};

#endif

