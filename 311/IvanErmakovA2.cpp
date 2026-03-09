#include <iostream>

using namespace std;

/* Loop
1. Find minimum dancing time of all the cows on stage. (T)
2. Remove the cow & update the remaining time of other dancing cows
3. De-queue & put the next cow on stage 
*/

//create queue struct
struct Queue
{

    //creates a dynamic array for the cow dancing times
    int* cows =  new int[10000];  

    int front = 0;      //front starts at 0 start at the index
    int rear = -1;      //rear - 1 because the queue is empty at start
    
    //returns true if queue is empty
    bool isEmpty()
    {  
        //at start front should be bigger than rear
        if(front > rear)
        {
            return true;
        }
        //if rear becomes bigger than front the queue is not empty
        else 
        {
            return false;
        }
    }      
    
    //adds element to the back of the queue
    void enQueue(int value)
    {
        rear++;                 //move rear forward
        cows[rear] = value;     //store new value 
    }     

    //remove element the front of the queue 
    int deQueue()
    {
        
        //check if it is empty first
        if(isEmpty())
        {
            return 1;
        }
        else 
        {
            int value = cows[front];    //get the front value 
            front++;                    //move front forward
            return value;               //return removed value
        }
    }

};


int main() 
{

    //create Queue object 
    Queue Q;    //this is the queue to hold the waiting cows

    int n;      //cows in the herd 
    int k;      //number of cows that can dance on the stage at the same time 

    cin >> n;   //grab the number of cows from user
    cin >> k;   //grab the number of the stage size 
 
    //create a dynamic array for the stage, each slot holds the remaing dancing time of the cow
    int* stage = new int[k];  

    /*
    loop to give each cow a time
    first k cows go directly to stage
    remaining cows go into the queue
    */
    for(int i = 0; i < n; i++)
    {
        int value;          
        cin >> value;       //grab dancing time

        //if i is less than k, k is the stage size it, the cows can go straight to the stage
        if(i < k)
        {
            stage[i] = value;       //goes directly on stage
        }
        //the extra cows will be stored in the queue 
        else
        {
            Q.enQueue(value);       //goes into the queue 
        }
    }

    //counter to track how many cows have finished dancing
    int cowsdonedancing = 0;    
    //counter to track the total time the cows have danced on stage
    int t = 0;

    //outer loop continues until the counter is != n, to keep going until all n cows have finished dancing
    while(cowsdonedancing != n) 
    {

        //inner loop to find the minimum value in the stage array
        //int mintime - variable to hold the minimun dancing time
        int mintime = stage[0];     //assume the first index is the min dancing time 
        for(int i = 0; i < k; i++)      //loop through the stage k times
        {
            //check to see if there is a cow if shorter dancing time
            if(stage[i] < mintime)  
            {
                mintime = stage[i];     //found a cow that is finishes dancing sooner
            }
        }

        //add mintime to t
        t += mintime;

        //loop to subtract the mintime from all the cows on the stage 
        for(int i = 0; i < k; i++)
        {
            stage[i] -= mintime; 
        }

        /*
        1. loop to find the cows that have a dancing time of 0 since they will be done dancing
        2. if there is a cow with time 0 we need to remove them and replace them with the next cow from the queue
        */
       for(int i = 0; i < k; i ++)
       {

            if(stage[i] == 0)
            {
                cowsdonedancing++;      //one more cow finished dancing
                
                //replace the finished cow with the next one from the queue
                //check if there are remainging cows in the queue before replacing
                if(!Q.isEmpty())
                {
                    stage[i] = Q.deQueue();      //bring the next cow on stage, deQueue will return the value of the cow and put its dancing time on stage
                }
                else    //no cows left waiting, make the number 1000001 so the slot never gets picked as the minimum time 
                {
                    stage[i] = 100001;
                }
            }
       }
    }

    cout << t;      //output the time

    //delete the dynamic arrays to free up allocated memory
    delete[] Q.cows;
    delete[] stage;

    return 0;
}