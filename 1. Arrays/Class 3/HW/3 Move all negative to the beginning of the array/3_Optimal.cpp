#include<bits/stdc++.h>
using namespace std;

vector<int> moveNegatives(vector<int> arr){
    int n = arr.size();
    int i=0, j=n-1;
    while(i<=j){
        if(arr[i] < 0)  i++;
        else if(arr[j] > 0) j--;
        else if(arr[i] > 0 && arr[j] < 0)   swap(arr[i++], arr[j--]);
    }
    return arr;
}

int main(){
    vector<int> arr {-12, 11, -13,-5,6,-7,5,-3,-6};
    vector<int> ans = moveNegatives(arr);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}

// TC: O(n)     SC: O(1)