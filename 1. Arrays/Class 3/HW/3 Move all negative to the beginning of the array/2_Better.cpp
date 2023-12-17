#include<bits/stdc++.h>
using namespace std;

vector<int> moveNegatives(vector<int> arr){
    int n = arr.size();
    vector<int> ans;
    for(int i=0; i<n; i++){
        if(arr[i] < 0)  
            ans.push_back(arr[i]);
    }

    for(int i=0; i<n; i++){
        if(arr[i] >= 0)
            ans.push_back(arr[i]);
    }
    return ans;
}

int main(){
    vector<int> arr {-12, 11, -13,-5,6,-7,5,-3,-6};
    
    vector<int> ans = moveNegatives(arr);

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
}

// TC: O(n) + O(n) = O(n)     SC: O(n)