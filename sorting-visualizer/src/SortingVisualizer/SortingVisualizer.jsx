import React, {useState, useEffect} from 'react';  //Import React itself to use JSX syntax and create components. useState to create state to store our array of bars. useEffect to run code when the component first mounts (when it is first rendered on the screen) to generate an initial array of random numbers
import './SortingVisualizer.css';                  //Import the CSS file for styling the SortingVisualizer component
import {getSelectionSortAnimations} from '../sortingAlgorithms/selectionSort';    //Import the function to get the animations for merge sort
import {getBubbleSortAnimations} from '../sortingAlgorithms/bubbleSort';          //Import the function to get the animations for bubble sort
import {getInsertionSortAnimations} from '../sortingAlgorithms/insertionSort';     //Import the function to get the animations for insertion sort
import { getQuickSortAnimations } from '../sortingAlgorithms/quickSort';
import { getMergeSortAnimations } from '../sortingAlgorithms/mergeSort';

const SortingVisualizer = () => {         //Define a component (like a function)
    
    console.log('SortingVisualizer component is rendering');

    /* JavaScript code here to create the Array of Bars (before return)
    1. create variable to hold the array (array) that holds the value (the array of numbers)
    2. A function to update the value (setArray)
    3. useState([]) - we use [] to initialize the array as an empty array
    */
    const [array, setArray] = useState([]);

    /*
    Use built in function called Math.random() to generate a random number between 0 and 1
    * 500 - to generate a random number between 0 and 500
    Math.floor() - to round down the number to the nearest integer (only whole numbers for the bars)
    + 1 - to make sure we never get 0  
    */
    const resetArray = () => {        //Function to generate a new array of random numbers (to reset the array)
        console.log('resetArray is being called');
        const arr = [];           //create a new array to hold the random numbers
        for (let i = 0; i < 50; i++) {     //for loop to generate 50 random numbers and push them into the array
            arr.push(Math.floor(Math.random() * 500) + 1);     //push random number in array (between 1 and 500)
        }
        console.log('Generated array:', arr);
        setArray(arr);            //update our state with the new array of random numbers
    }

    /*
    Function to have a reusable function to display the animations for all the sorting algorithms, we will pass in the animations array and the speed of the animation (delay between each animation step)
    */
    const animateSorting = (animations) =>
    {
        //loop through the animations array to display the animations
        for(let i = 0; i < animations.length; i++)
        {
            setTimeout(() => {   //setTimeout to create a delay between each animation step

                //grabs all the bars on the page and stores them in arrayBars
                const arrayBars = document.getElementsByClassName('array-bar');

                //grabs the indices of the two bars that we are comparing or swapping from the animations array for each animation
                const [barOneIdx, barTwoIdx, isSwap] = animations[i];        //isSwap - to know if we are comparing or swapping

                //grabs the srtyle of the two bars that we are comparing or swapping so we can change their color
                const barOneStyle = arrayBars[barOneIdx].style;
                const barTwoStyle = arrayBars[barTwoIdx].style;

                //if isSwap is true, then we are swapping the bars, otherwise we are comparing the bars
                if(isSwap)
                {

                    //for swap we want to change the color of the bars to show that we are swapping them
                    barOneStyle.backgroundColor = 'yellow';
                    barTwoStyle.backgroundColor = 'yellow';

                // Wait a bit, THEN swap and change back
                setTimeout(() => {

                // Swap the heights
                const tempHeight = barOneStyle.height;
                barOneStyle.height = barTwoStyle.height;
                barTwoStyle.height = tempHeight;
        
                // Change back to turquoise
                barOneStyle.backgroundColor = 'turquoise';
                barTwoStyle.backgroundColor = 'turquoise';

                }, 200);  // Wait 200ms before swapping, so the yellow color is visible before the swap happens

                }
                else 
                {
                    //for comparison we want to change the color of the bars to show that we are comparing them
                    barOneStyle.backgroundColor = 'red';
                    barTwoStyle.backgroundColor = 'red';

                     //After a brief moment change them back to the original color (turquiose)
                    setTimeout(() => {

                    barOneStyle.backgroundColor = 'turquoise';
                    barTwoStyle.backgroundColor = 'turquoise';   

                }, 50);      //50 ms delay to show the red color before changing back to turquoise

                }

            }, i * 50);      //50 ms delay between each animation step (i * 50) to create the animation effect

        }
    }

    /*
    useEffect - to call the resetArray function when the component first mounts (when it is first rendered on the screen) to generate an initial array of random numbers
    */
    useEffect(() => {
        console.log('useEffect is running');
        resetArray();
    }, []);

    /*
    Button for merge sort - when we click the button, it will call the mergeSort function
    */
    const mergeSort = () => {
        const animations = getMergeSortAnimations(array);
        
        //loop through the animations array to display the animations
        for (let i = 0; i < animations.length; i++) 
        {
            const arrayBars = document.getElementsByClassName('array-bar');     //grab all the bars on the page
            const [barIdx, newHeight, isSwap] = animations[i];                  //get the bar index, new height value, and whether its a swap or a comparison
            
            //setTimeout to create a delay between each animation step
            setTimeout(() => {
                const barStyle = arrayBars[barIdx].style;       //get the style of the bar at barIdx
                
                //if isSwap is true we are placing a value(setting new height)
                if (isSwap) {
                    // Set the new height for the bar (this is the merge step where we palce sorted values)
                    barStyle.height = `${newHeight}px`;
                    barStyle.backgroundColor = 'yellow';        //change color to yellow to show placement
                    
                    setTimeout(() => {
                        barStyle.backgroundColor = 'turquoise';     //change back to turquoise after a brief moment
                    }, 200);        //wait 200ms before changing back (same as other sorts)
                } 
                //if isSwap is false, we are just comparing
                else {    
                    // Just highlight for comparison
                    barStyle.backgroundColor = 'red';
                    
                    setTimeout(() => {
                        barStyle.backgroundColor = 'turquoise';     //change back to turquoise after comparison
                    }, 50);     //50ms delay to show the red color before chaning back
                }
            }, i * 50);         //50ms delay between each animation step (same as other sorting algorithms)
        }

    }

    /*
    Button for bubble sort - when we click the button, it will call the bubbleSort function
    */
   const bubbleSort = () => {
        const animations = getBubbleSortAnimations(array);     //get the animations for bubble sort by calling the getBubbleSortAnimations function and passing in the current array of bars (array)
        animateSorting(animations);                            //call the animateSorting function to display the animations for bubble sort
        console.log('Animations:', animations);
        console.log('Bubble Sort button is clicked');
   }

   /*
   Button for selection sort - when we click the button, it will call the selectionSort function
   */
   const selectionSort = () =>
   {
        const animations = getSelectionSortAnimations(array);     //get the animations for selection sort by calling the getSelectionSortAnimations function and passing in the current array of bars (array)
        animateSorting(animations);                               //call the animateSorting function to display the animations for selection sort
        console.log('Animations:', animations);
        console.log('Selection Sort button is clicked');
   }

   /*
   Button for insertion sort - when we click the button, it will call the insertionSort function
   */
   const insertionSort = () =>
   {
        const animations = getInsertionSortAnimations(array);     //get the animations for insertion sort by calling the getInsertionSortAnimations function and passing in the current array of bars (array)
        animateSorting(animations);                               //call the animateSorting function to display the animations for insertion sort
        console.log('Animations:', animations);
        console.log('Insertion Sort button is clicked');
   }

   /*
   Button for quick sort - when we click the button, it will call the quickSort function
   */
  const quickSort = () =>
  {
        const animations = getQuickSortAnimations(array);          //get the animations for quick sort by calling the getQuickSortAnimations function and passing in the current array of bars (array)
        animateSorting(animations);                                //call the animateSoring function to display the animations for quick sort
        console.log('Animations:', animations);
        console.log('Quick Sort button is clicked');
  }
  

   /*
   Button for heap sort - when we click the button, it will call the heapSort function
   */
  const heapSort = () =>
  {
        console.log('Heap Sort button is clicked');
  }

  

    //Where we put what we want to show on the screen (the JSX code)
    //className="array-container" - to style the container that holds the bars (defined in SortingVisualizer.css)
    //Button - HTML element for a button. onClick={resetArray} - when the button is clicked, it will call the resetArray function to generate a new array of random numbers
    //array.map() - to loop through every number in the array, value - the actual number (bar height), index - the position in the array
    return (
        <div className="array-container">
            <div className="top-buttons-container">
                <button className="generate-array-button" onClick={resetArray}>Generate New Array</button>
            </div>

            <div className="bars-container">
                {array.map((value, index) => (
                    <div
                        key={index}                        //key - to give each bar a unique identifier (index) to help React keep track of them when they change
                        className="array-bar"
                        style={{height: `${value}px`}}     //style - to set the height of each bar based on the value (the random number) in pixels (px)
                    >
                    </div>
                ))}
            </div>

            <div className="bottom-buttons-container">
                <button className="merge-sort-button" onClick={mergeSort}>Merge Sort</button>
                <button className="bubble-sort-button" onClick={bubbleSort}>Bubble Sort</button>
                <button className="selection-sort-button" onClick={selectionSort}>Selection Sort</button>
                <button className="insertion-sort-button" onClick={insertionSort}>Insertion Sort</button>
                <button className="quick-sort-button" onClick={quickSort}>Quick Sort</button>
                <button className="heap-sort-button" onClick={heapSort}>Heap Sort</button>
            </div>
        </div>    
    );
}

export default SortingVisualizer;        //Export the component so it can be available to other files (like App.js)