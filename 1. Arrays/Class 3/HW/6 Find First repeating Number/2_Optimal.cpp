#include<bits/stdc++.h>
using namespace std;

int findFirstRepeatingNumber(vector<int> arr){
    int n = arr.size();

    // Find max to create a new array of that size
    int maxi = INT_MIN;
    for(int i=0; i<n; i++)
        maxi = max(arr[i], maxi);
    
    // Creating a new array of maximum number size + 1
    int hash[maxi+1] = {0};

    // Increasing the frequency
    for(int i=0; i<n; i++)
        hash[arr[i]]++;

    // Check whether the array number's frequency in new array is > 1 (or) == 2
    for(int i=0; i<n; i++){
        if(hash[arr[i]] > 1)
            return arr[i];
    }
    return -1;
}

int main(){
    vector<int> arr {10,5,3,4,3,5,6};
    cout<<"First repeating number: "<<findFirstRepeatingNumber(arr)<<endl;
}

// TC: O(n)     SC: O(n)