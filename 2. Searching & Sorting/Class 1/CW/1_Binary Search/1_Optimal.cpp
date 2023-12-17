#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int target){
    int n = arr.size();
    int s = 0, e=n-1;
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
    vector<int> arr {2,4,7,10,15,19,21};
    int target = 2;
    cout<<binarySearch(arr, target)<<endl;

    //  Returns TRUE/FALSE while using STL function
    cout<<"Using binary search STL: "<<binary_search(arr.begin(), arr.end(), target);
}