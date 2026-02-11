// CS211 HW3 Header file for the stack class

// PURPOSE: Learn the concept of a stack and be able to implement it

// INSTRUCTION: Copy the purple lines from the notes to complete this file

/* ------------------------------------------------
 Your name: *Ivan Ermakov*
 Header file for the stack class
 Compiler: g++
 --------------------------------------------------- */

// ** first include appropriate files
#include <iostream>
// ** declare 2 aliases, making sure it will be an integer stack
const int MAX = 10;
typedef int el_t;

// ** Must add appropriate comments, too
class stack
{
 private: // data members hidden from the client

  el_t el[MAX];
  int top;
  
 public:  // for the client to use
  // do not forget the exception classes for underflow and overflow!

  // no need to do topElem and clearIt
  // just constructor, destructor, isEmpty, isFull, push, pop, displayAll

  // Exception Classes that the client can throw
   class Overflow{};
   class Underflow{};

//  Constructor 
    stack();
//  Destructor
    ~stack();

// HOW TO CALL: No argument. Returns Boolean.
// PURPOSE: returns true if stack is empty else false
    bool isEmpty ();

// HOW TO CALL: No argument. Returns Boolean.
// PURPOSE: returns true if stack is full else false
    bool isFull ();

// HOW TO CALL: Provide the element to be pushed as an argument.
// PURPOSE: if full, calls an emergency exit routine
//  if not full, enters an element at the top
    void  push (el_t);

// HOW TO CALL: Gives back the removed element via pass by reference.
// PURPOSE: if empty calls an emergency exit routine
//  if not empty, removes an element from the top
    void   pop  (el_t&);
// HOW TO CALL: No argument
// PURPOSE: to display the stack vertically from the top to the bottom
    void displayAll();
 
};
