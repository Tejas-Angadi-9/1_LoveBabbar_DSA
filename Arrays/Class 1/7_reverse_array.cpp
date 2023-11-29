// Reverse an array
#include<bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int n){
    cout<<"Before Reversing: ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

    cout<<"\nAfter reversing: ";
    int i=0, j=n-1;
    while(i<=j)
        swap(arr[i++], arr[j--]);
    
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    
}

int main(){
    int arr[] = {10,20,30,40,50,60,70};
    int n = 7;
    reverseArray(arr, n);
}

// TC: O(n)     SC: O(1)