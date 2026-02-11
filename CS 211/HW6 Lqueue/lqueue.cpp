// CS211 HW6P2 Linked List Queue Implementation File (Hidden from the client)

// INSTRUCTION: Complete all functions based on Week10-11 notes

/* -------------------------------------------------
 Your name: *Ivan Ermakov*
 Implementation file for the lqueue class
 Compiler: g++
 ---------------------------------------------------- */
// ** include all appropriate files

#include "lqueue.h"
#include<iostream>

using namespace std;

// ** Make sure all required comments are provided (every if-then-else
// and local variable purposes, too) in each function

lqueue::lqueue()
{ // initialize Front and Rear (for an empty  case)
  Front = NULL;
  Rear = NULL;
}

lqueue::~lqueue()
{
// ** Don't forget that the descructor must destroy the object by calling deleteFront until the list is empty.
// ** Put a cout at the start of the destructor so that you can be sure
// that it got called!
  cout << "calling destructor.... " << endl;
  
  while (!isEmpty())
    {
      el_t X; //local variable to hold the deleted element 
      deleteFront( X );
    }

}

//PURPOSE: Check if the queue is empty
bool lqueue::isEmpty()
{
  if(Front == NULL && Rear == NULL){ //if both Front and Rear are Null it is empty
    return true;
  }
  else {
    return false;
  }
}


//PURPOSE: add a element to the rear of the queue
//PARAMETERS: el_t Elem which is the element being added to the queue
void lqueue::addRear(el_t Elem)
{if ( isEmpty() )// special case for the first node
    {  // create the first node
      Rear = new Node;
      Front = Rear; //front and rear point to the same node because queue empty
    }  
  else // regular case for other nodes
    {  // as in Notes-10B
      Rear -> Next = new Node; //make a new node after current rear
      Rear = Rear -> Next;  //then move rear pointer to the new node
    }
  Rear->Next = NULL; //make sure new node doesn't point to anything 
  Rear -> Elem = Elem; //Store the element into rear node
  
  cout << Rear->Elem << endl; //show what was added
// make sure the rear->next is NULL
}//end of addRear  

//PURPOSE: remove and return the element that is at the front of queue
//PARAMETERS: el_t& Elem because Elem will receive the value that is removed
void lqueue::deleteFront(el_t& Elem)
{
  if ( isEmpty() )// empty case
    {
      throw Underflow(); //if it is empty throw Underflow 
    }
  else if ( Front == Rear  ) // only one node
    {
      Elem = Front -> Elem; //save the value being removed 
      delete Front;  // Delete Front node
      Front = NULL;  // Reset pointers because queue is empty
      Rear = NULL;
    }
  else // regular case
    {
      Node *Second; //create a new pointer 
      Second = Front -> Next; //second now points to the node after front 
      Elem = Front -> Elem; //save the value being removed
      delete Front; //delete old Front 
      Front = Second; //now front is pointing to the next node
    }// as in Notes-11 
}// end of deleteFront

// PURPOSE: display all elemts in the queue 
// PARAMETERS: 
void lqueue::displayAll()
{ if ( isEmpty() ) // empty [ empty ]
    {
      cout << "[ empty ]";
      return;
    }
  // use a while loop to go through the entire list and display horizontally in [ ]
    // e.g. [ 2 3 4]

  Node *P = Front; //point to the front of the loop to start
  cout << " [ "; 
  while ( P != NULL) //makes sure we go to the end of queue
    {
      cout << P -> Elem << " "; //cout the element that P is poiting too 
      P = P -> Next; //go to the next node 
    }
  cout << " ] ";
}//enf of displayAll


