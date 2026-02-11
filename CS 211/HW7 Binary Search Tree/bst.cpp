// CS211 HW7 Binary Search Tree file 

// INSTRUCTION: create a binary search tree and traverse it

/* -------------------------------------------------
 Your name: *Ivan Ermakov*
 Client file to create a binary search tree
 Compiler: g++
 -------------------------------------------------- */

// ** include necessary files
#include<iostream>

using namespace std;

// ** Declare tnode here
struct tnode
{
  int Elem;
  tnode *Rchild;
  tnode *Lchild;
};

// displays elements in IN-ORDER (should come out sorted) using recursion
void traverse(tnode* V)
{
  if (V != NULL)
    {
      traverse(V -> Lchild); //go down the left until null
      cout << V -> Elem;
      traverse(V -> Rchild); //go down the right until null 
    }
  if (V == NULL)
    {
    return;
    }
}// end of traverse

// create a new node with element C and return a pointer to it
tnode* createNode(int C)
{
  tnode *Z = new tnode;
  Z -> Elem = C;
  Z -> Rchild = NULL; //Make sure left is NULL
  Z -> Lchild = NULL; //Make sure right is null
  return Z; //return the pointer to the node
  
}// end of CreateNode

// Build a binary search tree
int main()
{
  tnode* root = NULL; // no tree yet
  tnode* P;  // for going down the tree
  tnode* N;  // for the new node
  int x;
  char answer;
  // This will keep on getting elements from the user and add
  // to the tree in the right place

  // ** First set up the root with a new node (use CreateNode) 
  cout << "Element for the root: ";
  cin>> x;
  
  root = createNode(x); 

  // ** while the user wants to continue
  cout << "Continue? (Y/N upper case)";
  cin >> answer;
  
  while(answer != 'N')
    {
      // ** get an element and create a new node N with it
      cout << "Element: ";
      cin >> x;

      N = createNode(x);
      
      // ** go down the tree to add N to the right place 
      P = root; // P starts at the root

      
      while (P -> Lchild != N && P -> Rchild != N) //aslong as P'right child and P'left child are not assigned a nenode, aslong as you have not added a new node 
	{
	  if (P -> Elem  > N->Elem) //check to see if new node elem is smaller than P elem to go down left of tree 
	  {
	    if (P -> Lchild == NULL ) //P's left is NULL the new node should be added to P's left
	      {
		P -> Lchild = N; //new node added to P's left 
		cout << "left child of " << P -> Elem << endl;
		
	      }
	    else
	      {
		P = P -> Lchild; //since it is not null P is now pointing to P's left child
	      }
	  }
	  else if (P -> Elem < N->Elem) //check to see if new node elem is bigger than P elem to go down the right of tree 
	  {
	    if (P -> Rchild == NULL) //P's right is NULL the new node should be added to P's right
	      {
		P -> Rchild = N; //new node added to P's right
		cout << "right child of " << P -> Elem << endl;
		
	      }
	    else
	      {
		P = P -> Rchild; //since it is not NULL P is now pointing to P's right child
	      }
	  }

      }// end of while to go down

      // ** while the user wants to continue
      cout << "Continue? (Y/N upper case)";
      cin >> answer;

      
    }// finished the tree

  cout << "In the sorted order..." << endl;
  traverse(root); 
  cout << endl;
  
}//end of main
