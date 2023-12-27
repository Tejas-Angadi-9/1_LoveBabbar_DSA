#include<bits/stdc++.h>
using namespace std;

int findOddOccuringElement(vector<int> arr){
    int n = arr.size();
    int s = 0, e = n-1;
    while (s<=e){
        int mid = s+(e-s)/2;
        if(s == e)  return s;
        if(mid % 2 == 0){
            if(arr[mid] == arr[mid+1])  s=mid+2;
            else e = mid;
        }
        else{
            if(arr[mid - 1] == arr[mid])    s = mid + 1;
            else    e = mid-1;
        }
    }
    return e;
}

int main(){
    vector<int> arr {1,1,2,2,3,3,4,4,3,600,600,4,4};
    int ans = findOddOccuringElement(arr);
    cout<<"Odd occuring Index: "<<ans<<endl;
    cout<<"Odd occuring Value: "<<arr[ans]<<endl;
}

// TC: O(logn)  SC: O(1)