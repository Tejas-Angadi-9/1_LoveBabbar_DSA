#include<bits/stdc++.h>
using namespace std;

vector<int> negativeIntegers(vector<int> arr, int k){
    int n = arr.size();
    vector<int> ans;
    for(int i=0; i<=n-k; i++){
        int value = 0;
        int j = (i+k)-1;
        for(int k=i; k<=j; k++){
            if(arr[k] < 0)
                value = arr[k];
            if(value < 0)
                break;
        }
        ans.push_back(value);
    }
    return ans;
}

int main(){
    vector<int> arr {-8, 2, 3, -6, 10};
    int k = 2;

    vector<int> ans = negativeIntegers(arr, k);
    for(auto it:ans){
        cout<<it<<" ";
    }
}