#include<bits/stdc++.h>
using namespace std;

int findPeak(vector<int> arr){
    int n = arr.size();
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;

    while(s<e){
        if(arr[mid] < arr[mid+1])
            s = mid + 1;
        else if(arr[mid] > arr[mid+1])
            e = mid;

        mid = s+(e-s)/2;
    }
    return mid;
}

int main(){
    vector<int> arr {0,10,5,2};
    int index = findPeak(arr);
    cout<<"Peak element index: "<<index<<endl;
    cout<<"Peak Element value: "<<arr[index]<<endl;
}