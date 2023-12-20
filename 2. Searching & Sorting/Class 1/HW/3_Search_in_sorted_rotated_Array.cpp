#include<bits/stdc++.h>
using namespace std;
int findPivot(vector<int> arr){
    int s = 0, e = arr.size()-1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(s == e)  return s;
        if(mid <= e && arr[mid] > arr[mid+1])
            return mid;
        else if(mid - 1 >= s && arr[mid-1] > arr[mid])
            return mid-1;
        else if(arr[mid] < arr[s])
            e = mid - 1;
        else 
            s = mid + 1;
        mid = s + (e-s)/2;
    }
    return -1;
}

int binarySearch(vector<int> arr, int s, int e, int target){
    int mid = s+(e-s)/2;

    while(s<=e){
        if(arr[mid] == target)      
            return mid;
        else if(arr[mid] > target)  e = mid - 1;
        else    s = mid + 1;

        mid = s+(e-s)/2;
    }
    return -1;
}


int main(){
    vector<int> arr{9,10,2,4,6,8};
    int target = 8;
    int pivotIndex = findPivot(arr);
    int ans;
    if(target >= arr[0] && target <= arr[pivotIndex])
        ans = binarySearch(arr, 0, pivotIndex, target);
    else
        ans = binarySearch(arr, pivotIndex+1, arr.size()-1, target);

    cout<<ans<<endl;
}

// TC: O(logN)  SC: O(1)