//! TWO POINTER APPROACH

#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int s, int val){
    int e = arr.size()-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid] == val) return mid;
        else if(arr[mid] > val) e = mid - 1;
        else    s = mid + 1;
    }
    return -1;
}

int findPairs(vector<int> arr, int k){
    sort(arr.begin(), arr.end());
    set<pair<int, int>> st;
    for(int i=0; i<arr.size()-1; i++){
        int val = arr[i] + k;
        if(binarySearch(arr, i+1, val) != -1){
            st.insert({arr[i], arr[i]+k});
            // cout<<arr[i]<<" "<<arr[i]+k<<endl;
        }
    }
    return st.size();
}

int main(){
    vector<int> arr {1,5,3,4,2};
    int k = 3;
    int ans = findPairs(arr, k);
    cout<<"Pairs: "<<ans<<endl;
}

// TC: O(nlogn)   SC: O(n)