#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tictactoe.h"

using namespace std;

TicTacToe::TicTacToe()
{
    // Initialize the board with numbers 1-9
    char num = '1';
    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            board[row][col] = num;
            num++;
        }
    }
}
// CONSTRUCTOR ENDS HERE

void TicTacToe::inputBoard(int ans)
{
    //check for invalid input 
    if(ans < 1 || ans > 9) //if the input is wrong throw an exception
    {
        throw InvalidNumber(); 
    }

    int col; //make col  
    int row; //make row 

    if(ans <= 3)  //if ans is <=3 then it will be row 0
    {
        row = 0;   
    }
    else if(ans <= 6) //if ans is <= 6 it will be row 1 
    {
        row = 1;
    }
    else   //else it will be row 2 
    {
        row = 2; 
    }
    
    if(ans == 1 || ans == 4 || ans == 7) //if ans is either 1,4,or 7 it is col 0
    {
        col = 0;
    }
    else if(ans == 2 || ans == 5 || ans == 8) //if ans is either 2,5, or 8 it is col 1
    {
        col = 1; 
    }
    else  //else it will be col 2 
    {
        col = 2;
    }

    board[row][col] = 'X'; //put an 'X' for what position it is in the matrix 
}


bool TicTacToe::isEmpty(int row, int col)
{
    if(board[row][col] == 'X' || board[row][col] == 'O') //if there is no 'X' or 'O' it is not empty 
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool TicTacToe::checkWinner()
{
    for(int row = 0; row < 3; row++) //loop to check for row win condition 
    {
        if(board[row][0] == board[row][1] && 
            board[row][1] == board[row][2]) 
        {
            return true; 
        }
    }

    for(int col = 0; col < 3; col++) //loop to check for col win condition 
    {
        if(board[0][col] == board[1][col] &&
             board[1][col] == board[2][col])
        {
            return true;
        }
    }

    if(board[0][0] == board[1][1] && //if statement to check for diagonal win condition going right to left 
         board[1][1] == board[2][2]) 
    {
        return true;
    }

    if(board[0][2] == board[1][1] && //if statement to check for diagonal win condition going left to right 
         board[1][1] == board[2][0])
    {
        return true;
    }

    return false;
}

bool TicTacToe::checkDraw() 
{
    if(checkWinner()) //if the winner is true there is no draw
    {
        return false;
    }

    for(int row = 0; row < 3; row++) //make a loop to check each slot of the matrix 
    {
        for(int col = 0; col < 3; col++)
        {
            if(isEmpty(row,col)) //use empty function to check for each slot in the matrix 
            {
                return false;
            }
        }
    }

    return true;  //if both check winner and empty is false then it is true 
}


void TicTacToe::computerMove()
{
    //first count how many 'O's the computer has to see if it's the computer's first move or not 
    int OCount = 0;
    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            if(board[row][col] == 'O')
            {
                OCount++;
            }
        }
    }

    //this is the computer's first move since there are no O on the board and there is 1 x already
    if(OCount == 0)
    {
        srand(time(0)); //random number generator 

        int row, col;

        //loop to keep generating random positions till we find an empty slot
        do
        {
            row = rand() % 3; //random row between 0-2
            col = rand() % 3; //random col between 0-2
        } while (!isEmpty(row,col));

        board[row][col] = 'O'; //place the computers random position
        return; //done with first move
    }

    //second move is to try and block the player so you have to check rows to block 
    for(int row = 0; row < 3; row++)
    {
        int XCount = 0; //count how many X's are in the row 
        int emptyCol = -1; //Track which column is empty if none is found then -1

        //look through each column in this row
        for(int col = 0; col < 3; col++)
        {
            if(board[row][col] == 'X')
            {
                XCount++; //means it found an X
            }
            else if (isEmpty(row, col))
            {
                emptyCol = col; //Found an empty spot
            }
        }

        //If player has 2 X's and there is an empty spot try to block them 
        if(XCount == 2 && emptyCol != -1)
        {
            board[row][emptyCol] = 'O';
            return;
        }
    }

    //check columns to block the player
    for(int col = 0; col < 3; col++)
    {
        int XCount = 0; //count how many X's are in the column
        int emptyRow = -1; //Track which row is empty

        //look through each row in this column
        for(int row = 0; row < 3; row++)
        {
            if(board[row][col] == 'X')
            {
                XCount++; //found an X
            }
            else if(isEmpty(row, col))
            {
                emptyRow = row; //Found an empty spot
            }
        }

        //If player has 2 X's and there is an empty spot try to block them
        if(XCount == 2 && emptyRow != -1)
        {
            board[emptyRow][col] = 'O';
            return;
        }
    }

    //check top-left and bottom-right for diagonal (\)
    int diagXCount = 0;//Count X's on this diagonal
    int emptyRow = -1; //Track empty position
    int emptyCol = -1;

    //Check positions [0][0], [1][1], [2][2]
    for(int i = 0; i < 3; i++)
    {
        if(board[i][i] == 'X') 
        {
            diagXCount++;  //Found an X
        }
        else if(isEmpty(i, i)) 
        { 
            emptyRow = i;   //Remember where the empty spot is
            emptyCol = i; 
        }
    }
    
    //If player has 2 X's on this diagonal, block them!
    if(diagXCount == 2 && emptyRow != -1)
    {
        board[emptyRow][emptyCol] = 'O';
        return;  //Blocking move complete
    }
    
    //Check top-right to bottom-left diagonal (/)
    diagXCount = 0;              //Reset counter for new diagonal
    emptyRow = -1;           //Reset empty position tracker
    emptyCol = -1;
    
    //Check positions [0][2], [1][1], [2][0]
    for(int i = 0; i < 3; i++)
    {
        if(board[i][2-i] == 'X') 
        {
            diagXCount++;  //Found an X
        }
        else if(isEmpty(i, 2-i)) 
        { 
            emptyRow = i;      //Remember where the empty spot is
            emptyCol = 2-i; 
        }
    }
    
    //If player has 2 X's on this diagonal, block them!
    if(diagXCount == 2 && emptyRow != -1)
    {
        board[emptyRow][emptyCol] = 'O';
        return;  //Blocking move complete
    }
    
    //NO BLOCKING NEEDED: Player doesn't have 2 in a row anywhere
    //Just place randomly in any empty spot
    int row, col;
    do 
    {
        row = rand() % 3;    //Random row (0-2)
        col = rand() % 3;    //Random column (0-2)
    } while(!isEmpty(row, col));  //Keep trying until we find an empty spot
    
    board[row][col] = 'O';  //Place the computer's piece
}


void TicTacToe::displayBoard()
{
    for(int row = 0; row < 3; row++) //use loop to display the board 
    {
        for(int column = 0; column < 3; column++)
        {
            cout << board[row][column] << " " << "|";
        }
        cout << endl;
        cout << "---------\n";
    }
}
