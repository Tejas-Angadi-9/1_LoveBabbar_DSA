#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    // Dynamic array creation
    int *left = new int[len1];
    int *right = new int[len2];

    // Copy the values
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k];
        k++;
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k];
        k++;
    }

    // Merge logic
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;

    while (leftIndex < len1 && rightIndex < len2)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex++] = left[leftIndex++];
        }
        else
        {
            arr[mainArrayIndex++] = right[rightIndex++];
        }
    }

    // Copy logic for remaining left array
    while (leftIndex < len1)
    {
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    // Copy logic for remaining right array
    while (rightIndex < len2)
    {
        arr[mainArrayIndex++] = right[rightIndex++];
    }
}

void mergeSort(int *arr, int s, int e)
{
    // base case
    if (s >= e)
        return;

    // Find mid
    int mid = s + (e - s) / 2;
    // Sort left part using recursion
    mergeSort(arr, s, mid);
    // Sort left part using recursion
    mergeSort(arr, mid + 1, e);

    // Merge these arrays which is divided -> Now time to conquer
    merge(arr, s, e);
}

int main()
{
    int arr[] = {38, 27, 43, 10};
    int n = sizeof(arr) / sizeof(int);

    int s = 0, e = n - 1;
    mergeSort(arr, s, e);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}