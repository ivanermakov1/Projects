# Sorting Visualizer

A React-based web application that visualizes different sorting algorithms in real-time with interactive controls.

## Project Overview

This project demonstrates how 5 different sorting algorithms work by animating them step-by-step. Watch as elements are compared, swapped, and sorted in real-time with visual feedback.

## Features

- **Interactive Visualization**: Watch sorting algorithms work in real-time with smooth animations
- **5 Sorting Algorithms**: 
  - Selection Sort
  - Bubble Sort
  - Insertion Sort
  - Quick Sort
  - Merge Sort

## Algorithms Explained

### Selection Sort
- **How it works**: Finds the largest element and moves it to the end
- **Time Complexity**: O(n²)
- **Best for**: Learning, small datasets
- **Stability**: Unstable

### Bubble Sort
- **How it works**: Compares adjacent elements and swaps them if out of order
- **Time Complexity**: O(n²)
- **Best for**: Educational purposes, nearly sorted data
- **Stability**: Stable

### Insertion Sort
- **How it works**: Builds sorted array by inserting elements one by one
- **Time Complexity**: O(n²)
- **Best for**: Small datasets, nearly sorted arrays
- **Stability**: Stable

### Quick Sort
- **How it works**: Divide and conquer using a pivot element
- **Time Complexity**: O(n log n) average, O(n²) worst case
- **Best for**: Large datasets, general-purpose sorting
- **Stability**: Unstable

### Merge Sort
- **How it works**: Divides array in half and merges sorted subarrays
- **Time Complexity**: O(n log n) guaranteed
- **Best for**: Large datasets, guaranteed performance
- **Stability**: Stable

## Technologies Used

- **React**: UI framework and component management
- **JavaScript (ES6+)**: Algorithm implementation
- **CSS3**: Styling and animations

## Getting Started

### Prerequisites
- Node.js (v14 or higher)
- npm (comes with Node.js)

### Installation

```bash
# Clone or navigate to the project
cd sorting-visualizer

# Install dependencies
npm install
```

### Running the Application

```bash
# Start the development server
npm start
```

The app will open at `http://localhost:3000` in your browser.

### Building for Production

```bash
npm run build
```

## How to Use

1. **Select Algorithm**: Choose a sorting algorithm from the dropdown menu
2. **Generate New Array**: Click "Generate New Array" for random data
3. **Start Sorting**: Click the "Sort" button to watch the visualization


## Author

Ivan Ermakov
