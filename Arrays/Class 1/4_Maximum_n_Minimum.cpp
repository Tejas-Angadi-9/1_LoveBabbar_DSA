// Find maximum and minimum number in an array
#include<bits/stdc++.h>
using namespace std;

int findMaximum(int arr[], int n){
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i] > maxi)
            maxi = arr[i];
    }
    return maxi;
}

int findMinimum(int arr[], int n){
    int mini = INT_MAX;
    for(int i=0; i<n; i++){
        if(arr[i] < mini)
            mini = arr[i];
    }
    return mini;
}

int main(){
    int arr[] = {2,4,1,6,8,9,0};
    int n = 7;
    cout<<"Maximum: "<<findMaximum(arr, n)<<endl;
    cout<<"Minimum: "<<findMinimum(arr, n)<<endl;
}

// TC: O(n)     SC: O(1)