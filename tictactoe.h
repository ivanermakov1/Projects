#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <iostream>

using namespace std;

//declare 2 aliases to make sure it is a interger stack
const int MAX = 3;


//make a class 
class TicTacToe {
private: // data members hiddens from client 
    
    char board[MAX][MAX];

public: //for client to use

    //create throw for invalid number
    class InvalidNumber{}; 
    
    //constructor 
    TicTacToe();
 
    //display function 
    void displayBoard();

    //input function
    void inputBoard(int ans);

    //check winner function 
    bool checkWinner();
    
    //check empty function
    bool isEmpty(int row, int col);
 
    //check draw function 
    bool checkDraw();

    //computer move function
    void computerMove();
    
};

#endif
