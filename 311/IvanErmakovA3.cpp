#include<iostream>
#include<array>
#include<algorithm>

using namespace std;

//Function prototypes (declarations)
void selectionSort(int array[], int size);
void bubbleSort(int array[], int size);
void insertionSort(int array[], int size);
void quickSort(int array[], int left, int right);
int quickPartition(int array[], int left, int right);
void mergeSort(int array[], int left, int right);
void mergeHelper(int array[], int left, int mid, int right);


/*
1.find the largest element and swap it with the right most element
2.look at remaining elements
3. repeat process
*/
void selectionSort(int array[], int size)
{

    /*
    create outer loop to go through the array
    i starts at size - 1 for the last element
    i-- to decrement down to the next last element
    */
    for(int i = size - 1; i > 0; i--)
    {
        int largestIndex = 0;        //index of the largest element, starts at 0 

        //create inner loop to find the largest element
        for(int j = 0; j <= i; j++)
        {
            //if the element of where we are in the array is larger than the current element using index largest we change largest 
            if(array[j] > array[largestIndex])
            {
                largestIndex = j;     //new largest index, store the index into largest
            }
        }

        //after finding the largest element we need to swap it with the last element
        //only swap if the largest element is not already in the correct position (if largestIndex is not equal to i)
        if(largestIndex != i)
        {
            //swap largest element with the last element (element at i)
            swap(array[largestIndex], array[i]);
        }
    }
}

/*
"bubbling up" the largest element
1. move from front to the end
2. "bubble" the largest value to the end using pair-wise comparisons and swapping
*/
void bubbleSort(int array[], int size)
{

    //use a boolean variable to keep track if we made any swaps we going through the array
    bool swapped = true;

    //while loop to stop until we haven't swapped meaning the we have sorted the array
    while(swapped)
    {

        swapped = false;        //assume don't need to swap at first, we go through the loop any no swaps are made it will exit the while loop

        //loop through the array 
        for(int i = 0; i < size - 1; i++)
        {
            //if the value before its next is bigger swap
            if(array[i] > array[i + 1])
            {
                swap(array[i], array[i + 1]);

                //make swapped true since we swapped and can continue the while loop
                swapped = true;
            }
        }
    }
}

/*
1. go through the list with n elements through n - 1
2. find the right place each number
3. swap element i with the one to its left if smaller, aka like you are inserting number card in your hard that is already sorted 
*/
void insertionSort(int array[], int size)
{

    //loop through the array but start from the second element(index 1), assume the first element is sorted
    for(int i = 1; i < size; i++)
    {
        int key = array[i];     //the element to be inserted
        int j = i - 1;          //index of the last sorted element

        //shift elements larger than key one position to the right
        //j >= 0 - make sure we don't go out bounds
        //array[j] > key - check if the current element is larger than what we're inserting
        while(j >= 0 && array[j] > key)
        {
            
            array[j + 1] = array[j];        //shfit element to the right

            j--;        //move to the previous element 
        }

        //insert the key at its correct position
        array[j + 1] = key;
    }
}

/*
divede - partian the array into two subarrays A[p..q-1] and A[q+1..r]
conquer - sort the two subarrays by calling quicksort recursively
combine - trivial
*/
//main Quick sort function
void quickSort(int array[], int left, int right)
{
    //base case: if p >= r, the subarray has 0 or 1 element (already sorted)
    if(left >= right)
    {
        return;
    }

    //partition and get the pivot index
    int q = quickPartition(array, left, right);

    //recursively sort left side (before pivot)
    quickSort(array, left , q - 1);

    //recursively sort right side (after pivot)
    quickSort(array, q + 1, right);
}

