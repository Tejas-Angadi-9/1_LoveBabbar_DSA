// Union arrays with no duplicates
#include<bits/stdc++.h>
using namespace std;

vector<int> unionArr(vector<int> a, vector<int> b){
    vector<int> ans;
    for(int i=0; i<a.size(); i++)
        ans.push_back(a[i]);
    
    for(int i=0; i<b.size(); i++)
        ans.push_back(b[i]);

    return ans;
}

void printArray(vector<int> ans){
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    vector<int> a = {2,4,6,8};
    vector<int> b = {1,3,7};

    vector<int> ans = unionArr(a, b);
    printArray(ans);
}

// TC: O(n)     SC: O(n)