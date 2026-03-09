/*
This function will return an array of animation that will be used to animate the bubble sort algorithm
First we make a copy of the array (arrayCopy)
Second we sort the copy array while recodording every comparison and swap into the animations array
Finally we return the animations array since it has all the steps and in the component (SortingVisualizer) we will replay the animations steps
*/
export function getBubbleSortAnimations(array)
{

    const animations = [];    //create an empty array to hold the animations

    const arrayCopy = array.slice();    //make a copy of the original array to sort (so we don't mutate the original array)

    //use bubble sort algorithm to sort the array and record the animations
    let swapped = true;    //boolean variable to keep track of whether we made any swaps in the current pass through the array

    //use a while loop to keep sorting until we don't need to swap anymore (until the array is sorted), outer loop
    while(swapped)
    {
        swapped = false;   //Assume we don't need to swap at first

        //inner loop to go through the array and compare adjacent elements
        for(let i = 0; i < arrayCopy.length - 1; i++)
        {
            //Record Comparison
            animations.push([i, i + 1, false]);     //record the comparison this show what bars we are comparing, false = comparison

            //if the current element is greater than the next element, we need to swap them
            if(arrayCopy[i] > arrayCopy[i + 1])
            {
                //swap the elements in the array
                const  temp = arrayCopy[i];
                arrayCopy[i] = arrayCopy[i + 1]
                arrayCopy[i + 1] = temp;

                //Record Swap
                animations.push([i, i + 1, true]);     //record the swap this show what bars we are swapping, true = swap

                swapped = true;    //we made a swap, so we need to keep sorting
            }
        }
    }
    

    return animations;        //return the animations array to be used in the SortingVisualizer component
}