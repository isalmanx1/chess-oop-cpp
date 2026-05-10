# CL1004 — Chess Game (OOP Lab Project)

## Group Members

| Name | GitHub Username | Role |
|------|----------------|------|
| Ayyan Ahmad | @Ayyan-Ahmad235 | piece abstract class, Pawn, Queen, King, Board class, main game loop |
| Salman Zulfiqar | @isalmanx1 | Knight, Bishop, Rook, Board initialization, move validation, turn switching, symbols |

## Project Description
A console-based two-player Chess Game built in C++ as part of the
OOP Lab (CL1004). The project demonstrates core Object-Oriented
Programming concepts through a fully functional chess board with
move validation for all six piece types.

## OOP Concepts Implemented
- Abstract base class (`piece`) with pure virtual functions
- Inheritance — six derived classes (Pawn, King, Queen, Rook, Bishop, Knight)
- Runtime Polymorphism — virtual function dispatch via vtable
- Encapsulation — protected/public access specifiers
- Dynamic Memory Allocation — `new` and `delete` for heap-managed pieces
- Destructor — proper memory cleanup in `Board::~Board()`

## Project Structure

| File | Purpose |
|------|---------|
| `xyz.h` | All class declarations and struct definitions |
| `chess.cpp` | Implementation of all piece and board functions |
| `main.cpp` | Main game loop, input handling, turn management |

## How to Run
1. Open Visual Studio
2. Create an empty C++ project
3. Add all three files (`xyz.h`, `chess.cpp`, `main.cpp`)
4. Build the solution — `Ctrl + Shift + B`
5. Run — `Ctrl + F5`

## How to Play
- Board displays as an 8×8 grid with row/column numbers
- **Uppercase letters** = White pieces
- **Lowercase letters** = Black pieces
- **Dots (.)** = Empty squares
- Enter moves as: `row col row col`

## Piece Symbols

| Symbol | Piece |
|--------|-------|
| P / p | Pawn |
| K / k | King |
| Q / q | Queen |
| R / r | Rook |
| B / b | Bishop |
| N / n | Knight |

## Example Move
Enter move: 6 3 5 3
Moves the piece at row 6, column 3 → to row 5, column 3

## Commit Guidelines
Each member has made a minimum of 3–5 meaningful commits
reflecting the part of the code they personally wrote.

## Course Info
- Course: Object Oriented Programming Lab
- Course Code: CL1004
