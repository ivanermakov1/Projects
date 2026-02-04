#include <iostream>
#include <ctime>        //for seeding time
#include <fstream>      //for file handling
#include <cstdlib>      //for rand and srand
#include <cctype>       //for tolower function

#include "hangman.h"    //include header file

using namespace std;


/*
    Constructor to initialize data members
*/
HangMan::HangMan(){
    
    lives = 6;                  //set lives to 6 at the start of the game
    fillLexicon();              //call fillLexicon function first to fill the vector with words from dictionary file
    fillRandomWordArray();      //call fillRandomWordArray function to choose a random word from the vector and fill the word string

}

void HangMan::fillLexicon()
{
    ifstream fin;                   //decalre fstream object 
    fin.open("dictionary.txt");     //open the dictionary file
    
    if(!fin.is_open())              //check if file is open
    {                               //throw error if file not open
        throw runtime_error("Failed to open the dictionary file");
    }

    string temporary;                   //temporarty string so we can put the word in the vector using fin

    while(getline(fin, temporary))      //reads each word in the file till it reaches the end
    {
        lexicon.push_back(temporary);   //push each word in the vector 
    }

    fin.close();                        //close the file after reading all the words
}

void HangMan::fillRandomWordArray()
{
    srand(time(0));                             //seed the random number generator

    word = lexicon[rand() % lexicon.size()];    //choose a random word from the vector using rand function % the size of the vector and assign it to the word using index[i]
}

void HangMan::userInput(char a)
{
    a = tolower(a);                       //use tolower to convert any uppercase letter to lowercase

    if(guessedLetters[a - 'a'] == true)   //checks if the letter has been guessed by doing a - 'a' to find the index of the letter in the array and if it is true it has been guess since it is set to false at start
    {
        cout << "You have already guessed that letter. Try another letter." << endl;
        return;                           //return to avoid going further
    }

    guessedLetters[a - 'a'] = true;       //set the index of the letter guessed to true in the array
}

bool HangMan::checkGuess(char a)
{
    for(int i = 0; i < word.size(); i++)   //create loop to check if the letter is in the word stopping at the size of the word
    {
        if(word[i] == a)                   //if the letter is equal to the index of the word it is true/correct
        {
            cout << "You have guessed a correct letter!" << endl;
            return true;                   //return true if letter is found in the word   
        }
    }

    lives--;                               //decrement lives by 1 if the letter is not found in the word
    cout << "Incorrect guess. You lost a life." << endl;
    return false;                          //return false if the letters is not in the word
}

bool HangMan::isGameWon()
{
    for(int i = 0; i < word.size(); i++)            //loop through each letter in the word 
    {
        if(guessedLetters[word[i] - 'a'] == false)  //check if the letter at the index of the word has been guessed by checking the array if it is false/it has not been guessed yet
        {
            return false;
        }
    }

    cout << "Congratulations! You have guessed the word: " << word << endl; 
    return true;                                    //if all letters have been guessed return true/game is won     
}

bool HangMan::isGameLost()
{
    if(lives == 0)               //check if lives is equal to 0 to see if game is lost 
    {
        cout << "Game is Over! You ran out of lives. The word was: " << word << endl;
        return true;            //return true if the game is lost
    }

    return false;               //return false if the game is not lost  
}

void HangMan::DisplayBoard()
{
    cout << "Lives Remaining: " << lives << endl;  //display the amount of lives remaining

    switch(lives)           //switch case to display the hangman based on the amount of lives
    {
        case 6:
            cout << "  ____________" << endl;          
            cout << " /|          | " << endl;
            cout << " ||            " << endl;
            cout << " ||            " << endl;
            cout << " ||            " << endl;
            cout << " ||            " << endl;
            cout << " ||            " << endl;
            cout << "_||__________  " << endl;
            break;
        case 5:
            cout << "  ____________" << endl;
            cout << " /|          | " << endl;
            cout << " ||          O  " << endl;
            cout << " ||            " << endl;
            cout << " ||            " << endl;
            cout << " ||            " << endl;
            cout << " ||            " << endl;
            cout << "_||__________  " << endl;
            break;
        case 4:
            cout << "  ____________" << endl;
            cout << " /|          | " << endl;
            cout << " ||          O " << endl;
            cout << " ||          | " << endl;
            cout << " ||            " << endl;
            cout << " ||            " << endl;
            cout << " ||            " << endl;
            cout << "_||__________  " << endl;
            break;
        case 3:
            cout << "  ____________" << endl;
            cout << " /|          | " << endl;
            cout << " ||          O " << endl;
            cout << " ||         /| " << endl;
            cout << " ||            " << endl;
            cout << " ||            " << endl;
            cout << " ||            " << endl;
            cout << "_||__________  " << endl;
            break;
        case 2:
            cout << "  ____________" << endl;
            cout << " /|          | " << endl;
            cout << " ||          O " << endl;
            cout << " ||         /|\\ " << endl;
            cout << " ||            " << endl;
            cout << " ||            " << endl;
            cout << " ||            " << endl;
            cout << "_||__________  " << endl;
            break;
        case 1:
            cout << "  ____________" << endl;
            cout << " /|          | " << endl;
            cout << " ||          O " << endl;
            cout << " ||         /|\\ " << endl;
            cout << " ||         /  " << endl;
            cout << " ||            " << endl;
            cout << " ||            " << endl;
            cout << "_||__________  " << endl;
            break;
        case 0:

            cout << "You have no lives left. You are hanged!" << endl;   //last case is when you lose the game 

            cout << "  ____________" << endl;
            cout << " /|          | " << endl;
            cout << " ||          O " << endl;
            cout << " ||         /|\\ " << endl;
            cout << " ||         / \\ " << endl;
            cout << " ||            " << endl;
            cout << " ||            " << endl;
            cout << "_||__________  " << endl;
            break;
        default:
            cout << "Error displaying hangman board." << endl;      //default case for error handling
            break;
    }

    for (int i = 0; i < word.size(); i++)    //loop to check if the letters in the word has been guessed or not to display it 
    {
        if(guessedLetters[word[i] - 'a'] == true)
        {
            cout << word[i] << " ";     //if letter has been guessed display the letter
        }
        else
        {
            cout << "_ ";           //if letter has not been guessed display underscore
        }
    }

    cout << "\n" << endl;   //new line for formatting

    cout << "Letters guessed so far: " << endl;
    for(int i = 0; i < 26; i++)    //loop to display the letters that have been guessed and not guessed
    {
        char letter = 'a' + i;      //first convert the index to the corresponding letter by adding 'a' to the index

        if(guessedLetters[i] == true)   //check if the letter at that index has been guessed
        {
            cout << "- ";      //if it has been guessed display by using a dash
        }
        else 
        {
            cout << letter << " ";  //if it has not been guessed display the letter
        }
    }
    
    cout << "\n" << endl;      //new line for formatting

}

void HangMan::resetGame()
{
    lives = 6;                                 //reset lives to 6
    
    fillRandomWordArray();                     //call fillRandomWordArray function to choose a new random word from the vector and fill the word string

    for(int i = 0; i < 26; i++)
    {
        guessedLetters[i] = false;            //reset all the letters in the array to false/not guessed
    }

}

