# Tic Tac Toe Game

A C++ console-based Tic Tac Toe game where you play against an intelligent computer opponent.

## Project Overview

This is a Tic Tac Toe game implementation in C++ featuring a computer AI that plays defensively and strategically. The game uses a 3x3 grid where you play as 'X' and the computer plays as 'O'.

## Features

- **Computer AI**: Intelligent opponent that:
  - Makes strategic first moves
  - Blocks your winning moves
  - Checks rows, columns, and diagonals for blocking opportunities
  - Makes random moves when not blocking
- **Input Validation**: Error handling for invalid moves
- **Game Status Checking**: Win detection, draw detection, and empty space tracking
- **Clear Board Display**: ASCII formatted game board
- **Replay Option**: Play multiple games in one session

## How to Play

1. Run the program
2. Answer "yes" when prompted to confirm you want to play
3. The board displays numbers 1-9 for position selection:

1 | 2 | 3
4 | 5 | 6
7 | 8 | 9

4. Enter a number (1-9) to place your 'X'
5. Computer automatically responds with its 'O'
6. First player to get 3 in a row (horizontally, vertically, or diagonally) wins
7. If all spaces fill without a winner, it's a draw

## Game Rules

- Players alternate turns (you first, then computer)
- Each position can only be used once
- Invalid moves result in an error and turn loss
- Game ends when someone wins or the board is full
- Winning conditions: 3 in a row/column/diagonal

## Technologies Used

- **Language**: C++
- **Object-Oriented Programming**: TicTacToe class design
- **Exception Handling**: Custom exception classes for invalid input
- **2D Arrays**: 3x3 board representation
- **Game Logic**: Win/draw detection algorithms

### Code Architecture

### TicTacToe Class

- **Data Members**:
  - `board[3][3]`: 2D array representing the game board
  - Position values: '1'-'9' (empty), 'X' (player), 'O' (computer)

- **Public Methods**:
  - `TicTacToe()`: Constructor initializing the board
  - `displayBoard()`: Renders the current game state
  - `inputBoard(int)`: Places player's X at specified position
  - `checkWinner()`: Checks for winning conditions
  - `isEmpty(int, int)`: Checks if a position is available
  - `checkDraw()`: Determines if game is a draw
  - `computerMove()`: Executes computer's move with AI logic

### Computer AI Logic

1. **First Move**: Places 'O' at a random position
2. **Blocking Strategy**: 
   - Scans each row for 2 'X's with an empty space → blocks
   - Scans each column for 2 'X's with an empty space → blocks
   - Checks both diagonals for 2 'X's → blocks
3. **Default**: If no blocking needed, places 'O' randomly

## What I Learned

- **2D Array Manipulation**: Working with matrix structures
- **Game AI**: Implementing strategic blocking logic
- **Win Detection**: Checking rows, columns, and diagonals
- **Exception Handling**: Creating custom exception classes
- **Algorithm Design**: Implementing efficient game logic
- **State Management**: Tracking game progress and board state
- **Input Validation**: Handling and catching user errors

## Compilation & Execution

```bash
# Compile the program
g++ -o tictactoe tictactoe.cpp tictactoetest.cpp

# Run the game
./tictactoe
```

## Example Gameplay

Welcome to the TicTacToe game would you like to play? Answer 'yes' to play.yes
Welcome to TIC TAC TOE. You are X, Computer is O.
1 | 2 | 3
---+---+---
4 | 5 | 6
---+---+---
7 | 8 | 9
Enter your move (1-9): 5
Now it is Computer's turn.
1 | 2 | 3
---+---+---
4 | X | 6
---+---+---
7 | 8 | O

## Game States

- **In Progress**: Game continues until win or draw
- **Player Wins**: 3 'X's in a row/column/diagonal
- **Computer Wins**: 3 'O's in a row/column/diagonal
- **Draw**: All 9 spaces filled without a winner

## Future Enhancements

- [ ] Difficulty levels (easy, medium, hard)
- [ ] Score tracking across sessions
- [ ] Undo last move feature
- [ ] GUI version with graphics
- [ ] Network multiplayer support
- [ ] AI using minimax algorithm
- [ ] Game statistics and win rate

## Error Handling

- **Invalid Number**: Entering a number outside 1-9 range
- **Already Taken**: Selecting a position already occupied
- Both errors prevent the player's turn from completing

## Author

Ivan Ermakov
