#include<bits/stdc++.h>
using namespace std;

int findInNearlySortedArray(vector<int> arr, int target){
    int s = 0, e=arr.size()-1;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(arr[mid] == target)  return mid;
        else if(arr[mid - 1] == target) return mid-1;
        else if(arr[mid+1] == target)   return mid+1;
        else if(arr[mid] > target)  e = mid - 2;
        else    s = mid + 2;

        mid = s+(e-s)/2;
    }
    return -1;
}

int main(){
    vector<int> arr {10,3,40,20,50,70};
    int target = 70;
    int ans = findInNearlySortedArray(arr, target);
    cout<<"Index: "<<ans<<endl;
}

// TC: O(logn)  SC: O(1)