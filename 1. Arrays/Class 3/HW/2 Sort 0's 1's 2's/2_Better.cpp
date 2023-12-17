#include<iostream>
#include<vector>
using namespace std;

vector<int> sortNumbers(vector<int> arr){
    int n = arr.size();

    vector<int> ans;
    int zeroCnt = 0, oneCnt = 0, twoCnt = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 0) zeroCnt++;
        else if(arr[i] == 1)    oneCnt++;
        else twoCnt++;
    }

    while(zeroCnt--){
        ans.push_back(0);
    }
    while(oneCnt--){
        ans.push_back(1);
    }
    while(twoCnt--){
        ans.push_back(2);
    }
    return ans;
}

int main(){
    vector<int> arr {2,0,2,1,1,0};
    vector<int> ans = sortNumbers(arr);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}

// TC: O(n)     SC: O(1)