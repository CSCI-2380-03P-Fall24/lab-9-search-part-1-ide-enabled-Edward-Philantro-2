#include <iostream>
#include <string>

using namespace std;

// write a function to print the contents of your array
//   bonus (+5% to your grade for this lab)! try to implement your function so that it can accept
//     many types of data (int, char, string, etc.)
//  Replace the ... with proper parameters
template <typename flexibleType> // ???
void printArray(flexibleType arr[], int size) { 
    if (size == 0) return;
    cout << arr[0] << endl;
    printArray(arr + 1, size - 1);
}

// Implement a sequential search algorithm
// your function should search for a target value (target)
//    within the indices of "start" to "end"
// return true if target exists in the array within this range,
//    return false otherwise
bool seqSearch(string target, string arr[], int start, int end) {
    if (start > end) {return false;}
        if (arr[start] == target){return true;}
   return seqSearch(target, arr, start + 1, end);
}

// Implement an iterative binary search 
// Return true if target exists in the array with size n,
//    return false otherwise 
bool binSearch(float target, float arr[], int n){  
   int first = 0;
   int last = n - 1;
   int middle;
   while (first <= last){
    middle = (first + last)/2;
      if (target == arr[middle]){
         return true;
      }else if (target < arr[middle]){
            last = middle - 1;
         }
         else {
            first = middle + 1;
         }
    }
    return false;
}

// Implement a recursive binary search 
// Return true if target exists in the array with size n
//   return false otherwise
bool binSearchR(char target, char charray[], int n) {
    // base case
    if (n==0){return false;} 
   //general case
    if(target == charray[n/2]){return true;}
    else if (target < charray[n / 2]){ return binSearchR(target, charray, n = n/2);}
    else if (target > charray[n / 2]){ return binSearchR(target, charray + (n/2) + 1, n - (n/2) - 1);}
}

// Implement Exponential Search
//    Reuse your iterative binSearch(...) on a narrowed window
//    Assumes the array is sorted in ascending order
// Step 1: Handle edge cases (empty array) and quickly check the first element.
// Step 2: Grow a “bound”: start at 1, then repeatedly double it
//         while you are still inside the array and the current value is less than the target.
// Step 3: Define a search window:
//         - The left edge is halfway back from the current bound.
//         - The right edge is the smaller of (current bound) and (last valid index).
// Step 4: Run your existing binSearch on just that window and return its result.
//         You may pass a pointer to the start of the window and its length,
//         or copy that window to a temporary buffer if you prefer.
bool expSearch(float target, float arr[], int n) {
    if (n == 0 ) {return false;}
    if (target == arr[0]) {return true;}
    int i = 1;
    while ( n > i && arr[i] < target){
        i *= 2;
    }
    int right;
    int left = i/2;
    if (i > n-1) {right = n -1;} else {right = i;}
   return binSearch(target, arr + left, n = right - left + 1);
}
