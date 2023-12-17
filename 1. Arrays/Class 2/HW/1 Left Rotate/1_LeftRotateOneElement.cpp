// Rotate the array of size n to the left size by 1 element
#include<bits/stdc++.h>
using namespace std;

vector<int> rotateArray(vector<int> arr, int n){
    // STEP 1: Pick the first element
    int x = arr[0];
    
    // STEP 2: Move all the remaining elements to the left by 1 position
    for(int i=0; i<n-1; i++){
        arr[i] = arr[i+1];
    }

    // STEP 3: Put the x in the last position of the array where the space is empty
    arr[n-1] = x;

    // STEP 4: Return the rotated array
    return arr;
}

int main(){
    vector<int> arr {1,2,3,4,5};
    int n = arr.size();
    vector<int> ans = rotateArray(arr, n);

    for(auto it:ans)
        cout<<it<<" ";
}