#include<bits/stdc++.h>
using namespace std;

int findPeak(vector<int> arr){
    int n = arr.size();
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

int main(){
    vector<int> arr {0,10,5,2};
    cout<<"Peak Element: "<<findPeak(arr)<<endl;
}