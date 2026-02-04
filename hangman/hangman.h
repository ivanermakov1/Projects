#ifndef HANGMAN_H
#define HANGMAN_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype> 

using namespace std;

//make a class 
class HangMan{

    //data members hiddden from the client 
    private:

    string word;                        //random word taken that the players is trying to guess

    bool guessedLetters[26] = {false};  //array to check if any of the letters have been guessed first all letters are set to false

    vector <string> lexicon;            //vector to hold all the words from the dictionary file   

    int lives;                          //amount of lives you have 

    void fillLexicon();                 //function that fills the lexicon vector with words from the dictionary file

    void fillRandomWordArray();         //function to fil array with random word 


    //avaible for client to use 
    public:
    
    //constructor
    HangMan();              
  
    int getLives() const {return lives;}    //fucntion check amount of lives and display

    void DisplayBoard();                    //function to display the hangman

    void userInput(char a);                 //function to collect users letters

    bool checkGuess(char a);                //function to check whether players guess is correct
    
    bool isGameWon();                       //function to check if game is won  

    bool isGameLost();                      //function to check if game is lost

    void resetGame();                        //function to reset the game
};

#endif 