#include<iostream>
#include<vector>
using namespace std;

int findUniqueElement(vector<int> arr, int n){
    int ans = 0;
    for(int i=0; i<n; i++)
        ans = ans ^ arr[i];
    return ans;
}

int main(){
    vector<int> arr = {10,20,20,30,10};

    
    cout<<findUniqueElement(arr, arr.size())<<endl;
}

// TC: O(n)     SC: O(1)