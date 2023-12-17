// DUTCH NATIONAL FLAG ALGORITHM
#include<iostream>
#include<vector>
using namespace std;

vector<int> sortNumbers(vector<int> arr){
    int n = arr.size();
    int low = 0, mid = 0, high = n-1;

    while(mid <= high){
        if(arr[mid] == 0)   swap(arr[low++], arr[mid++]);
        else if(arr[mid] == 1)  mid++;
        else if(arr[mid] == 2)    swap(arr[mid], arr[high--]);
    }
    return arr;
}

int main(){
    vector<int> arr {2,0,2,1,1,0};
    vector<int> ans = sortNumbers(arr);

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
}

// TC: O(n)     SC: O(1)