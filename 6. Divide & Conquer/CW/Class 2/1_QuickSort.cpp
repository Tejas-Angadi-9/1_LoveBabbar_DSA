#include<bits/stdc++.h>
using namespace std;

int partition(int *arr, int s, int e){
    //* Choose the pivot Value
    int pivotIndex = s;
    int pivotElement = arr[s];

    //* Find the right position for the pivot element and place it there
    int cnt = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i] <= pivotElement){
            cnt++;
        }
    }

    //* PivotElement's correct index is found after the end of this array. So place it over there
    int correctIndex = s + cnt;
    swap(arr[pivotIndex], arr[correctIndex]);
    pivotIndex = correctIndex;
    
    //* Left partition should contain numbers less than pivotElement & right partition should contain number greater than pivotElement
    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] < pivotElement){
            i++;
        }
        while(arr[j] > pivotElement){
            j--;
        }

        //* There can be 2 cases 
        //* 1. found elements to be swapped. That were placed in the wrong position from the pivotNumber 
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i], arr[j]);
        }
        //* 2. No elements found to be swapped.
    }
    return pivotIndex;  
}

void quickSort(int arr[], int s, int e){
    //* Base case
    if(s >= e)
        return;
    
    //* Partition logic, return pivotIndex
    int p = partition(arr, s, e);

    //* Recursive calls
    //pivot element's left part
    quickSort(arr, s, p-1);
    //pivot element's right part
    quickSort(arr, p+1, e);
}

int main(){
    int arr[] = {8,1,3,4,20,50,30};
    int n = sizeof(arr)/sizeof(int);

    int s = 0, e = n-1;
    quickSort(arr, s, e);

    for(auto it:arr){
        cout<<it<<" ";
    }
}