// CS211 HW6P2 Linked List Queue Header File 

// PURPOSE: to learn the concept of linked list in dynamic memory 
//          and to be able to handle pointers

// INSTRUCTION: Complete ** based on Week10 notes

/* -------------------------------------------------
 Your name: *Ivan Ermakov*
 Header file for the lqueue class
 Compiler: g++
 ---------------------------------------------------- */

// ** anything to #include?
#ifndef LQUEUE_H
#define LQUEUE_H

#include<iostream>

using namespace std;
// ** declare el_t for the element type to be int for now

typedef int el_t;

// ** declare struct Node here

struct Node
{
  el_t Elem; //elem that stores the value of the user 
  Node    *Next;  //pointer that points to the next node 
};


class lqueue
{
private: // data members from the client
  Node *Front;
  Node *Rear;


 public: // available to the client

  class Underflow{};   // exception

// ** be sure to add appropriate comments below for each prototype
//    to help the client call these functions:  PURPOSE and HOW TO CALL

  lqueue();
  ~lqueue();
  
  bool isEmpty(); //check if the queue is empty 

  void addRear(el_t); //adds element to the rear and type the element in the () that you want to add 

  void deleteFront(el_t&); //deletes the front element in the queue and returns the element inside the node 

  void displayAll(); //displays the queue 
  
};

#endif 
