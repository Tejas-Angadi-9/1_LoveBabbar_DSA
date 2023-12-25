#include<bits/stdc++.h>
using namespace std;

int findInNearlySortedArray(vector<int> arr, int target){
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == target)
            return i;
    }
    return -1;
}

int main(){
    vector<int> arr {10,3,40,20,50,70};
    int target = 70;
    int ans = findInNearlySortedArray(arr, target);
    cout<<"Index: "<<ans<<endl;
}

// TC: O(n)  SC: O(1)