#ifndef HANGMAN_H
#define HANGMAN_H

#include <iostream>

using namespace std;

//make a class 
class HangMan{

    //data members hiddden from the client 
    private:

    string word;                    //random word taken 

    char* userIn;                   //using dynamic array so we can change the capacity 

    string lexicon[20];             //random word from the dictionary  

    int lives;                      //amount of lives you have 

    string getRandomWord();         //function that gets rando

    void fillRandomWordArray();     //function to fil array with random word 


    //avaible for client to use 
    public:
    
    //constructor
    HangMan();              
  
    int getLives() const {return lives;}    //fucntion check amount of lives and display

    void DisplayBoard();                    //function to display the hangman

    void userInput(char a);                 //function to collect users letters
    

};



#endif 