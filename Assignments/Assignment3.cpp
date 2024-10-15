/*
    * Darion Badillo
    * 09/24/2024
    * CS 3060
    * Assignment 3
    *
    * Description:
	* C++ program that contains three functions: 
	* Main function will prompt the user to select a program to run (1-3).
    *   Search Benchmarks: This program will take an array of integers and a key, then perform linear and binary search on the array and display the number of comparisons made.
    *   Mode Function: This program will take an array of integers and return the mode
    *   Median Function: This program will take an array of integers and return the median value.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


// Constants
const int ARRAY_SIZE = 30;
const int ARRAY_SIZE_1 = 35;

// Function Prototypes
void generateRandomArray(int array[], int size);
void searchBenchmarks(int array[], int size, int key);
int linearSearch(int array[], int size, int key);
void bubbleSort(int array[], int size);
int binarySearch(int array[], int size, int key);
int findMode(int* array, int size);
double findMedian(int* array, int size);

// Main function
int main() {
    // Seed the random number generator
    srand(time(0));

    // Variable
    int control = 0, evenArray[ARRAY_SIZE] = {}, oddArray[ARRAY_SIZE_1] = {}, randomNum, randomIndex, mode;
    double median = 0.0;

    // Function Calls

    cout << "Select a program to run (1-3): " << endl;
    while (control < 1 || control > 3) {
        cout << "1. Search Benchmarks\n2. Find Mode \n3. Median Function" << endl;

        // Input: user selection
        cin >> control;
        if (control < 1 || control > 3) {
            cout << "Invalid input" << endl;
		} // if
	} // while

    switch (control) {

        // Search Benchmarks
        case 1:
            cout << "\nSearch Benchmarks" << endl;
            cout << "_____________________________________" << endl;

            // Fill the array with random numbers
            generateRandomArray(evenArray, ARRAY_SIZE); 
            
            // Generate a random number to search for while ensuring it is in the evenArray
            randomNum = rand() % 100;
            randomIndex = rand() % ARRAY_SIZE;
            evenArray[randomIndex] = randomNum; 

            // Call the search benchmarks function
            searchBenchmarks(evenArray, ARRAY_SIZE, randomNum);
            
            break;

		// Mode Function
        case 2:
            cout << "Find Mode" << endl;
            cout << "_____________________________________" << endl;

            // Fill the array with random numbers
            generateRandomArray(evenArray, ARRAY_SIZE); 

            // Call the mode function
            mode = findMode(evenArray, ARRAY_SIZE);

                // No mode found
            if (mode == -1) {
                cout << "No mode found." << endl;
            } // if
            
            // Mode found
            else {
                // Display the mode
                cout << "Mode: " << mode << endl;

            } // else
    
            break;
        
		// Median Function
        case 3:
            cout << "Median Function" << endl;
            cout << "_____________________________________" << endl;
            
            
            // Flip a coin to determine an if an array's size is positive or negative for the median function ()
            randomNum = rand() % 2;

            // Fill the odd-sized array with random numbers and print

            if (randomNum == 1) {

                // Fill the array with random numbers
                generateRandomArray(oddArray, ARRAY_SIZE_1);

                bubbleSort(oddArray, ARRAY_SIZE_1);

                // Call the median function
                median = findMedian(oddArray, ARRAY_SIZE_1);
            } // if

            // Fill the even-size array with random numbers
            else {

                // Fill the array with random numbers
                generateRandomArray(evenArray, ARRAY_SIZE);

                // Sort the array
                bubbleSort(evenArray, ARRAY_SIZE);

                // Call the median function
                median = findMedian(evenArray, ARRAY_SIZE);
            } // else

            // Display the median
            cout << "Median Value: " << median << endl;
            
            break;

		// Default case
        default:
            cout << "Invalid input. Goodbye!" << endl;
            break;
        }

	// End of program
    return 0;
} // main

// Functions

// Generates an array of random integers
void generateRandomArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100; // Random numbers between 0 and 99
    } // for
} // generateRandomArray

// Takes an array and a key, performs linear and binary search, and displays the number of comparisons made
void searchBenchmarks(int array[], int size, int key) {

    // Variables to store comparison counts
    int linearComparisons = 0;
    int binaryComparisons = 0;

    // Perform linear search
    linearComparisons = linearSearch(array, size, key);
    
    // Sorts the array and performs binary search
    bubbleSort(array, size); 
    binaryComparisons = binarySearch(array, size, key);

    // Display Comparisons
    cout << "\nTarget to search for: " << key << endl;
    cout << "\nLinear Search\t\tBinary Search" << endl;
    cout << "_____________________________________" << endl;
    cout << linearComparisons << " comparisons\t\t" << binaryComparisons << " comparisons" << endl;
} // searchBenchmarks

// Performs a linear search and returns the number of comparisons made
int linearSearch(int array[], int size, int key) {

    // Variable to count comparisons
    int comparisons = 0; 

    // Loop through the array
    for (int i = 0; i < size; i++) {

            // Increment comparisons for each iteration
            comparisons++;

            // Check if the current element is the key
            if (array[i] == key) {
                break; // Return index if key found
            } // if
        } // for
    
    // Return the number of comparisons made
    return comparisons; 
} // linearSearch

// Function to perform bubble sort 
// Algorithm heavily references code found on GeeksforGeeks (https://www.geeksforgeeks.org/bubble-sort-algorithm/)
void bubbleSort(int array[], int size) {

    // Variable to track if a swap occurred
    bool swapped;
    int temp;

    // Loop through the array
    for (int i = 0; i < size - 1; i++) {
        swapped = false;

        // Compare adjacent elements
        for (int j = 0; j < size - i - 1; j++) 
        {
            // If the current element is greater than the next, swap them
            if (array[j] > array[j + 1]) {
                // Swap the elements
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true;
            } // if
        } // inner for

        // If no two elements were swapped in the inner loop, the array is already sorted
        if (!swapped)
        {
            break;
        } //if

    } // outer for

} // bubbleSort

// Performs a binary search and returns the number of comparisons made
int binarySearch(int array[], int size, int key) {
    int low = 0, high = size - 1, comparisons = 0;

    while (low <= high) {
        comparisons++;
        int mid = low + (high - low) / 2;

        if (array[mid] == key)
        {
            break;
        } // if
        
        // Adjust the low boundary
        else if (array[mid] < key) 
        {
            low = mid + 1; 
        } // else if
        
        // Adjust the high boundary
        else 
        {
            high = mid - 1;
        } // else
    } // while

    return comparisons; // Return the number of comparisons made
} // binarySearch

// Takes an array and determines the mode, or most frequently occurring number using pointers
int findMode(int* array, int size) {

    // Variables
    int mode = -1, maxCount = 0;

    cout << "\nArray Elements: " << endl;
    
    // Loop through the array while printing each element
    for (int i = 0; i < size; i++) {
        int count = 0;

        // Use pointer notation to print elements
        cout << *(array + i) << " "; 

        // Count occurrences of the current element using pointer notation
        for (int j = 0; j < size; j++) {
            
            if (*(array + j) == *(array + i)) {
                count++;
            } // if
        } // inner for

        // Update mode if count of current element is greater than maxCount
        if (count > maxCount) {
            maxCount = count;
            mode = *(array + i);
        } // if
    } // outer for

    cout << endl; // New line after printing array elements

    cout << "\nMode occurs " << maxCount << " times." << endl; 
    return mode;    
} // findMode


// Determines the median of an array while using pointers to access elements and returns the median value
double findMedian(int* array, int size) {
    // Variable 
    double median = 0.0;

    // Check if the size is even or odd
    if (size % 2 == 0) {
        // If even, average the two middle elements
        median = (*(array + size / 2 - 1) + *(array + size / 2)) / 2.0;
    } // if

    else {
        // If odd, return the middle element
        median = *(array + size / 2);
    } // else

    return median; 
} // findMedian
