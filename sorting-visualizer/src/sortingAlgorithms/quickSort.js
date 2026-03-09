/*
This function will return an array of animation that will be used to animate the quick sort algorithm
First we make a copy of the array (arrayCopy)
Second we sort the copy array while recodording every comparison and swap into the animations array
Finally we return the animations array since it has all the steps and in the component (SortingVisualizer) we will replay the animations steps
*/

export function getQuickSortAnimations(array)
{

    const animations = [];

    const arrayCopy = array.slice();

    //call the recursive function here, 0 starting index(low) first element of array , arrayCopy.length - 1 ending index(high) last element of array
    quickSortHelper(arrayCopy, 0, arrayCopy.length - 1, animations);

    return animations;
}

/*
need helper function because recusion needs to track the boundaries (low and high)
arr - the arrar we are sorting (the copy)
low- the starting index of the subarray we are sorting
high - the ending index of the subarray we are sorting
animations - the array where we record all our comparions/swaps
*/
function quickSortHelper(arr, low, high, animations)
{
    
    if(low < high)
    {
        //grab the return value from the partition(the partition point = the INDEX where we split the arrat after rearranging)
        const partitionIndex = partition(arr, low, high, animations);

        //recursively sort left side
        quickSortHelper(arr, low, partitionIndex - 1, animations);

        //recursively sort right side
        quickSortHelper(arr, partitionIndex + 1, high, animations);
    }
}

//function to find  the median of the first and last index for a better pivot 
function medianOfThree(arr, low, high, animations)
{
    const mid = Math.floor((low + high) / 2);       //calculates the middle index between low and high

    //if the lower index(first) is greater in value than the middle index swap them
    if (arr[low] > arr[mid])
    {
        const temp = arr[low];
        arr[low] = arr[mid];
        arr[mid] = temp;
        
        animations.push([low, mid, true]);      //record swap
    } 
    
    //if the lower index(first) is greater in value than the higher index(last) swap them
    if (arr[low] > arr[high])
    {
        const temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;

        animations.push([low , high, true]);    //record swap
    }
    
    //if the middle index is greater in value than the higher index(last) swap them
    if (arr[mid] > arr[high])
    {
        const temp = arr[mid];
        arr[mid] = arr[high];
        arr[high] = temp;

        animations.push([mid, high , true]);    //record swap
    }

    return mid;     //return the index of the median (our pivot)
}

//partition function that rearranges the array so all elements smaller than the pivot fo left, and larger go right
function partition(arr, low, high, animations) 
{

    // Call the median of three function to get the pivot index
    const pivotIndex = medianOfThree(arr, low, high, animations);

    // Pivot value gets the value of the pivot arr[pivotIndex]
    const pivotValue = arr[pivotIndex];
    
    // Swap pivot to the high position to get it out of the way during partitioning
    let temp = arr[pivotIndex];
    arr[pivotIndex] = arr[high];
    arr[high] = temp;

    // Only record swap if we actually moved it
    if (pivotIndex !== high) {
        animations.push([pivotIndex, high, true]);      // Record swap
    }
    
    let left = low;        // Left pointer starts at low
    let right = high - 1;  // Right pointer starts at high-1 since pivot is now at high
    
    // Outer loop: keep going as long as the pointers haven't crossed
    while (left <= right) {

        // First inner loop: move left to the right as long as elements are smaller than pivot
        // STOP when we find an element that >= pivot (belongs on the right side)
        while (left <= right && arr[left] < pivotValue) {
            animations.push([left, high, false]);       // Record comparison with pivot
            left++;     // Increment left to the right

        }
        
        // Second inner loop: move right to the left as long as elements are >= pivot
        // STOP when we find an element that's < pivot (belongs on the left side)
        while (left <= right && arr[right] >= pivotValue) {
            animations.push([right, high, false]);      // Record comparison with pivot
            right--;     // Decrement right to the left

        }

        // After both loops: left should be pointing at a "big" element (should be right of pivot)
        // and right should be pointing at a "small" element (should be on the left)
        // Swap if pointers haven't crossed
        if (left < right) {
            let temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            animations.push([left, right, true]);       // Record swap
        }
    }
    
    // Swap pivot back from high position to its final correct position (at left)
    temp = arr[left];
    arr[left] = arr[high];
    arr[high] = temp;
    animations.push([left, high, true]);
    
    return left;        // Return the final position of the pivot (partition point)
}