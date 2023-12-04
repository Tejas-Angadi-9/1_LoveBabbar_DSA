#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> arr, int n){
    // STEP 1: Create a hashmap
    unordered_map<int, int> mpp;

    // STEP 2: Traverse through the array and store the value's freq in hashmap
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }

    // STEP 3: Traverse through the hashmap and check which key's value is > n/2
    for(auto it:mpp){
        // STEP 4: If greater then return that element
        if(it.second > n/2)
            return it.first;
    }

    // STEP 5: Return -1 when there is no majority element
    return -1;
}

int main(){
    vector<int> arr {2,2,1,1,1,2,2};
    int n = arr.size();

    int ans = majorityElement(arr, n);
    cout<<"Majority Element: "<<ans<<endl;
}