// First complete this program and then change it to use a set "0" .. "9"
// with queue size of 100

#include <iostream>
#include <string>
#include "queue.h"
using namespace std;

// Generates all strings made up of A, B, and C
int main()
{
  queue abcqueue;  // string queue

  abcqueue.add("0");
  abcqueue.add("1");
  abcqueue.add("2");
  abcqueue.add("3");
  abcqueue.add("4");
  abcqueue.add("5");
  abcqueue.add("6");
  abcqueue.add("7");
  abcqueue.add("8");
  abcqueue.add("9");

  while (true)
    {
    try
      {
	string item;
	abcqueue.remove(item); // remove
	//abcqueue.displayAll(); // display it
	cout << item << endl; 

	// Stop after 000
        if(item == "000") {
	  cout << "Cannot add" << endl;
	  break;  // exit the while loop
        }


	if(item.length() < 3) //only does 2 digit combinations until 000
	{ 
	abcqueue.add(item + "0"); //add item + "0"
	abcqueue.add(item + "1"); //add item + "1"
	abcqueue.add(item + "2"); //add item + "2"
	abcqueue.add(item + "3"); //add item + ...
	abcqueue.add(item + "4");
	abcqueue.add(item + "5");
	abcqueue.add(item + "6");
	abcqueue.add(item + "7");
	abcqueue.add(item + "8");
	abcqueue.add(item + "9");
	}
	
      }
    // Catch exceptions and report problems and quit the program now. 
    catch (queue::Overflow)
      {cerr << "Cannot add" << endl; exit(1);  }
    catch (queue::Underflow)
      { cerr << "Cannot delete" << endl; exit(1); }

    }// end of while
}
