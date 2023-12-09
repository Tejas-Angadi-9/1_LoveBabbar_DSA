// Union with duplicates
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a {1,2,4,6,8,10};
    vector<int> b {3,4,5,6};

    vector<int> ans;
    for(int i=0; i<a.size(); i++){
        int ele = a[i];
        for(int j=0; j<b.size(); j++){
            if(ele == b[j]){
                b[j] = INT_MIN;
            }
        }
    }

    for(int i=0; i<a.size(); i++){
        ans.push_back(a[i]);
    }

    for(int i=0; i<b.size(); i++){
        if(b[i] != INT_MIN)
            ans.push_back(b[i]);
    }

    for(auto it:ans){
        cout<<it<<" ";
    }
}

// TC: O(n^2)   SC: O(n)