// CS211 HW2 Implementation File (Hidden from the client)

// INSTRUCTION: Always look for ** and complete them. Do not delete them!

// THE PURPOSE: Learn to write member functions
// Define all functions (constructor, destructor, 
// readNames, displayNames)
// and provide required comments PURPOSE: PARAMETERS:

// Note that you can use all the data members
// without declaring them again in this file.
// Do not forget to say names:: in front of function names 


/* -------------------------------------------------
 Your name: *Ivan Ermakov*
 Implementation File for HW2 names class
 Compiler: g++
 --------------------------------------------------- */

// ** first, include correct files, including "names.h"
#include "names.h"
#include <iostream>

// Constructor
names::names()
{ // ** do all data member initializations here
  N[3][4];
}

names::~names()
{ // nothing to do since we use static memory
}

//PURPOSE: collect the names from the txt file and store it into matrix 
//PARAMETERS: ifstream& fin 
void names::readNames(ifstream& fin)
{
  char row = 0; //create char for row
  char column = 0; //create char for column
  int rows = 0; //turn a into int
  int columns = 0; //turn b into int
  string name; //collect name
  while(fin>> row >> column >> name)// makes sure it collects everyrthing from file
    {
      rows  = row - int('a'); // -'a' to convert
      columns  = column - int('a');
      N[rows][columns] = name;
    }
}

// ** complete displayNames too!

//PUROSE: to display the names in the matrix in a nice format and seeing what row and column each name goes in
//PARAMETERS: 
void names::displayNames()
{
  for(int r = 0; r < 3; r++)//loop for rows
    {
      for(int c = 0; c < 4; c++)//loop for columns
        {
          cout << "|";
          if(N[r][c].length() > 0) //checks if column is empty
            {
	      cout << N[r][c];
            }
          else{
            cout << "----";
          }
        }
      cout << endl; //make a new row
    }
}
