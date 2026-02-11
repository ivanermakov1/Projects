#include<iostream>

using namespace std;

//create a struct for the node of the linked list
struct Node
{  
    int Elem;       //variable to store the element of the node 
    Node *Next;     //pointer to the next node in the linked list 
};

int main()
{

    Node *Front = NULL;     //pointer that points to the front node
    Node *Rear = NULL;      //poinrer that points to the rear node

    int sizeLinkedList;     //variable for the size of the linked list

    cin >> sizeLinkedList;  //collect input


    //loop to collect number for the linked list
    for(int i = 0; i < sizeLinkedList; i++)
    {
        int number;         //varaible to store the number inputed by the user
        cin >> number;      //collect input

        Node *tmp = new Node;    //create a new node
        tmp->Elem = number;      //store the number in the node
        tmp->Next = NULL;        //set the next pointer to null

        if(Rear == NULL)        //if the rear is null that means the linked list is empty so we have to set the front and rear node to the new node 
        {
            Front = tmp;        //set the front to the new node
            Rear = tmp;         //set the rear to the new node
        }
        else                    
        {
            Rear->Next = tmp;   //connect the rear node to the new node
            Rear = tmp;         //update the rear to point to the new node
        }
    }

    Node *current = Front;     //pointer to traverse the linked list starting from the front

    
    //create a while loop to traverse the linked list and print the elemets
    while(current != NULL)    //loop until we reach the end of the linked list we know we reach the end when current is NULL
    {
        cout << current->Elem << " ";   //print the element of the current node
        current = current->Next;        //move to the next node
    }
    
    Node *current2 = Front;    //pointer to traverse the linked list which starts at the front
    Node *prev = NULL;         //pointer to keep track of the previous node which starts at null because we are at the front 

    //outer while loop to traverse each node in the linked list
    while(current2 != NULL)         //loop until we reach the end of the linked list
    {
        Node *check = Front;        //pointer to check for duplicates starting at the front node
        bool duplicate = false;     //bool to keep track whether we found a duplicate or not it is false at the start since there is no duplicate yet

        //inner while loop to check for duplicates by checking previous nodes in the linked list
        while(check != current2)    //loop until we reach the current node
        {
            if(check -> Elem == current2 -> Elem)   //check if the element of the check node is equal to the element of the current2 node
            {
                duplicate = true;   //if they are equal that means we found a duplicate = true
                break;              //break to avoid going further 
            }
            check = check -> Next;  //move the check pointer to the next node to keep checing for duplicates 
        }

        if(duplicate)               //if we found a duplicate we have to remove current2 node
        {
            if(current2 == Front)   //if the current2 node is the front node we have to update 
            {
                Front = current2 -> Next;    //update the front to be the next nodeof current2 to remove the current2 node from the linked list 
            }
            else 
            {
                prev -> Next = current2 -> Next;    //if the current2 node is not the front node we have to update the previous node to point to the next node of current2 to remove current2 from the linked list
            }
        }
        else
        {
            prev = current2;        //if we did not find a duplicate we have to update the previous node to be the current2 node
        }

        current2 = current2 -> Next;    //move the current2 pointer to the next node to keep traversing the linked list
    }

    cout << endl;

    current2 = Front;       //reset the current2 pointer to the fron to traverse the linked list to print out after removing duplicates 

    //loop to traverse the linked list and print the elements
    while(current2 != NULL)   //loop until we reach the end of the linked list
    {
        cout << current2 -> Elem << " ";    //print the element of the current2 node
        current2 = current2 -> Next;        //set the current2 pointer to the next to keep traversing 
    }

    //need 3 pointer to reverse the linked list
    Node *current3 = Front;    //pointer to traverse the linked list starting at the front
    Node *prev2 = NULL;        //pointer to keep track of the previous node starting at null because we are at the front
    Node *next = NULL;         //pointer to keep track of the next node starting at null

    //loop to revese the linked list
    while(current3 != NULL)    //loop until we reach the end of the linked list
    {
        next = current3 -> Next;    //save the next node in the next pointer before we change it 
        current3 -> Next = prev2;    //reverse the current3 node to point to the previous node 
        prev2 = current3;            //move prev2 forward to be the current3 node
        current3 = next;            //move current3 forward to be the next node which we saved before 
    }

    Front = prev2;       //update front to point to the new first node 

    cout << endl;

    current3 = Front;    //reset current3 to the front to traverse the linked list to print out after reversing

    //loop to traverse the linked list and print the elements
    while(current3 != NULL)
    {
        cout << current3 -> Elem << " ";    //print the element of the current3 node
        current3 = current3 -> Next;        //move the current3 pointer to the next to keep traversing
    }

    cout << endl;

    return 0;
}