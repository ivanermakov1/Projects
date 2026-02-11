// CS211 HW4 Implementation file for the queue class (Hidden from the client)

// INSTRUCTION: Be sure to use the code from the Notes.

/* ----------------------------------------------
 Your name: *Ivan Ermakov*
 Implementation file for the queue class
 Compiler: g++
---------------------------------------------------- */

// ** include appropriate files including "queue.h"
#include "queue.h"
#include <iostream>

using namespace std;
// ** define all memeber functions matching queue.h
// and add good comments PURPOSE & PARAMETER

// constructor 
queue::queue()
{
  count = 0; //count is 0 at start
  front = 0; //front starts at 0 
  rear = -1; //rear starts at -1 because the queue is empty 
}

//destructor 
queue::~queue()
{
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
  if (count == 0) //if count is 0 return true
  return true;
  else
    return false;
}

//  PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
  if(count == MAX) //if count has reached its max return true
    return true;
  else
    return false;
}

// PURPOSE: if full, throw Overflow
// if not full, enters an element at the rear (wraps around)
void queue::add(el_t elem)
{
  if(isFull()) { //call the isFull func to see if we can add
    throw Overflow(); //if it is full throw Overflow
    } else {
    rear = (rear + 1) % MAX; //move rear to the next postion and wraps around using % MAx
      el[rear] = elem; //store element at the back/rear of the queue
      count++; //inc count since we are adding 
   }
  /*
  cout << "Front = " <<" " << front <<
      " Rear = " << " " <<  rear  << " Count = " << " " << count << endl;
  */
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back via pass by reference
// Wraps around
void queue::remove(el_t& elem)
{
  if(isEmpty()) { //call the isEmpty function to check if we can remove
    throw Underflow(); //throw Underflow if it is empty
  } else {
    elem = el[front]; //store the element at the front of the queue
    front = (front + 1) % MAX; //move front to the next position and wrap around using % MAX
    count --; //dec count since we are removing 
  }

  /*
  cout << "Front = " <<" " << front <<
    " Rear = " << " " <<  rear  << " Count = " << " " << count << endl;  
  */
}

//PURPOSE: display everything in the queue from front to rear horizontally enclosed in []
//if empty, displays [ empty ]
void queue::displayAll()
{
  if(isEmpty()){ //call the isEmpty function to see if there is anything to display 
    cout << "[ isEmpty ]" << endl;
  } else {
    cout << "[ ";

    int i = front; //make i the front 

    while(true){ //loop until we hit the rear 
      cout << el[i] << " "; //cout the elements in the queue
      if(i == rear){ //checks if we hit the end of the queue if it is = rear 
	break;
      }
      i = (i+1) % MAX; //moves to the next index and wraps using % MAX
    }

    cout << " ] ";
  }
  cout << endl;
  
  cout << "Front = " << front << " Rear = " << rear  << " Count = " << count << endl;
  
}



// ** For displayAll, cout Front, Rear and Count just for this HW
//    so that it is easy for you to see how the queue is wrapping around.




