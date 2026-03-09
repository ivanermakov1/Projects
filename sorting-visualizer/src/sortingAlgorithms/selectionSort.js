/*
This function will return an array of animation that will be used to animate the selection sort algorithm
First we make a copy of the array (arrayCopy)
Second we sort the copy array while recodording every comparison and swap into the animations array
Finally we return the animations array since it has all the steps and in the component (SortingVisualizer) we will replay the animations steps
*/
export function getSelectionSortAnimations(array)
{

    const animations = [];    //create an empty array to hold the animations

    const arrayCopy = array.slice();    //make a copy of the original array to sort (so we don't mutate the original array)

    //use selection sort algorithm to sort the array and record the animations
    //create outer loop to go through the array from the end to the beginning 
    for(let i = arrayCopy.length - 1; i > 0; i--)
    {
        let maxIndex = 0;    //assume the first element is the largest (max) element
        
        //create inner loop to find the largest element in the unsorted portion of the array (from index 0 to i)
        for(let j = 0; j <= i; j++)
        {

            animations.push([j, maxIndex, false]);      //record the comparison this show what bars we are comparing, false = comparison

            if(arrayCopy[j] > arrayCopy[maxIndex])     //if we find a larger elemnent, update the maxIndex
            {
                maxIndex = j;       //update the maxIndex to the index of the new largest element
            }
        }

        //after we find the largest element in the inner loop, we need to swap it with the last element
        if(maxIndex !== i)     //only swap if the largest element is not already in the correct position (if maxIndex is not equal to i)
        {
            //swap the largest element with the last element (element at index i), need temp variable to swap in JavaScript
            const temp = arrayCopy[i];
            arrayCopy[i] = arrayCopy[maxIndex];
            arrayCopy[maxIndex] = temp;

            animations.push([i, maxIndex, true]);     //record the swap this show what bars we are swapping, true = swap

        }
    }


    return animations;        //return the animations array to be used in the SortingVisualizer component 

}