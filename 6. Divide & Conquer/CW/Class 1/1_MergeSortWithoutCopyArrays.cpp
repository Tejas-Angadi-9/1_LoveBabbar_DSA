#include <iostream>
using namespace std;

//* Function to merge the broken parts into a single part while sorting
void merge(int *arr, int s, int mid, int e) {
    int len1 = mid - s + 1; // Length of the left part
    int len2 = e - mid;     // Length of the right part

    int *temp = new int[len1 + len2]; // Temporary array to store merged elements
    int i = s, j = mid + 1, k = 0;    // Pointers for the left, right, and temporary arrays

    // Merge the two parts into the temporary array
    while (i <= mid && j <= e) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy the remaining elements of the left part, if any
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements of the right part, if any
    while (j <= e) {
        temp[k++] = arr[j++];
    }

    // Copy the merged elements from the temporary array back to the original array
    for (int idx = 0; idx < k; idx++) {
        arr[s + idx] = temp[idx];
    }

    // Free the memory allocated for the temporary array
    delete[] temp;
}

//* Merge sort function
void mergeSort(int *arr, int s, int e) {
    // Base case
    if (s >= e) {
        return;
    }

    // Find the mid index
    int mid = s + (e - s) / 2;

    // Recursively sort the left and right halves
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    // Merge the sorted halves
    merge(arr, s, mid, e);
}

int main() {
    int arr[] = {38, 27, 43, 10};
    int n = sizeof(arr) / sizeof(int);

    // Perform merge sort
    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
