# Hangman Game

A C++ console-based Hangman game where you try to guess a word by selecting letters before running out of lives.

## Project Overview

This is a classic Hangman game implementation in C++. The computer picks a random word from a dictionary, and you have 6 lives to guess the word by entering letters one at a time. Each incorrect guess costs you a life.

## Features

- **Random Word Selection**: Computer picks a random word from a dictionary file
- **Hangman Visualization**: ASCII art display showing your remaining lives
- **Letter Tracking**: See which letters you've already guessed
- **Play Again**: Option to play multiple rounds without restarting
- **Exception Handling**: Proper error handling for file operations

## How to Play

1. Run the program
2. The computer picks a random word (shown as underscores)
3. Guess letters one at a time
4. Correct guesses reveal the letter in the word
5. Wrong guesses cost you a life
6. Win by guessing all letters before losing all 6 lives
7. Game displays the final word whether you win or lose
8. Choose to play again or exit

## Game Rules

- You start with **6 lives**
- Each incorrect guess costs **1 life**
- You win when you guess all letters in the word
- You lose when you run out of lives (reach 0)
- Cannot guess the same letter twice

## Technologies Used

- **Language**: C++
- **File Handling**: Reading dictionary from `dictionary.txt`
- **Object-Oriented Programming**: HangMan class with private/public methods
- **Error Handling**: Try-catch for file exceptions

## Code Architecture

### HangMan Class
- **Data Members**:
  - `word`: The secret word being guessed
  - `guessedLetters[26]`: Array tracking which letters have been guessed
  - `lexicon`: Vector storing all words from dictionary
  - `lives`: Number of remaining lives

- **Public Methods**:
  - `HangMan()`: Constructor initializing game
  - `DisplayBoard()`: Shows hangman, word progress, and guessed letters
  - `userInput(char)`: Records user's letter guess
  - `checkGuess(char)`: Validates guess and updates lives
  - `isGameWon()`: Checks if player guessed all letters
  - `isGameLost()`: Checks if player ran out of lives
  - `resetGame()`: Resets game for another round
  - `getLives()`: Returns remaining lives

## What I Learned

- **File I/O**: Reading data from external files
- **Dynamic Data Structures**: Using vectors for storing word lists
- **Arrays**: Using boolean arrays for tracking game state
- **Exception Handling**: Using try-catch for error management
- **OOP Concepts**: Class design, encapsulation, and method organization
- **Game Logic**: Implementing win/loss conditions and game flow
- **String Manipulation**: Working with characters and strings

## Compilation & Execution

```bash
# Compile the program
g++ -o hangman hangman.cpp hangmantest.cpp

# Run the game
./hangman
```

## ASCII Hangman Stages

The game displays different hangman stages based on remaining lives:
- 6 lives: Empty gallows
- 5 lives: Head appears
- 4 lives: Body appears
- 3 lives: Left arm appears
- 2 lives: Right arm appears
- 1 life: Left leg appears
- 0 lives: Right leg appears (Game Over)

## Future Enhancements

- [ ] Difficulty levels (easy, medium, hard words)
- [ ] Score tracking across multiple games
- [ ] Hint system (reveal a letter)
- [ ] Category display (sports, animals, etc.)
- [ ] Time limit per guess
- [ ] Leaderboard with high scores
- [ ] GUI version using graphics library

## Requirements

- C++ compiler (g++, clang, etc.)
- `dictionary.txt` file in the same directory
