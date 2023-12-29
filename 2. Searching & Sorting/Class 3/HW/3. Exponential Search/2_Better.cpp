#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int x, int s, int e){
    while(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid] == x)   return mid;
        else if(arr[mid] > x)  e = mid-1;
        else    s = mid+1;
    }
    return -1;
}

int exponentialSearch(vector<int> arr, int target){
    int i=0, j=1, n=arr.size();
    if(arr[0] == target)    return 0;
    while(arr[j] <= target){
        if(arr[i] <= target){
            i = j;
            j = j*2;
        }
        if(j > n)  j = n-1;
        i = i/2;
    }
    return binarySearch(arr, target, i, j);
}

int main(){
    vector<int> arr {3,4,5,6,11,13,14,15,56,70};
    int x = 13;
    int ans = exponentialSearch(arr, x);
    cout<<"Index: "<<ans<<endl;
}