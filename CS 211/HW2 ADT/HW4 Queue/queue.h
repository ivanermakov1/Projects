// CS211 HW4 Header file for queue class

// PURPOSE: Learn the concept of a queue and be able to implement it using
// an array without wasting space by wrapping around.

// INSTRUCTION: Use the purple lines from the notes to complete this file

/* ----------------------------------------------
 Your name: *Ivan Ermakov*
 Header file for the queue class
 Compiler: g++
---------------------------------------------------- */

// ** include appropriate file
#include<iostream>
using namespace std;

// ** declare aliases, making sure it will be a string queue
typedef string el_t; //el_t is an alias for string 
const int MAX = 10; //max is alias for the max number of elements

// ** be sure to add appropriate comments
class queue
{
 private: // data members hidden from the client

  el_t el[MAX]; //a string array called el
  int  count;   // how many elements do we have right now? (0 – MAX)
  int  front;   // where the front element of the queue is.
  int  rear;    // where the rear element of the queue is.


 public: // available to the client
  // do not forget the exception classes for Underflow and Overflow
  // Functions are: constructor, destructor, isEmpty, isFull, add, remove, displayAll

  class Overflow{};
  class Underflow{};
  
  // constructor 
  queue(); 

  //destructor 
  ~queue();

  // HOW TO CALL: No argument. Returns Boolean.
  // PURPOSE: returns true if queue is empty, otherwise false
  bool isEmpty();

  // HOW TO CALL:  No argument. Returns Boolean.
  //  PURPOSE: returns true if queue is full, otherwise false
  bool isFull();

  // HOW TO CALL: Provide the element to be added as an argument.   
  // PURPOSE: if full, throw Overflow
  // if not full, enters an element at the rear 
  void add(el_t);

  // HOW TO CALL: Gives back the removed element via pass by reference. 
  // PURPOSE: if empty, throw Underflow
  // if not empty, removes the front element to give it back via pass by reference
  void remove(el_t&);

  // HOW TO CALL: No argument. Returns nothing.
  //PURPOSE: display everything in the queue from front to rear horizontally enclosed in []
  //if empty, displays [ empty ]
  void displayAll();

};
