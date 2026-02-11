// EC: Postfix Calculator Using a Stack

// Your Name:
//--------------------------------------

//Complete this program based on comments

using namespace std;

#include <iostream>
#include <string>
#include "stack.h"
#include <stdlib.h>


//Purpose of the program: Evaluate stack expressions in postfix notation
//Algorithm: Takes user input postfix expression and pushes integers onto the stack, pop when operator is read.
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression

  cout << "type a postfix expression: ";
  cin >> expression;

  int i = 0;  // character position within expression
  char item;  // one char out of the expression

  int box1;  // receive things from pop
  int box2;  // receive things from pop

  int result = 0; //integer to hold result of operations

  while (expression[i] != '\0') // this is a char
    {
      try
	{
	  item = expression[i]  ;  // current char

	  //2.  if it is an operand (number), 
	  //    push it (you might get Overflow exception)
          //    Note that item must be converted into int (item - '0')
          if ( item - '0' >= 0 && item - '0' <= 9 )
	    {
	      postfixstack.push(item - '0');
	    }
	    
	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //    apply the operator to the two operands, and
	  //    push the result.

	  else if ((item == '+') || (item == '-') || (item == '*'))
	    {
	      postfixstack.pop(box1);
	      postfixstack.pop(box2);
	      //cases for different operators follow:

	      if (item == '-')
		{
	          result = box1 - box2; //do - because it is the - operator 
		  postfixstack.push(result); //then push it into the stack
		}
	      else if (item == '+')
		{
                  result = box1 + box2; //do + because it is the + operator 
		  postfixstack.push(result); //then push it into the stack 
		}
	      else
		{
		  result = box1 * box2; //do * because it is the * operator 
		  postfixstack.push(result); //then push it into the stack 
		}
	    }
	  else throw "invalid item";
	  cout << "STACK" << endl;
          postfixstack.displayAll();
	  cout << "--------------" << endl;
	} // this closes try

      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow)
	{
	  cout << "Overflow. Too many operands." << endl;
	  exit(1);
	}
      catch (stack::Underflow) // for too few operands
	{
	  cout << "Underflow. Too few operands." << endl;
	  exit(1);
	}
      catch (char const* errorcode) // for invalid item
	{
	  cout << "Invalid items detected." << endl;
	  exit(1);
	}
      // go back to the loop after incrementing i
      i++;
    }// end of while

  // After the loop successfully completes: 
  // ** The result will be at the top of the stack. Pop it and show it.
  cout << "This is the result: " << endl;
  cout << result << endl; //cout result 
  postfixstack.pop(result); //then pop it
  // If anything is left on the stack, an incomplete expression was found.
  // ** Inform the user.
  if ( !postfixstack.isEmpty()) { //call func isEmpty to check if stack is not empty
	cout << "was an incomplete experssion though" << endl;
  }
}// end of the program
