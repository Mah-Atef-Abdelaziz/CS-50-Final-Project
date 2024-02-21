# Sorting_Algorithms_Tracer_in_C

## Video Demo:  <https://youtu.be/j3IG25K1pNE>

## Description

This project is a C program that allows users to input an array of integers and choose from various sorting algorithms to sort the array. After sorting, the program prints the sorted array along with the steps involved in each sorting algorithm.

Here's a breakdown of the project:

Header Files Inclusion: The necessary header files such as <stdio.h>, <stdlib.h>, and <string.h> are included.

Function Prototypes: Prototypes for functions used in the program are declared.

Main Function: The main() function initializes the program. It prompts the user to input the number of elements in the array and the elements themselves. Then, it presents a menu for choosing a sorting algorithm or exiting the program. Based on the user's choice, it calls the corresponding sorting function and prints the sorted array.

Sorting Functions:

intersectionSort(): Implements the intersection sort algorithm.
selectionSort(): Implements the selection sort algorithm.
bubbleSort(): Implements the bubble sort algorithm.
quickSort(): Implements the quick sort algorithm.
mergeSort(): Implements the merge sort algorithm.
merge(): Helper function for merge sort.
shellSort(): Implements the shell sort algorithm.
Print Functions:

printBigO(): Prints the time and space complexity of each sorting algorithm.
Memory Management: Dynamic memory allocation is used to allocate memory for the array.

User Interaction: The program interacts with the user by displaying menus, taking user inputs, and providing outputs accordingly.

Algorithmic Analysis: The program not only sorts the array but also provides information about the time and space complexity of each sorting algorithm.

Overall, this project serves as a learning tool for understanding various sorting algorithms and their complexities, as well as practicing C programming concepts like dynamic memory allocation, user input/output, and function implementation.
