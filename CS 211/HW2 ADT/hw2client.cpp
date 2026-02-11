// CS211 HW2 Client

// THE PURPOSE: Learn to write a simple client

// INSTRUCTION: Always look for ** and complete them
// Pay attention to what are #included; Never delete the ** comments!

/* -----------------------------------------------
 Your name: *Ivan Ermakov*
 Client File for HW2 using the names class
 Compiler: g++

 Program Description: Use the read names function to the read the names of the file and input into matrix
                             and the use the display function to display it

 ---------------------------------------------------- */

#include<iostream>
#include<fstream>
#include<string>
#include "names.h"

using namespace std;


// The driver to use names
int main()
{ 
  names Name; // ** declare an object

  ifstream fin;// ** declare any other necessary variables
  string file_name; //variable for file name input

   // ** get the input file and set the input stream
  do { 
    cout << "What is the name of the file: " ;

    cin >> file_name; //get user input

    fin.open(file_name.c_str()); //open file 

    if(!fin.is_open()) //if statement to see of file is open  
      {
	cout << "Wrong Name. Try again." << endl; //error message
      }
    
    else {

      Name.readNames(fin);  // ** call readNames with the stream

      Name.displayNames();  // ** call displayNames
    }
  } while (!fin.is_open()); //end of do while loop

  fin.close(); //close file

} // end of main

