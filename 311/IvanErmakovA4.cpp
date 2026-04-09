#include <iostream>

using namespace std;

class Node
{
    public:

    int key;                //data for the node
    struct Node* left;      //pointer to the left subtree 
    struct Node* right;     //pointer to the right subtree
    int height;             //height of the node

    //constructor for the node class
    Node(int data)
    {
        key = data;          //initialize the key with the data input
        height = 0;          //initialize the height to 0
        left = right = NULL; //initialize the left and right pointers to NULL
    }
};

class AVLTree
{
    public:

    Node* root;              //pointer to the root of the AVL tree

    //helper functions 

    //function to get the max of two integers so we can use it to update the height of a node after insetion or deletion 
    int max(int a, int b);

    //function to get the height of a node
    //Node* node is the input parameter for the node we want to get the height of 
    int height(Node* node);

    //funnction to get the balace factor of Node N
    //Node* N is the input parameter for the node we want to get the balance factor of
    int getBalance(Node* N);

    //function to output the tree in preorder traversal
    //Node* root is the input parameter for the node we want to start the preorder traversal from, usually the root
    void preOrder(Node* root);


    //rotation functions for the AVL tree

    //Node* z is the input parameter for the node we want to perform the rotation on, usually the node that is unbalanced after insertion or deletion
    Node* rightRotate(Node* z);     //function for right rotation
    Node* leftRotate(Node* z);      //function for left rotation

    //constructor for the AVL tree class
    AVLTree()
    {
        root = NULL;          //initialize the root to NULL, start with an empty tree
    }
};

    //function to get the max of two integers so we can use it to update the height of a node after insetion or deletion 
    int max(int a, int b)
    {
        return (a > b) ? a : b;     //return the maximum of a and b using the ternary operator
    }

    //function to get the height of a node
    //Node* node is the input parameter for the node we want to get the height of 
    int height(Node* node)         
    {
        if(node == NULL)        //if the node is NULL that means we are at a leaf node or the tree is empty
        {
            return -1;          //return -1 to indicate that the height of is -1 for NULL nodes
        }
        return node->height;    //return the height of the node
    }    

    //funnction to get the balace factor of Node N
    //Node* N is the input parameter for the node we want to get the balance factor of
    int getBalance(Node* N)
    {
        if(N == NULL)   //if the node is NULL that means we are at a leaf node or the tree is empty
        {
            return 0;
        }
        return height(N->left) - height(N->right);     //return the balance factor by subtracting the height of the right subtree from the height of the left subtree
    }

    //function to output the tree in preorder traversal
    //Node* root is the input parameter for the node we want to start the preorder traversal from, usually the root
    void preOrder(Node* root)
    {
        if(root == NULL)        //if the node is NULL that means we are at a leaf node or the tree is empty
        {
            return;             //return to stop the recursion when we reach a NULL node
        }

        static bool first = true;   //static variable to keep track of whether we are printing the first key or not, initialized to true at the start 
        if(!first)                  //if it's not the first key being printed, we want to print a space before the key to separate it from the previous key
        {
            cout << " ";            //print a space before the key if it's not the first key being printed
        }
        first = false;              //set first to false after printing the first key

        cout << root->key;          //print the key of the current node
        preOrder(root->left);       //recursively call preOrder on the left subtree
        preOrder(root->right);      //recursively call preOrder on the right subtree
    }

    //function for left rotation
    //Node* z is the input parameter for the node we want to perform the rotation on
    Node* leftRotate(Node* z)
    {
        Node *y = z->right;         //y is the right child of z, which will become the new root of the subtree after the left rotation
        Node *T2 = y->left;         //T2 is the left child of y, which will become the right child of z after the left rotation

        //perform rotation
        y->left = z;               //make z the left child of y
        z->right = T2;             //make T2 the right child of z

        //update heights after rotation
        z->height = max(height(z->left), height(z->right)) + 1;     //update the height of z by taking the maximum of the heights of its left and right subtrees and adding 1 for the current node
        y->height = max(height(y->left), height(y->right)) + 1;     //update the height of y by taking the maximum of the heights of its left and right subtrees and adding 1 for the current node  
        
        //return the new root of the subtree after the left rotation, which is y
        return y;
    }

    //function for right rotation
    //Node* z is the input parameter for the node we want to perform the rotation on
    Node* rightRotate(Node* z)
    {
        Node *y = z->left;          //y is the left child of z, which will become the new root of the subtree after the right rotation
        Node *T3 = y->right;        //T3 is the right child of y, which will become the left child of z after the right rotation

        //perform rotation
        y->right = z;              //make z the right child of y
        z->left = T3;              //make T3 the left child of z

        //update heights after rotation
        z->height = max(height(z->left), height(z->right)) + 1;     //update the height of z by taking the maximum of the heights of its left and right subtrees and adding 1 for the current node
        y->height = max(height(y->left), height(y->right)) + 1;     //update the height of y by taking the maximum of the heights of its left and right subtrees and adding 1 for the current node  
        
        //return the new root of the subtree after the right rotation, which is y
        return y;
    }



int main()
{


    return 0;
}