#include <iostream>

using namespace std;


struct Node
{
    int Elem;
    Node *Next;
};

class Queue
{
    private:
        Node *Front;    //pointer to the front node of the queue
        Node *Rear;     //pointer to the rear node of the queue
        int size;       //variable to keep track of the size of the queue

    public:
    

    void enQueue(int);  //function to add an element to the rear of the queue

    void deQueue();     //function to remove an element from the front of the queue

    void getHead();     //function to get the element at the front of the queue

    void isEmpty();     //function to check if the queue is empty

    int getsize();      //function to get the size of the queue
};

