// CS211 HW6P2 Linked List Queue Client File 

// INSTRUCTION: Complete all cases based on the comments

/* -------------------------------------------------
 Your name: **
 Client file to test the lqueue class
 Compiler: g++
 -------------------------------------------------- */ 

// ** include all appropriate files
#include "lqueue.h"
#include<iostream>

using namespace std;
// You may handle both Cases in one main()
int main()
{

    
  int X; // local variable
  
  // Case1 lines here ------------------
  cout << "....Starting case 1..." << endl;
  
  // Declare L.
  lqueue L;

     //1.check empty and report the result
     if (L.isEmpty()) cout << "Empty." << endl; else cout << "Not empty." << endl;

     // 2.display the empty queue
     L.displayAll();
     cout << endl;

     // 3.add 3 integers 1, 2, 3
     L.addRear(1); L.addRear(2);L.addRear(3);

     // 4.remove twice (indicate the elements removed)
     L.deleteFront(X); cout << "removed " << X << endl;    // X is a local variable
     L.deleteFront(X); cout << "removed " << X << endl;    // X is a local variable

     // 5.display the queue again (one element)
     L.displayAll();
     cout << endl;

     // 6.check empty again and report the result
     if (L.isEmpty()){ cout << "Empty." << endl;}
       else cout << "Not empty." << endl;

     cout << endl;
     
     // Case 2 lines here ------------------
     cout << "....Starting case 2..." << endl;
     
     //7.remove again (indicate the element removed)
     L.deleteFront(X); cout << "removed " << X << endl;

     // 8.check empty again and report the result
     if (L.isEmpty()){cout << "Empty." << endl;}
     else{ cout << "Not empty." << endl;}

     //Declare L2.
     lqueue L2;

     //1.display the queue which is empty
     L2.displayAll();
     cout << endl;

     //2.immediately try to remove (this should fail as Underflow in a catch statement)
     try {
     L2.deleteFront(X);
     }
     catch (lqueue::Underflow)
       {
	 cerr << "Underflow." << endl;
       }
     cout << endl;

     // Case 3 lines here (these are your own test cases) -------
     cout << "....Starting case 3..." << endl;
     
	  
  // ** comment each step as I did above
  //  make sure every if-then-else in lqueue.cpp got tested and different orders of
  // calling functions are tested.
  
     //Declare L3
     lqueue L3;

     //1. Display emmty queue
     L3.displayAll();
     cout << endl;
     
     //2. Add 4 integers: 6 7 8 9
     L3.addRear(6);
     L3.addRear(7);
     L3.addRear(8);
     L3.addRear(9);

     //3. Display it now after adding
     L3.displayAll();
     cout << endl;
     
     //4. Remove once for regular case
     L3.deleteFront(X);
     cout << "removed " << X << endl;

     //5. Display it after deleting
     L3.displayAll();
     cout << endl;

     //6. Remove 2 elements
     L3.deleteFront(X);
     cout << "removed " << X << endl;

     L3.deleteFront(X);
     cout << "removed " << X << endl;

     //7.  Add 10 to see if it gets added to rear
     L3.addRear(10);
     cout << endl;

     //8. display to see 10 added
     L3.displayAll();
     cout << endl;
     
     //9. Delete one more time
     L3.deleteFront(X);
     cout << "removed " << X << endl;

     //10. Display since there should only be 1 element
     L3.displayAll();
     cout << endl;

     //11. Remove the last element for a one node case
     L3.deleteFront(X);
     cout << "removed " << X << endl;

     //12. Should be empty after removing so check empty
     if (L3.isEmpty()) cout << "Empty." << endl;
     else cout << "Not empty." << endl;

     //13. remove again to cause Underflow
     try
       {
	 L3.deleteFront(X);
       }
     catch (lqueue::Underflow)
       {
	 cerr << "Underflow." << endl;
       }

     cout << endl;
     
}// end of main
