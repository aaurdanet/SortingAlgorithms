Sorting Algorithms Implementation

This C program implements various sorting algorithms (Selection Sort, Insertion Sort, Bubble Sort, and Merge Sort) to sort integer arrays. The program also measures the runtime and extra memory allocated by each sorting algorithm.
Code Structure

The program comprises the following key components:
Sorting Algorithms

    Selection Sort:
        selectionSort function implements the Selection Sort algorithm.
        Measures the runtime and extra memory allocated.

    Insertion Sort:
        insertionSort function implements the Insertion Sort algorithm.
        Measures the runtime and extra memory allocated.

    Bubble Sort:
        bubbleSort function implements the Bubble Sort algorithm.
        Measures the runtime and extra memory allocated.

    Merge Sort:
        mergeSort function implements the Merge Sort algorithm.
        Measures the runtime and extra memory allocated.

Data Parsing

    parseData function reads integer data from an input file and returns the size of the dataset.

Printing

    printArray function prints the first and last 100 items in the data array.

Main Function

The main function serves as the entry point. It iterates through three input files, performs sorting using various algorithms, and prints the results.
Usage

Ensure you have input files named "input1.txt," "input2.txt," and "input3.txt" with appropriate data. Compile and run the program, and it will display sorting results for each dataset.

bash

$ gcc your_program.c -o your_program
$ ./your_program

Feel free to adapt and integrate these sorting algorithm implementations into your projects as needed.
