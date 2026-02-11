#include<iostream> 

using namespace std;

int main()
{
    int sizeArray;               //varaible for the size of the array

    
    cin >> sizeArray;            //collect input
    
    int incArray[sizeArray];     //create the array with 10 elements for now 

    

    for(int i = 0; i < sizeArray; i++)      //loop to collect number for the array
    {
        cin >> incArray[i];                 //input the numbers into the array
    }


    int minNum = 0;              //count for minimun number of moves to make it ascending order

    for(int i = 0; i < sizeArray - 1; i ++)     //loop through the array to check but using sizeArray - 1 to avoid out of bounds error when checking since we are using i + 1
    {
        if(incArray[i + 1] < incArray[i])       //checks whether the next number in the array is smaller than the previous
        {
            minNum += incArray[i] - incArray[i + 1];        //minus the previous index by the next to update the count 
            incArray[i + 1] = incArray[i];                  //update the next index to be the same as previous inddex to maake it ascending ordeer
        }
    }

    cout << minNum << endl;
    
    return 0;
}