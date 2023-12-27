//! TWO POINTER APPROACH

#include<bits/stdc++.h>
using namespace std;

int findPairs(vector<int> arr, int k){
    sort(arr.begin(), arr.end());
    int i=0, j=i+1;
    set<int> st;
    while(j<arr.size()){
        int diff = arr[j] - arr[i];
        if(diff == k){
            st.insert(arr[j]);
            i++, j++;
        }
        else if(diff > k){
            j=i+1;
            i++;
        }
        else if(diff < k)  j++;
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