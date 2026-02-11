// CS211 HW3 Tester client for the stack class

// INSTRUCTION: Must test each member function with do-while menu-switch and output
// easy to understand results;
// Type based on ** comments and do NOT delete the ** comments

/* ----------------------------------------------------
 Your name: *Ivan Ermakov*
 Test client file for HW3 to test the stack class
 Compiler: g++
 ------------------------------------------------- */

//** first, include the appropriate files, including stack
#include "stack.h"
#include <iostream>

using namespace std;
// The driver to test every member function 
int main()
{
  // ** declare a stack object first
  stack S; 
  
  int answer;   // user menu choice
  int integer; // user interger for push
  
  do {

    try
      {
	cout << " ---------- MENU --------- " << endl;
	cout << "1 call pop" << endl;
	cout << "2 call push" << endl; 
	cout << "3 call isEmpty" << endl;
	cout << "4 call isFull" << endl;
	cout << "5 call displayAll" << endl;
	cout << "0 to quit" << endl;
	
	cin >> answer;
	
	switch (answer)
	  {
	   // ** for pop and push, do not check isEmpty or isFull
	  case 1:
	    S.pop(answer); //call pop func
	    cout << "Element was popped" << endl;
	    break;
	  case 2:
	    cout << "Enter a interger to be added: ";
	    cin >> integer;
	    S.push(integer); //call the push func to get the input of user 
	    break;
	  case 3:
	    if(S.isEmpty()){ //call isEmpty func
		cout << "Stack is empty." << endl;
	      } else {
	      cout << "Stack has elements." << endl; //if false display message
	      }
	    break;
	  case 4:
	    if(S.isFull()){
	      cout << "Stack is full. " << endl; //call isFull func
	    } else {
	      cout << "Stack has more room" << endl; //if false display message 
	    }
	    break;
	  case 5:
	    S.displayAll(); //call display func
	    break;
	  case 0:
	    cout << "You have quit" << endl;
	    break;
	      
	    // ** note that for isEmpty and isFull, report the result
	    
	    
	  default: cout << "bad choice" << endl;
	  }// end of switch

      }//end of try
    // ** catches here to display error message for Overflow and Underflow
    //    but do not exit(1) so that you can continue

    catch(stack::Overflow)
      {cout<< "Stack has overflowed" << endl;}
    catch(stack::Underflow)
      {cout<< "Stack has underflowed" << endl;}
    
  } while ( answer != 0);

}// end of main

// Note that the end user will have to do 5 displayAll to see
// the result of pushing and popping each time UNLESS you do displayAll after switch.

