#include<bits/stdc++.h>
using namespace std;

vector<int> findClosestElements(vector<int> arr, int k, int x){
    vector<int> ans;
    int l=0, h=arr.size()-1;
    while(h-l >= k){
        if(x - arr[l] > arr[h] - x)     l++;
        else    h--;
    }
    for(int i=l; i<=h; i++)
        ans.push_back(arr[i]);
    return ans;
}

int main(){
    vector<int> arr {12,16,22,30,35,39,42,45,48,50,53,55,56};
    int k = 4, x = 35;
    vector<int> ans = findClosestElements(arr, k, x);
    for(int it:ans)
        cout<<it<<" ";
}

// TC: O(n-k)   O(1)