//partition function we use as a helper function for quick sort
int quickPartition(int array[], int left, int right)
{
    int pivot = array[left];        //pivot is the leftmost element
     int q = left + 1;              //q marks the position where elements <= pivot should go
    int i = left + 1;               //i is the current index we're examining

    //main loop condition that keeps the partition process going, make sure two pointers don't cross each other, once they do, we are done partitioning
    while(i <= right)
    {
        //if current element is <= pivot, it belongs in the left partition
        if(array[i] <= pivot)
        {
            //swap the element at q with element at i
            //this puts the smaller/equal element at position q
            swap(array[q], array[i]);
            q++;    //move q forward to the next position
        }

        //always move i forward to check next element
        i++;
    }
    
    //after loop all elements form (left+1) to (q-1) are <= pivot
    //then place pivot in its correct position by swapping with element at (q-1)
    swap(array[left], array[q - 1]);
    
    //return the final position of pivot
    return q - 1;
}

/*
divide - split the array in half recursively until you have single elemenets
conquer - merge the sorted subarrays back together in sorted order
*/
void mergeSort(int array[], int left, int right)
{
    //base case: if ;eft == right, single element(already sorted)
    if(left == right)
    {
        return;
    }

    //find middle point
    int mid =(left + right) / 2;

    //recursively sort the left half
    mergeSort(array, left, mid);

    //recursively sort the right half
    mergeSort(array, mid + 1, right);

    //merge the two sorted halves
    mergeHelper(array, left, mid, right);
}

//helper function to merge two sorted subarrays
void mergeHelper(int array[], int left, int mid, int right)
{
    //calculate sizes
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    //create temporary arrays
    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];

    //copy left half to leftArr
    //left hald: starts at left and goes to mid
    for(int i = 0; i < leftSize; i++)
    {
        leftArr[i] = array[left + i];       //left + i starts at beginning of left subarray
    }

    //copy right half to rightArr
    //right half: starts at mid + 1 and goes to right
    for(int i = 0; i < rightSize; i++)
    {
        rightArr[i] = array[mid + 1 + i];   //mid + 1 + i starts at element after middle
    }

    //initialize pointers
    int i = 0;      //pointer for leftArr
    int j = 0;      //pointer for rightArr
    int k = left;   //pointer for main array

    //merge: while both subarrays are nonempty
    while(i < leftSize && j < rightSize)
    {
        //if element from left is smaller or equak, copy it
        if(leftArr[i] <= rightArr[j])
        {
            array[k] = leftArr[i];      //copy smaller element from left to main array
            i++;        //move next element in leftArr
        }

        //else copy from right 
        else
        {
            array[k] = rightArr[j];     //copy smaller element from right to main array
            j++;        //move next element in rightArr
        }

        k++;        //always move forward in main array after each placement
    }

    //copy any leftover elements fron leftArr
    while(i < leftSize)
    {
        array[k] = leftArr[i];
        i++;
        k++;
    }

    //copy any leftover elements from rightArr
    while(j < rightSize)
    {
        array[k] = rightArr[j];
        j++;
        k++;
    }

    //free temporary arrays
    delete[] leftArr;
    delete[] rightArr;

}

int main()
{

//create a dynamic array to sort the numbers from the user
int* numbers = new int[10000];

int numInt;     //varialble for the amount of integers that we need to sort
cin >> numInt;  //grab the input

int numAlg;     //variable to choose what sorting algoritmn the user wants
cin >> numAlg;  //grab the input

//loop through n times to get the value of each integers from the user
for(int i = 0; i < numInt; i++)
{
    int value;
    cin >> value;
    numbers[i] = value;     //value goes into the numbers array
}

//switch case for the algorithm the user chooses to use to sort the array
switch (numAlg)
{
    case 1:
        selectionSort(numbers, numInt);
        break;
    case 2:
        bubbleSort(numbers, numInt);
        break;
    case 3:
        insertionSort(numbers, numInt);
        break;
    case 4:
        quickSort(numbers, 0, numInt - 1);
        break;
    case 5:
        mergeSort(numbers, 0, numInt - 1);
        break; 
}

//loop to print out the array
for(int i = 0; i < numInt; i++)
{
    //if i is == numInt - 1 means we are at the last element of the array and don't need to print a " "
    if (i == numInt - 1)
    {
        cout << numbers[i];
    }
    else
    {
        cout << numbers[i] << " ";
    }
}

//delete numbers array to free up allocated memory 
delete[] numbers;

return 0;
}