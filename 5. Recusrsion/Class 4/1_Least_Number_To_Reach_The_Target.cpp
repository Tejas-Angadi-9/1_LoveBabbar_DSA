#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int target){
    //bc
    if(target == 0)
        return 0;
    
    if(target < 0)
        return INT_MAX;
    
    int mini = INT_MAX;
    for(int i=0; i<arr.size(); i++){
        int ans = solve(arr, target - arr[i]);
        if(ans != INT_MAX){
            ans = ans + 1;
            mini = min(mini, ans);
        }
    }
    return mini;
}

int main(){
    vector<int> arr {1,2};
    int target = 5;
    int ans = solve(arr, target);
    cout<<"Least Numbers required to get the target: "<<ans<<endl;
}