#include<bits/stdc++.h>
using namespace std;

int firstOccurance(vector<int> arr, int target){
    int n = arr.size();
    int s = 0, e=n-1, ans = -1; 
    int mid = s+(e-s)/2;

    while(s<=e){
        if(arr[mid] == target){
            ans = mid;
            e = mid - 1;
        }      
        else if(arr[mid] > target)  e = mid - 1;
        else    s = mid + 1;

        mid = s+(e-s)/2;
    }
    return ans;
}

int lastOccurance(vector<int> arr, int target){
    int n = arr.size();
    int s = 0, e=n-1, ans = -1; 
    int mid = s+(e-s)/2;

    while(s<=e){
        if(arr[mid] == target){
            ans = mid;
            s = mid + 1;
        }      
        else if(arr[mid] > target)  e = mid - 1;
        else    s = mid + 1;

        mid = s+(e-s)/2;
    }
    return ans;
}

int main(){
    vector<int> arr {1,3,4,4,4,4,4,6,7,9};
    int target = 4;
    int firstAns = firstOccurance(arr, target);
    int lastAns = lastOccurance(arr, target);

    cout<<"First occurance index: "<<firstAns<<endl;
    cout<<"Last occurance index: "<<lastAns<<endl;
    cout<<"Total occurance's: "<<lastAns - firstAns + 1<<endl;
}