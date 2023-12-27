#include<bits/stdc++.h>
using namespace std;

int findPairs(vector<int> arr, int k){
    set<int> st;
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(abs(arr[j] - arr[i]) == k){
                st.insert(arr[j]);
            }
        }
    }
    return st.size();
}

int main(){
    vector<int> arr {1,1,1,1};
    int k = 0;
    int ans = findPairs(arr, k);
    cout<<"Pairs: "<<ans<<endl;
}

// TC: O(n^2)   SC: O(1)