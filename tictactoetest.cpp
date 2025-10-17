#include <iostream> 
#include "tictactoe.h"

using namespace std;

int main()
{
    TicTacToe game; //create the TicTacToe object

    string answer;
    do{
    cout << "Welcome to the TicTacToe game would you like to play? Answer 'yes' to play.";
    cin >> answer;
    } while (answer != "yes");

    cout << "Welccome to TIC TAC TOE."; 
    cout << "You are X, Computer is O." << endl;
    

    int playerMove;
    do
    {
        //Display the board first
        game.displayBoard();
        cout << endl;

        //Do player turn first
        cout << "Enter your move (1-9): ";
        cin >> playerMove;

        try
        {
            game.inputBoard(playerMove); //place players 
        }
        catch(TicTacToe::InvalidNumber)
        {
            cout << "Invalid Move! Please enter a number between 1-9!" << endl;
            break;
        }

        //check if player won
        if(game.checkWinner())
        {
            game.displayBoard();
            cout << "You have one the game!" << endl;
            break;
        }

        //check if player had a draw
        if(game.checkDraw())
        {
            game.displayBoard();
            cout << "It is a draw!" << endl;
            break;
        }

        //do computer turn
        cout << "Now it is Computer's turn. " << endl;
        game.computerMove();

        //Check if the computer won
        if(game.checkWinner())
        {
            game.displayBoard();
            cout << "Computer Wins!" << endl;
            break;
        }

        //Check for the computer draw
        if(game.checkDraw())
        {
            game.displayBoard();
            cout << "It is a draw!" << endl;
            break;
        }


        
    } while (true);
    
    return 0;


}
