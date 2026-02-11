// CS211 HW3 Implementation file for the stack class

// INSTRUCTION: Copy purple lines from the notes to complete this file.
// Do not do any cout except for displayAll

/* ----------------------------------------------
 Your name: *Ivan Ermakov*
 Implementation file for the stack class
 Compiler: g++
 ----------------------------------------------- */

// ** include appropriate files, including stack.h
#include "stack.h"
#include <iostream>
using namespace std;

// ** define all member fuctions below making sure they match stack.h
// ** provide appropriate comments PURPOSE & PARAMETERS above each function

// Constructor must initialize  to begin with.
stack::stack(){} // no need to initialize the array

// Destructor: do not leave garbage behind - until it is empty, pop(reuse existing functions)
stack::~stack(){}
                     

// PURPOSE: returns true if stack is empty if .size() == 0
// Parameters: No argument. Returns Boolean.
bool stack::isEmpty(){
  if(el.size() == 0){ //use .size() to check if empty
    return true;
  } else {
    return false;  //if it is not empty return false
    }
  }     
//PURPOSE: isFull should always be false because it is a vector
// Parameters: No argument. Returns Boolean.
bool stack::isFull(){
  return false; //always return false
   }
/*
® Style Note:  We should use other member functions instead of repeating its code.  Therefore, isFull and isEmpty are called below.  This way, the definitions of full and empty are isolated.
 */

// PURPOSE: push calls uses push_back  adds an element to vector el after incrementing top.
// Parameters: the element elem to be pushed
void stack::push(el_t elem){
  el.push_back(elem); //use push_back to push
}
//PURPOSE: pop calls isEmpty and if true, throws exception.
//Otherwise, removes an element from el and gives it back.
// Parameters: the popped element elem to be returned by reference
void stack::pop(el_t& elem){
  if (isEmpty()){
    throw Underflow(); //throw if it is empty 
    } else {
    elem = el.back(); //back() first to get the value of the last element
    el.pop_back(); //actually removes it from the vector 
  }
}

// PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
// Otherwise, diplays the elements vertically sandwiched between lines of dashes.
void stack::displayAll(){
  if (isEmpty()){ //call isEmpty func first
    cout << "[ isEmpty ]" << endl; 
  } else {
    for(int i = el.size() - 1; i >= 0; i--) //intiate i to be el.size() -1
      {
	cout << el[i];
      }
  }
  cout << endl;
}

