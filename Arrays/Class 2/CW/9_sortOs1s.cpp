// Sort O's and 1's
#include<bits/stdc++.h>
using namespace std;

vector<int> sortNumbers(vector<int> arr, int n){
    int i=0, j=n-1;
    while(i<=j){
        if(arr[i] == 1 && arr[j] == 0)
            swap(arr[i++], arr[j--]);
        else if(arr[i] == 0)    i++;
        else if(arr[j] == 1)    j--;
    }
    return arr;
}

int main(){
    vector<int> arr = {0,1,1,0,1,0,1,1,0,0,1,0,1,1,0,0,1};
    int n = arr.size();

    vector<int> ans = sortNumbers(arr, n);

    for(auto it:ans)
        cout<<it<<" ";
}