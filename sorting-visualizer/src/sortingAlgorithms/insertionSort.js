/*
This function will return an array of animation that will be used to animate the insertion sort algorithm
First we make a copy of the array (arrayCopy)
Second we sort the copy array while recodording every comparison and swap into the animations array
Finally we return the animations array since it has all the steps and in the component (SortingVisualizer) we will replay the animations steps
*/
export function getInsertionSortAnimations(array)
{

    const animations = [];    //create an empty array to hold the animations

    const arrayCopy = array.slice();   //make a copy of the original array to sort (so we don't mutate the original array)

    //use insertion sort algorithm to sort the array and record the animations
    //outer loop to go through the array from the second element to the end (since the first element is already sorted)
    for(let i = 1; i < arrayCopy.length; i++)
    {
        let key = arrayCopy[i];    //the current element we are trying to insert into the sorted portion of the array

        let j = i - 1;    //the index of the last element in the sorted portion of the array

        //inner loop to go through the sorted portion of the array and find the correct position for the key element
        while(j >= 0 && arrayCopy[j] > key)     //Keep going as long as we haven't reached the beginning (j >= 0) AND the element at j is bigger than our key
        {
            //Record Comparison
            animations.push([j, j + 1, false]);     //record the comparison this show what bars we are comparing, false = comparison

            arrayCopy[j + 1] = arrayCopy[j];    //shift the element at index j to the right (to index j + 1) to make room for the key element to be inserted

            //Record Swap
            animations.push([j, j + 1, true]);     //record the swap this show what bars we are swapping, true = swap

            j--;    //move to the next element in the sorted portion of the array (to the left)
        }

        arrayCopy[j + 1] = key;    //place the key element in its correct position in the sorted portion of the array (at index j + 1)
    }

    return animations;        //return the animations array to be used in the SortingVisualizer component
}