/*
    * Darion Badillo
    * 10/01/2024
    * CS 3060
    * Assignment 4
    *
    * Description:
	* C++ program that contains three functions: 
	* Main function will prompt the user to select a program to run (1-4).
    *   Search Benchmarks: This program will take a dynamically generated array of integers and a key, then perform linear and binary search on the array and display the number of comparisons made.
    *   Mode Function: This program will take a dynamically generated array of integers and find the mode(s) of the array and display the mode(s) and their frequency.
    *   Median Function: This program will take a dynamically generated array of integers and return the median value.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function Prototypes
int* initializeArray(int &size);
void generateRandomArray(int array[], int size);
void searchBenchmarks();
int linearSearch(int array[], int size, int key);
void bubbleSort(int array[], int size);
int binarySearch(int array[], int size, int key);
void findMode();
double findMedian();

// Main
int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));  

    int control;
    double answer = 0.0;

    do {
        // Reset control variable
        control = 0; 
        // Prompt the user to select a program to run
        cout << "Select a program to run (1-3) or enter 4 to exit: " << endl;
        while (control < 1 || control > 4) {
            cout << "1. Search Benchmarks\n2. Find Mode \n3. Median Function \n4. Exit" << endl;
            cin >> control;
            if (control < 1 || control > 4) {
                cout << "Invalid input" << endl;
            } // if
        } // while

        // Switch statement to run the selected program
        switch (control) {

            // Search Benchmarks case
            case 1:
                cout << "-----------------------------------" << endl;
                cout << "Search Benchmarks" << endl;
                cout << "-----------------------------------" << endl;
                searchBenchmarks(); 
                break;

            // Find Mode case
            case 2:
                cout << "-----------------------------------" << endl;
                cout << "Find Mode" << endl;
                cout << "-----------------------------------" << endl;
                findMode(); 
                break;

            // Median Function case
            case 3:
                cout << "-----------------------------------" << endl;
                cout << "Median Function" << endl;
                cout << "-----------------------------------" << endl;
                answer = findMedian();  
                cout << "Median: " << answer << endl;

                break;

            // Exit case
            case 4:
                cout << "-----------------------------------" << endl;
                cout << "Exiting program." << endl;
                break;

            // Default case
            default:
                cout << "Invalid input." << endl;
                break;
        }

        cout << "-----------------------------------" << endl;

    } while (control != 4);

    // Exit 
    return 0;

} // main

/* Functions */

// Takes an array to initialize based on user input. Array can either be filled with rand vals or user input
int* initializeArray(int& size) {

    //Variables
    bool valid = false;
    int* array = NULL;
    char choice;

    // Input validation for getting the size of the array
    while (!valid) {
        // Ask the user for the size of the array
        cout << "\nEnter the size of the array: ";
        cin >> size;

        // Check if the size is valid
        if (size > 0) {
            valid = true;
        } 
        else {
            cout << "Invalid size. Please enter a positive integer." << endl;
        }
    }

    // Dynamically allocate memory for the array
    array = new int[size];

    valid = false; // Reset the valid flag

    // Ask the user if they want to generate random values or input values manually
    cout << "Do you want random values? (y/n): ";
    cin >> choice;

    // Input validation for the array generation method
    while(!valid) {
        if (isalpha(choice)) {
            choice = tolower(choice);

            if (choice == 'y' || choice == 'n') {
                valid = true;
            } // inner if

            else {
                cout << "Invalid input. Please enter 'y' or 'n': ";
                cin >> choice;
            } // inner else
        
        } // if
        
        else {
            cout << "Invalid input. Please enter 'y' or 'n': ";
            cin >> choice;
        } // else
    } // while


    if (choice == 'y') {
        // Generate random values
        generateRandomArray(array, size);
    } else {
        // Manually input values
        cout << "Enter " << size << " values: " << endl;
        for (int i = 0; i < size; i++) {
            cout << i+1 << ".) ";
            cin >> array[i];
        }
    }

    // Return the array
    return array;  
}


// Generates an array of random integers
void generateRandomArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100; // Random numbers between 0 and 99
    } // for
} // generateRandomArray

// Takes an array and a key, performs linear and binary search, and displays the number of comparisons made
void searchBenchmarks() {
    int size, linearComparisons, binaryComparisons;
    
    // Use initializeArray to create the array based on user input
    int* array = initializeArray(size);

    // Ask the user for the key to search for
    int key;
    cout << "Enter the value to search for (key): ";
    cin >> key;

    // Perform linear search
    linearComparisons = linearSearch(array, size, key);

    // Sort the array to send to binary search
    bubbleSort(array, size);  
    binaryComparisons = binarySearch(array, size, key);

    // Display results
    cout << "\nTarget to search for: " << key << endl;
    cout << "Linear Search Comparisons: " << linearComparisons << endl;
    cout << "Binary Search Comparisons: " << binaryComparisons << endl;

    // Free dynamically allocated memory
    delete[] array;
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

        // Check if the key is at the middle
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

    // Return the number of comparisons made
    return comparisons; 
} // binarySearch

// Mode Function 
void findMode() {

    // Variables
    bool modeFound = false;
    int size, minVal = 0, maxVal = 0, range = 0, maxCount = 0;
    int* modeCount = NULL;

    // Use initializeArray to create the array based on user input
    int* array = initializeArray(size);



    // Find the min and max value in the array to allocate modeCount properly
    for (int i = 0; i < size; i++) {

        if (array[i] < minVal) {
            minVal = array[i];
        } // if

        if (array[i] > maxVal) {
            maxVal = array[i];
        } // if
    } // for

    // Calculate the range of the array and allocate modeCount to store the frequency of each element
    range = maxVal - minVal + 1;

    modeCount = new int[range](); 

     // Count occurrences of each value
    for (int i = 0; i < size; i++) {
        modeCount[array[i] - minVal]++;  // Adjust index by subtracting minVal
    } // for

    // Find the maximum count of any value
    for (int i = 0; i < range; i++) {
        if (modeCount[i] > maxCount) {
            maxCount = modeCount[i];
        } // if
    } // for

    // Print all modes
    cout << "Modes with frequency " << maxCount << ": ";
    for (int i = 0; i < range; i++) {

        // Print the mode(s) with the max count
        if (modeCount[i] == maxCount) {

            // Set modeFound to true if a mode is found
            modeFound = true;

            // Print the mode(s) while adjusting the index by adding minVal
            cout << (i + minVal) << " "; 
        } // if
    } // for

    cout << endl;

    // Print message if no mode is found
    if (!modeFound) {
        cout << "No mode found.";
    } // if

    cout << endl;

    // Free dynamically allocated memory
    delete[] array;
    delete[] modeCount;

} // findMode


// Determines the median of an array while using pointers to access elements and returns the median value
double findMedian() {
    // Variable 
    int size;
    double median = 0.0;

    // Use initializeArray to create the array based on user input
    int* array = initializeArray(size);
    bubbleSort(array, size);

    // Check if the size is even or odd
    if (size % 2 == 0) {
        // If even, average the two middle elements
        median = (*(array + size / 2 - 1) + *(array + size / 2)) / 2.0;
    } // if

    // If odd, return the middle element
    else {
        median = *(array + size / 2);
    } // else

    // Free dynamically allocated memory
    delete[] array;

    // Return the median
    return median; 
} // findMedian
