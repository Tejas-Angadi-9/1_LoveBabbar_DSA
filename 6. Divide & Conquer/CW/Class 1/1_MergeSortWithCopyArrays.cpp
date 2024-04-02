//! Creating 2 copy arrays

#include<bits/stdc++.h>
using namespace std;

//* Function to merge the broken parts into a single part while sorting
void merge(int *arr, int s, int e){
    //Find the mid
    int mid = s+(e-s)/2;

    // Find the len of 2 halves
    int len1 = (mid - s) + 1;
    int len2 = e - mid;

    //? Create the new array dynamically
    int *left = new int[len1];
    int *right = new int[len2];

    // Copy the values
    // for the left part from 0 i.e start
    int k = s;
    for(int i=0; i<len1; i++){
        left[i] = arr[k++];
    }
    // for the right part from mid + 1
    k = mid+1;
    for(int i=0; i<len1; i++){
        right[i] = arr[k++];
    }

    // Logic of checking which is smaller and then putting the values from left/right into the main array back
    int leftIndex = 0, rightIndex = 0, mainArrayIndex = s;

    // When leftIndex and rightIndex is inside the left and right array respectively
    while(leftIndex < len1 && rightIndex < len2){
        if(left[leftIndex] < right[rightIndex]){
            // Put the value which is smaller in the main array back starting the index of s
            arr[mainArrayIndex++] = left[leftIndex++];
        }
        else{
            arr[mainArrayIndex++] = right[rightIndex++];
        }
    }

    // When rightIndex runs out of right array we copy the all the values of left array as there is no values to compare
    while(leftIndex < len1){
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    // When leftIndex runs out of left array we copy the all the values of right array as there is no values to compare
        while(rightIndex < len2){
        arr[mainArrayIndex++] = right[rightIndex++];
    }
} 

//* Merge sort function
void mergeSort(int *arr, int s, int e){
    //Base case
    if(s >= e)  
        return;

    // Finding the mid 
    int mid = s+(e-s)/2;

    // Dividing the array in two parts using mid 
    //Left part from start to mid 
    mergeSort(arr, s, mid);
    //Right part from mid+1 to end 
    mergeSort(arr, mid+1, e);

    // Merge these broken arrays into a single array while sorting using the sorting logic. //* From the function
    merge(arr, s, e);
}

int main(){
    int arr[] = {38,27,43,10};
    int n = sizeof(arr)/sizeof(int);

    int s = 0, e = n-1;
    mergeSort(arr, s, e);

    // It is sorted as we change in the main array which is passed as a pointer
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}