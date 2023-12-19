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

int main(){
    vector<int> arr {2,4,6,7,8,9,10,12,20};
    int ans = findPivot(arr);
    cout<<"Pivot Index: "<<ans<<endl;
}

// TC: O(logN)  SC: O(1)