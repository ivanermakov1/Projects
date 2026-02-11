// CS211 HW4 Tester client for the queue class

// INSTRUCTION: Must test each member function with do-while menu-switch and output
// easy to understand results

/* -----------------------------------------------------
 Your name: *Ivan Ermakov*
 Test client for the queue class
 Compiler: g++
 ------------------------------------------------------- */

// ** include appropriate files
#include "queue.h"
#include <iostream>

using namespace std;

// The driver to test every member function 
int main()
{
  // ** declare a queue object first
  queue q;
  
  int answer;   // user menu choice
  string string; //user string for add 
  do {

    try
      {
	cout << " ---------- MENU --------- " << endl;
	cout << "1 call remove" << endl;
	cout << "2 call add" << endl; 
	cout << "3 call isEmpty" << endl;
	cout << "4 call isFull" << endl;
	cout << "5 call displayAll" << endl;
	cout << "0 to quit" << endl;
	
	cin >> answer;
	
	switch (answer)
	  {
	    // ** do case 1 and case 2 without checking isEmpty or isFull
	  case 1:
	    q.remove(string); //call remove func
	    cout << string <<  " has been removed." << endl; //cout the string being removed 
	    break;
	  case 2:
	    cout << "Enter a string to be added: "; //prompt the user to enter a string
	    cin >> string;
	    q.add(string); //call add func
	    break;
      
	    // ** note that for isEmpty and isFull, report the result

	  case 3:
	    if(q.isEmpty()){ //call the isEmpty func if user chooses 3
	      cout << "Queue is empty right now." << endl;
	    } else {
	      cout << "Queue has some elements." << endl; //if it is not empty give message
	    }
	    break;
	  case 4:
	    if(q.isFull()){ //call  the isFull func if user chooses 4
	      cout << "Queue is full right now." << endl;
	    } else {
	      cout << "Queue has more room." << endl; //if it is not full give message
	    }
	    break;
	  case 5:
	    q.displayAll(); //call displayAll func if user chooses 5
	    break;
	  case 0:
	    cout << "You have quit." << endl;
	    break;
	    
	  default: cout << "bad choice" << endl;
	  }// end of switch

      }//end of try
    // ** catches here to display error message but do not exit(1)
    catch(queue::Underflow)
      {cout << "Queue has underflowed" << endl;}
    catch(queue::Overflow)
      {cout << "Queue has overflowed" << endl;} 
	
  } while ( answer != 0);

} //end of main

// Note that the end user will have to do 5 displayAll to see
// the result of adding and removing each time.

