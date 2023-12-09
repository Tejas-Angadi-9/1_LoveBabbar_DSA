#include<bits/stdc++.h>
using namespace std;

vector<int> findIntersection(vector<int> a, vector<int> b){
    vector<int> ans;
    for(int i=0; i<a.size(); i++){
        int ele = a[i];
        for(int j=0; j<b.size(); j++){
            if(ele == b[j]){
                b[j] = -1;
                ans.push_back(ele);
            }
        }
    }
    return ans;
}

int main(){
    vector<int> a{1,2,3,3,4,6,8};
    vector<int> b{3,3,4,10};

    vector<int> ans = findIntersection(a, b);

    for(auto it:ans)
        cout<<it<<" ";
}

// TC: O(n^2)     SC:O(n) 