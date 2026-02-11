// CS211 HW2 Header File for ADT version of HW1

// THE PUROSE of this HW is to learn to use ADT

// INSTRUCTION: Always look for ** and complete them
// Read the header file carefully to learn how it is organized and commented

/* ---------------------------------------------
 Your name: *Ivan Ermakov*
 Header File for HW1's string-matrix class
 Compiler: g++
------------------------------------------------ */

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class names
{
 private: // data members hidden from the client
  string N[3][4];  // matrix of strings

 public: // available to the client

  // I am making sure the comments are for client programmers
  names();  // constructor
  ~names(); // destructor
  
  void readNames(ifstream&);          // read from the input file stream
  void displayNames();                // display names

};   
// don't forget the semicolon at the end.


