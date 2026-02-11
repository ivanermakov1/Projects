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

// Constructor must initialize top to be -1 to begin with.
stack::stack()
{ top = -1; } // no need to initialize the array

// Destructor does not have to do anything since this is a static array
// and it will get destroyed automatically when you leave its scope.
stack::~stack()
{ // nothing to do when using static memory
}

// PURPOSE: returns true if stack is empty else false (empty means top is -1)
// Parameters: No argument. Returns Boolean.
bool stack::isEmpty(){
  if (top == -1){
    return true;
  }else {
    return false;
  }
}     
//PURPOSE: isFull checks top and returns true if full, else false (full means top is MAX-1)
// Parameters: No argument. Returns Boolean.
bool stack::isFull(){
   if (top == MAX-1 ){
    return true;
   } else {
     return false;
   }
}
/*
® Style Note:  We should use other member functions instead of repeating its code.  Therefore, isFull and isEmpty are called below.  This way, the definitions of full and empty are isolated.
 */

// PURPOSE: push calls isFull and if true, throws exception.
// Otherwise, adds an element to el after incrementing top.
// Parameters: the element elem to be pushed
void stack::push(el_t elem){
  if (isFull()){
    throw Overflow();
   } else {
    el[++top] = elem;
  }
}
//PURPOSE: pop calls isEmpty and if true, throws exception.
//Otherwise, removes an element from el and gives it back.
// Parameters: the popped element elem to be returned by reference
void stack::pop(el_t& elem){
  if (isEmpty()){
    throw Underflow();
    } else {
    elem = el[top--];
  }
}

// PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
// Otherwise, diplays the elements vertically sandwiched between lines of dashes.
void stack::displayAll(){
  if (isEmpty()){
   cout << "[ isEmpty ]" << endl;
  } else {
    for(int i = top; i >= 0; i--)
      {
	cout << el[i] << endl;
      }
  }
}

