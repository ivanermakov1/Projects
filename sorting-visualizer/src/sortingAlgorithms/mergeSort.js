/*
This function will return an array of animation that will be used to animate the merge sort algorithm
First we make a copy of the array (arrayCopy)
Second we sort the copy array while recodording every comparison and swap into the animations array
Finally we return the animations array since it has all the steps and in the component (SortingVisualizer) we will replay the animations steps
*/
export function getMergeSortAnimations(array)
{
    const animations = [];

    const arrayCopy = array.slice();

    const auxiliaryArray = array.slice();       //need helper array for merging 

    mergeSortHelper(arrayCopy, 0, arrayCopy.length - 1, auxiliaryArray, animations);

    return animations;

}

function mergeSortHelper(arr, startIdx, endIdx, auxiliaryArray, animations)
{
    //Base case if single elements is already sorted 
    //When startIdx === endIdx, that means the subarray has only one element (start and end are the same index).
    if(startIdx === endIdx)
    {
        return;
    }

    const middleIdx = Math.floor((startIdx + endIdx) / 2);

    //recursively sort the left half (from startIdx to middleIdx)
    mergeSortHelper(arr, startIdx, middleIdx, auxiliaryArray, animations);

    //recursively sort the right half (fromt the middleIdx + 1 to endIdx)
    mergeSortHelper(arr, middleIdx + 1, endIdx, auxiliaryArray, animations);

    //merge the two sorted halves
    merge(arr, startIdx, middleIdx, endIdx, auxiliaryArray, animations);

}

function merge(arr, startIdx, middleIdx, endIdx, auxiliaryArray, animations)
{
    //copy to auxiliary array
    //We need to copy the current subarray to auxiliaryArray because we're going to overwrite arr as we merge 
    // The auxiliary array holds the original values so we can compare them
    for(let i = startIdx; i <= endIdx; i++)
    {
        auxiliaryArray[i] = arr[i];
    }

    //setup three pointers
    let i = startIdx;       //Pointer for left subarray, i starts at the beginning of the left sorted half (startIdx to middleIdx)
    let j = middleIdx + 1;  //Pointer for the right subarray, j starts at the beginning of the right sorted half (middleIdx + 1 to endIdx)
    let k = startIdx;       //Pointer for main array, k is where we'll place the next element in the main array

    /*
    main merge loop
    keep looping aslong both conditions are true
    i <= middleIdx — the left subarray still has elements we haven't looked at yet
    j <= endIdx — the right subarray still has elements we haven't looked at yet
    */
    while(i <= middleIdx && j <= endIdx)
    {
        animations.push([i, j, false]);     //record comparison

        //if the element (auxiliaryArray[i]) is smaller or equal copy it to the main array at position k
        if(auxiliaryArray[i] <= auxiliaryArray[j])
        {
            arr[k] = auxiliaryArray[i];
            i++;        //move left pointer forward since we used that element
        }
        //else the right element (auxiliaryArray[j]) is smaller copy it to the main array at position k
        else
        {
            arr[k] = auxiliaryArray[j];
            j++;        //move right poiter forward since we used that element
        }

        //record the animation showing we placed a value at position k
        animations.push([k , arr[k], true]);
        k++;        //move k forward to the next position in the main array
    }

        //copy remaining element from the left subarray (if any)
        // This runs only if the left subarray still has elements left after the main merge loop
        // (meaning the right subarray ran out of elements first)
        while(i <= middleIdx)
        {
            animations.push([i , i, false]);    //record comparison
            arr[k] = auxiliaryArray[i];          //copy remaining elements from the left subarray to the main array
            animations.push([k, arr[k], true]); //record placement
            i++;        //move left pointer forward
            k++;        //move main array pointer forward
        }

        //copy remaining elements from the right subarray (if any)
        // This runs only if the right subarray still has elements left after the main merge loop
        // (meaning the left subarray ran out of elements first)
        while(j <= endIdx)
        {
            animations.push([j, j, false]);     //record comparison
            arr[k] = auxiliaryArray[j];         //copy the remaining element from the right subarray to the main array
            animations.push([j, arr[k], true]); //record placement
            j++;        //move right pointer forward 
            k++;        //move main array pointer forward
        }

}