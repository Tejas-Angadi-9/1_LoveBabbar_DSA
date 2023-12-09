#include<bits/stdc++.h>
using namespace std;

vector<int> sortNumbers(vector<int> arr){
    sort(arr.begin(), arr.end());

    return arr;
}

int main(){
    vector<int> arr {2,0,2,1,1,0};

    vector<int> ans = sortNumbers(arr);
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
}

// TC: O(nLogn)     SC: O(1)