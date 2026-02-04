#include "hangman.h"   //include header file

using namespace std;

int main()
{
    try
    {
        HangMan hangman;    //create HangMan object
        
        char playerChoice;  //variable to hold player's choice to play again
        
        //outer loop to prompt user to play again
        do
        {

        //inner loop to play the game
        while(!hangman.isGameWon() && !hangman.isGameLost())        //loop continues until the game is either won or lost
        {
            hangman.DisplayBoard();             //display the hangman board

            char userGuess;                     //variable to hold user's guess 
            cout << "Enter your guess, a-z: ";  
            cin >> userGuess;                   //collect user input for their letter guess

            hangman.userInput(userGuess);       //call userInput funtion to collects user's letter

            hangman.checkGuess(userGuess);      //call checkGuess function to check if the user's guess is correct
        }

        hangman.DisplayBoard();                //display the final hangman board after game is won or lost

        cout << "Do you want to play again? (y/n): ";   //prompt user to play again
        cin >> playerChoice;                            //collect user input for their choice
        playerChoice = tolower(playerChoice);           //convert input to lowercase to handle both cases

        if(playerChoice == 'y')                 //if user wants to play again
        {
            hangman.resetGame();                //call resetGame function to reset the game 
        }
        else                                    //else user does not want to play again
        {
            cout << "Thank you for playing Hangman!" << endl;       
        }

    } while(playerChoice == 'y');               //continue outer loop if user wants to play again               

    }
    catch(runtime_error& e)     //catch runtime error exception
    {
        cerr << "Error: " << e.what() << endl;  //display error message using what() function 
    }
}